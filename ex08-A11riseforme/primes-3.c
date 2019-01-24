#include"cs1010.h"
long check_prime(long n)
{
    long i=2,j=0;
    while(i<n)
    {
        if(n%i==0)
            j=j+1;
        i=i+1; 
    }

    if(j>0)
        return 0;
    else
        return 1;    
}

int main()
{
    long p,i=2,flag=0;
    p = cs1010_read_long();

    for(i;i<p;i++)
    {
        if((check_prime(i)==1)&&(check_prime(p-i)==1))
        {
            cs1010_print_string("Yes");
            flag =flag+1;
            break;
        }
        
    }   
        
    if(flag==0)
        cs1010_print_string("No");
    
    return 0;
}
