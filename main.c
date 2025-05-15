#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

int main(int argc, char const *argv[])
{

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Texture *texture = NULL;
    SDL_FRect rect;
    rect.x = 0;
    rect.y = 0;
    int width = 100 * 16;
    int height = 56.25 * 16;
    rect.w = width;
    rect.h = height;
    bool quit = false;
    bool team_red = false;

    SDL_SetAppMetadata("Sky Vincent SDL Game", "1.0", "com.skyvincent.sdl-game");

    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    }

    if (!SDL_CreateWindowAndRenderer("SDL Game", width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_TRANSPARENT, &window, &renderer))
    {
        SDL_Log("Failed to create window and/or renderer", SDL_GetError());
    }

    texture = IMG_LoadTexture(renderer, "../resources/blue.png");
    if (!texture)
    {
        SDL_Log("No Image: %s", SDL_GetError());
    }

    while (!quit)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                quit = true;
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColorFloat(renderer, 0.0f, 0.0f, 0.0f, 0.0f);
        SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
        SDL_RenderTexture(renderer, texture, NULL, &rect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
