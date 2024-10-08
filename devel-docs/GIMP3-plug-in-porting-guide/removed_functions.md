## Removed Functions

These functions have been removed from GIMP 3. Most of them were deprecated
since GIMP 2.10.x or older versions. As we bump the major version, it is time
to start with a clean slate.

Below is a correspondence table with replacement function. The replacement is
not necessarily a direct search-and-replace equivalent. Some may have different
parameters, and in some case, it may require to think a bit about how things
work to reproduce the same functionality. Nevertheless everything which was
possible in the previous API is obviously still possible.

| Removed function                                | Replacement                                       |
| ----------------------------------------------- | ------------------------------------------------- |
| `gimp_attach_new_parasite()`                    | `gimp_attach_parasite()`                          |
| `gimp_brightness_contrast()`                    | `gimp_drawable_brightness_contrast()`             |
| `gimp_brushes_get_brush()`                      | `gimp_context_get_brush()`                        |
| `gimp_brushes_get_brush_data()`                 | `gimp_brush_get_pixels()`                         |
| `gimp_brushes_get_spacing()`                    | `gimp_brush_get_spacing()`                        |
| `gimp_brushes_set_spacing()`                    | `gimp_brush_set_spacing()`                        |
| `gimp_by_color_select()`                        | `gimp_image_select_color()`                       |
| `gimp_by_color_select_full()`                   | `gimp_image_select_color()`                       |
| `gimp_channel_menu_new()`                       | `gimp_channel_combo_box_new()`                    |
| `gimp_checks_get_shades()`                      | `gimp_checks_get_colors()`                        |
| `gimp_color_balance()`                          | `gimp_drawable_color_color_balance()`             |
| `gimp_color_display_convert()`                  | `gimp_color_display_convert_buffer()`             |
| `gimp_color_display_convert_surface()`          | `gimp_color_display_convert_buffer()`             |
| `gimp_color_display_stack_convert()`            | `gimp_color_display_stack_convert_buffer()`       |
| `gimp_color_display_stack_convert_surface()`    | `gimp_color_display_stack_convert_buffer()`       |
| `gimp_color_profile_combo_box_add()`            | `gimp_color_profile_combo_box_add_file()`         |
| `gimp_color_profile_combo_box_get_active()`     | `gimp_color_profile_combo_box_get_active_file()`  |
| `gimp_color_profile_combo_box_set_active()`     | `gimp_color_profile_combo_box_set_active_file()`  |
| `gimp_color_profile_store_add()`                | `gimp_color_profile_store_add_file()`             |
| `gimp_colorize()`                               | `gimp_drawable_colorize_hsl()`                    |
| `gimp_context_get_transform_recursion()`        | *N/A*                                             |
| `gimp_context_set_transform_recursion()`        | *N/A*                                             |
| `gimp_curves_explicit()`                        | `gimp_drawable_curves_explicit()`                 |
| `gimp_curves_spline()`                          | `gimp_drawable_curves_spline()`                   |
| `gimp_desaturate()`                             | `gimp_drawable_desaturate()`                      |
| `gimp_desaturate_full()`                        | `gimp_drawable_desaturate()`                      |
| `gimp_drawable_attach_new_parasite()`           | `gimp_item_attach_parasite()`                     |
| `gimp_drawable_bpp()`                           | `gimp_drawable_get_bpp()`                         |
| `gimp_drawable_delete()`                        | `gimp_item_delete()`                              |
| `gimp_drawable_get_image()`                     | `gimp_item_get_image()`                           |
| `gimp_drawable_get_linked()`                    | *N/A*                                             |
| `gimp_drawable_get_name()`                      | `gimp_item_get_name()`                            |
| `gimp_drawable_get_tattoo()`                    | `gimp_item_get_tattoo()`                          |
| `gimp_drawable_get_visible()`                   | `gimp_item_get_visible()`                         |
| `gimp_drawable_height()`                        | `gimp_drawable_get_height()`                      |
| `gimp_drawable_is_channel()`                    | `gimp_item_is_channel()`                          |
| `gimp_drawable_is_layer()`                      | `gimp_item_is_layer()`                            |
| `gimp_drawable_is_layer_mask()`                 | `gimp_item_is_layer_mask()`                       |
| `gimp_drawable_is_text_layer()`                 | `gimp_item_is_text_layer()`                       |
| `gimp_drawable_is_valid()`                      | `gimp_item_is_valid()`                            |
| `gimp_drawable_menu_new()`                      | `gimp_drawable_combo_box_new()`                   |
| `gimp_drawable_offsets()`                       | `gimp_drawable_get_offsets()`                     |
| `gimp_drawable_parasite_attach()`               | `gimp_item_attach_parasite()`                     |
| `gimp_drawable_parasite_detach()`               | `gimp_item_detach_parasite()`                     |
| `gimp_drawable_parasite_find()`                 | `gimp_item_get_parasite()`                        |
| `gimp_drawable_parasite_list()`                 | `gimp_item_get_parasite_list()`                   |
| `gimp_drawable_preview_new()`                   | `gimp_drawable_preview_new_from_drawable()`       |
| `gimp_drawable_preview_new_from_drawable_id()`  | `gimp_drawable_preview_new_from_drawable()`       |
| `gimp_drawable_set_image()`                     | *N/A*                                             |
| `gimp_drawable_set_linked()`                    | *N/A*                                             |
| `gimp_drawable_set_name()`                      | `gimp_item_set_name()`                            |
| `gimp_drawable_set_tattoo()`                    | `gimp_item_set_tattoo()`                          |
| `gimp_drawable_set_visible()`                   | `gimp_item_set_visible()`                         |
| `gimp_drawable_transform_2d()`                  | `gimp_item_transform_2d()`                        |
| `gimp_drawable_transform_2d_default()`          | `gimp_item_transform_2d()`                        |
| `gimp_drawable_transform_flip()`                | `gimp_item_transform_flip()`                      |
| `gimp_drawable_transform_flip_default()`        | `gimp_item_transform_flip()`                      |
| `gimp_drawable_transform_flip_simple()`         | `gimp_item_transform_flip_simple()`               |
| `gimp_drawable_transform_matrix()`              | `gimp_item_transform_matrix()`                    |
| `gimp_drawable_transform_matrix_default()`      | `gimp_item_transform_matrix()`                    |
| `gimp_drawable_transform_perspective()`         | `gimp_item_transform_perspective()`               |
| `gimp_drawable_transform_perspective_default()` | `gimp_item_transform_perspective()`               |
| `gimp_drawable_transform_rotate()`              | `gimp_item_transform_rotate()`                    |
| `gimp_drawable_transform_rotate_default()`      | `gimp_item_transform_rotate()`                    |
| `gimp_drawable_transform_rotate_simple()`       | `gimp_item_transform_rotate_simple()`             |
| `gimp_drawable_transform_scale()`               | `gimp_item_transform_scale()`                     |
| `gimp_drawable_transform_scale_default()`       | `gimp_item_transform_scale()`                     |
| `gimp_drawable_transform_shear()`               | `gimp_item_transform_shear()`                     |
| `gimp_drawable_transform_shear_default()`       | `gimp_item_transform_shear()`                     |
| `gimp_drawable_width()`                         | `gimp_drawable_get_width()`                       |
| `gimp_edit_blend()`                             | `gimp_drawable_edit_gradient_fill()`              |
| `gimp_edit_bucket_fill()`                       | `gimp_drawable_edit_bucket_fill()`                |
| `gimp_edit_bucket_fill_full()`                  | `gimp_drawable_edit_bucket_fill()`                |
| `gimp_edit_clear()`                             | `gimp_drawable_edit_clear()`                      |
| `gimp_edit_fill()`                              | `gimp_drawable_edit_fill()`                       |
| `gimp_edit_paste_as_new()`                      | `gimp_edit_paste_as_new_image()`                  |
| `gimp_edit_named_paste_as_new()`                | `gimp_edit_named_paste_as_new_image()`            |
| `gimp_edit_stroke()`                            | `gimp_drawable_edit_stroke_selection()`           |
| `gimp_edit_stroke_vectors()`                    | `gimp_drawable_edit_stroke_item()`                |
| `gimp_ellipse_select()`                         | `gimp_image_select_ellipse()`                     |
| `gimp_enum_combo_box_set_stock_prefix()`        | `gimp_enum_combo_box_set_icon_prefix()`           |
| `gimp_enum_stock_box_new()`                     | `gimp_enum_icon_box_new()`                        |
| `gimp_enum_stock_box_new_with_range()`          | `gimp_enum_icon_box_new_with_range()`             |
| `gimp_enum_stock_box_set_child_padding()`       | `gimp_enum_icon_box_set_child_padding()`          |
| `gimp_enum_store_set_stock_prefix()`            | `gimp_enum_store_set_icon_prefix()`               |
| `gimp_equalize()`                               | `gimp_drawable_equalize()`                        |
| `gimp_flip()`                                   | `gimp_item_transform_flip_simple()`               |
| `gimp_floating_sel_relax()`                     | *N/A*                                             |
| `gimp_floating_sel_rigor()`                     | *N/A*                                             |
| `gimp_free_select()`                            | `gimp_image_select_polygon()`                     |
| `gimp_fuzzy_select()`                           | `gimp_image_select_contiguous_color()`            |
| `gimp_fuzzy_select_full()`                      | `gimp_image_select_contiguous_color()`            |
| `gimp_gamma()`                                  | `gimp_drawable_get_format()`                      |
| `gimp_get_icon_theme_dir()`                     | *N/A*                                             |
| `gimp_get_path_by_tattoo()`                     | `gimp_image_get_path_by_tattoo()`                 |
| `gimp_get_theme_dir()`                          | *N/A*                                             |
| `gimp_gradients_get_gradient_data()`            | `gimp_gradient_get_uniform_samples()`             |
| `gimp_gradients_sample_custom()`                | `gimp_gradient_get_custom_samples()`              |
| `gimp_gradients_sample_uniform()`               | `gimp_gradient_get_uniform_samples()`             |
| `gimp_histogram()`                              | `gimp_drawable_histogram()`                       |
| `gimp_hue_saturation()`                         | `gimp_drawable_hue_saturation()`                  |
| `gimp_image_add_channel()`                      | `gimp_image_insert_channel()`                     |
| `gimp_image_add_layer()`                        | `gimp_image_insert_layer()`                       |
| `gimp_image_add_vectors()`                      | `gimp_image_insert_path()`                        |
| `gimp_image_attach_new_parasite()`              | `gimp_image_attach_parasite()`                    |
| `gimp_image_base_type()`                        | `gimp_image_get_base_type()`                      |
| `gimp_image_free_shadow()`                      | `gimp_drawable_free_shadow()`                     |
| `gimp_image_get_channel_position()`             | `gimp_image_get_item_position()`                  |
| `gimp_image_get_cmap()`                         | `gimp_image_get_colormap()`                       |
| `gimp_image_get_layer_position()`               | `gimp_image_get_item_position()`                  |
| `gimp_image_get_vectors_position()`             | `gimp_image_get_item_position()`                  |
| `gimp_image_height()`                           | `gimp_image_get_height()`                         |
| `gimp_image_lower_channel()`                    | `gimp_image_lower_item()`                         |
| `gimp_image_lower_layer()`                      | `gimp_image_lower_item()`                         |
| `gimp_image_lower_layer_to_bottom()`            | `gimp_image_lower_item_to_bottom()`               |
| `gimp_image_lower_vectors()`                    | `gimp_image_lower_item()`                         |
| `gimp_image_lower_vectors_to_bottom()`          | `gimp_image_lower_item_to_bottom()`               |
| `gimp_image_menu_new()`                         | `gimp_image_combo_box_new()`                      |
| `gimp_image_parasite_attach()`                  | `gimp_image_attach_parasite()`                    |
| `gimp_image_parasite_detach()`                  | `gimp_image_detach_parasite()`                    |
| `gimp_image_parasite_find()`                    | `gimp_image_get_parasite()`                       |
| `gimp_image_parasite_list()`                    | `gimp_image_get_parasite_list()`                  |
| `gimp_image_raise_channel()`                    | `gimp_image_raise_item()`                         |
| `gimp_image_raise_layer()`                      | `gimp_image_raise_item()`                         |
| `gimp_image_raise_layer_to_top()`               | `gimp_image_raise_item_to_top()`                  |
| `gimp_image_raise_vectors()`                    | `gimp_image_raise_item()`                         |
| `gimp_image_raise_vectors_to_top()`             | `gimp_image_raise_item_to_top()`                  |
| `gimp_image_scale_full()`                       | `gimp_image_scale()`                              |
| `gimp_image_set_cmap()`                         | `gimp_image_set_colormap()`                       |
| `gimp_image_width()`                            | `gimp_image_get_width()`                          |
| `gimp_install_cmap()`                           | *N/A*                                             |
| `gimp_invert()`                                 | `gimp_drawable_invert()`                          |
| `gimp_item_get_linked()`                        | *N/A*                                             |
| `gimp_item_set_linked()`                        | *N/A*                                             |
| `gimp_layer_menu_new()`                         | `gimp_layer_combo_box_new()`                      |
| `gimp_layer_scale_full()`                       | `gimp_layer_scale()`                              |
| `gimp_layer_translate()`                        | `gimp_item_transform_translate()`                 |
| `gimp_levels()`                                 | `gimp_drawable_levels()`                          |
| `gimp_levels_auto()`                            | `gimp_drawable_levels_stretch()`                  |
| `gimp_levels_stretch()`                         | `gimp_drawable_levels_stretch()`                  |
| `gimp_min_colors()`                             | *N/A*                                             |
| `gimp_palettes_get_palette()`                   | `gimp_context_get_palette()`                      |
| `gimp_palettes_get_palette_entry()`             | `gimp_palette_entry_get_color()`                  |
| `gimp_parasite_attach()`                        | `gimp_attach_parasite()`                          |
| `gimp_parasite_data()`                          | `gimp_parasite_get_data()`                        |
| `gimp_parasite_data_size()`                     | `gimp_parasite_get_data()`                        |
| `gimp_parasite_detach()`                        | `gimp_detach_parasite()`                          |
| `gimp_parasite_find()`                          | `gimp_get_parasite()`                             |
| `gimp_parasite_flags()`                         | `gimp_parasite_get_flags()`                       |
| `gimp_parasite_list()`                          | `gimp_get_parasite_list()`                        |
| `gimp_parasite_name()`                          | `gimp_parasite_get_name()`                        |
| `gimp_path_delete()`                            | `gimp_image_remove_path()`                        |
| `gimp_path_get_current()`                       | `gimp_image_get_selected_paths()`                 |
| `gimp_path_get_locked()`                        | *N/A*                                             |
| `gimp_path_get_points()`                        | `gimp_path_stroke_get_points()`                   |
| `gimp_path_get_point_at_dist()`                 | `gimp_path_stroke_get_point_at_dist()`            |
| `gimp_path_get_tattoo()`                        | `gimp_item_get_tattoo()`                          |
| `gimp_path_import()`                            | `gimp_image_import_paths_from_file()`             |
| `gimp_path_list()`                              | `gimp_image_get_paths()`                          |
| `gimp_path_set_current()`                       | `gimp_image_set_selected_paths()`                 |
| `gimp_path_set_locked()`                        | *N/A*                                             |
| `gimp_path_set_points()`                        | `gimp_path_stroke_new_from_points()`              |
| `gimp_path_set_tattoo()`                        | `gimp_item_set_tattoo()`                          |
| `gimp_path_stroke_current()`                    | `gimp_edit_stroke_vectors()`                      |
| `gimp_path_to_selection()`                      | `gimp_image_select_item()`                        |
| `gimp_patterns_get_pattern()`                   | `gimp_context_get_pattern()`                      |
| `gimp_patterns_get_pattern_data()`              | `gimp_pattern_get_pixels()`                       |
| `gimp_perspective()`                            | `gimp_item_transform_perspective()`               |
| `gimp_posterize()`                              | `gimp_drawable_posterize()`                       |
| `gimp_prop_enum_stock_box_new()`                | `gimp_prop_enum_icon_box_new()`                   |
| `gimp_prop_stock_image_new()`                   | `gimp_prop_icon_image_new()`                      |
| `gimp_prop_unit_menu_new()`                     | `gimp_prop_unit_combo_box_new()`                  |
| `gimp_rect_select()`                            | `gimp_image_select_rectangle()`                   |
| `gimp_rotate()`                                 | `gimp_item_transform_rotate()`                    |
| `gimp_round_rect_select()`                      | `gimp_image_select_round_rectangle()`             |
| `gimp_scale()`                                  | `gimp_item_transform_scale()`                     |
| `gimp_selection_combine()`                      | `gimp_image_select_item()`                        |
| `gimp_selection_layer_alpha()`                  | `gimp_image_select_item()`                        |
| `gimp_selection_load()`                         | `gimp_image_select_item()`                        |
| `gimp_shear()`                                  | `gimp_item_transform_shear()`                     |
| `gimp_stock_init()`                             | `gimp_icons_init()`                               |
| `gimp_text()`                                   | `gimp_text_fontname()`                            |
| `gimp_text_get_extents()`                       | `gimp_text_get_extents_fontname()`                |
| `gimp_text_layer_get_hinting()`                 | `gimp_text_layer_get_hint_style()`                |
| `gimp_text_layer_set_hinting()`                 | `gimp_text_layer_set_hint_style()`                |
| `gimp_threshold()`                              | `gimp_drawable_threshold()`                       |
| `gimp_toggle_button_sensitive_update()`         | `g_object_bind_property()`                        |
| `gimp_transform_2d()`                           | `gimp_item_transform_2d()`                        |
| `gimp_unit_menu_update()`                       | `#GimpUnitComboBox`                               |
| `gimp_vectors_export_to_file()`                 | `gimp_image_export_path_to_file()`                |
| `gimp_vectors_export_to_string()`               | `gimp_image_export_path_to_string()`              |
| `gimp_vectors_get_image()`                      | `gimp_item_get_image()`                           |
| `gimp_vectors_get_linked()`                     | *N/A*                                             |
| `gimp_vectors_get_name()`                       | `gimp_item_get_name()`                            |
| `gimp_vectors_get_tattoo()`                     | `gimp_item_get_tattoo()`                          |
| `gimp_vectors_get_visible()`                    | `gimp_item_get_visible()`                         |
| `gimp_vectors_import_from_file()`               | `gimp_image_import_paths_from_file()`             |
| `gimp_vectors_import_from_string()`             | `gimp_image_import_paths_from_string()`           |
| `gimp_vectors_is_valid()`                       | `gimp_item_is_valid()`                            |
| `gimp_vectors_parasite_attach()`                | `gimp_item_attach_parasite()`                     |
| `gimp_vectors_parasite_detach()`                | `gimp_item_detach_parasite()`                     |
| `gimp_vectors_parasite_find()`                  | `gimp_item_get_parasite()`                        |
| `gimp_vectors_parasite_list()`                  | `gimp_item_get_parasite_list()`                   |
| `gimp_vectors_set_linked()`                     | *N/A*                                             |
| `gimp_vectors_set_name()`                       | `gimp_item_set_name()`                            |
| `gimp_vectors_set_tattoo()`                     | `gimp_item_set_tattoo()`                          |
| `gimp_vectors_set_visible()`                    | `gimp_item_set_visible()`                         |
| `gimp_vectors_to_selection()`                   | `gimp_image_select_item()`                        |
| `gimp_zoom_preview_get_drawable_id()`           | `gimp_zoom_preview_get_drawable()`                |
| `gimp_zoom_preview_new()`                       | `gimp_zoom_preview_new_from_drawable()`           |
| `gimp_zoom_preview_new_from_drawable_id()`      | `gimp_zoom_preview_new_from_drawable()`           |
| `gimp_zoom_preview_new_with_model()`            | `gimp_zoom_preview_new_with_model_from_drawable()`|
