#ifndef SNAKE_H
#define SNAKE_H
#include<iostream>
#include<cstdio>
#include<windows.h>
#include<time.h>
#include<conio.h>
#define AV_SPEED 1
#define AH_SPEED 1
#define SPEED 50
using std::cout;
using std::cin;
using std::endl;

void gotoxy(int x, int y);
class Board;
class Food;
class Body
{
//private:
public:
    int x_pos;
    int y_pos;
    //int length;
    int speed;
public:
    void move_right()
    {
        x_pos++;
    }
    void move_left()
    {
        x_pos--;
    }
    void move_up()
    {
        y_pos--;
    }
    void move_down()
    {
        y_pos++;
    }
    int GetX()
    {
        return x_pos;
    }
    int GetY()
    {
        return y_pos;
    }
    int GetS()
    {
        return speed;
    }
    void SpeedUp()
    {
        if(speed > 100)
            speed -= 100;
    }
    void Draw();
    void Empty();
    bool GetFood(Food& f);
    Body(int x = 25, int y = 10, int s = 10);
};
class Snake
{
private:
    Body tab[100];
    int length;
    bool path;
public:
    Snake(int l = 1);
    Body GetTab(int n);
    int Move(Board& board, Food& food);
    int GetL() const;
    int Autonomous(Board& board, Food& food);
};
class Board
{
    //friend class Snake;
private:
    int height;
    int width;
    int option;
public:
    int GetW()
    {
        return width;
    }
    int GetH()
    {
        return width;
    }
    void Draw(int h = 20, int w = 50);
    Board(int h = 20, int w = 50);
    void GameOver(const Snake& snake);
    int GetO()
    {
        return option;
    }

};

class Food
{
private:
    int x_pos;
    int y_pos;
public:
    Food(int x = rand() % 46 + 2, int y = 6 + 2);
    void Draw(int x,int y);
    int GetX()
    {
        return x_pos;
    }
    int GetY()
    {
        return y_pos;
    }
};

#endif // SNAKE_H
