from django import forms
from .models import ImageModel


class UserForm(forms.ModelForm):
    class Meta:
        model = ImageModel
        fields = ['title', 'content']
