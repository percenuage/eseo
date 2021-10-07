#include "colour.h"
#include <stdio.h>
#if defined(__WIN32__)
    #include <windows.h>


    void gotoXY(int x, int y){
       HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
       COORD coord;
       coord.X = x;
       coord.Y = y;
       SetConsoleCursorPosition(console,coord);
    }



    void setColour(int foreground, int background){
       HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        background = background<<4;
       SetConsoleTextAttribute(console, foreground | background);
    }



    void clrScr(){
       CONSOLE_SCREEN_BUFFER_INFO screen;
       DWORD charsWritten;
       HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
       COORD coord = {0,0};
       DWORD dwConSize;
       GetConsoleScreenBufferInfo(console,&screen);
       dwConSize = screen.dwSize.X * screen.dwSize.Y;
       FillConsoleOutputCharacter(console,(TCHAR)' ',dwConSize,coord,&charsWritten);
       GetConsoleScreenBufferInfo(console,&screen);
       FillConsoleOutputAttribute(console,screen.wAttributes,dwConSize,coord,&charsWritten);
       SetConsoleCursorPosition(console,coord);
    }


#else

    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <unistd.h>

    void setColour(int foreground, int background){
        if((foreground>=30)&&(foreground<=37)){
            printf("\e[%dm",foreground);
        }
        if((foreground>=20)&&(foreground<=27)){
            printf("\e[1;%dm",foreground+10);

        }
        if(background>=20 && background<=27)
            background+=10;
        if((background<30)||(background>37))
            return;
        printf("\e[%dm",background+10);
    }

    void gotoXY(int x,int y){
        printf("\e[%d;%dH",y,x);
    }


    void clrScr(){
        printf("\e[H\e[2J");
    }



#endif

