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
 * Initialise la liste afin qu'elle soit utilisable.
 * A utiliser sur toute nouvelle variable du type intList avant utilisation.
 */
void fbl_initList(fblList *l);

/**
 * Insert une cellule avec la valeur value en tête de liste.
 */
void fbl_beginingInsert(fblList *l, int value, void (*keyHandler)(void));

/**
 * Change le pointeur de fonction pour cette valeur.
 * Assertion d'entrée : l != NULL && contains(l, value)
 */
void fbl_changeHandler(fblList *l, int value, void (*keyHandler)(void));

/**
 * Supprime la première occurence de cellule à valeur value.
 * Ne fait rien si aucune cellule ne contient cette valeur.
 */
void fbl_deleteValue(fblList *l, int value);

/**
 * Retourne 1 si la liste contient la valeur value, 0 sinon.
 */
int fbl_contains(fblList *l, int value);

/**
 * Détruit correctement la liste.
 */
void fbl_destroyList(fblList *l);

/**
 * Donne la taille de la liste.
 */
int fbl_size(fblList *l);

#endif
