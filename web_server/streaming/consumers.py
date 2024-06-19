import json
from channels.generic.websocket import AsyncWebsocketConsumer
from django_redis import get_redis_connection


class RoomConsumer(AsyncWebsocketConsumer):
    async def connect(self):
        self.room_id = self.scope["url_route"]["kwargs"]["room_id"]
        self.room_group_name = f"room_{self.room_id}"
        self.user_id = self.scope["url_route"]["kwargs"]["user_id"]
        room_key = f"room:{self.room_id}:users"

        redis_conn = get_redis_connection("default")
        redis_conn.sadd(room_key, self.user_id)

        await self.channel_layer.group_add(self.room_group_name, self.channel_name)

        await self.accept()

        await self.send_viewer_count()

    async def disconnect(self, code):
        await self.channel_layer.group_discard(self.room_group_name, self.channel_name)

        room_key = f"room:{self.room_id}:users"

        redis_conn = get_redis_connection("default")
        redis_conn.srem(room_key, self.user_id)

        await self.send_viewer_count()

    async def send_viewer_count(self):
        room_key = f"room:{self.room_id}:users"

        redis_conn = get_redis_connection("default")
        viewer_count = redis_conn.scard(room_key)

        await self.channel_layer.group_send(
            self.room_group_name,
            {
                "type": "update_viewer_count",
                "viewer_count": viewer_count,
            },
        )

    async def update_viewer_count(self, event):
        viewer_count = event["viewer_count"]

        await self.send(
            text_data=json.dumps(
                {
                    "viewer_count": viewer_count,
                }
            )
        )
