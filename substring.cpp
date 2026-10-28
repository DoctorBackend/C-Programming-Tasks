#include <iostream>
#include "substring.h"

using namespace std;

bool is_prefix(char first[30] ,char second[100])
{
 
    for(int i=0;first[i]!='\0';i++)
    {
        if(first[i]!=second[i])
        {
                return false;
        }
    }
    return true;
}
int substring_position(char first[30], char second[30])
{
    
    if(is_prefix(first,second))
    {
        return 0;
    }
    else  
    {
        int i=0;
        int j=0;
        for(i;second[i]!='\0' && first[j]!='\0';i++)
        {
            if(is_prefix(first+j,second+i))
            {
                j++;
            }
            else
            {
                j=0;  
            }
            continue;
        }
        if(j!=0)
        {
            return i-j;
        }
        else
        {
            return -1;
        }
    }
}
