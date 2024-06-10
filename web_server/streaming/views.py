from rest_framework.permissions import IsAuthenticated
from rest_framework.response import Response
from rest_framework.viewsets import ModelViewSet
from rest_framework import status
from rest_framework.exceptions import NotFound
from rest_framework_simplejwt.authentication import JWTAuthentication
from .models import Room, Video
from .serializers import RoomSerializer, VideoSerializer


class RoomViewSet(ModelViewSet):
    queryset = Room.objects.all()
    serializer_class = RoomSerializer
    permission_classes = [IsAuthenticated]
    authentication_classes = [JWTAuthentication]

    def dispatch(self, request, *args, **kwargs):
        res = super().dispatch(request, *args, **kwargs)
        return res

    def retrieve(self, request, *args, **kwargs):
        pk = kwargs.get("pk")
        try:
            room = Room.objects.get(room_id=pk)
        except Room.DoesNotExist:
            raise NotFound(detail="Room not found", code=status.HTTP_404_NOT_FOUND)

        serializer = self.get_serializer(room)
        return Response(serializer.data)


class VideoViewSet(ModelViewSet):
    queryset = Video.objects.all()
    serializer_class = VideoSerializer
    permission_classes = [IsAuthenticated]
    authentication_classes = [JWTAuthentication]

    def dispatch(self, request, *args, **kwargs):
        res = super().dispatch(request, *args, **kwargs)
        return res

    def retrieve(self, request, *args, **kwargs):
        pk = kwargs.get("pk")
        try:
            video = Video.objects.get(video_id=pk)
        except Video.DoesNotExist:
            raise NotFound(detail="Video not found", code=status.HTTP_404_NOT_FOUND)

        serializer = self.get_serializer(video)
        return Response(serializer.data)
