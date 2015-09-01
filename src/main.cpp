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

bool init() {
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    return true;
}

bool loadMedia() {
    gHelloWorld = loadTexture("res/hello_world.bmp");
    if (gHelloWorld == NULL) {
        return false;
    }
    return true;
}


void close() {
    SDL_DestroyTexture(gHelloWorld);
    gHelloWorld = NULL;
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;
    SDL_Quit();
}

void gameLoop() {
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while(SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if ( e.type == SDL_KEYDOWN ) {
                switch( e.key.keysym.sym ) {
                    case SDLK_UP:
                        printf("Up\n");
                        break;
                    case SDLK_DOWN:
                        printf("Down\n");
                        break;
                    case SDLK_LEFT:
                        printf("Left\n");
                        break;
                    case SDLK_RIGHT:
                        printf("Right\n");
                        break;
                    default:
                        break;
                }
            }
            SDL_RenderClear(gRenderer);
            SDL_RenderCopy(gRenderer, gHelloWorld, NULL, NULL);
            SDL_RenderPresent(gRenderer);
        }
    }
}

SDL_Texture* loadTexture( std::string path ) {
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
    } else {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if(newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

int main( int argc, char* args[] ) {
    if (init()) {
        if (loadMedia()) {
            gameLoop();
        }
    }
    close();
    return 0;
}

