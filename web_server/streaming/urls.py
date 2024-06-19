from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import RoomViewSet, VideoViewSet, test

app_name = "streaming"

router = DefaultRouter()
router.register("room", RoomViewSet)
router.register("video", VideoViewSet)

urlpatterns = [
    path("", include(router.urls)),
    path("test/<int:room_id>/<str:user_id>/", test, name="test"),
]
