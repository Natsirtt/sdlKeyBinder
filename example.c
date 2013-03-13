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
