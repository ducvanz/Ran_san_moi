#include"khoitao.h"
#ifndef XULY_ANH_H_INCLUDED
#define XULY_ANH_H_INCLUDED
// Load hình ảnh từ file
SDL_Texture* loadTexture(string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (surface == NULL) {
        cerr << "Khong the tai texture " << path << "! SDL_image Error: " << IMG_GetError() << endl;
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
void k_tr()
{
    if (pineappleTexture == NULL) {
        SDL_DestroyTexture(headTexture);
        SDL_DestroyTexture(backgroundTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
}

// Tải âm thanh và phát
void playSound(const char* path) {
    Mix_Chunk* chunk = Mix_LoadWAV(path);
    if (!chunk) {
        printf("loi tai am thanh: %s\n", Mix_GetError());
        return;
    }

    // Phát âm thanh
    Mix_PlayChannel(-1, chunk, 0);

    // Đợi cho đến khi âm thanh kết thúc
    while (Mix_Playing(-1)) {
        SDL_Delay(0.1);
    }

    // Giải phóng bộ nhớ
    Mix_FreeChunk(chunk);

}


#endif // XULY_ANH_H_INCLUDED
