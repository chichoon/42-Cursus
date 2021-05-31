from django.shortcuts import render


# Create your views here.
def titlescreen(request):
    # add titlescreen.
    return render(request, 'moviemon/title.html', {})


def worldmap(request):
    lst_2d = []
    for i in range(0, 25):
        lst_1d = []
        for j in range(0, 25):
            if i == 12 and j == 12:
                lst_1d.append('s')
            else:
                lst_1d.append('0')
        lst_2d.append(lst_1d)
    return render(request, 'moviemon/worldmap.html', {})
