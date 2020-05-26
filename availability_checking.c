#include<stdio.h>
#include"main.h"

int check_availability(booking *b,int total_seats)
{ 
  int i;
  int free_seats = 0;
  for(i=0;i<total_seats;i++)
  { 
    if(b[i].id_num == 0)
    { 
      
      free_seats += 1;
    }
  }
  return(free_seats);
}