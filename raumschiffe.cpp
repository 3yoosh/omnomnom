#include <SDL.h>
#include <SDL_image.h>
#include "schiff.h"
#include "sterne.h"

int main(int a, char**b) {
    // Fenster aufbauen
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("Raumschiff", 100, 100, 760, 580,SDL_WINDOW_SHOWN);
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    IMG_Init( IMG_INIT_PNG );
    SDL_Surface *hintergrund = IMG_Load("bilder/background.png");

    Sterne s1(0, 3, "bilder/stars3.png");
    Sterne s2(0, 6, "bilder/stars2.png");
    Sterne s3(0, 10, "bilder/stars1.png");

    Raumschiff r(100, 100, "raumschiffe.png");

    SDL_Event e;
    int taste;

    for (int i=0; i<100000; i++) {

        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_KEYDOWN ) {
              taste = e.key.keysym.sym;
              if (taste == SDLK_UP) { r.oben(); }
              else if (taste == SDLK_DOWN) { r.unten(); }
              else if (taste == SDLK_LEFT) { r.links(); }
              else if (taste == SDLK_RIGHT) { r.rechts(); }
            }
        }

        SDL_BlitSurface(hintergrund, NULL, surf, NULL);
        s1.bewegen();
        s2.bewegen();
        s3.bewegen();
        s1.zeichnen(surf);
        s2.zeichnen(surf);
        s3.zeichnen(surf);
        r.zeichnen(surf);

        SDL_UpdateWindowSurface(win);
        SDL_Delay(10);
    }

    return 0;
}
