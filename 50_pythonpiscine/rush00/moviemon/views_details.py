from django.shortcuts import render
from . import game


def detail_context(movie_id, setting):
    movie_data = setting.movie_db[movie_id]
    dic = {
        'btn_b': "location.href='../moviedex/';",
        'movie_title': movie_data['title'],
        'movie_year': movie_data['year'],
        'movie_rate': movie_data['rate'],
        'movie_poster': movie_data['poster'],
        'movie_synopsis': movie_data['synopsis'],
        'movie_director': movie_data['director'],
        'movie_actor': movie_data['actor'],
    }
    return dic


def details(request, movie_id):
    temp_setting = game.SettingData()
    print(movie_id)
    context = detail_context(movie_id, temp_setting)
    return render(request, 'moviemon/detail.html', context)
