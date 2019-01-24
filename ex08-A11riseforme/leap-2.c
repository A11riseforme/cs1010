#include"cs1010.h"

int main()
{   
    long year;
    year = cs1010_read_long();
    if(year%100!=0)
    {       
        if(year%4!=0)
            cs1010_print_string("Not Leap Year");
        else
            cs1010_print_string("Leap Year");
    }
    else
    {   
        if(year%400==0)          
            cs1010_print_string("Leap Year");
        else
            cs1010_print_string("Not Leap Year");

    }

    return 0;
}

