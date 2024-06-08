from django.contrib.auth.mixins import LoginRequiredMixin
from rest_framework.viewsets import ModelViewSet
from rest_framework.response import Response
from rest_framework import status
from rest_framework.exceptions import NotFound
from .models import Room
from .serializers import RoomSerializer


class RoomViewSet(ModelViewSet):
    queryset = Room.objects.all()
    serializer_class = RoomSerializer

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
