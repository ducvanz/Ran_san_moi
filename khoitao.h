#ifndef KHOITAO_H_INCLUDED
#define KHOITAO_H_INCLUDED
#include <iostream>
#include <vector>
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include<SDL_mixer.h>
#include<SDl_ttf.h>

using namespace std;

string image_head="head_right.png";
string qua="saurieng.png";
string than_ran="than_ran.png";
const char* eat="eatFood.wav";
const char* endgame="endGame.wav";
const char* fon="Outwrite.ttf";

// bien game over
bool validDirection = true;
bool wallCollision =true;
bool selfCollision=true;
// he so delay
int dlay= 100;

//bien chi thao tac dieu huong
int thao_tac_game=0;

// Diem cua nguoi choi
int score = 0;
int highScore=0;

// Cac hang so
const int r = 12;
const int p = 2 * r;
const int step = 20;
const int width = 800;
const int height = 600;

bool test = true;
// Khai bao SDL
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

// Background
const char* image = "background.png";
SDL_Texture* backgroundTexture = NULL;

const char* imageMenu="backgroundMenu.png";
SDL_Texture* backgroundMenu = NULL;
const char* play="huong_dan.png";
SDL_Texture* to_play=NULL;

// Texture cho đầu rắn
SDL_Texture* headTexture = NULL;
// Texture cho thân rắn
SDL_Texture* thanTexture = NULL;
// Texture cho quả sầu riêng
SDL_Texture* pineappleTexture = NULL;

// phong chu
TTF_Font* font=nullptr;
 // Màu văn bản là đen
SDL_Color textColor = {0, 0, 0};
// in diem len man hình
string scoreText = "Score: " + to_string(score);
string HighScore = "High Score: " + to_string(highScore);

// Toa do ran, qua bong
struct Circle {
    int x, y;
};

// Dot cua con ran
vector<Circle> snake;

// Qua bong nho
Circle ball;

// Qua bong lon
Circle bigBall;

// cac bien trong ham main
    SDL_Event e;//
    char direction = 'r'; //huong di chuyen
    bool quit = false;// thoat sdl
    int count = 0;//dem so lan an bong


// Khởi tạo SDL_mixer
void initSDL_mixer() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        printf("Lỗi khi khởi tạo SDL_mixer: %s\n", Mix_GetError());
    }
}

// khoi taoj SDL_ttf
void initSDL_ttf()
{
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    }
}

// Hàm load font từ file
TTF_Font* loadFontFromFile(const char* filePath, int fontSize) {
    // Load font từ tệp tin .ttf với kích thước fontSize
    TTF_Font* font = TTF_OpenFont(filePath, fontSize);
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
    }
    return font;
}
#endif // KHOITAO_H_INCLUDED
