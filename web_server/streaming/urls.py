from django.urls import path, include
from rest_framework.routers import DefaultRouter
from . import views

app_name = "streaming"

router = DefaultRouter()
router.register("room", views.RoomViewSet)
router.register("video", views.VideoViewSet)

urlpatterns = [
    path("", include(router.urls)),
]
