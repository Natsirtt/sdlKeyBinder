#  
#  Copyright (c) 2013 Tristan Louet
#  
#  This file is part of sdlKeyBinder.
#
#  sdlKeyBinder is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  sdlKeyBinder is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with sdlKeyBinder.  If not, see <http://www.gnu.org/licenses/>.

GCC=gcc
RM=rm -f
LIBS_SDL=-lSDL_image `sdl-config --libs`
CFLAGS=--std=c99 -Wall
CFLAGS_SDL=`sdl-config --cflags` -Wall

all: sdlKeyBinder.o

sdlKeyBinder.o: sdlKeyBinder.c sdlKeyBinder.h intList.h fblList.h
	$(GCC) -c $(CFLAGS) $(CFLAGS_SDL) $<

intList.o: intList.h intList.c
	$(GCC) -c $(CFLAGS) $<

fblList.o: fblList.h fblList.c
	$(GCC) -c $(CFLAGS) $<

clean:
	$(RM) *.{o,gch}
