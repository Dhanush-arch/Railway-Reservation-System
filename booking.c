#include<string.h>
#include"main.h"
#include"availability_checking.h"

int book(int id,char name[10],booking *b,int total_seats)
{   
    if(check_availability(b,total_seats))
    {
        strcpy(b[id].name,name);
        b[id].id_num = id+1;
        return 1;
    }
    else
    {
        return 0;
    }
    
}
