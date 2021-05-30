from django.shortcuts import render
from django.views.generic import View
from . import forms as MyForms
from pathlib import Path
import logging

logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)


# Create your views here.
class FormView(View):
    form_class = MyForms.MyForm
    initial = {'text_input': ''}
    template_name = 'ex02/forms.html'
    log_path = Path(__file__).resolve().parent.parent / 'logs/logfile'

    def get(self, request):
        form = self.form_class(initial=self.initial)
        log_lst = []
        try:
            with open(self.log_path, 'r') as mylog:
                lines = mylog.readlines()
                for line in lines:
                    log_lst.append(line)
        except Exception:
            self.log_path.parent.mkdir(exist_ok=True)
            self.log_path.touch()

        context = {'form': form, 'log_lst': log_lst}
        return render(request, self.template_name, context)

    def post(self, request):
        form = self.form_class(request.POST)
        if form.is_valid():
            new_text = form.cleaned_data['text_input']
            logger.debug(new_text)
        log_lst = []
        try:
            with open(self.log_path, 'r') as mylog:
                lines = mylog.readlines()
                for line in lines:
                    log_lst.append(line)
        except Exception:
            self.log_path.parent.mkdir(exist_ok=True)
            self.log_path.touch()
        context = {'form': form, 'log_lst': log_lst}
        return render(request, self.template_name, context)
