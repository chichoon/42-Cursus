from django import forms


class UserForm(forms.Form):
    title = forms.CharField(max_length=128, required=True)
    content = forms.ImageField(required=True)
