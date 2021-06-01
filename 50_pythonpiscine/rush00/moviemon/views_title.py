from django.shortcuts import render
from django.shortcuts import redirect

# Create your views here.
def titlescreen(request):
    context = {
        'btn_north': "location.href='';",
        'btn_west': "location.href='';",
        'btn_east': "location.href='';",
        'btn_south': "location.href='';",
        'btn_a': "location.href='worldmap?from=new';",
        'btn_b': "location.href='/options/load_game?from=title';",
        'btn_start': "location.href='';",
        'btn_select': "location.href='';",
    }
    return render(request, 'moviemon/title.html', context)
