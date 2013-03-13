sdlKeyBinder
==========

Copyright (c) 2013 Tristan Louet

This file is part of sdlKeyBinder.

sdlKeyBinder is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

sdlKeyBinder is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
you should have received a copy of the GNU General Public License
along with sdlKeyBinder.  If not, see <http://www.gnu.org/licenses/>.

------------------------------------------------------------------------

Please report any bug to tristan.louet@etu.univ-rouen.fr
Please also feel free to ask any question or make any suggestion at the
same email address.
I'll also be glad to know of every modification you made for your own
usage that I could implement too !

Please write [SKB] at the beginning of your mail object so I can know
what's the pupose of it.

------------------------------------------------------------------------

The purpose of this library written in C is to provide a tool helping
handle of the keyboard inputs while using the SDL.

You can have a keyBinder typed variable that you have to update at each
SDL_KEYUP or SDL_KEYDOWN event so that it can keep for you the
information of each key that is down or up. Here is an example of a
function that is called every time a SDL_Event is polled in the main
loop (kb is the keyBinder variable) :

void eventCatcher(SDL_Event *event) {
  switch (event->type) {
    case SDL_KEYDOWN:
      skbKeyPressed(&kb, event->key.keysym.sym);
      continue = !skbIsPressed(&kb, SDLK_ESCAPE); //If escape is pressed, the program will quit
      break;
    case SDL_KEYUP:
      skbKeyReleased(&kb, event->key.keysym.sym);
      break;
  }
}

As you can see, testing if a key is currently pressed is as simple as
calling to skbIsPressed(), assuming you correctly called skbKeyPressed()
and skbKeyReleased when it was necessary.

The second fonctionality of a keyBinder is key-handlers functions.
By calling skbBindKeyHandler(keyBinder kb, int key, (*keyHandler)(void)),
you can inform the keyBinder that the function "keyHandler" has to be
called every time the function skbHandle(kb) is used but ONLY IF the 
skbIsPressed(kb, key) returns 1.
