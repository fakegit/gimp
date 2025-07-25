/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpcolorbutton.h
 * Copyright (C) 1999-2001 Sven Neumann
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

/* This provides a button with a color preview. The preview
 * can handle transparency by showing the checkerboard.
 * On click, a color selector is opened, which is already
 * fully functional wired to the preview button.
 */

#pragma once

#if !defined (__GIMP_WIDGETS_H_INSIDE__) && !defined (GIMP_WIDGETS_COMPILATION)
#error "Only <libgimpwidgets/gimpwidgets.h> can be included directly."
#endif

#include <libgimpwidgets/gimpbutton.h>

G_BEGIN_DECLS

#define GIMP_TYPE_COLOR_BUTTON (gimp_color_button_get_type ())
G_DECLARE_DERIVABLE_TYPE (GimpColorButton,
                          gimp_color_button,
                          GIMP, COLOR_BUTTON,
                          GimpButton)


struct _GimpColorButtonClass
{
  GimpButtonClass  parent_class;

  /*  signals  */
  void  (* color_changed)   (GimpColorButton *button);

  /*  virtual functions  */
  GType (* get_action_type) (GimpColorButton *button);

  /* Padding for future expansion */
  void (* _gimp_reserved0) (void);
  void (* _gimp_reserved1) (void);
  void (* _gimp_reserved2) (void);
  void (* _gimp_reserved3) (void);
  void (* _gimp_reserved4) (void);
  void (* _gimp_reserved5) (void);
  void (* _gimp_reserved6) (void);
  void (* _gimp_reserved7) (void);
  void (* _gimp_reserved8) (void);
  void (* _gimp_reserved9) (void);
};


GtkWidget    * gimp_color_button_new              (const gchar       *title,
                                                   gint               width,
                                                   gint               height,
                                                   GeglColor         *color,
                                                   GimpColorAreaType  type);

void           gimp_color_button_set_title        (GimpColorButton   *button,
                                                   const gchar       *title);
const gchar  * gimp_color_button_get_title        (GimpColorButton   *button);

void           gimp_color_button_set_color        (GimpColorButton   *button,
                                                   GeglColor         *color);
GeglColor    * gimp_color_button_get_color        (GimpColorButton   *button);

gboolean       gimp_color_button_has_alpha        (GimpColorButton   *button);
void           gimp_color_button_set_type         (GimpColorButton   *button,
                                                   GimpColorAreaType  type);

gboolean       gimp_color_button_get_update       (GimpColorButton   *button);
void           gimp_color_button_set_update       (GimpColorButton   *button,
                                                   gboolean           continuous);

void           gimp_color_button_set_color_config (GimpColorButton   *button,
                                                   GimpColorConfig   *config);

GSimpleActionGroup *
               gimp_color_button_get_action_group (GimpColorButton   *button);

G_END_DECLS
