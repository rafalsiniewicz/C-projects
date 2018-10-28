#include "snake.h"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Body:: Body(int x, int y, int s): x_pos(x), y_pos(y), speed(s)
{
    gotoxy(x_pos,y_pos);
    cout << '*';

}

void Body:: Draw()
{
    //system("cls");
    gotoxy(x_pos,y_pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xe);
    cout <<  '*';
}
void Body:: Empty()
{
    //system("cls");
    gotoxy(x_pos,y_pos);
    //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xe);
    cout <<  ' ';
}
bool Body::GetFood(Food& f)
{
    if(x_pos == f.GetX() && y_pos == f.GetY())
        return true;
}
Snake::Snake(int l):length(l)
{
}
Body Snake:: GetTab(int n)
{
    return tab[n];
}
int Snake:: Move(Board& board, Food& food)
{
    static unsigned int counter = 0;
    static bool U, D, L, R;
    if(counter == 0)
    {
        U = L = D = R = 0;
        counter++;
    }
    switch(_getch())
    {
    case 80: //DOWN

d:
        if(U == 0)
        {
            U = L = R = 0;
            D = 1;
            for(int i = 0; i < length; i++)
                tab[i].speed = 80;
            while(tab[0].GetY() < board.GetH()/2.5)
            {
                for(int i = 4; i < length; i++)
                    if(tab[0].GetX() == tab[i].GetX() && tab[0].GetY() == tab[i].GetY())
                        return 1;
                //goto ex;
                int tempx[length];
                int tempy[length];
                for(int i = 0; i < length; i++)
                {
                    tempx[i] = tab[i].x_pos;
                    tempy[i] = tab[i].y_pos;
                }
                tab[0].Empty();
                tab[0].move_down();
                tab[0].Draw();
                for(int i = 1; i < length; i++)
                {
                    tab[i].Empty();
                    tab[i].x_pos = tempx[i-1];
                    tab[i].y_pos = tempy[i-1];
                    tab[i].Draw();
                }
                if(tab[0].GetFood(food))
                {

                    int a = rand() % (board.GetW()-4) + 2;
                    int b = rand() % int(board.GetH()/2.5 - 2) + 2;
                    food.Draw(a, b);
                    for(int i = 0; i < length; i++)
                        if(tab[i].x_pos == a && tab[i].y_pos == b)
                        {
                            a = rand() % (board.GetW()-4) + 2;
                            b = rand() % int(board.GetH()/2.5 - 2) + 2;
                            food.Draw(a, b);
                        }
                    /*tab temp[length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length; i++)
                    {
                        temp[i].x_pos = tab[i].x_pos;
                        temp[i].y_pos = tab[i].y_pos;
                        temp[i].speed = tab[i].speed;
                    }
                    delete [] tab;
                    tab* tab = new tab[++length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length - 1; i++)
                    {
                        tab[i].x_pos = temp[i].x_pos;
                        tab[i].y_pos = temp[i].y_pos;
                        tab[i].speed = temp[i].speed;
                    }
                    //delete [] temp;*/
                    length++;
                    tab[length - 1].x_pos = tab[length-2].x_pos;
                    tab[length - 1].y_pos = tab[length-2].y_pos - 1;
                    tab[length - 1].speed = tab[length-2].speed;
                    //delete [] temp;
                    gotoxy(tab[0].x_pos, tab[0].y_pos);

                }
                Sleep(tab[0].GetS());
                if(_kbhit())
                    break;
            }
        }
        else
            goto u;
        break;

    case 72: //UP

        //while(1)
u:
        if(D == 0)
        {
            D = L = R = 0;
            U = 1;
            for(int i = 0; i < length; i++)
                tab[i].speed = 80;
            while(tab[0].GetY() > 0)
            {

                //Sleep(100);
                for(int i = 4; i < length; i++)
                    if(tab[0].GetX() == tab[i].GetX() && tab[0].GetY() == tab[i].GetY())
                        return 1;
                int tempx[length];
                int tempy[length];
                for(int i = 0; i < length; i++)
                {
                    tempx[i] = tab[i].x_pos;
                    tempy[i] = tab[i].y_pos;
                }
                tab[0].Empty();
                tab[0].move_up();
                tab[0].Draw();
                for(int i = 1; i < length; i++)
                {
                    tab[i].Empty();
                    tab[i].x_pos = tempx[i-1];
                    tab[i].y_pos = tempy[i-1];
                    tab[i].Draw();
                }
                if(tab[0].GetFood(food))
                {


                    int a = rand() % (board.GetW()-4) + 2;
                    int b = rand() % int(board.GetH()/2.5 - 2) + 2;
                    food.Draw(a, b);
                    for(int i = 0; i < length; i++)
                        if(tab[i].x_pos == a && tab[i].y_pos == b)
                        {
                            a = rand() % (board.GetW()-4) + 2;
                            b = rand() % int(board.GetH()/2.5 - 2) + 2;
                            food.Draw(a, b);
                        }
                    /*tab temp[length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length; i++)
                    {
                        temp[i].x_pos = tab[i].x_pos;
                        temp[i].y_pos = tab[i].y_pos;
                        temp[i].speed = tab[i].speed;
                    }
                    delete [] tab;
                    tab* tab = new tab[++length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length - 1; i++)
                    {
                        tab[i].x_pos = temp[i].x_pos;
                        tab[i].y_pos = temp[i].y_pos;
                        tab[i].speed = temp[i].speed;
                    }
                    //delete [] temp;*/
                    length++;
                    tab[length - 1].x_pos = tab[length-2].x_pos;
                    tab[length - 1].y_pos = tab[length-2].y_pos + 1;
                    tab[length - 1].speed = tab[length-2].speed;
                    //delete [] temp;
                }
                Sleep(tab[0].GetS());
                if(_kbhit())
                    break;
            }
        }
        else
            goto d;
        //Sleep(1000);
        break;


    case 75: //LEFT

l:
        if(R == 0)
        {
            D = U = R = 0;
            L = 1;
            for(int i = 0; i < length; i++)
                tab[i].speed = 50;
            while(tab[0].GetX() > 1)
            {
                for(int i = 4; i < length; i++)
                    if(tab[0].GetX() == tab[i].GetX() && tab[0].GetY() == tab[i].GetY())
                        return 1;
                int tempx[length];
                int tempy[length];
                for(int i = 0; i < length; i++)
                {
                    tempx[i] = tab[i].x_pos;
                    tempy[i] = tab[i].y_pos;
                }
                tab[0].Empty();
                tab[0].move_left();
                tab[0].Draw();
                for(int i = 1; i < length; i++)
                {
                    tab[i].Empty();
                    tab[i].x_pos = tempx[i-1];
                    tab[i].y_pos = tempy[i-1];
                    tab[i].Draw();
                }

                if(tab[0].GetFood(food))
                {


                    int a = rand() % (board.GetW()-4) + 2;
                    int b = rand() % int(board.GetH()/2.5 - 2) + 2;
                    food.Draw(a, b);
                    for(int i = 0; i < length; i++)
                        if(tab[i].x_pos == a && tab[i].y_pos == b)
                        {
                            a = rand() % (board.GetW()-4) + 2;
                            b = rand() % int(board.GetH()/2.5 - 2) + 2;
                            food.Draw(a, b);
                        }
                    /*tab temp[length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length; i++)
                    {
                        temp[i].x_pos = tab[i].x_pos;
                        temp[i].y_pos = tab[i].y_pos;
                        temp[i].speed = tab[i].speed;
                    }
                    delete [] tab;
                    tab* tab = new tab[++length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length - 1; i++)
                    {
                        tab[i].x_pos = temp[i].x_pos;
                        tab[i].y_pos = temp[i].y_pos;
                        tab[i].speed = temp[i].speed;
                    }
                    //delete [] temp;*/
                    length++;
                    tab[length - 1].x_pos = tab[length-2].x_pos - 1;
                    tab[length - 1].y_pos = tab[length-2].y_pos ;
                    tab[length - 1].speed = tab[length-2].speed;
                    //delete [] temp;
                }
                Sleep(tab[0].GetS());
                if(_kbhit())
                    break;
            }
        }
        else
            goto r;
        break;

    case 77: //RIGHT

r:
        if(L == 0)
        {
            D = U = L = 0;
            R = 1;
            for(int i = 0; i < length; i++)
                tab[i].speed = 50;
            while(tab[0].GetX() < board.GetW() - 2)
            {
                for(int i = 4; i < length; i++)
                    if(tab[0].GetX() == tab[i].GetX() && tab[0].GetY() == tab[i].GetY())
                        return 1;
                int tempx[length];
                int tempy[length];
                for(int i = 0; i < length; i++)
                {
                    tempx[i] = tab[i].x_pos;
                    tempy[i] = tab[i].y_pos;
                }
                tab[0].Empty();
                tab[0].move_right();
                tab[0].Draw();
                for(int i = 1; i < length; i++)
                {
                    tab[i].Empty();
                    tab[i].x_pos = tempx[i-1];
                    tab[i].y_pos = tempy[i-1];
                    tab[i].Draw();
                }
                if(tab[0].GetFood(food))
                {

                    int a = rand() % (board.GetW()-4) + 2;
                    int b = rand() % int(board.GetH()/2.5 - 2) + 2;
                    food.Draw(a, b);
                    for(int i = 0; i < length; i++)
                        if(tab[i].x_pos == a && tab[i].y_pos == b)
                        {
                            a = rand() % (board.GetW()-4) + 2;
                            b = rand() % int(board.GetH()/2.5 - 2) + 2;
                            food.Draw(a, b);
                        }
                    /*tab temp[length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length; i++)
                    {
                        temp[i].x_pos = tab[i].x_pos;
                        temp[i].y_pos = tab[i].y_pos;
                        temp[i].speed = tab[i].speed;
                    }
                    delete [] tab;
                    tab* tab = new tab[++length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length - 1; i++)
                    {
                        tab[i].x_pos = temp[i].x_pos;
                        tab[i].y_pos = temp[i].y_pos;
                        tab[i].speed = temp[i].speed;
                    }
                    //delete [] temp;*/
                    length++;
                    tab[length - 1].x_pos = tab[length-2].x_pos + 1;
                    tab[length - 1].y_pos = tab[length-2].y_pos;
                    tab[length - 1].speed = tab[length-2].speed;
                    //delete [] temp;
                }
                Sleep(tab[0].GetS());
                if(_kbhit())
                    break;
            }
        }
        else
            goto l;
        break;
        /*case 52:
            cout << "a";
        default:
            cout << "a";
        */

        /*default:
            if (D == 1)
                goto x;
            else if ( U == 1)
                goto y;
            else if ( R == 1)
                goto z;
            else if ( L == 1)
                goto q;
            break;
        */
    }
    return 0;
}
int Snake:: Autonomous(Board& board, Food& food)
{
    static unsigned int counter = 0;
    bool U, D, L, R;
    if(counter == 0)
    {
        U = L = D = R = 0;
        counter++;
    }
da:

    while(tab[0].GetY() < food.GetY()) //DOWN

    {
        path = 0;
        for(int i = 1; i < length; i++)
        {
            for(int j = 1; j < length/4; j++)
            {
                if(tab[0].GetY() == tab[i].GetY() - j  && tab[0].GetX() == tab[i].GetX())
                {
                    path = 1;
                    break;
                }
            }
        }
        //cout << "a";
        if(U == 0)
        {

            if(path == 0)
            {
aa:
                U = L = R = 0;
                D = 1;
                if(length < 100)
                {
                    for(int i = 0; i < length; i++)
                        tab[i].speed = AV_SPEED;
                }
                else
                {
                    for(int i = 0; i < length; i++)
                        tab[i].speed = AV_SPEED + 100;
                }

                for(int i = 4; i < length; i++)
                    if(tab[0].GetX() == tab[i].GetX() && tab[0].GetY() == tab[i].GetY())
                        return 1;
                //goto ex;
                int tempx[length];
                int tempy[length];
                for(int i = 0; i < length; i++)
                {
                    tempx[i] = tab[i].x_pos;
                    tempy[i] = tab[i].y_pos;
                }
                tab[0].Empty();
                tab[0].move_down();
                tab[0].Draw();
                for(int i = 1; i < length; i++)
                {
                    tab[i].Empty();
                    tab[i].x_pos = tempx[i-1];
                    tab[i].y_pos = tempy[i-1];
                    tab[i].Draw();
                }
                if(tab[0].GetFood(food))
                {

                    int a = rand() % (board.GetW()-4) + 2;
                    int b = rand() % int(board.GetH()/2.5 - 2) + 2;
                    food.Draw(a, b);
                    for(int i = 0; i < length; i++)
                        if(tab[i].x_pos == a && tab[i].y_pos == b)
                        {
                            a = rand() % (board.GetW()-4) + 2;
                            b = rand() % int(board.GetH()/2.5 - 2) + 2;
                            food.Draw(a, b);
                        }
                    /*tab temp[length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length; i++)
                    {
                        temp[i].x_pos = tab[i].x_pos;
                        temp[i].y_pos = tab[i].y_pos;
                        temp[i].speed = tab[i].speed;
                    }
                    delete [] tab;
                    tab* tab = new tab[++length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length - 1; i++)
                    {
                        tab[i].x_pos = temp[i].x_pos;
                        tab[i].y_pos = temp[i].y_pos;
                        tab[i].speed = temp[i].speed;
                    }
                    //delete [] temp;*/
                    length++;
                    tab[length - 1].x_pos = tab[length-2].x_pos;
                    tab[length - 1].y_pos = tab[length-2].y_pos - 1;
                    tab[length - 1].speed = tab[length-2].speed;
                    //delete [] temp;
                    gotoxy(tab[0].x_pos, tab[0].y_pos);

                }
                Sleep(tab[0].GetS());

            }
            else
            {
                path = 0;
                for(int i = 1; i < length; i++)
                {
                    for(int j = 1; j < length/8; j++)
                    {
                        if(tab[0].GetY() == tab[i].GetY()  && tab[0].GetX() == tab[i].GetX() - j && tab[0].GetX() > 0)
                        {
                            goto ba;
                        }
                    }
                }
                //path = 0;
                goto ca;
            }

        }
        else if(U == 1 && tab[0].GetX() == food.GetX())
            goto ba;
        else
            goto da;



    }
ua:
    while(tab[0].GetY() > food.GetY()) //UP
        // && tab[0].GetY() > 0
    {
        path = 0;
        for(int i = 1; i < length; i++)
        {
            for(int j = 1; j < length/4; j++)
            {
                if(tab[0].GetY() == tab[i].GetY() + j && tab[0].GetX() == tab[i].GetX())
                {
                    //cout << "c";
                    path = 1;
                    break;
                }
            }
        }

        if(D == 0)
        {

            if(path == 0)
            {
ea:
                D = L = R = 0;
                U = 1;
                if(length < 100)
                {
                    for(int i = 0; i < length; i++)
                        tab[i].speed = AV_SPEED;
                }
                else
                {
                    for(int i = 0; i < length; i++)
                        tab[i].speed = AV_SPEED + 100;
                }


                //Sleep(100);
                for(int i = 4; i < length; i++)
                    if(tab[0].GetX() == tab[i].GetX() && tab[0].GetY() == tab[i].GetY())
                        return 1;
                int tempx[length];
                int tempy[length];
                for(int i = 0; i < length; i++)
                {
                    tempx[i] = tab[i].x_pos;
                    tempy[i] = tab[i].y_pos;
                }
                tab[0].Empty();
                tab[0].move_up();
                tab[0].Draw();
                for(int i = 1; i < length; i++)
                {
                    tab[i].Empty();
                    tab[i].x_pos = tempx[i-1];
                    tab[i].y_pos = tempy[i-1];
                    tab[i].Draw();
                }
                if(tab[0].GetFood(food))
                {


                    int a = rand() % (board.GetW()-4) + 2;
                    int b = rand() % int(board.GetH()/2.5 - 2) + 2;
                    food.Draw(a, b);
                    for(int i = 0; i < length; i++)
                        if(tab[i].x_pos == a && tab[i].y_pos == b)
                        {
                            a = rand() % (board.GetW()-4) + 2;
                            b = rand() % int(board.GetH()/2.5 - 2) + 2;
                            food.Draw(a, b);
                        }
                    /*tab temp[length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length; i++)
                    {
                        temp[i].x_pos = tab[i].x_pos;
                        temp[i].y_pos = tab[i].y_pos;
                        temp[i].speed = tab[i].speed;
                    }
                    delete [] tab;
                    tab* tab = new tab[++length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length - 1; i++)
                    {
                        tab[i].x_pos = temp[i].x_pos;
                        tab[i].y_pos = temp[i].y_pos;
                        tab[i].speed = temp[i].speed;
                    }
                    //delete [] temp;*/
                    length++;
                    tab[length - 1].x_pos = tab[length-2].x_pos;
                    tab[length - 1].y_pos = tab[length-2].y_pos + 1;
                    tab[length - 1].speed = tab[length-2].speed;
                    //delete [] temp;
                }
                Sleep(tab[0].GetS());


            }

            else
            {
                path = 0;
                for(int i = 1; i < length; i++)
                {
                    for(int j = 1; j < length/8; j++)
                    {
                        if(tab[0].GetY() == tab[i].GetY()  && tab[0].GetX() == tab[i].GetX() - j && tab[0].GetX() > 0)
                        {
                            goto ba;
                        }
                    }
                }
                //path = 0;
                goto ca;
            }
        }
        else if(D == 1 && tab[0].GetX() == food.GetX())
            goto ba;
        else
            goto la;
        //Sleep(1000);

    }

la:
    while(tab[0].GetX() > food.GetX()) //LEFT
        // && tab[0].GetX() > 1
    {
        path = 0;
        for(int i = 1; i < length; i++)
        {
            for(int j = 1; j < length/4; j++)
            {
                if(tab[0].GetY() == tab[i].GetY()  && tab[0].GetX() == tab[i].GetX() + j)
                {
                    path = 1;
                    break;
                }
            }
        }



        if(R == 0)
        {
            if(path == 0)
            {
ba:
                D = U = R = 0;
                L = 1;
                if(length < 100)
                {
                    for(int i = 0; i < length; i++)
                        tab[i].speed = AV_SPEED;
                }
                else
                {
                    for(int i = 0; i < length; i++)
                        tab[i].speed = AV_SPEED + 100;
                }

                for(int i = 4; i < length; i++)
                    if(tab[0].GetX() == tab[i].GetX() && tab[0].GetY() == tab[i].GetY())
                        return 1;
                int tempx[length];
                int tempy[length];
                for(int i = 0; i < length; i++)
                {
                    tempx[i] = tab[i].x_pos;
                    tempy[i] = tab[i].y_pos;
                }
                tab[0].Empty();
                tab[0].move_left();
                tab[0].Draw();
                for(int i = 1; i < length; i++)
                {
                    tab[i].Empty();
                    tab[i].x_pos = tempx[i-1];
                    tab[i].y_pos = tempy[i-1];
                    tab[i].Draw();
                }

                if(tab[0].GetFood(food))
                {


                    int a = rand() % (board.GetW()-4) + 2;
                    int b = rand() % int(board.GetH()/2.5 - 2) + 2;
                    food.Draw(a, b);
                    for(int i = 0; i < length; i++)
                        if(tab[i].x_pos == a && tab[i].y_pos == b)
                        {
                            a = rand() % (board.GetW()-4) + 2;
                            b = rand() % int(board.GetH()/2.5 - 2) + 2;
                            food.Draw(a, b);
                        }
                    /*tab temp[length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length; i++)
                    {
                        temp[i].x_pos = tab[i].x_pos;
                        temp[i].y_pos = tab[i].y_pos;
                        temp[i].speed = tab[i].speed;
                    }
                    delete [] tab;
                    tab* tab = new tab[++length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length - 1; i++)
                    {
                        tab[i].x_pos = temp[i].x_pos;
                        tab[i].y_pos = temp[i].y_pos;
                        tab[i].speed = temp[i].speed;
                    }
                    //delete [] temp;*/
                    length++;
                    tab[length - 1].x_pos = tab[length-2].x_pos - 1;
                    tab[length - 1].y_pos = tab[length-2].y_pos ;
                    tab[length - 1].speed = tab[length-2].speed;
                    //delete [] temp;
                }
                Sleep(tab[0].GetS());


            }
            else
            {
                path = 0;
                for(int i = 1; i < length; i++)
                {
                    for(int j = 1; j < length/8; j++)
                    {
                        if(tab[0].GetY() == tab[i].GetY() + j && tab[0].GetX() == tab[i].GetX() && tab[0].GetY() < board.GetH()/2.5)
                        {
                            goto aa;
                        }
                    }
                }
                //path = 0;
                goto ea;
            }

        }
        else if(R == 1 && tab[0].GetY() == food.GetY())
            goto aa;
        else
            goto da;

    }
ra:
    while(tab[0].GetX() < food.GetX()) //RIGHT
        // && tab[0].GetX() < board.GetW() - 2
    {
        path = 0;
        for(int i = 1; i < length; i++)
        {
            for(int j = 1; j < length/4; j++)
            {
                if(tab[0].GetY() == tab[i].GetY()  && tab[0].GetX() == tab[i].GetX() - j)
                {
                    path = 1;
                    break;
                }
            }
        }

        if(L == 0)
        {


            if(path == 0)
            {
ca:
                D = U = L = 0;
                R = 1;
                if(length < 100)
                {
                    for(int i = 0; i < length; i++)
                        tab[i].speed = AV_SPEED;
                }
                else
                {
                    for(int i = 0; i < length; i++)
                        tab[i].speed = AV_SPEED + 100;
                }

                for(int i = 4; i < length; i++)
                    if(tab[0].GetX() == tab[i].GetX() && tab[0].GetY() == tab[i].GetY())
                        return 1;
                int tempx[length];
                int tempy[length];
                for(int i = 0; i < length; i++)
                {
                    tempx[i] = tab[i].x_pos;
                    tempy[i] = tab[i].y_pos;
                }
                tab[0].Empty();
                tab[0].move_right();
                tab[0].Draw();
                for(int i = 1; i < length; i++)
                {
                    tab[i].Empty();
                    tab[i].x_pos = tempx[i-1];
                    tab[i].y_pos = tempy[i-1];
                    tab[i].Draw();
                }
                if(tab[0].GetFood(food))
                {

                    int a = rand() % (board.GetW()-4) + 2;
                    int b = rand() % int(board.GetH()/2.5 - 2) + 2;
                    food.Draw(a, b);
                    for(int i = 0; i < length; i++)
                        if(tab[i].x_pos == a && tab[i].y_pos == b)
                        {
                            a = rand() % (board.GetW()-4) + 2;
                            b = rand() % int(board.GetH()/2.5 - 2) + 2;
                            food.Draw(a, b);
                        }
                    /*tab temp[length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length; i++)
                    {
                        temp[i].x_pos = tab[i].x_pos;
                        temp[i].y_pos = tab[i].y_pos;
                        temp[i].speed = tab[i].speed;
                    }
                    delete [] tab;
                    tab* tab = new tab[++length];
                    gotoxy(25,10);
                    cout << ' ';
                    for(int i = 0; i < length - 1; i++)
                    {
                        tab[i].x_pos = temp[i].x_pos;
                        tab[i].y_pos = temp[i].y_pos;
                        tab[i].speed = temp[i].speed;
                    }
                    //delete [] temp;*/
                    length++;
                    tab[length - 1].x_pos = tab[length-2].x_pos + 1;
                    tab[length - 1].y_pos = tab[length-2].y_pos;
                    tab[length - 1].speed = tab[length-2].speed;
                    //delete [] temp;
                }
                Sleep(tab[0].GetS());

            }
            else
            {
                path = 0;
                for(int i = 1; i < length; i++)
                {
                    for(int j = 1; j < length/8; j++)
                    {
                        if(tab[0].GetY() == tab[i].GetY() + j && tab[0].GetX() == tab[i].GetX() && tab[0].GetY() < board.GetH()/2.5)
                        {
                            goto aa;
                        }
                    }
                }
                //path = 0;
                goto ea;
            }

        }
        else if(L == 1 && tab[0].GetY() == food.GetY())
            goto aa;
        else
            goto da;

    }

    return 0;
}
int Snake::GetL() const
{
    return length;
}
void Board:: Draw(int h, int w)
{
    gotoxy(0,0);
    Board(h,w);
}

