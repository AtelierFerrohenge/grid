#include "chunk.h"

Vector2 Chunk::map_to_local(const Vector2i &p_pos) const {
    // Figure out how to set the default for this
    Vector2 local;
    GDVIRTUAL_CALL(_map_to_local, p_pos, local);
    return local;
}

Vector2i Chunk::local_to_map(const Vector2 &p_pos) const {
    // Figure out how to set the default for this
    Vector2i map;
    GDVIRTUAL_CALL(_local_to_map, p_pos, map);
    return map;
}

int Chunk::get_move_cost(const Vector2i &p_pos) const {
    int move_cost;
    GDVIRTUAL_CALL(_get_move_cost, p_pos, move_cost);
    return move_cost;
}

void Chunk::_bind_methods() {
    ClassDB::bind_method(D_METHOD("map_to_local", "map_position"), &Chunk::map_to_local);
    ClassDB::bind_method(D_METHOD("local_to_map", "local_position"), &Chunk::local_to_map);
    ClassDB::bind_method(D_METHOD("get_move_cost", "map_position"), &Chunk::get_move_cost);

    GDVIRTUAL_BIND(_map_to_local, "map_position");
    GDVIRTUAL_BIND(_local_to_map, "local_position");
    GDVIRTUAL_BIND(_get_move_cost, "map_position");
}