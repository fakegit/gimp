#!/usr/bin/env python3

#   Gimp-Python - allows the writing of Gimp plugins in Python.
#   Copyright (C) 2006  Manish Singh <yosh@gimp.org>
#
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation; either version 3 of the License, or
#   (at your option) any later version.
#
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.
#
#   You should have received a copy of the GNU General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.

import gi
gi.require_version('Gimp', '3.0')
from gi.repository import Gimp
from gi.repository import GObject
from gi.repository import GLib
from gi.repository import Gio

import sys


def code_eval(procedure, args, data):

    # Get the parameters
    if args.length() != 1:
        error = 'No parameters given'
        return procedure.new_return_values(Gimp.PDBStatusType.CALLING_ERROR,
                                           GLib.Error(error))

    code = args.index(0)
    if code == '-':
        code = sys.stdin.read()
    exec(code, globals())
    return procedure.new_return_values(Gimp.PDBStatusType.SUCCESS, GLib.Error())


class PythonEval (Gimp.PlugIn):
    ## Parameters ##
    __gproperties__ = {
        "code": (str,
                 "Python code to evaluate, or '-' to read from stdin",
                 "Python code to evaluate, or '-' to read from stdin",
                 "",
                 GObject.ParamFlags.READWRITE)
    }

    ## GimpPlugIn virtual methods ##
    def do_query_procedures(self):
        self.set_translation_domain("gimp30-python",
                                    Gio.file_new_for_path(Gimp.locale_directory()))

        return ['python-fu-eval']

    def do_create_procedure(self, name):
        procedure = Gimp.Procedure.new(self, name,
                                       Gimp.PDBProcType.PLUGIN,
                                       code_eval, None)
        procedure.set_documentation ("Evaluate Python code",
                                     "Evaluate python code under the python interpreter (primarily for batch mode)",
                                     name)

        procedure.set_attribution("Manish Singh",
                                  "Manish Singh",
                                  "2006")

        procedure.add_argument_from_property(self, "code")

        return procedure


Gimp.main(PythonEval.__gtype__, sys.argv)
