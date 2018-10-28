#include "snake.h"
int main()
{
    //char key;
    srand(time(0));
    char answer;

    do {
    Board board;
    //Snake* snake = new Snake[length];
    Snake snake;
    //Body snake[100];
    Food food;
    gotoxy(snake.GetTab(0).GetX(),snake.GetTab(0).GetY());
    //char tab[board.GetW()][board.GetH()];
    while(snake.GetTab(0).GetX() < board.GetW()-2 && snake.GetTab(0).GetX() > 1 && snake.GetTab(0).GetY() < board.GetH()/2.5 && snake.GetTab(0).GetY() > 0)
    {

        if(board.GetO() == 1)
        {
            if(snake.Move(board, food) == 1)
                break;
            gotoxy(board.GetW()/2.5,board.GetH()/2.5 + 1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            cout << "SCORE: " << snake.GetL();
        }
        else if(board.GetO() == 2)
        {
            Snake snake2;
            if(snake.Move(board, food) == 1 && snake2.Move(board, food) == 1)
                break;
            gotoxy(board.GetW()/2.5,board.GetH()/2.5 + 1);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
            cout << "SCORE: " << snake.GetL();
        }
        else if(board.GetO() == 3)
        {
            if(snake.Autonomous(board, food) == 1)
                break;

        }
    }
    //delete [] snake;
    board.GameOver(snake);
    //Sleep(1000);
    cout << "Do you want to play again? (y/n) ";
    cin >> answer;
    system("cls");
    }while(answer == 'y');

    return 0;
}
