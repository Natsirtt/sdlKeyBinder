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

#ifndef SDL_KEY_UTILS_MAIN
#define SDL_KEY_UTILS_MAIN

#define KEY_NB 231

#include "intList.h"
#include "fblList.h"

typedef struct {
  fblList functionBind;
  intList keyBind;
} keyBinder;

/**
 * Initialisation of the keyBinder.
 * This function must be called before any futher usage of a just-created
 * keyBinder variable.
 */
void skbInitKeyBinder(keyBinder *kb);

/**
 * This function records the function pointed by "keyHandler" as the
 * handler of the key "key" (which must have been passed as a SDL_KEY).
 * It means that any call to skbHandle(kb) (where kb is here the same
 * as the real argument passed to skbBindKeyHandler()) will make a call
 * to the keyHandler function if the key is, at this moment, pressed.
 */
void skbBindKeyHandler(keyBinder *kb, int key, void (*keyHandler)(void));

/**
 * This function makes the keyBinder record the key as being currently
 * pressed. The keyBinder will consider this key as pressed until a call
 * to skbKeyReleased(kb, key) is made.
 */
void skbKeyPressed(keyBinder *kb, int key);

/**
 * This function makes the keyBinder record the key as being unpressed.
 * It will consider the key not pressed until a call to
 * skbKeyPressed(kb, key) is made.
 */
void skbKeyReleased(keyBinder *kb, int key);

/**
 * This function simply returns 1 if the SDL_KEY "key" is pressed,
 * otherwise it returns 0.
 */
int skbIsPressed(keyBinder *kb, int key);

/**
 * This function will make a call to every precedently binded function
 * (with skbBindKeyHandler()) if the key that is binded to the function
 * is currently pressed.
 */
void skbHandle(keyBinder *kb);

/**
 * Destroys the keyBinder.
 * This function should be called by the time the keyBinder becomes
 * useless, otherwise some memory leaks could happen.
 */
void skbDestroyKeyBinder(keyBinder *kb);

#endif
