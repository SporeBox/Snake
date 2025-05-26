/*This piece of code was originally from Lazy Foo' Productions (http://lazyfoo.net/)*/
//Using SDL and standard IO
#include "snake.h"
//Screen dimension constants
#define SCREEN_WIDTH  1920
#define SCREEN_HEIGHT 1080
#define SCREEN_X 0
#define SCREEN_Y 0

bool init();

//Loads media
bool loadMedia();

void Prgclose();

SDL_Window* gWindow = NULL;
	
SDL_Surface* gScreenSurface = NULL;

SDL_Surface* image = NULL;

bool init()
{
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
		gWindow = SDL_CreateWindow( "You Win", SCREEN_X, SCREEN_Y, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_BORDERLESS );
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
	image = SDL_LoadBMP( "pictures/youWin.bmp" );
	if( image == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", "pictures/youWin.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void closeWindow()
{
	//Deallocate surface
	SDL_FreeSurface( image );
	image = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void trimitere_start() {
    SDL_Quit();

    const char *new_program = "./start";
    execlp(new_program, new_program, (char *)NULL);

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
			SDL_BlitSurface( image, NULL, gScreenSurface, NULL );
			
			//Update the surface
			SDL_UpdateWindowSurface( gWindow );

		    
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
