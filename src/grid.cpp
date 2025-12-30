#include "grid.h"

Vector2 Grid::map_to_local(const Vector2i &p_pos) const {
    // Figure out how to set the default for this
    Vector2 local;
    GDVIRTUAL_CALL(_map_to_local, p_pos, local);
    return local;
}

Vector2i Grid::local_to_map(const Vector2 &p_pos) const {
    // Figure out how to set the default for this
    Vector2i map;
    GDVIRTUAL_CALL(_local_to_map, p_pos, map);
    return map;
}

void Grid::add_chunk(Chunk *p_chunk, const Vector2i &p_pos) {
    String chunk_name = position_to_name(p_pos);
    // Check to make sure there's not already a chunk here - need to figure out C++ "asserts"
    // Should be a string name not a string - look into how to do this
    p_chunk->set_name(chunk_name);
    // Review if parameter should actually be a pointer not a reference
    add_child(p_chunk);
}

Chunk *Grid::get_chunk(const Vector2i &p_pos) const {
    String chunk_name = position_to_name(p_pos);
    // Assert chunk exists
    return get_node<Chunk>(chunk_name);
}

void Grid::remove_chunk(const Vector2i &p_pos) {
    get_chunk(p_pos)->queue_free();
}

Vector2i Grid::get_chunk_basis_x() const {
    // Figure out how to set the default for this
    Vector2i chunk_basis_x;
    GDVIRTUAL_CALL(_get_chunk_basis_x, chunk_basis_x);
    return chunk_basis_x;
}

Vector2i Grid::get_chunk_basis_y() const {
    // Figure out how to set the default for this
    Vector2i chunk_basis_y;
    GDVIRTUAL_CALL(_get_chunk_basis_y, chunk_basis_y);
    return chunk_basis_y;
}

String Grid::position_to_name(const Vector2i &p_pos) const {
    return String("({0}, {1})").format(Array({p_pos.x, p_pos.y}));
}

void Grid::_bind_methods() {
    ClassDB::bind_method(D_METHOD("map_to_local", "map_position"), &Grid::map_to_local);
    ClassDB::bind_method(D_METHOD("local_to_map", "local_position"), &Grid::local_to_map);
    ClassDB::bind_method(D_METHOD("add_chunk", "chunk", "map_position"), &Grid::add_chunk);
    ClassDB::bind_method(D_METHOD("get_chunk", "map_position"), &Grid::get_chunk);
    ClassDB::bind_method(D_METHOD("remove_chunk", "map_position"), &Grid::remove_chunk);

    // No need to bind get_chunk_basis_x, get_chunk_basis_y, position_to_name

    GDVIRTUAL_BIND(_map_to_local, "map_position");
    GDVIRTUAL_BIND(_local_to_map, "local_position");

    GDVIRTUAL_BIND(_get_chunk_basis_x);
    GDVIRTUAL_BIND(_get_chunk_basis_y);
}