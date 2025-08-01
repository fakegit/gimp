/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpbrush.h
 * Copyright (C) 2023 Jehan
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

#if !defined (__GIMP_H_INSIDE__) && !defined (GIMP_COMPILATION)
#error "Only <libgimp/gimp.h> can be included directly."
#endif

#include <libgimp/gimpresource.h>

G_BEGIN_DECLS

/* For information look into the C source or the html documentation */


#define GIMP_TYPE_BRUSH (gimp_brush_get_type ())
G_DECLARE_FINAL_TYPE (GimpBrush,
                      gimp_brush,
                      GIMP, BRUSH,
                      GimpResource)


GeglBuffer * gimp_brush_get_buffer (GimpBrush  *brush,
                                    gint        max_width,
                                    gint        max_height,
                                    const Babl *format) G_GNUC_WARN_UNUSED_RESULT;
GeglBuffer * gimp_brush_get_mask   (GimpBrush  *brush,
                                    gint        max_width,
                                    gint        max_height,
                                    const Babl *format) G_GNUC_WARN_UNUSED_RESULT;

G_END_DECLS
