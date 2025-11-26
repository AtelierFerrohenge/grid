@abstract
class_name Grid
# Assume 2D for now, may want to extend for 3D in the future
extends Node2D


@abstract func map_to_local(map_position: Vector2i) -> Vector2


func add_chunk(chunk: Chunk, chunk_position: Vector2i) -> void:
	var chunk_name: String = _position_to_name(chunk_position)
	assert(not has_node(NodePath(chunk_name)), "A chunk already exists at this position.")
	chunk.name = StringName(chunk_name)
	add_child(chunk)


func get_chunk(chunk_position: Vector2i) -> Chunk:
	var chunk_name: String = _position_to_name(chunk_position)
	assert(has_node(NodePath(chunk_name)), "A chunk doesn't exist at this position.")
	return get_node(NodePath(chunk_name))


func remove_chunk(chunk_position: Vector2i) -> void:
	get_chunk(chunk_position).queue_free()


@abstract func _get_chunk_basis_x() -> Vector2i


@abstract func _get_chunk_basis_y() -> Vector2i


func _position_to_name(chunk_position: Vector2i) -> String:
	return "(%d, %d)" % [chunk_position.x, chunk_position.y]
