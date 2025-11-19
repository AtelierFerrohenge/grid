@abstract
class_name Grid
extends Node2D


func add_chunk(chunk: TileMapLayer, chunk_position: Vector2i) -> void:
	var chunk_name: String = _position_to_name(chunk_position)
	assert(not has_node(NodePath(chunk_name)), "A chunk already exists at this position.")
	chunk.name = StringName(chunk_name)
	add_child(chunk)


func remove_chunk(chunk_position: Vector2i) -> void:
	var chunk_name: String = _position_to_name(chunk_position)
	assert(has_node(NodePath(chunk_name)), "A chunk doesn't exist at this position.")
	get_node(NodePath(chunk_name)).queue_free()


@abstract func _get_chunk_basis_x() -> Vector2i


@abstract func _get_chunk_basis_y() -> Vector2i


func _position_to_name(chunk_position: Vector2i) -> String:
	return "(%d, %d)" % [chunk_position.x, chunk_position.y]
