from django.urls import path
from . import views_world
from . import views_title
from . import views_battle
from . import views_moviedex
from . import views_details


urlpatterns = [
    path('', views_title.titlescreen, name='titlescreen'),
    path('worldmap/', views_world.worldmap, name='worldmap'),
    path('battle/<str:moviemon_id>', views_battle.battle, name='battle'),
    path('moviedex/', views_moviedex.moviedex, name='moviedex'),
    path('moviedex/<str:movie_id>', views_details.details, name='details'),
]
