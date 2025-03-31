#include "snake.h"

#define WINDOW_X 0
#define WINDOW_Y 0
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define BUTTON_WIDTH 300
#define BUTTON_HEIGHT 100


void render_button(SDL_Renderer *renderer, SDL_Rect spButton) {
  // Setăm culoarea pentru buton
  SDL_SetRenderDrawColor(renderer, 211, 219, 222, 255);

  // Calculăm poziția butonului pentru a-l centra
  spButton.w = BUTTON_WIDTH;
  spButton.h = BUTTON_HEIGHT;
  spButton.x = WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2;
  spButton.y = WINDOW_HEIGHT / 4;

  // Desenăm butonul
  SDL_RenderFillRect(renderer, &spButton);
}

int isMouseOverButton(int mouseX, int mouseY, SDL_Rect button) {
  // Verificăm dacă mouse-ul este deasupra butonului
  return (mouseX >= button.x && mouseX <= button.x + button.w &&
          mouseY >= button.y && mouseY <= button.y + button.h);
}

int main(void) {

  SDL_Window *window;
  SDL_Renderer *renderer;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "ERROR: SDL_INIT_VIDEO");
  }

  window = SDL_CreateWindow(
    "Snake",
    WINDOW_X,
    WINDOW_Y,
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    SDL_WINDOW_BORDERLESS
  );

  if (!window) {
    fprintf(stderr, "ERROR: !window");
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    fprintf(stderr, "ERROR: !renderer");
  }

  bool quit = false;
  SDL_Event event;
  
  SDL_Rect spButton; // Butonul
  spButton.w = BUTTON_WIDTH;
  spButton.h = BUTTON_HEIGHT;
  spButton.x = WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2;
  spButton.y = WINDOW_HEIGHT / 4;

  while (!quit) {
    // Ștergem ecranul (setăm culoarea de fundal)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Desenăm butonul
    render_button(renderer, spButton);

    // Verificăm evenimentele
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        quit = true;
        break;

      case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_ESCAPE) {
          quit = true;
        }
        break;

      case SDL_MOUSEBUTTONDOWN:
        // Verificăm dacă click-ul este pe buton
        if (isMouseOverButton(event.button.x, event.button.y, spButton)) {
          quit = true; // Dacă click-ul este pe buton, închidem aplicația
        }
        break;
      }
    }

    // Actualizăm ecranul
    SDL_RenderPresent(renderer);
  }

  // Curățăm
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
