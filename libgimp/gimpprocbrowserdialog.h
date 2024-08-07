/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-1997 Peter Mattis and Spencer Kimball
 *
 * gimpprocbrowserdialog.c
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

#if !defined (__GIMP_UI_H_INSIDE__) && !defined (GIMP_COMPILATION)
#error "Only <libgimp/gimpui.h> can be included directly."
#endif

#ifndef __GIMP_PROC_BROWSER_DIALOG_H__
#define __GIMP_PROC_BROWSER_DIALOG_H__

G_BEGIN_DECLS


/* For information look into the C source or the html documentation */


#define GIMP_TYPE_PROC_BROWSER_DIALOG (gimp_proc_browser_dialog_get_type ())
G_DECLARE_DERIVABLE_TYPE (GimpProcBrowserDialog, gimp_proc_browser_dialog, GIMP, PROC_BROWSER_DIALOG, GimpDialog)


struct _GimpProcBrowserDialogClass
{
  GimpDialogClass  parent_class;

  void (* selection_changed) (GimpProcBrowserDialog *dialog);
  void (* row_activated)     (GimpProcBrowserDialog *dialog);

  /* Padding for future expansion */
  void (* _gimp_reserved1) (void);
  void (* _gimp_reserved2) (void);
  void (* _gimp_reserved3) (void);
  void (* _gimp_reserved4) (void);
  void (* _gimp_reserved5) (void);
  void (* _gimp_reserved6) (void);
  void (* _gimp_reserved7) (void);
  void (* _gimp_reserved8) (void);
};


GtkWidget * gimp_proc_browser_dialog_new          (const gchar  *title,
                                                   const gchar  *role,
                                                   GimpHelpFunc  help_func,
                                                   const gchar  *help_id,
                                                   ...) G_GNUC_NULL_TERMINATED;

gchar     * gimp_proc_browser_dialog_get_selected (GimpProcBrowserDialog *dialog);


G_END_DECLS

#endif  /* __GIMP_PROC_BROWSER_DIALOG_H__ */
