from django.shortcuts import render
from django.views.generic import FormView
from .forms import UserForm
from .models import ImageModel


# Create your views here.
class Init(FormView):
    template_name = 'ex00/main.html'
    form_class = UserForm

    def get(self, request):
        form = self.form_class(initial=self.initial)
        images = ImageModel.objects.all()
        return render(request, self.template_name, {'images': images, 'form': form})

    def post(self, request):
        form = self.form_class(request.POST, request.FILES)
        images = ImageModel.objects.all()
        if form.is_valid():
            title = form.cleaned_data['title']
            content = form.cleaned_data['content']
            ImageModel.objects.create(
                title=title,
                content=content
            )
        return render(request, self.template_name, {'images': images, 'form': form})
