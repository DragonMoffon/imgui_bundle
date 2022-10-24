function(add_imgui_bundle_bindings)
    #########################################################################
    # Build python module that provides bindings to the library hello_imgui
    #########################################################################
    set(bound_library imgui_bundle)                 # The library for which we are building bindings
    set(python_native_module_name _imgui_bundle)    # This is the native python module name
    set(python_wrapper_module_name imgui_bundle)    # This is the python wrapper around the native module
    set(python_module_sources

        bindings/module.cpp

        bindings/litgen_glue_code.h
        bindings/imgui_docking_internal_types.h

        bindings/pybind_hello_imgui.cpp
        bindings/pybind_imgui.cpp
        bindings/pybind_imgui_internal.cpp
        bindings/pybind_implot.cpp
        bindings/pybind_imgui_bundle.cpp
        bindings/pybind_imgui_color_text_edit.cpp
        bindings/pybind_imgui_node_editor.cpp
        bindings/pybind_imgui_knobs.cpp
        bindings/pybind_im_file_dialog.cpp
        bindings/pybind_imspinner.cpp
        bindings/pybind_imgui_md.cpp
        )

    pybind11_add_module(${python_native_module_name} ${python_module_sources})
    target_compile_definitions(${python_native_module_name} PRIVATE VERSION_INFO=${PROJECT_VERSION})
    lg_setup_module(
        ${bound_library}
        ${python_native_module_name}
        ${python_wrapper_module_name}
    )

    target_link_libraries(${python_native_module_name} PUBLIC ${bound_library})
endfunction()