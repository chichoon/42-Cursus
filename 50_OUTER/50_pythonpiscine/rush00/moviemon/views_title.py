from django.shortcuts import render


# Create your views here.
def titlescreen(request):
    context = {
        'btn_a': "location.href='/worldmap?from=new';",
        'btn_b': "location.href='/options/load_game/';",
    }
    return render(request, 'moviemon/title.html', context)
