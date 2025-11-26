@abstract
class_name Chunk
extends Node2D


@abstract func map_to_local(map_position: Vector2i) -> Vector2


@abstract func get_move_cost(tile: Vector2i) -> int
