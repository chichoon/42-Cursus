from django.urls import path
from . import views_world
from . import views_title


urlpatterns = [
    path('', views_title.titlescreen, name='titlescreen'),
    path('worldmap/', views_world.worldmap, name='worldmap'),
]
