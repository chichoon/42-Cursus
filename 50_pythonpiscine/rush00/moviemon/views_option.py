from django.shortcuts import render
from . import game


def options(request):
    context = {
        'btn_a': "location.href='save_game/';",
        'btn_b': "location.href='/';",
        'btn_start': "location.href='/worldmap/';",
    }
    return render(request, 'moviemon/options.html', context)


def save_game_context(data, setting, save_flag):
    dic = {
        'btn_north': "location.href='?ctrl=n';",
        'btn_south': "location.href='?ctrl=s';",
        'btn_a': "location.href='?ctrl=a';",
        'btn_b': "location.href='/options/';",
        'btn_start': "location.href='/worldmap/';",
        'save_index': data.save_index,
        'slota': setting.slots['slota'],
        'slotb': setting.slots['slotb'],
        'slotc': setting.slots['slotc'],
        'save_flag': save_flag,
    }
    return dic


def save_file(data, setting):
    status = str(len(data.catched_movie)) + '_' + str(len(list(setting.movie_db.keys())))
    if data.save_index == 1:
        data.remove('slota_' + setting.slots['slota'].replace('/', '_'))
        data.dump('slota_' + status)
        setting.slots['slota'] = status.replace('_', '/')
        return 'a'

    elif data.save_index == 2:
        data.remove('slotb_' + setting.slots['slotb'].replace('/', '_'))
        data.dump('slotb_' + status)
        setting.slots['slotb'] = status.replace('_', '/')
        return 'b'

    elif data.save_index == 3:
        data.remove('slotc_' + setting.slots['slotc'].replace('/', '_'))
        data.dump('slotc_' + status)
        setting.slots['slotc'] = status.replace('_', '/')
        return 'c'


def save_game(request):
    ctrl = request.GET.get('ctrl', None)
    temp_data = game.GameData()
    temp_setting = game.SettingData()
    temp_data.load('temp')

    save_flag = None
    if ctrl == 'n':
        if temp_data.save_index > 1:
            temp_data.save_index -= 1
    elif ctrl == 's':
        if temp_data.save_index < 3:
            temp_data.save_index += 1
    elif ctrl == 'a':
        save_flag = save_file(temp_data, temp_setting)

    context = save_game_context(temp_data, temp_setting, save_flag)
    temp_data.dump('temp')
    temp_setting.save_slots()
    return render(request, 'moviemon/save_game.html', context)


def load_game_context(data, setting, load_flag):
    btn_a = "location.href='/worldmap/';"
    if load_flag is None:
        btn_a = "location.href='?ctrl=a';"
    dic = {
        'btn_north': "location.href='?ctrl=n';",
        'btn_south': "location.href='?ctrl=s';",
        'btn_a': btn_a,
        'btn_b': "location.href='/';",
        'load_index': data.save_index,
        'slota': setting.slots['slota'],
        'slotb': setting.slots['slotb'],
        'slotc': setting.slots['slotc'],
        'load_flag': load_flag
    }
    return dic


def load_file(data, setting):
    if data.save_index == 1 and setting.slots['slota'] != 'Free':
        status = setting.slots['slota'].replace('/', '_')
        print(status)
        data.load('slota_' + status)
        return 'a'

    elif data.save_index == 2 and setting.slots['slotb'] != 'Free':
        status = setting.slots['slotb'].replace('/', '_')
        print(status)
        data.load('slotb_' + status)
        return 'b'

    elif data.save_index == 3 and setting.slots['slotc'] != 'Free':
        status = setting.slots['slotc'].replace('/', '_')
        print(status)
        data.load('slotc_' + status)
        return 'c'


def load_game(request):
    ctrl = request.GET.get('ctrl', None)
    temp_data = game.GameData()
    temp_setting = game.SettingData()
    temp_data.load('temp')

    load_flag = None
    if ctrl == 'n':
        if temp_data.save_index > 1:
            temp_data.save_index -= 1
    elif ctrl == 's':
        if temp_data.save_index < 3:
            temp_data.save_index += 1
    elif ctrl == 'a':
        load_flag = load_file(temp_data, temp_setting)
    context = load_game_context(temp_data, temp_setting, load_flag)
    temp_data.dump('temp')
    return render(request, 'moviemon/load_game.html', context)
