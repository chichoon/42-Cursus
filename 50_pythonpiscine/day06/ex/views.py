from django.shortcuts import render, redirect
from django.conf import settings
from . import forms
from . import models
from django.contrib import messages
from django.contrib.auth import login, authenticate, logout
from django.contrib.auth.forms import AuthenticationForm
from django.views.decorators.csrf import csrf_exempt
import random


# Create your views here.
@csrf_exempt
def ex00(request):
    lst = settings.USERNAME
    if request.session is None or request.session.get('username') is None :
        request.session['username'] = lst[random.randrange(0, 11)]
        request.session.set_expiry(42)
    if request.session.get('username2') is not None:
        message = 'Hello, ' + request.session['username2']
        if_login = True
    else:
        if_login = False
        message = 'You are not logged in yet.'

    return render(request, 'ex/index.html', {
        'login_message': f"HELLO, {request.session['username']}! {request.session['username']} will be eliminated in 42 seconds.",
        'message': message,
        'if_login': if_login
        })


@csrf_exempt
def regist(request):
    message = ''
    login_id = ''
    if request.session.get('username2') is not None:
        messages.info(request, "Already logged in.")
        return redirect("ex:ex00")
    if request.session.get('username') is not None:
        login_id = request.session.get('username')
        request.session.set_expiry(42)
    if request.method == "POST":
        form = forms.RegistrationForm(request.POST)
        if form.is_valid():
            user = form.save()
            login(request, user)
            message = "Registration done!"
            messages.success(request, message)
            return redirect("ex:log_in")
        message = "Registration unsuccessful."
        messages.error(request, message)
    form = forms.RegistrationForm
    return render(request, "ex/regist.html", {
        'login_message': f"HELLO, {login_id}! {login_id} will be eliminated in 42 seconds.",
        "register_form": form,
        "message": message,
        })


@csrf_exempt
def log_in(request):
    message = ''
    username = ''
    login_id = ''
    if request.session.get('username2') is not None:
        messages.info(request, "Already logged in.")
        return redirect("ex:ex00")
    if request.method == "POST":
        form = AuthenticationForm(request, data=request.POST)
        if form.is_valid():
            username = form.cleaned_data.get('username')
            password = form.cleaned_data.get('password')
            user = authenticate(username=username, password=password)
            if user is not None:
                login(request, user)
                request.session['username'] = username
                request.session['username2'] = username
                request.session.set_expiry(0)
                messages.info(request, f"You are now logged in as {username}.")
                return redirect("ex:ex00")
            else:
                message = "Invalid username or password."
                messages.error(request, message)
        else:
            message = "Invalid username or password."
            messages.error(request, message)
    elif request.session.get('username') is not None:
        login_id = request.session.get('username')
        request.session.set_expiry(42)
    form = AuthenticationForm()
    return render(request, "ex/login.html", {
        'login_message': f"HELLO, {login_id}! {login_id} will be eliminated in 42 seconds.",
        'login_form': form,
        'message': message, })


@csrf_exempt
def log_out(request):
    logout(request)
    request.session['username2'] = None
    messages.info(request, "logged out.")
    return redirect("ex:ex00")
