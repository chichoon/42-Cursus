from django.shortcuts import render
from django.shortcuts import redirect

# Create your views here.
def titlescreen(request):
    #ctrl = request.GET.get('ctrl', None)
    #if


    return render(request, 'moviemon/title.html', {})

'''
class TitleView(request):
    template_dir = 'moviemon/title.html'
    context = {}

    def get(request):
'''
