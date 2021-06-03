from re import template
from django.shortcuts import render
from django.http import HttpResponse, response
from . import models


# Create your views here.
def populate(request):
    lst = [
        ['The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'],
        ['Attack of the Clones', 'George Lucas', 'Rick McCallum', '2002-05-16'],
        ['Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'],
        ['A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum', '1977-05-25'],
        ['The Empire Strikes Back', ' Irvin Kershner', 'Gary Kurtz, Rick McCallum', '1980-05-17'],
        ['Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25'],
        ['The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11'],
    ]
    i = 1
    string = ''
    try:
        for elem in lst:
            model = models.Ex05(
                title=elem[0],
                director=elem[1],
                episode_nb=i,
                producer=elem[2],
                release_date=elem[3]
            )
            model.save()
            i += 1
            string += 'OK '
    except Exception as e:
        string += str(e)
    return HttpResponse(string)


def display(request):
    lst = []
    model = models.Ex05.objects.all()
    for elem in model:
        lst.append([
            elem.title,
            elem.episode_nb,
            elem.opening_crawl,
            elem.director,
            elem.producer,
            elem.release_date
        ])
    if len(lst) == 0:
        return HttpResponse("No data available")
    else:
        context = {
            'data': lst,
        }
        return render(request, 'ex05/display.html', context)


def remove(request):
    try:
        if request.method == 'POST':
            form = request.POST
            data = models.Ex05.objects.filter(title=form['movie_title'])
            data.delete()
        lst = []
        model = models.Ex05.objects.all()
        for elem in model:
            lst.append(elem.title)
        if len(lst) == 0:
            raise Exception
        return render(request, 'ex05/remove.html', {'movie_lst': lst, })
    except Exception:
        return HttpResponse("No data Available")
