
#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
//
#include"khoitao.h"
#include"xuly_anh.h"
#include"mylib.h"
#include"draw.h"
#include"di_chuyen.h"
#include"an_bong.h"

// Kiem tra ran dam vao tuong
bool testWallCollision() {
    int m = snake[0].x;
    int n = snake[0].y;
    return (m >= r/2 && m <= width - r/2 && n >= r/2 && n <= height - r/2);
}

// Kiem tra ran cham vao than no
bool testSelfCollision() {
    for (int i = 1; i < snake.size(); ++i) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            return false;
        }
    }
    return true;
}


//
int mo_sdl()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Khong mo duoc SDL: " << SDL_GetError() << endl;
        return 1;
    }

    window = SDL_CreateWindow("\t \t Ran san moi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        cout << "Khong mo duoc cua so: " << SDL_GetError() << endl;
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        cout << "Khong tao duoc but ve: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    return 0;
}

//
void ket_thuc()
{
    Mix_CloseAudio();
    SDL_DestroyTexture(pineappleTexture);
    SDL_DestroyTexture(headTexture);
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

//
void khoi_tao_first()
{
        // Mo dau tro choi voi 1 con ran 3 khuc
    Circle head = { 50, height / 2 };
    snake.push_back(head);
    snake.push_back({ 30, height / 2 });
    snake.push_back({ 10, height / 2 });

    // Random vi tri qua bong
    placeBall();

    // Ve con ran ban dau
    draw(head.x, head.y);
}


// khoi tao lai game
void reset()
{
    if(highScore>score) highScore=score;
    snake.clear();
    khoi_tao_first();
    thao_tac_game=0;
    score=0;
    validDirection=true;
    wallCollision=true;
    selfCollision=true;
    image_head="head_right.png";
    direction = 'r';
    count = 0;
}
#endif
