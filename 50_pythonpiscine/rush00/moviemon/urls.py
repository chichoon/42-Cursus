from django.urls import path
from . import views_world
from . import views_title
from . import views_battle
from . import views_moviedex
from . import views_option


urlpatterns = [
    path('', views_title.titlescreen, name='titlescreen'),
    path('worldmap/', views_world.worldmap, name='worldmap'),
    path('battle/<str:moviemon_id>/', views_battle.battle, name='battle'),
    path('moviedex/', views_moviedex.moviedex, name='moviedex'),
    path('moviedex/<str:movie_id>/', views_moviedex.details, name='details'),
    path('options/', views_option.options, name='options'),
    path('options/save_game/', views_option.save_game, name='save_game'),
    path('options/load_game/', views_option.load_game, name='load_game'),
]
