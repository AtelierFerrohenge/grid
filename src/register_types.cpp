#include "register_types.h"

#include <gdextension_interface.h>
// Figure out why the below line is in the template but not in the tutorial
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

// Review if I need chunk.h if grid.h already has it - style usage
#include "chunk.h"
#include "grid.h"

using namespace godot;

void initialize_gdextension_types(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
    // Review why GDREGISTER_ABSTRACT_CLASS doesn't seem to work
    GDREGISTER_VIRTUAL_CLASS(Chunk);
    GDREGISTER_VIRTUAL_CLASS(Grid);
}

void uninitialize_gdextension_types(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C"
{
    // Probably rename example_library_init later
    // Figure out why GDExtensionClassLibraryPtr is const in the tutorial but not the template
    GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        // Figure out why the template doesn't need godot:: in front of GDExtensionBinding
        GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
        init_obj.register_initializer(initialize_gdextension_types);
        init_obj.register_terminator(uninitialize_gdextension_types);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}