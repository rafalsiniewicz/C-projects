#ifndef CALENDAR_H_
#define CALENDAR_H_
#include<stdio.h>
#include<windows.h>
#include<ctype.h>
#define SIZE 70
void output(int month, int year);
void menu(int month, int year);
void gotoxy (int x, int y);
int display_days_in_month(int starting_day, int month, int year);
#endif // CALENDAR_H_
