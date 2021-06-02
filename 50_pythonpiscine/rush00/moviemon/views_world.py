from django.shortcuts import render
from django.shortcuts import redirect
from . import game
import random


# Create your views here.
def world_load(data, state):
    if state == 'title':
        data.dump('temp')

    data.load('temp')


def world_move(data, ctrl):
    if ctrl == 'n' and data.coord_y > 0:
        data.coord_y -= 1
        data.move_dir = 'n'
    elif ctrl == 'w' and data.coord_x > 0:
        data.coord_x -= 1
        data.move_dir = 'w'
    elif ctrl == 's' and data.coord_y < data.size - 1:
        data.coord_y += 1
        data.move_dir = 's'
    elif ctrl == 'e' and data.coord_x < data.size - 1:
        data.coord_x += 1
        data.move_dir = 'e'


def world_context(data, flag):
    table_size = [i for i in range(0, data.size)]
    dic = {
        'coord_x': data.coord_x,
        'coord_y': data.coord_y,
        'move_dir': data.move_dir,
        'table_row': table_size,
        'table_col': table_size,
        'btn_north': "location.href='?ctrl=n';",
        'btn_west': "location.href='?ctrl=w';",
        'btn_east': "location.href='?ctrl=e';",
        'btn_south': "location.href='?ctrl=s';",
        'btn_a': "location.href='';",
        'btn_b': "location.href='';",
        'btn_start': "location.href='';",
        'btn_select': "location.href='';",
        'flag': flag,
    }
    return dic


def world_random_event(data):
    rand_seed = random.randrange(1, 11)
    if rand_seed < 4:
        data.ball += 1
        return 1
    elif rand_seed > 9:
        return 2
    else:
        return 0


def worldmap(request):
    event_flag = 0
    state = request.GET.get('from', None)
    ctrl = request.GET.get('ctrl', None)
    temp_data = game.GameData()
    temp_setting = game.SettingData()
    world_load(temp_data, state)
    world_move(temp_data, ctrl)
    event_flag = world_random_event(temp_data)
    context = world_context(temp_data, event_flag)
    temp_data.dump('temp')
    return render(request, 'moviemon/worldmap.html', context)

