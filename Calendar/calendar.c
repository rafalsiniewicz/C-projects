#include "calendar.h"
COORD coord = {0, 0}; // sets coordinates to (0,0) as global variables
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y are the coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int display_days_in_month(int starting_day, int month, int year)
{
    int days_in_month;
    static int counter = 0;
    month %= 12;
    starting_day %= 7;
    //Months are numered according to table numeration in C, so January is 0, February 1 and so on
    if(month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
    {
        days_in_month = 31;
    }
    else if(month == 3 || month == 5 || month == 8 || month == 10)
    {
        days_in_month = 30;
    }
    else if((year - 2000) % 4 == 0)
    {
        days_in_month = 29;
    }
    else
        days_in_month = 28;
    int tab[days_in_month]; //tab consists numbers from 1 to days_in_month to further display them on screen
    for(int i = 0; i < days_in_month; i++)
        tab[i] = i + 1;
    for(int i = 0, j = starting_day; i < days_in_month; i++, j++)
    {
        if(!(j % 7))
            j = 0;
        if(j < starting_day)
            gotoxy(10 * j, i/7 + 5);
        else
            gotoxy(10 * j, i/7 + 4);
        if(counter > 598)//counter to not display antyhing on screen during setting calculation
            printf("%d", tab[i]);
    }
    counter++;
    return coord.X/10 + 1;
}
void output(int month, int year)
{
    static int counter = 0;
    static int tab[600];
    month = month + (year - 2000) * 12;
    int temp_month = month;
    month %= 12;
    if(!counter)
    {
        tab[0] = 5;
        for(int i = 1, j = 2000; i < 600; i++)
        {
            tab[i] = display_days_in_month(tab[i-1], i-1, j);
            if(i % 11 == 0)
                j++;
        }
    }
    system("cls"); //set screen
    gotoxy(0,0);
    for(int i = 0; i < SIZE; i++)
        printf("-");
    printf("\n");
    switch(month) //display months
    {
    case 0:
        printf("\t\t\t   January, %d\n", year);
        break;
    case 1:
        printf("\t\t\t   February, %d\n", year);
        break;
    case 2:
        printf("\t\t\t   March, %d\n", year);
        break;
    case 3:
        printf("\t\t\t   April, %d\n", year);
        break;
    case 4:
        printf("\t\t\t   May, %d\n", year);
        break;
    case 5:
        printf("\t\t\t   June, %d\n", year);
        break;
    case 6:
        printf("\t\t\t   July, %d\n", year);
        break;
    case 7:
        printf("\t\t\t   August, %d\n", year);
        break;
    case 8:
        printf("\t\t\t   September, %d\n", year);
        break;
    case 9:
        printf("\t\t\t   October, %d\n", year);
        break;
    case 10:
        printf("\t\t\t   November, %d\n", year);
        break;
    case 11:
        printf("\t\t\t   December, %d\n", year);
        break;
    }

    for(int i = 0; i < SIZE; i++)
        printf("-");
    printf("\n");
    printf("%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "Monday", "Tuesday",
           "Wednesday", "Thursday", "Friday", "Saturday", "Sunday");
    for(int i = 0; i < 601; i++)
    {
        if(temp_month == i)
        {
            gotoxy(0,3);
            display_days_in_month(tab[i], i, year);
        }
    }
    counter++;
}
void menu(int month, int year)
{
    char choose;
    int m, y;
    output(month, year);
    printf("\n\nPress n to go next, press p to go previous, s to select date (month year), press q to quit.\n");
    scanf("%c", &choose);
    while(choose != 'q')
    {
        switch(choose)
        {
        case 'n':
            if(year > 2049)
                break;
            output(++month, year);
            if(!((month + 1)% 12))
                year++;
            break;
        case 'p':
            month--;
            if(!((month + 1)% 12))
                year--;
            if(year < 2000)
                break;
            output(month, year);
            break;
        case 's':
            scanf("%d %d", &m, &y);
            menu(m - 1,y);
            break;
        case 'q':
            break;
        }
        gotoxy(0,8);
        printf("\n\nPress n to go next, press p to go previous, s to select date (month year), press q to quit.\n");
        scanf("%c", &choose);
    }
}
