#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"main.h"
#include"availability_checking.h"
#include"booking.h"
#include"cancellation.h"
#include"prepare_chart.h"


// typedef struct {
//   int id_num;
//   char name[10];
// }booking;

// static int TOTAL_SEATS;

// int check_availability(booking *b,int total_seats)
// { 
//   int i;
//   int free_seats = 0;
//   for(i=0;i<total_seats;i++)
//   {
//     if(b[i].id_num == 0)
//     {
//       free_seats += 1;
//     }
//   }

//   return(free_seats);
// }

// int book(int id,char name[10],booking *b)
// {   
//     if(check_availability(b,TOTAL_SEATS))
//     {
//         strcpy(b[id].name,name);
//         b[id].id_num = id;
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
    
// }

// int cancel(int id,booking *b)
// { 
//     // char str_temp = " ";
//     b[id].id_num = 0;
//     // strcpy(b[id].name,str_temp);
//     return 1;
// }

// void printChart(booking *b,int total_seats)
// { 
//   int i;
//   printf("\nID\t Name\n");
//   for(i=0;i<total_seats;i++)
//   {
//     if(b[i].id_num!=0)
//     {
//       printf("%d\t %s",b[i].id_num,b[i].name);
//     }
//   }
// }

void displayChoice(booking *b,int index,int total_seats)
{ 
  int choice;
  char str[10];
  int i = 0;
  printf("\n1.Booking");
  printf("\n2.Availability Checking");
  printf("\n3.Cancellation");
  printf("\n4.Prepare chart");
  printf("\n5.Exit");
  printf("\nYour choice: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:
      printf("Enter your Details...\n");
      printf("Name: ");
      scanf("%s",str);
      if(book(index,str,b,total_seats))
      {
        printf("Booking Success...\n");
        index +=1;
      }
      else
      {
        printf("Booking Failed.\nSeats Unavailable.\n");
      }
      displayChoice(b,index,total_seats);
      break;
    case 2:
      printf("\nChecking The Available Seats...");
      printf("\nSeats available: %d\n",check_availability(b,total_seats));
      displayChoice(b,index,total_seats);

      break;
    case 3:
      printf("\nEnter the Id of the seat to be cancelled: ");
      scanf("%d",&i);
      if(cancel(i,b))
      {
        printf("Seat Cancellation Successful..\n");
      }
      else
      {
        printf("Seat Cancellation Failed.\n");
      }
      displayChoice(b,index,total_seats);

      break;
    case 4:
      printf("\nPreparing Chart...\n");
      printChart(b,total_seats);
      displayChoice(b,index,total_seats);
      break;
      
    case 5:
      return;
    default:
      printf("Enter a valid option...");
      displayChoice(b,index,total_seats);

  }
}

int main()
{ 
  int total_seats;
  int index = 0;
  printf("\nEnter the total no.of seats: ");
  scanf("%d",&total_seats);
  // TOTAL_SEATS = total_seats;
  // printf("%d",TOTAL_SEATS);
  booking *b = malloc(total_seats*sizeof(booking));
  displayChoice(b,index,total_seats);
  free(b);
  return 0;
}
