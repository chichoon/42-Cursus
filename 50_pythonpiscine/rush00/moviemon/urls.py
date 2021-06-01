from django.urls import path
from . import views


urlpatterns = [
    path('', views.titlescreen, name='titlescreen'),
    path('worldmap/', views.worldmap, name='worldmap'),
    url(r'^worldmap/(?P<dir_move>)/$', views.worldmap, name='worldmap'),
]
