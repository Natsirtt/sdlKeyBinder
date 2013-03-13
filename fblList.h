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

#ifndef SDL_KEY_UTILS_FUNCTION_BIND_LIST
#define SDL_KEY_UTILS_FUNCTION_BIND_LIST

typedef struct FBL_CELL{
  int val;
  void (*keyHandler)(void);
  struct FBL_CELL *next;
} fblCell;

typedef struct {
  fblCell *data;
  int size;
} fblList;

/**
 * Initialisation of the list.
 * This function must be called as soon as a new fblList is created
 * and before any further usage of it.
 */
void fbl_initList(fblList *l);

/**
 * Head insertion of the value and its binded function in the list.
 */
void fbl_beginingInsert(fblList *l, int value, void (*keyHandler)(void));

/**
 * Bind a new function for the value.
 * The list must already contains the value.
 */
void fbl_changeHandler(fblList *l, int value, void (*keyHandler)(void));

/**
 * Deletes the first occurency of the cell containing the value.
 * Doesn't do anything if no cell does.
 */
void fbl_deleteValue(fblList *l, int value);

/**
 * Returns 1 if the list contains a cell with this value, 0 otherwise.
 */
int fbl_contains(fblList *l, int value);

/**
 * Destroy the list.
 * This function should be called as soon as a fblList becomes useless,
 * otherwise some memory leaks could appear.
 */
void fbl_destroyList(fblList *l);

/**
 * Returns the size of the list.
 */
int fbl_size(fblList *l);

#endif
