from django.db import models


# Create your models here.
class ImageModel(models.Model):
    title = models.CharField(max_length=128)
    content = models.ImageField(upload_to='image')