Board:: Board(int h, int w):height(h), width(w)
{
    int answer;
    gotoxy(25,10);
    cout << "SNAKE GAME";
    gotoxy(25,11);
    cout << "CHOOSE OPTION:";
    gotoxy(25,12);
    cout << "1. SINGLE GAME";
    gotoxy(25,13);
    cout << "2. MULTIPLAYER GAME";
    gotoxy(25,14);
    cout << "3. AUTONOMOUS GAME";
    gotoxy(25,15);
    cout << "4. QUIT";
    gotoxy(25,16);
    cin >> answer;
    while(answer < 1 || answer > 4)
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cin.get();
        cin >> answer;
    }
    switch(answer)
    {
    case 1:
        system("cls");
        gotoxy(25,10);
        cout << "Press ENTER to start";
        while(_getch() != 13)
            _getch();
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xe);
        for(int i = 0; i < height; i++)
            cout << "||" << endl;
        gotoxy(0,0);
        for(int i = 0; i < width; i++)
            cout << '=';
        for(int i = 1; i < height; i++)
        {
            gotoxy(width - 2,i);
            cout << "||";
        }
        cout << endl;
        for(int i = 0; i < width; i++)
            cout << '=';
        option = 1;
        break;
    case 2:
        system("cls");
        gotoxy(25,10);
        cout << "Press ENTER to start";
        while(_getch() != 13)
            _getch();
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xe);
        for(int i = 0; i < height; i++)
            cout << "||" << endl;
        gotoxy(0,0);
        for(int i = 0; i < width; i++)
            cout << '=';
        for(int i = 1; i < height; i++)
        {
            gotoxy(width - 2,i);
            cout << "||";
        }
        cout << endl;
        for(int i = 0; i < width; i++)
            cout << '=';
        gotoxy(w+1,1);
        //second board
        for(int i = 0; i < height; i++)
            {
                cout << "||";
                gotoxy(w+1,i+1);
            }
        gotoxy(w + 1,0);
        for(int i = 0; i < width; i++)
            cout << '=';
        for(int i = 1; i < height; i++)
        {
            gotoxy(2*w-1,i);
            cout << "||";
        }
        gotoxy(w+1,h);
        for(int i = 0; i < width; i++)
            cout << '=';
        option = 2;
        break;
    case 3:
        system("cls");
        gotoxy(25,10);
        cout << "Press ENTER to start";
        while(_getch() != 13)
            _getch();
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xe);
        for(int i = 0; i < height; i++)
            cout << "||" << endl;
        gotoxy(0,0);
        for(int i = 0; i < width; i++)
            cout << '=';
        for(int i = 1; i < height; i++)
        {
            gotoxy(width - 2,i);
            cout << "||";
        }
        cout << endl;
        for(int i = 0; i < width; i++)
            cout << '=';
        option = 3;
        break;
    case 4:
        exit(0);
    }
}
void Board:: GameOver(const Snake& snake)
{
    gotoxy(width/2.5,height+1);
    cout << "               ";
    gotoxy(20,10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xc);
    cout << "GAME OVER" << endl;
    gotoxy(20,11);
    cout << "SCORE: " << snake.GetL();
    cin.get();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xf);
    gotoxy(20,height/2.5+1);
}
void Food:: Draw(int x, int y)
{
    x_pos = x;
    y_pos = y;
    gotoxy(x_pos,y_pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xb);
    cout << '$';
}

Food:: Food(int x, int y): x_pos(x), y_pos(y)
{
    gotoxy(x_pos,y_pos);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0xb);
    cout << '$';
}
