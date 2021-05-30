from django.shortcuts import render


# Create your views here.
def ex03(request):
    lst = []
    for i in range(0, 50):
        color_code = str(i * 2)
        lst.append(color_code)
    return render(request, 'ex03/ex03.html', {'lst': lst})
