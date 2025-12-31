class_name MonoGrid
extends Grid


func _map_to_local(map_position: Vector2i) -> Vector2:
	return get_chunk(Vector2i.ZERO).map_to_local(map_position)


func _local_to_map(local_position: Vector2) -> Vector2i:
	return get_chunk(Vector2i.ZERO).local_to_map(local_position)


func add_chunk(chunk: Chunk, chunk_position: Vector2i) -> void:
	assert(chunk_position == Vector2i.ZERO, "Chunking should not be used in MonoGrid.")
	super(chunk, chunk_position)


func set_tile_map(map: Chunk) -> void:
	add_chunk(map, Vector2i.ZERO)


func get_tile_map() -> Chunk:
	return get_chunk(Vector2i.ZERO)


func unset_tile_map() -> void:
	remove_chunk(Vector2i.ZERO)


func _get_chunk_basis_x() -> Vector2i:
	assert(false, "Chunking should not be used in MonoGrid.")
	return Vector2i.ZERO


func _get_chunk_basis_y() -> Vector2i:
	assert(false, "Chunking should not be used in MonoGrid.")
	return Vector2i.ZERO
