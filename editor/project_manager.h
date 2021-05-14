/*************************************************************************/
/*  project_manager.h                                                    */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2021 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2021 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include "editor/editor_about.h"
#include "editor/plugins/asset_library_editor_plugin.h"
#include "scene/gui/dialogs.h"
#include "scene/gui/file_dialog.h"

class ProjectList;
class ProjectListFilter;
class CreateProjectDialog;

class ProjectManager : public Control {
	GDCLASS(ProjectManager, Control);

	Panel *gui_base;

	Button *erase_button;
	Button *remove_missing_button;
	Button *open_button;
	Button *rename_button;
	Button *run_button;
	
	EditorAbout *about;

	EditorAssetLibrary *asset_library;

	ProjectListFilter *project_filter;
	ProjectListFilter *project_order_filter;
	Label *loading_label;

	ConfirmationDialog *language_restart_dialog;
	ConfirmationDialog *erase_dialog;
	ConfirmationDialog *multi_open_dialog;
	ConfirmationDialog *multi_run_dialog;
	ConfirmationDialog *multi_scan_dialog;
	ConfirmationDialog *update_settings_dialog;
	ConfirmationDialog *open_templates_dialog;
	AcceptDialog *error_dialog;
	CreateProjectDialog *create_project_dialog;

	TabContainer *tabs;
	HBoxContainer *local_projects_hbox;
	ProjectList *project_list;

	LinkButton *version_button;
	OptionButton *language_button;

	void _explore_demo_projects();
	void _scan_projects();
	void _run_project_button_pressed();
	void _run_project_confirmed();
	void _open_selected_projects();
	void _ask_open_selected_projects();
	void _import_project();
	void _create_project();
	void _rename_project();
	void _ask_erase_project();
	void _erase_project();
	void _erase_missing_projects();
	void _update_project_buttons();
	void _language_selected(int p_id);
	void _restart();
	void _scan_begin(const String &p_base);

	// For MacOS.
	void _global_menu_action(const Variant &p_id, const Variant &p_meta);

	void _load_recent_projects();
	void _scan_dir(const String &path, List<String> *r_projects);

	void _install_project_from_zip(const String &p_zip_path, const String &p_title);

	void _dim_window();
	void _unhandled_input(const Ref<InputEvent> &p_ev);
	void _files_dropped(PoolStringArray p_files, int p_screen);
	void _scan_multiple_folders(PoolStringArray p_files);

	void _version_button_pressed();
	void _on_order_option_changed();
	void _on_filter_option_changed();

protected:
	void _notification(int p_what);
	static void _bind_methods();

public:
	ProjectManager();
	~ProjectManager();
};

#endif // PROJECT_MANAGER_H
