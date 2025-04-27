/*This piece of code was originally from Lazy Foo' Productions (http://lazyfoo.net/)*/
//Using SDL and standard IO
#include "snake.h"
//Screen dimension constants
#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT 1080
#define SCREEN_X 0
#define SCREEN_Y 0

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void Prgclose();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SCREEN_X, SCREEN_Y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	gHelloWorld = SDL_LoadBMP( "pictures/youWin.bmp" );
	if( gHelloWorld == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "pictures/youWin.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void closeWindow()
{
	//Deallocate surface
	SDL_FreeSurface( gHelloWorld );
	gHelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void trimitere_start() {
    SDL_Quit(); // Închide SDL înainte de a porni alt program

    const char *new_program = "./start"; // Calea către noul executabil
    execlp(new_program, new_program, (char *)NULL);

    // Dacă execvp eșuează:
    perror("Eroare la lansarea noului program");
    exit(EXIT_FAILURE);
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Apply the image
			SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
			
			//Update the surface
			SDL_UpdateWindowSurface( gWindow );

		    
			//Hack to get window to stay up
			SDL_Event e;
			bool quit = false;
			
			while( quit == false ){
			  SDL_Delay(1000);
			  quit = true;
			  trimitere_start();
			 
			}
		}
	}

	
	
	//Free resources and close SDL
	closeWindow();

	return 0;
}
