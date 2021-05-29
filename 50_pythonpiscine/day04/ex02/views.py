from django.shortcuts import render

# Create your views here.
def forms(request):
    return render(request, 'ex02/forms.html')
