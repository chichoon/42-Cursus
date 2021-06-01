from django.shortcuts import render
from django.shortcuts import redirect


# Create your views here.

def worldmap(request):
    ctrl = request.GET.get('ctrl', None)

    return render(
        request,
        'moviemon/worldmap.html',
        {
            'loc_char': loc_char,
            'table_row': table_row,
            'table_col': table_col,
            })

