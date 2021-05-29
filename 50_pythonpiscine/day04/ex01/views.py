from django.shortcuts import render
from django.template import loader


# Create your views here.
def django(request):
    loader.get_template('base.html')
    return render(request, 'django.html')


def display(request):
    loader.get_template('base.html')
    return render(request, 'display.html')


def templates(request):
    loader.get_template('base.html')
    return render(request, 'templates.html')
