from django.db import models

# Create your models here.
class Post(models.Model):
    received_txt = models.CharField()
    received_time = models.DateTimeField(auto_now_add=True)
