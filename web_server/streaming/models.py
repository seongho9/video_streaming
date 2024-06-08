from django.db import models
from django.shortcuts import reverse


class Room(models.Model):
    room_id = models.CharField(max_length=128)
    title = models.CharField(max_length=50)
    description = models.CharField(max_length=50)
    created_at = models.DateTimeField(auto_now_add=True)
    streamer_id = models.CharField(max_length=20)
    tag = models.CharField(max_length=8)

    class Meta:
        ordering = ["-room_id"]

    def get_absolute_url(self):
        return reverse("streaming:room_detail", kwargs={"pk": self.pk})


class Video(models.Model):
    video_id = models.IntegerField()
    video_url = models.CharField(max_length=200)
    uploader_id = models.CharField(max_length=20)
    created_at = models.DateTimeField(auto_now_add=True)
    views = models.IntegerField()
    description = models.CharField(max_length=50)
