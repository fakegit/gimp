/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2000 Peter Mattis and Spencer Kimball
 *
 * gimpimagemetadata.h
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

G_BEGIN_DECLS

/* For information look into the C source or the html documentation */


GimpMetadata * gimp_image_metadata_save_prepare   (GimpImage             *image,
                                                   const gchar           *mime_type,
                                                   GimpMetadataSaveFlags *suggested_flags);
GimpMetadata * gimp_image_metadata_save_filter    (GimpImage             *image,
                                                   const gchar           *mime_type,
                                                   GimpMetadata          *metadata,
                                                   GimpMetadataSaveFlags  flags,
                                                   GFile                 *file,
                                                   GError               **error);

GimpImage    * gimp_image_metadata_load_thumbnail (GFile                 *file,
                                                   GError               **error);


/*  for internal use only  */

G_GNUC_INTERNAL void     _gimp_image_metadata_load_finish  (GimpImage             *image,
                                                            const gchar           *mime_type,
                                                            GimpMetadata          *metadata,
                                                            GimpMetadataLoadFlags  flags);

G_GNUC_INTERNAL gboolean _gimp_image_metadata_save_finish  (GimpImage             *image,
                                                            const gchar           *mime_type,
                                                            GimpMetadata          *metadata,
                                                            GimpMetadataSaveFlags  flags,
                                                            GFile                 *file,
                                                            GError               **error);

G_END_DECLS
