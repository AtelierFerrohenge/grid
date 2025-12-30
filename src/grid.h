#pragma once

// Assume 2D for now, may want to extend for 3D in the future
#include "godot_cpp/classes/node2d.hpp"

#include <godot_cpp/core/gdvirtual.gen.inc>

// Review inclusion of local .h files and if this is the cleanest way
#include "chunk.h"

using namespace godot;

class Grid : public Node2D {
    GDCLASS(Grid, Node2D)

public:
    Grid() = default;
    ~Grid() override = default;

    virtual Vector2 map_to_local(const Vector2i &p_pos) const;
    virtual Vector2i local_to_map(const Vector2 &p_pos) const;

    // Review if Chunk reference is how it's done
    // Couldn't const p_chunk, review when const is needed and when not
    // Apparently it also needs to be a pointer not a reference
    void add_chunk(Chunk *p_chunk, const Vector2i &p_pos);
    // Had to change Chunk & to Chunk * - review if this is standard
    Chunk *get_chunk(const Vector2i &p_pos) const;
    void remove_chunk(const Vector2i &p_pos);

    // All of the below should likely not be public

    virtual Vector2i get_chunk_basis_x() const;
    virtual Vector2i get_chunk_basis_y() const;

    String position_to_name(const Vector2i &p_pos) const;

protected:
    static void _bind_methods();

    // Review in const Vector2i & or just Vector2 should be used here (same for the line below)
    GDVIRTUAL1RC_REQUIRED(Vector2, _map_to_local, const Vector2i &)
    GDVIRTUAL1RC_REQUIRED(Vector2i, _local_to_map, const Vector2 &)

    GDVIRTUAL0RC_REQUIRED(Vector2i, _get_chunk_basis_x)
    GDVIRTUAL0RC_REQUIRED(Vector2i, _get_chunk_basis_y)
};
