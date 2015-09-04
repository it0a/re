#include <SDL.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;

SDL_Texture* gHelloWorld = NULL;
SDL_Texture* loadTexture( std::string path );
SDL_Renderer* gRenderer = NULL;
