from django.shortcuts import render


# Create your views here.
def titlescreen(request):
    # add titlescreen.
    return render(request, 'moviemon/title.html', {})




def worldmap(request):
    size = 10
    table_row = [i for i in range(0, size)]
    table_col = [i for i in range(0, size)]
    return render(
        request,
        'moviemon/worldmap.html',
        {
            'loc_char': loc_char,
            'table_row': table_row,
            'table_col': table_col,
            })
