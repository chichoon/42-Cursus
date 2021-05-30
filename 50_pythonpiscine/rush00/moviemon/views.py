from django.shortcuts import render


# Create your views here.
def titlescreen(request):
    # add titlescreen.
    return render(request, 'title/title.html', {})

