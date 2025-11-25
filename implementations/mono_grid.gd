class_name MonoGrid
extends Grid


func add_chunk(chunk: Chunk, chunk_position: Vector2i) -> void:
	assert(chunk_position == Vector2i.ZERO, "Chunking should not be used in MonoGrid.")
	super(chunk, chunk_position)


func remove_chunk(chunk_position: Vector2i) -> void:
	assert(chunk_position == Vector2i.ZERO, "Chunking should not be used in MonoGrid.")
	super(chunk_position)


func set_tile_map(map: Chunk) -> void:
	add_chunk(map, Vector2i.ZERO)


func unset_tile_map() -> void:
	remove_chunk(Vector2i.ZERO)


func _get_chunk_basis_x() -> Vector2i:
	assert(false, "Chunking should not be used in MonoGrid.")
	return Vector2i.ZERO


func _get_chunk_basis_y() -> Vector2i:
	assert(false, "Chunking should not be used in MonoGrid.")
	return Vector2i.ZERO
