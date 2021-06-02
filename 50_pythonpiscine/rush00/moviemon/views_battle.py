from django.shortcuts import render
from . import game
import random


def battle_catch_flag(data, setting, movie_id):
    movie_rating = setting.movie_db[movie_id]['rate']
    capture_rate = 50 - (float(movie_rating) * 10) + (data.strength * 5)
    if capture_rate < 1:
        capture_rate = 1
    elif capture_rate > 90:
        capture_rate = 90
    if capture_rate > (random.random() * 100):
        return 2
    else:
        return 1


def battle_context(data, setting, movie_id, flag):
    movie_rating = setting.movie_db[movie_id]['rate']
    capture_rate = 50 - (float(movie_rating) * 10) + (data.strength * 5)
    if capture_rate < 1:
        capture_rate = 1
    elif capture_rate > 90:
        capture_rate = 90
    btn_a = "location.href='?ball=true';"
    if flag == 2:
        btn_a = "location.href='?ball=false';"
    print(flag)
    dic = {
        'btn_a': btn_a,
        'btn_b': "location.href='../worldmap/';",
        'movie_name': setting.movie_db[movie_id]['title'],
        'movie_poster': setting.movie_db[movie_id]['poster'],
        'movie_strength': setting.movie_db[movie_id]['rate'],
        'flag': flag,
        'movieball': data.ball,
        'capture_rate': capture_rate,
        'my_strength': data.strength,
    }
    return dic


def battle(request, moviemon_id):
    ball_thrown = request.GET.get('ball', None)
    temp_data = game.GameData()
    temp_data.load('temp')
    temp_setting = game.SettingData()
    if moviemon_id in temp_data.catched_movie:
        flag = 2
    else:
        flag = 0
    if ball_thrown == 'true' and temp_data.ball > 0 and flag != 2:
        flag = battle_catch_flag(temp_data, temp_setting, moviemon_id)
        temp_data.ball -= 1
        if flag == 2:
            temp_data.catched_movie.append(moviemon_id)
            temp_data.strength += 1
    context = battle_context(temp_data, temp_setting, moviemon_id, flag)
    temp_data.dump('temp')
    return render(request, 'moviemon/battle.html', context)

