#include "snake.h"

#define WINDOW_X 0
#define WINDOW_Y 0
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define BUTTON_WIDTH 300
#define BUTTON_HEIGHT 100

  
void render_button_sp(SDL_Renderer *renderer, SDL_Rect spButton) {
  // Setăm culoarea pentru buton
  SDL_Surface* surface = IMG_Load("pictures/singleplayer.png");
  SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  // Calculăm poziția butonului pentru a-l centra
  spButton.w = BUTTON_WIDTH;
  spButton.h = BUTTON_HEIGHT;
  spButton.x = WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2;
  spButton.y = WINDOW_HEIGHT / 4;
  
  // Desenăm butonul
  SDL_RenderCopy(renderer, buttonTexture, NULL, &spButton);
  SDL_DestroyTexture(buttonTexture);
}

void render_button_mp(SDL_Renderer *renderer, SDL_Rect spButton) {
  // Setăm culoarea pentru buton
  SDL_Surface* surface = IMG_Load("pictures/multiplayer.png");
  SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  // Calculăm poziția butonului pentru a-l centra
  spButton.w = BUTTON_WIDTH;
  spButton.h = BUTTON_HEIGHT;
  spButton.x = WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2;
  spButton.y = WINDOW_HEIGHT / 4 + BUTTON_HEIGHT + 4;
  
  // Desenăm butonul
  SDL_RenderCopy(renderer, buttonTexture, NULL, &spButton);
  SDL_DestroyTexture(buttonTexture);
}

void render_button_quit(SDL_Renderer *renderer, SDL_Rect spButton) {
  // Setăm culoarea pentru buton
  SDL_Surface* surface = IMG_Load("pictures/quit.png");
  SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);

  // Calculăm poziția butonului pentru a-l centra
  spButton.w = BUTTON_WIDTH;
  spButton.h = BUTTON_HEIGHT;
  spButton.x = WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2;
  spButton.y = WINDOW_HEIGHT / 4 + 2 * BUTTON_HEIGHT + 8;
  
  // Desenăm butonul
  SDL_RenderCopy(renderer, buttonTexture, NULL, &spButton);
  SDL_DestroyTexture(buttonTexture);
}

int isMouseOverButton(int mouseX, int mouseY, SDL_Rect button) {
  // Verificăm dacă mouse-ul este deasupra butonului
  return (mouseX >= button.x && mouseX <= button.x + button.w &&
          mouseY >= button.y && mouseY <= button.y + button.h);
}

void trimitere_sp() {
    SDL_Quit(); // Închide SDL înainte de a porni alt program

    const char *new_program = "./snake"; // Calea către noul executabil
    execlp(new_program, new_program, (char *)NULL);

    // Dacă execvp eșuează:
    perror("Eroare la lansarea noului program");
    exit(EXIT_FAILURE);
}

void trimitere_mp() {
    SDL_Quit(); // Închide SDL înainte de a porni alt program

    const char *new_program = "./snakeMp"; // Calea către noul executabil
    execlp(new_program, new_program, (char *)NULL);

    // Dacă execvp eșuează:
    perror("Eroare la lansarea noului program");
    exit(EXIT_FAILURE);
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
  
  SDL_Rect spButton; // Butoanele
  SDL_Rect mpButton;
  SDL_Rect quitButton;

  spButton.w = BUTTON_WIDTH;
  spButton.h = BUTTON_HEIGHT;
  spButton.x = WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2;
  spButton.y = WINDOW_HEIGHT / 4;

  mpButton.w = BUTTON_WIDTH;
  mpButton.h = BUTTON_HEIGHT;
  mpButton.x = WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2;
  mpButton.y = WINDOW_HEIGHT / 4 + BUTTON_HEIGHT + 4;

  quitButton.w = BUTTON_WIDTH;
  quitButton.h = BUTTON_HEIGHT;
  quitButton.x = WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2;
  quitButton.y = WINDOW_HEIGHT / 4 + 2 * BUTTON_HEIGHT + 8;
 
  while (!quit) {
    // Ștergem ecranul (setăm culoarea de fundal)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Desenăm butonul
    render_button_sp(renderer, spButton);
    render_button_mp(renderer, mpButton);
    render_button_quit(renderer, quitButton);


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
	  trimitere_sp();
        }
	if (isMouseOverButton(event.button.x, event.button.y, mpButton)) {
	  trimitere_mp();
        }
	if (isMouseOverButton(event.button.x, event.button.y, quitButton)) {
	  quit = true;
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
