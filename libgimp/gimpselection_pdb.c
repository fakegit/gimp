/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimpselection_pdb.c
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

/* NOTE: This file is auto-generated by pdbgen.pl */

#include "config.h"

#include "stamp-pdbgen.h"

#include "gimp.h"


/**
 * SECTION: gimpselection
 * @title: gimpselection
 * @short_description: Functions for manipulating selections.
 *
 * Functions for manipulating selections.
 **/


/**
 * gimp_selection_bounds:
 * @image: The image.
 * @non_empty: (out): TRUE if there is a selection.
 * @x1: (out): x coordinate of upper left corner of selection bounds.
 * @y1: (out): y coordinate of upper left corner of selection bounds.
 * @x2: (out): x coordinate of lower right corner of selection bounds.
 * @y2: (out): y coordinate of lower right corner of selection bounds.
 *
 * Find the bounding box of the current selection.
 *
 * This procedure returns whether there is a selection for the
 * specified image. If there is one, the upper left and lower right
 * corners of the bounding box are returned. These coordinates are
 * relative to the image. Please note that the pixel specified by the
 * lower right coordinate of the bounding box is not part of the
 * selection. The selection ends at the upper left corner of this
 * pixel. This means the width of the selection can be calculated as
 * (x2 - x1), its height as (y2 - y1).
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_bounds (GimpImage *image,
                       gboolean  *non_empty,
                       gint      *x1,
                       gint      *y1,
                       gint      *x2,
                       gint      *y2)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-bounds",
                                               args);
  gimp_value_array_unref (args);

  *non_empty = FALSE;
  *x1 = 0;
  *y1 = 0;
  *x2 = 0;
  *y2 = 0;

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  if (success)
    {
      *non_empty = GIMP_VALUES_GET_BOOLEAN (return_vals, 1);
      *x1 = GIMP_VALUES_GET_INT (return_vals, 2);
      *y1 = GIMP_VALUES_GET_INT (return_vals, 3);
      *x2 = GIMP_VALUES_GET_INT (return_vals, 4);
      *y2 = GIMP_VALUES_GET_INT (return_vals, 5);
    }

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_value:
 * @image: The image.
 * @x: x coordinate of value.
 * @y: y coordinate of value.
 *
 * Find the value of the selection at the specified coordinates.
 *
 * This procedure returns the value of the selection at the specified
 * coordinates. If the coordinates lie out of bounds, 0 is returned.
 *
 * Returns: Value of the selection.
 **/
gint
gimp_selection_value (GimpImage *image,
                      gint       x,
                      gint       y)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gint value = 0;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_INT, x,
                                          G_TYPE_INT, y,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-value",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    value = GIMP_VALUES_GET_INT (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return value;
}

/**
 * gimp_selection_is_empty:
 * @image: The image.
 *
 * Determine whether the selection is empty.
 *
 * This procedure returns TRUE if the selection for the specified image
 * is empty.
 *
 * Returns: Is the selection empty?
 **/
gboolean
gimp_selection_is_empty (GimpImage *image)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean is_empty = FALSE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-is-empty",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    is_empty = GIMP_VALUES_GET_BOOLEAN (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return is_empty;
}

/**
 * gimp_selection_translate:
 * @image: The image.
 * @offx: x offset for translation.
 * @offy: y offset for translation.
 *
 * Translate the selection by the specified offsets.
 *
 * This procedure actually translates the selection for the specified
 * image by the specified offsets. Regions that are translated from
 * beyond the bounds of the image are set to empty. Valid regions of
 * the selection which are translated beyond the bounds of the image
 * because of this call are lost.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_translate (GimpImage *image,
                          gint       offx,
                          gint       offy)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_INT, offx,
                                          G_TYPE_INT, offy,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-translate",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * _gimp_selection_float:
 * @drawables: (element-type GimpDrawable) (array zero-terminated=1): The drawables from which to float selection.
 * @offx: x offset for translation.
 * @offy: y offset for translation.
 *
 * Float the selection from the specified drawable with initial offsets
 * as specified.
 *
 * This procedure determines the region of the specified drawable that
 * lies beneath the current selection. The region is then cut from the
 * drawable and the resulting data is made into a new layer which is
 * instantiated as a floating selection. The offsets allow initial
 * positioning of the new floating selection.
 *
 * Returns: (transfer none): The floated layer.
 **/
