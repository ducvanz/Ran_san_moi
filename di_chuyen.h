#ifndef DI_CHUYEN_H_INCLUDED
#define DI_CHUYEN_H_INCLUDED
void di_chuyen()
{
    switch (e.key.keysym.sym) {
        case SDLK_0:
        if(thao_tac_game==2||thao_tac_game==3) thao_tac_game=0;
        break;
        case SDLK_1:
            if(thao_tac_game==2)
            {
                dlay=100;
                thao_tac_game=0;
                break;
            }
            if(thao_tac_game==0) thao_tac_game=1;
            break;
        case SDLK_2:
            if(thao_tac_game==2)
            {
                dlay=70;
                thao_tac_game=0;
                break;
            }
            if(thao_tac_game==0) thao_tac_game=2;
            break;
        case SDLK_3:
            if(thao_tac_game==2)
            {
                dlay=50;
                thao_tac_game=0;
                break;
            }
            if(thao_tac_game==0) thao_tac_game=3;
            break;
        case SDLK_LEFT:
            if (direction != 'r')
            {
                    direction = 'l';
                    image_head = "head_left.png";
            }
        break;
        case SDLK_RIGHT:
            if (direction != 'l')
            {
                    direction = 'r';
                    image_head = "head_right.png";
            }
        break;
        case SDLK_UP:
             if (direction != 'd')
             {
                    direction = 'u';
                image_head = "head_up.png";
             }
        break;
        case SDLK_DOWN:
            if (direction != 'u')
            {
                    direction = 'd';
                    image_head = "head_down.png";
            }

            break;
        }
}

void nhay(int &stepX,int &stepY)
{
        switch (direction)
        {
        case 'r':
            stepX = step;
            break;
        case 'l':
            stepX = -step;
            break;
        case 'u':
            stepY = -step;
            break;
        case 'd':
            stepY = step;
            break;
        }
}
void cap_nhat_vi_tri(int stepX,int stepY)
{
        for (int i = snake.size() - 1; i >= 1; i--)
        {
            snake[i].x = snake[i - 1].x;
            snake[i].y = snake[i - 1].y;
        }

        snake[0].x += stepX;
        snake[0].y += stepY;
}
#endif // DI_CHUYEN_H_INCLUDED
