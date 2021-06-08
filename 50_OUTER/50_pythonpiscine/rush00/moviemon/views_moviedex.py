from django.http.response import Http404
from django.shortcuts import render
from django.shortcuts import redirect
from . import game


def moviedex_context(lst):
    btn_a = "location.href='';"
    if lst is not None:
        movie_id = lst[0][1]
        movie_poster = lst[1]
        btn_a = "location.href='" + movie_id + "/';"
    else:
        movie_id = None
        movie_poster = []
    dic = {
        'btn_north': "location.href='?ctrl=n';",
        'btn_south': "location.href='?ctrl=s';",
        'btn_a': btn_a,
        'btn_select': "location.href='/worldmap';",
        'lst_id': movie_id,
        'lst_poster': movie_poster,
        'selected_index': 3
    }
    return dic


def get_three_movielist(data, setting):
    lst1 = []
    lst2 = []

    if len(data.catched_movie) == 0:
        return None
    elif len(data.catched_movie) == 1:
        data0 = data.catched_movie[0]
        data1 = data.catched_movie[0]
        data2 = data.catched_movie[0]
    elif len(data.catched_movie) == 2:
        if data.index == 0:
            data0 = data.catched_movie[1]
            data1 = data.catched_movie[0]
            data2 = data.catched_movie[1]
        elif data.index == 1:
            data0 = data.catched_movie[0]
            data1 = data.catched_movie[1]
            data2 = data.catched_movie[0]
    else:
        if data.index == 0:
            data0 = data.catched_movie[len(data.catched_movie) - 1]
            data1 = data.catched_movie[data.index]
            data2 = data.catched_movie[data.index + 1]
        elif data.index == len(data.catched_movie) - 1:
            data0 = data.catched_movie[len(data.catched_movie) - 2]
            data1 = data.catched_movie[data.index]
            data2 = data.catched_movie[0]
        else:
            data0 = data.catched_movie[data.index - 1]
            data1 = data.catched_movie[data.index]
            data2 = data.catched_movie[data.index + 1]
    lst1 = [data0, data1, data2]
    lst2 = [setting.movie_db[data0]['poster'], setting.movie_db[data1]['poster'], setting.movie_db[data2]['poster']]

    return [lst1, lst2]


def moviedex(request):
    ctrl = request.GET.get('ctrl', None)
    temp_data = game.GameData()
    temp_data.load('temp')
    temp_setting = game.SettingData()

    if len(temp_data.catched_movie) > 0:
        if ctrl == 's':
            if temp_data.index < len(temp_data.catched_movie) - 1:
                temp_data.index += 1
            else:
                temp_data.index = 0
        elif ctrl == 'n':
            if temp_data.index > 0:
                temp_data.index -= 1
            else:
                temp_data.index = len(temp_data.catched_movie) - 1
    else:
        temp_data.index = None
    lst = get_three_movielist(temp_data, temp_setting)
    context = moviedex_context(lst)
    temp_data.dump('temp')
    if ctrl is not None:
        return redirect(request.path)
    return render(request, 'moviemon/moviedex.html', context)


def detail_context(movie_id, setting):
    movie_data = setting.movie_db[movie_id]
    dic = {
        'btn_b': "location.href='/moviedex/';",
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
    if movie_id not in list(temp_setting.movie_db.keys()):
        raise Http404('Moviemon not found')
    print(movie_id)
    context = detail_context(movie_id, temp_setting)
    return render(request, 'moviemon/detail.html', context)
