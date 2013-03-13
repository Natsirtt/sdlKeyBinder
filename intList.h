/*  
 *  Copyright (c) 2013 Tristan Louet
 *  
 *  This file is part of sdlKeyBinder.
 *
 *  sdlKeyBinder is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  sdlKeyBinder is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with sdlKeyBinder.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SDL_KEY_UTILS__INTLIST
#define SDL_KEY_UTILS__INTLIST

typedef struct INT_CELL {
  int val;
  struct INT_CELL *next;
} intCell;

typedef struct {
  intCell *data;
  int size;
} intList;

/**
 * Initialisation of the list.
 * Must be called on a new intList variable before any further usage.
 */
void il_initList(intList *l);

/**
 * Head insertion of "value" in the list "l".
 */
void il_beginingInsert(intList *l, int value);

/**
 * Deletes the first occurency of "value" in the list "l".
 * Doesn't do anything if "value" wasn't in it.
 */
void il_deleteValue(intList *l, int value);

/**
 * Returns 1 if "value" is contained in the list "l", 0 otherwise.
 */
int il_contains(intList *l, int value);

/**
 * Destroy the list.
 * This should be called by the program using a list, otherwise some
 * memory leaks could appear.
 */
void il_destroyList(intList *l);

/**
 * Returns the size of the list "l".
 */
int il_size(intList *l);

#endif
