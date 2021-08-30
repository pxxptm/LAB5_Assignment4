#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
using namespace std;

void draw_ship(int x,int y)
{
    COORD c={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    cout << " <-0-> ";
}

void erase_ship(int x,int y)
{
    COORD c={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    cout << "      ";
}

int main()
{
    char ch=' ';
    int x=38,y=20;
    draw_ship(x,y);
    do
    {
        if (_kbhit())
        {
            ch=_getch();
            if(ch=='a') { if(x-1>=0) draw_ship(--x,y);}
            if(ch=='d') { if(x+1<=80) draw_ship(++x,y);}
            if(ch=='w') { if(y-1>=0) { erase_ship(x,y); draw_ship(x,--y); } }
            if(ch=='s') { if(y+1<=23) { erase_ship(x,y); draw_ship(x,++y); } }
            fflush(stdin);
        }
        Sleep(100);
    } while (ch!='x');
    return 0;
}
