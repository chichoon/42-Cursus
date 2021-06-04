from django.urls import path
from . import views
app_name = 'ex'


urlpatterns = [
    path('', views.ex00, name='ex00'),
    path('register/', views.regist, name='register'),
    path('login/', views.log_in, name='login'),
    path('logout/', views.log_out, name='logout'),
]
