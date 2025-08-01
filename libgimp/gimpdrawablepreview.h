/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpdrawablepreview.h
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

#pragma once

#if !defined (__GIMP_UI_H_INSIDE__) && !defined (GIMP_COMPILATION)
#error "Only <libgimp/gimpui.h> can be included directly."
#endif

G_BEGIN_DECLS

/* For information look into the C source or the html documentation */


#define GIMP_TYPE_DRAWABLE_PREVIEW (gimp_drawable_preview_get_type ())
G_DECLARE_FINAL_TYPE (GimpDrawablePreview,
                      gimp_drawable_preview,
                      GIMP, DRAWABLE_PREVIEW,
                      GimpScrolledPreview)


GtkWidget    * gimp_drawable_preview_new_from_drawable (GimpDrawable        *drawable);
GimpDrawable * gimp_drawable_preview_get_drawable      (GimpDrawablePreview *preview);

/*  for internal use only  */
G_GNUC_INTERNAL void      _gimp_drawable_preview_area_draw_thumb (GimpPreviewArea *area,
                                                                  GimpDrawable    *drawable,
                                                                  gint             width,
                                                                  gint             height);
G_GNUC_INTERNAL gboolean  _gimp_drawable_preview_get_bounds      (GimpDrawable    *drawable,
                                                                  gint            *xmin,
                                                                  gint            *ymin,
                                                                  gint            *xmax,
                                                                  gint            *ymax);

G_END_DECLS

