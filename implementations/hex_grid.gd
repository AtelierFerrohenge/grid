class_name HexGrid
extends Grid

@export var _chunk_radius: int


func _get_chunk_basis_x() -> Vector2i:
	return Vector2i(_get_chunk_diameter(), -_chunk_radius)


func _get_chunk_basis_y() -> Vector2i:
	return Vector2i(_chunk_radius, _chunk_radius + 1)


func _get_chunk_diameter() -> int:
	return 2 * _chunk_radius + 1
