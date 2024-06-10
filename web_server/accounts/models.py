from django.contrib.auth.models import AbstractUser
from django.db import models
import uuid


class User(AbstractUser):
    id = models.CharField(
        primary_key=True, default=uuid.uuid4, editable=False, max_length=32
    )

    class Meta:
        db_table = "user"
