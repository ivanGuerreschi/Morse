# Makefile.am
# Copyright (C) 2020 Ivan Guerreschi
#
# This file is part of morse.
#
# Author: Ivan Guerreschi <ivanguerreschi86@gmail.com>
# Maintainer: Ivan Guerreschi <ivanguerreschi86@gmail.com>e
#
# morse is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#  
# morse is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with morse.  If not, see <http://www.gnu.org/licenses/>. 

AM_CFLAGS = -I $(top_srcdir)/src \
          -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs \
	  -Wjump-misses-init -Wlogical-op -fanalyzer	

bin_PROGRAMS = morse
morse_SOURCES = main.c menu.c
