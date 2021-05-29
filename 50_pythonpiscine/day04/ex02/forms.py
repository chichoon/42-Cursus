from django import forms


class Myform(forms.Form):
    received_txt = forms.CharField(required=True)
