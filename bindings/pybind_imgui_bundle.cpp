#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>


namespace py = pybind11;

void py_init_module_imgui_bundle_inner(py::module& m);
void py_init_module_hello_imgui(py::module& m);
void py_init_module_imgui_main(py::module& m);
void py_init_module_imgui_internal(py::module& m);
void py_init_module_implot(py::module& m);
void py_init_module_imgui_color_text_edit(py::module& m);
void py_init_module_imgui_node_editor(py::module& m);
void py_init_module_imgui_knobs(py::module& m);
void py_init_module_im_file_dialog(py::module& m);
void py_init_module_imspinner(py::module& m);
void py_init_module_imgui_md(py::module& m);
void py_init_module_immvision(py::module& m);
void py_init_module_imgui_backends(py::module& m);


void py_init_module_imgui_bundle(py::module& m)
{
    py_init_module_imgui_bundle_inner(m);

    auto module_imgui =  m.def_submodule("imgui");
    py_init_module_imgui_main(module_imgui);

    auto module_imgui_internal =  module_imgui.def_submodule("internal");
    py_init_module_imgui_internal(module_imgui_internal);

    auto module_himgui =  m.def_submodule("hello_imgui");
    py_init_module_hello_imgui(module_himgui);

    auto module_implot =  m.def_submodule("implot");
    py_init_module_implot(module_implot);

    auto module_imgui_color_text_edit =  m.def_submodule("imgui_color_text_edit");
    py_init_module_imgui_color_text_edit(module_imgui_color_text_edit);

    auto module_imgui_node_editor =  m.def_submodule("imgui_node_editor");
    py_init_module_imgui_node_editor(module_imgui_node_editor);

    auto module_imgui_knobs =  m.def_submodule("imgui_knobs");
    py_init_module_imgui_knobs(module_imgui_knobs);

	auto module_im_file_dialog =  m.def_submodule("im_file_dialog");
	py_init_module_im_file_dialog(module_im_file_dialog);

    auto module_imspinner =  m.def_submodule("imspinner");
    py_init_module_imspinner(module_imspinner);

    auto module_imgui_md =  m.def_submodule("imgui_md");
    py_init_module_imgui_md(module_imgui_md);

    auto module_immvision =  m.def_submodule("immvision");
    py_init_module_immvision(module_immvision);

    auto module_imgui_backends =  m.def_submodule("imgui_backends");
    py_init_module_imgui_backends(module_imgui_backends);
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// <litgen_glue_code>  // Autogenerated code below! Do not edit!

// </litgen_glue_code> // Autogenerated code end
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


#include "hello_imgui/hello_imgui.h"
#include "imgui_bundle/imgui_bundle.h"
#include "imgui-node-editor/imgui_node_editor_internal.h"


namespace ax
{
    namespace NodeEditor
    {
        // using EditorContext = Detail::EditorContext;
        struct EditorContext: public Detail::EditorContext {};
    }
}


void py_init_module_imgui_bundle_inner(py::module& m)
{
    using namespace ImGuiBundle;
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // <litgen_pydef> // Autogenerated code below! Do not edit!
    ////////////////////    <generated_from:imgui_bundle.h>    ////////////////////
    auto pyClassAddOnsParams =
        py::class_<ImGuiBundle::AddOnsParams>
            (m, "AddOnsParams", "")
        .def(py::init<>()) // implicit default constructor
        .def_readwrite("with_implot", &ImGuiBundle::AddOnsParams::withImplot, "Set withImplot=True if you need to plot graphs")
        .def_readwrite("with_markdown", &ImGuiBundle::AddOnsParams::withMarkdown, " Set withMarkdown=True if you need to render Markdown\n (alternatively, you can set withMarkdownOptions)")
        .def_readwrite("with_node_editor", &ImGuiBundle::AddOnsParams::withNodeEditor, " Set withNodeEditor=True if you need to render a node editor\n (alternatively, you can set withNodeEditorConfig)")
        .def_readwrite("with_node_editor_config", &ImGuiBundle::AddOnsParams::withNodeEditorConfig, "You can tweak NodeEditorConfig (but this is optional)")
        .def_readwrite("with_markdown_options", &ImGuiBundle::AddOnsParams::withMarkdownOptions, "You can tweak MarkdownOptions (but this is optional)")
        ;


    m.def("run",
        py::overload_cast<HelloImGui::RunnerParams &, const ImGuiBundle::AddOnsParams &>(ImGuiBundle::Run), py::arg("runner_params"), py::arg("add_ons_params") = ImGuiBundle::AddOnsParams());

    m.def("run",
        py::overload_cast<const HelloImGui::SimpleRunnerParams &, const ImGuiBundle::AddOnsParams &>(ImGuiBundle::Run), py::arg("simple_params"), py::arg("add_ons_params") = ImGuiBundle::AddOnsParams());

    m.def("run",
        py::overload_cast<const VoidFunction &, const std::string &, bool, bool, const ScreenSize &, float, bool, bool, bool, const std::optional<NodeEditorConfig> &, const std::optional<ImGuiMd::MarkdownOptions> &>(ImGuiBundle::Run),
        py::arg("gui_function"), py::arg("window_title") = "", py::arg("window_size_auto") = false, py::arg("window_restore_previous_geometry") = false, py::arg("window_size") = ImGuiBundle::DefaultScreenSize, py::arg("fps_idle") = 10.f, py::arg("with_implot") = false, py::arg("with_markdown") = false, py::arg("with_node_editor") = false, py::arg("with_node_editor_config") = py::none(), py::arg("with_markdown_options") = py::none(),
        " Helper to run an app inside imgui_bundle, using HelloImGui:\n\n (HelloImGui::SimpleRunnerParams)\n     - `guiFunction`: the function that will render the ImGui widgets\n     - `windowTitle`: title of the window\n     - `windowSizeAuto`: if True, autosize the window from its inner widgets\n     - `windowRestorePreviousGeometry`: if True, restore window size and position from last run\n     - `windowSize`: size of the window\n     - `fpsIdle`: fps of the application when idle\n\n (ImGuiBundle::AddOnsParams)\n     - `with_implot`: if True, then a context for implot will be created/destroyed automatically\n     - `with_markdown` / `with_markdown_options`: if specified, then  the markdown context will be initialized\n       (i.e. required fonts will be loaded)\n     - `with_node_editor` / `with_node_editor_config`: if specified, then a context for imgui_node_editor\n       will be created automatically.");

    m.def("clock_seconds",
        ImGuiBundle::ClockSeconds);

    m.def("current_node_editor_context",
        ImGuiBundle::CurrentNodeEditorContext);

    m.def("visible_font_size",
        ImGuiBundle::VisibleFontSize, " Visible font size, i.e ImGui::GetFontSize() / ImGui::GetIO().FontGlobalScale\n In order to scale your widgets properly on all platforms, use multiples of this size.\n (on MacOS with retina FontGlobalScale can be equal to 2)");

    m.def("em_size",
        ImGuiBundle::EmSize, " EmSize returns the visible font size, i.e ImGui::GetFontSize() / ImGui::GetIO().FontGlobalScale\n In order to scale your widgets properly on all platforms, use multiples of this size.\n (on MacOS with retina FontGlobalScale can be equal to 2)\n (EmSize is an alias for VisibleFontSize)");
    ////////////////////    </generated_from:imgui_bundle.h>    ////////////////////

    // </litgen_pydef> // Autogenerated code end
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!  AUTOGENERATED CODE END !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
