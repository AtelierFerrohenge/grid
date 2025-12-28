#pragma once

// Assume 2D for now, may want to extend for 3D in the future
#include "godot_cpp/classes/node2d.hpp"

#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

class Chunk : public Node2D {
    GDCLASS(Chunk, Node2D)

public:
    Chunk() = default;
    ~Chunk() override = default;

    virtual Vector2 map_to_local(const Vector2i &p_pos) const;
    virtual Vector2i local_to_map(const Vector2 &p_pos) const;
    virtual int get_move_cost(const Vector2i &p_pos) const;

protected:
    static void _bind_methods();

    // Review in const Vector2i & or just Vector2 should be used here (same for the line below)
    GDVIRTUAL1RC_REQUIRED(Vector2, _map_to_local, const Vector2i &)
    GDVIRTUAL1RC_REQUIRED(Vector2i, _local_to_map, const Vector2 &)
    GDVIRTUAL1RC_REQUIRED(int, _get_move_cost, const Vector2i &)
};
