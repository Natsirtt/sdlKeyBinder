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

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "sdlKeyBinder.h"

void _skbError(const char *msg) {
  fprintf(stderr, "sku_error: %s\n", msg);
}

void _skbWarning(const char *msg) {
  fprintf(stderr, "sku_warning: %s\n", msg);
}

void skbInitKeyBinder(keyBinder *kb) {
  if (kb == NULL) {
    _skbError("null keyBinder pointer");
    return;
  }
  il_initList(&(kb->keyBind));
  fbl_initList(&(kb->functionBind));
}

void skbBindKeyHandler(keyBinder *kb, int key, void (*keyHandler)(void)) {
  if (kb == NULL) {
    _skbError("null keyBinder pointer");
    return;
  }
  if (!fbl_contains(&(kb->functionBind), key)) {
    fbl_beginingInsert(&(kb->functionBind), key, keyHandler);
  } else {
    fbl_changeHandler(&(kb->functionBind), key, keyHandler);
  }
}

void skbKeyPressed(keyBinder *kb, int key) {
  if (kb == NULL) {
    _skbError("null keyBinder");
    return;
  }
  if (skbIsPressed(kb, key)) {
    _skbWarning("Key was already pressed");
    return;
  }
  il_beginingInsert(&(kb->keyBind), key);
}

void skbKeyReleased(keyBinder *kb, int key) {
  if (kb == NULL) {
    _skbError("null keyBinder pointer");
    return;
  }
  if (!skbIsPressed(kb, key)) {
    _skbWarning("Key was'nt pressed");
    return;
  }
  il_deleteValue(&(kb->keyBind), key);
}

int skbIsPressed(keyBinder *kb, int key) {
  if (kb == NULL) {
    _skbError("null keyBinder pointer");
    return -1;
  }
  return il_contains(&(kb->keyBind), key);
}

void skbHandle(keyBinder *kb) {
  fblCell *handlersCell = kb->functionBind.data;
  while (handlersCell != NULL) {
    if (il_contains(&(kb->keyBind), handlersCell->val)) {
      handlersCell->keyHandler();
    }
    handlersCell = handlersCell->next;
  }
}

void skbDestroyKeyBinder(keyBinder *kb) {
  il_destroyList(&(kb->keyBind));
  fbl_destroyList(&(kb->functionBind));
}
