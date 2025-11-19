class_name Grid
extends Node2D

# Make these read-only or calculated values
var chunk_basis_x: Vector2i
var chunk_basis_y: Vector2i


func add_chunk(chunk: TileMapLayer, position: Vector2i) -> void:
	chunk.name = StringName(_position_to_name(position))
	add_child(chunk)


func delete_chunk(position: Vector2i) -> void:
	get_node(NodePath(_position_to_name(position))).queue_free()


func _position_to_name(position: Vector2i) -> String:
	return "(%d, %d)" % [position.x, position.y]


func _ready():
	add_chunk(TileMapLayer.new(), Vector2i.ZERO)
	delete_chunk(Vector2i.ZERO)
