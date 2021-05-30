from django.shortcuts import render
from django import forms


class MyForm(forms.Form):
    text_input = forms.CharField(required=True)

