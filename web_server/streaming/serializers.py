from rest_framework.serializers import ModelSerializer
from .models import Room, Video


class RoomSerializer(ModelSerializer):
    class Meta:
        model = Room
        fields = "__all__"


class VideoSerializer(ModelSerializer):
    class Meta:
        model = Video
        fields = "__all__"
