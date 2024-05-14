#ifndef AN_BONG_H_INCLUDED
#define AN_BONG_H_INCLUDED

void bong_nho()
{
    if (snake.front().x >= ball.x - 15 && snake.front().x <= ball.x + 15 &&
        snake.front().y >= ball.y - 15 && snake.front().y <= ball.y + 15) {
        score += 5;
        snake.push_back(snake.back());
        placeBall();
        count++;
        playSound(eat);
    }

}

void bong_lon(int tm)
{
    if (snake.front().x >= bigBall.x - p - 5 && snake.front().x <= bigBall.x + p - 5 &&
    snake.front().y >= bigBall.y - p - 5 && snake.front().y <= bigBall.y + p - 5&&test) {
            if (tm <= 10) score += 50;
            else if (tm <= 20) score += 30;
            else if (tm <= 35) score += 20;
            else score += 10;
            bigBall.x = 0;
            bigBall.y = 0;
            test=false;
            tm=0;
            playSound(eat);
        }
}
#endif // AN_BONG_H_INCLUDED
