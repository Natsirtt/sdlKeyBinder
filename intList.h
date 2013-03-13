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
 * Initialise la liste afin qu'elle soit utilisable.
 * A utiliser sur toute nouvelle variable du type intList avant utilisation.
 */
void il_initList(intList *l);

/**
 * Insert une intCellule avec la valeur value en tête de liste.
 */
void il_beginingInsert(intList *l, int value);

/**
 * Supprime la première occurence de intCellule à valeur value.
 * Ne fait rien si aucune intCellule ne contient cette valeur.
 */
void il_deleteValue(intList *l, int value);

/**
 * Retourne 1 si la liste contient la valeur value, 0 sinon.
 */
int il_contains(intList *l, int value);

/**
 * Détruit correctement la liste.
 */
void il_destroyList(intList *l);

/**
 * Donne la taille de la liste.
 */
int il_size(intList *l);

#endif
