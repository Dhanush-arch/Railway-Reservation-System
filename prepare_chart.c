#include"main.h"
#include<stdio.h>

void printChart(booking *b,int total_seats)
{ 
  int i;
  printf("\nID\t Name\n");
  for(i=0;i<total_seats;i++)
  {
    if(b[i].id_num!=0)
    {
      printf("%d\t %s\n",b[i].id_num,b[i].name);
    }
  }
}
