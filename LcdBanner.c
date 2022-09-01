/*
 * lcd__banner.c
 *
 *  Created on: Aug 30, 2022
 *      Author: dmvp01
 */
#include "lcdBanner.h"
#include "math.h"
void init_lcd()
{
    timer_init(); // Initialize Timer, needed before any LCD screen fucntions can be called
                  // and enables time functions (e.g. timer_waitMillis)
    lcd_init();   // Initialize the the LCD screen.  This also clears the screen.
}
void print_banner(char * _str)
{
    char * str = malloc(sizeof(char) * (strlen(_str)+ 1));

    if(strlen(_str) < 20)
    {
        sprintf(str, "%-20s", _str);
    }
    else
    {
        strcpy(str, _str);


    }

    while(1)
        {
        int pos = 0;


    int len = strlen(str);


    int numChar = 0;
    int numspaces = 19;
    while(numspaces >= 0)
    {
        lcd_printf("%*s%.*s", numspaces, " ", numChar, str  );
        timer_waitMillis(300);

        numChar++;
        numspaces--;
    }

    numspaces = 0;
    numChar = 20;

    char toprint[21];
    toprint[20] = '\0';


    int i = 0;
    int j = 19;
    char subtext[20];
    while(i < len && j < len )
    {

        subtext[19] = '\0';

        memcpy(subtext, &str[i], j);

        lcd_printf("%.20s", subtext);

        timer_waitMillis(300);

        i++;
        j++;
    }

    i = 0;

    while(i < 20)
    {
        char  text[21];
        memcpy(text, &subtext[i], 20);
        text[20-i] = '\0';

       lcd_printf(text);
       timer_waitMillis(300);
       i++;
    }
    }






// todo Count numer of characters
// create a string with correct number of spaces beforehand 0
//lcd printf with substring of 20 characters
 //
}


