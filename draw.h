#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

#include "mylib.h"


//
int load_back()
{
        // Load background
    SDL_Surface* surface = IMG_Load(image);
    if (surface == NULL)
    {
        cout << "Khong mo duoc background: " << SDL_GetError() << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return 0;
}
//
int load_back_menu()
{
        // Load background
    SDL_Surface* surface_menu = IMG_Load(imageMenu);
    if (surface_menu == NULL)
    {
        cout << "Khong mo duoc background: " << SDL_GetError() << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    backgroundMenu = SDL_CreateTextureFromSurface(renderer, surface_menu);
    SDL_FreeSurface(surface_menu);
    return 0;
}
//
int load_back_play()
{
        // Load background
    SDL_Surface* surface_play = IMG_Load(play);
    if (surface_play == NULL)
    {
        cout << "Khong mo duoc background play: " << SDL_GetError() << endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    to_play = SDL_CreateTextureFromSurface(renderer, surface_play);
    SDL_FreeSurface(surface_play);
    return 0;
}

// Hàm render text lên renderer
bool renderText( const char* text, int x, int y) {
    // Tạo bề mặt chứa văn bản
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == NULL) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    // Tạo texture từ bề mặt văn bản
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
        printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        SDL_FreeSurface(textSurface); // Giải phóng bề mặt văn bản nếu không thể tạo texture
        return false;
    }

    // Lấy kích thước của văn bản
    int textWidth = textSurface->w;
    int textHeight = textSurface->h;

    // Xóa bề mặt không cần thiết
    SDL_FreeSurface(textSurface);

    // Vị trí của văn bản trên cửa sổ
    SDL_Rect textRect = {x, y, textWidth, textHeight}; // X, Y, Width, Height

    // Vẽ văn bản lên renderer
    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    // Giải phóng texture văn bản
    SDL_DestroyTexture(textTexture);

    return true;
}

// Hàm hiển thị menu
void showMenu() {
    // Ve background len cua so
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Ve background
    SDL_RenderCopy(renderer, backgroundMenu, NULL, NULL);

    // In các mục menu
    renderText("Menu", 350, 120);
    renderText("1. Start Game", 300, 200);
    renderText("2. Level", 300, 250);
    renderText("3. How to play ?", 300, 300);

    // Update màn hình
    SDL_RenderPresent(renderer);
}

//
// how to play
void huongdan() {
    // Ve background len cua so
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Ve background
    SDL_RenderCopy(renderer, to_play, NULL, NULL);

    // In các mục menu
    renderText(" chon 0 de quay lai",500,550);

    // Update màn hình
    SDL_RenderPresent(renderer);
}

//
void level()
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // In các mục menu
    renderText("1. Easy", 300, 150);
    renderText("2. Medium", 300, 200);
    renderText("3. Hard", 300, 250);
    renderText("0. Exit", 300, 300);
    // Update màn hình
    SDL_RenderPresent(renderer);

}
// Ve lai sau moi thao tac
void draw(int x, int y) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Ve background
    SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

    // ve diem len man hinh
    scoreText = "Score: " + to_string(score);
    HighScore = "High Score: " + to_string(highScore);
    renderText( scoreText.c_str(), 10, 10);
    renderText( HighScore.c_str(), 580, 10);

    // Ve ran
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 1; i < snake.size(); ++i) {
        SDL_Rect destRect = { snake[i].x - r, snake[i].y - r, 2 * r, 2 * r };
        SDL_RenderCopy(renderer, thanTexture, NULL, &destRect);
    }

    // Ve qua bong nho
    SDL_Rect ballRect = { ball.x - r, ball.y - r, 2 * r, 2 * r };
    SDL_RenderCopy(renderer, pineappleTexture, NULL, &ballRect);

    // Ve qua bong lon
    if ((bigBall.x != 0 || bigBall.y != 0) && test) {
        SDL_Rect bigBallRect = { bigBall.x - p, bigBall.y - p, 2 * p, 2 * p };
        SDL_RenderCopy(renderer, pineappleTexture, NULL, &bigBallRect);
    }

    // Ve dau ran
    SDL_Rect headRect = { x - r, y - r, 2 * r , 2 * r  };
    SDL_RenderCopy(renderer, headTexture, NULL, &headRect);

    SDL_RenderPresent(renderer);
}

// Random vi tri qua bong
void placeBall() {
    srand(time(0));
    ball.x = rand() % (width - 2 * r) + r;
    ball.y = rand() % (height - 2 * r-10) + r+10;
}

// Random qua bong lon
Circle randomBigBall() {
    Circle bigball;
    srand(time(0));
    bigball.x = rand() % (width - 2 * p) + p;
    bigball.y = rand() % (height - 2 * p-10) + p+10;

    bool check = true;
    for (Circle c : snake) {
        if ((bigball.x >= c.x - r && bigball.x <= c.x + r) && (bigball.y >= c.y - r && bigball.y <= c.y + r)) {
            return randomBigBall();
        }
    }

    return bigball;
}

#endif // DRAW_H_INCLUDED
