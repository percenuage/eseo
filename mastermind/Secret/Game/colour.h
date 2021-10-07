#ifndef COLOUR_H_INCLUDED
#define COLOUR_H_INCLUDED

    #if defined(__WIN32) && !defined(UNIX)

        #define NOIR 0X0000
        #define BLEU 0x0001
        #define VERT 0x0002
        #define CYAN 0x0003
        #define ROUGE 0x0004
        #define MAGENTA 0x0005
        #define JAUNE 0x0006
        #define BLANC 0x0007
        #define GRIS 0X0008
        #define BLEU_VIF 0x0009
        #define VERT_VIF 0x000A
        #define CYAN_VIF 0x000B
        #define ROUGE_VIF 0x000C
        #define MAGENTA_VIF 0x000D
        #define JAUNE_VIF 0x000E
        #define BLANC_VIF 0x000F

    #else
        #define NOIR 30
        #define ROUGE 31
        #define VERT 32
        #define JAUNE 33
        #define BLEU 34
        #define MAGENTA 35
        #define CYAN 36
        #define BLANC 37
        #define GRIS 20
        #define ROUGE_VIF 21
        #define VERT_VIF 22
        #define JAUNE_VIF 23
        #define BLEU_VIF 24
        #define MAGENTA_VIF 25
        #define CYAN_VIF 26
        #define BLANC_VIF 27
    #endif


    void setColour(int foreground, int background);
    void gotoXY(int x,int y);
    void clrScr();


#endif // COLOUR_H_INCLUDED