GimpLayer *
_gimp_selection_float (const GimpDrawable **drawables,
                       gint                 offx,
                       gint                 offy)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  GimpLayer *layer = NULL;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_CORE_OBJECT_ARRAY, drawables,
                                          G_TYPE_INT, offx,
                                          G_TYPE_INT, offy,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-float",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    layer = GIMP_VALUES_GET_LAYER (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return layer;
}

/**
 * gimp_selection_invert:
 * @image: The image.
 *
 * Invert the selection mask.
 *
 * This procedure inverts the selection mask. For every pixel in the
 * selection channel, its new value is calculated as (255 - old-value).
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_invert (GimpImage *image)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-invert",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_sharpen:
 * @image: The image.
 *
 * Sharpen the selection mask.
 *
 * This procedure sharpens the selection mask. For every pixel in the
 * selection channel, if the value is &gt; 127, the new pixel is
 * assigned a value of 255. This removes any \"anti-aliasing\" that
 * might exist in the selection mask's boundary.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_sharpen (GimpImage *image)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-sharpen",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_all:
 * @image: The image.
 *
 * Select all of the image.
 *
 * This procedure sets the selection mask to completely encompass the
 * image. Every pixel in the selection channel is set to 255.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_all (GimpImage *image)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-all",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_none:
 * @image: The image.
 *
 * Deselect the entire image.
 *
 * This procedure deselects the entire image. Every pixel in the
 * selection channel is set to 0.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_none (GimpImage *image)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-none",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_feather:
 * @image: The image.
 * @radius: Radius of feather (in pixels).
 *
 * Feather the image's selection
 *
 * This procedure feathers the selection. Feathering is implemented
 * using a gaussian blur.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_feather (GimpImage *image,
                        gdouble    radius)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_DOUBLE, radius,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-feather",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_border:
 * @image: The image.
 * @radius: Radius of border (in pixels).
 *
 * Border the image's selection
 *
 * This procedure borders the selection. Bordering creates a new
 * selection which is defined along the boundary of the previous
 * selection at every point within the specified radius.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_border (GimpImage *image,
                       gint       radius)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_INT, radius,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-border",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_grow:
 * @image: The image.
 * @steps: Steps of grow (in pixels).
 *
 * Grow the image's selection
 *
 * This procedure grows the selection. Growing involves expanding the
 * boundary in all directions by the specified pixel amount.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_grow (GimpImage *image,
                     gint       steps)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_INT, steps,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-grow",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_shrink:
 * @image: The image.
 * @steps: Steps of shrink (in pixels).
 *
 * Shrink the image's selection
 *
 * This procedure shrinks the selection. Shrinking involves trimming
 * the existing selection boundary on all sides by the specified number
 * of pixels.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_selection_shrink (GimpImage *image,
                       gint       steps)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_INT, steps,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-shrink",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_flood:
 * @image: The image.
 *
 * Remove holes from the image's selection
 *
 * This procedure removes holes from the selection, that can come from
 * selecting a patchy area with the Fuzzy Select Tool. In technical
 * terms this procedure floods the selection. See the Algorithms page
 * in the developer wiki for details.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.10
 **/
gboolean
gimp_selection_flood (GimpImage *image)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  gboolean success = TRUE;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-flood",
                                               args);
  gimp_value_array_unref (args);

  success = GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS;

  gimp_value_array_unref (return_vals);

  return success;
}

/**
 * gimp_selection_save:
 * @image: The image.
 *
 * Copy the selection mask to a new channel.
 *
 * This procedure copies the selection mask and stores the content in a
 * new channel. The new channel is automatically inserted into the
 * image's list of channels.
 *
 * Returns: (transfer none): The new channel.
 **/
GimpChannel *
gimp_selection_save (GimpImage *image)
{
  GimpValueArray *args;
  GimpValueArray *return_vals;
  GimpChannel *channel = NULL;

  args = gimp_value_array_new_from_types (NULL,
                                          GIMP_TYPE_IMAGE, image,
                                          G_TYPE_NONE);

  return_vals = _gimp_pdb_run_procedure_array (gimp_get_pdb (),
                                               "gimp-selection-save",
                                               args);
  gimp_value_array_unref (args);

  if (GIMP_VALUES_GET_ENUM (return_vals, 0) == GIMP_PDB_SUCCESS)
    channel = GIMP_VALUES_GET_CHANNEL (return_vals, 1);

  gimp_value_array_unref (return_vals);

  return channel;
}
