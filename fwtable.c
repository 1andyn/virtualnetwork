#include <stdio.h>
#include <stdlib.h>
#include "fwtable.h"

FWTable * createTable()
{
   return (FWTable *)malloc(sizeof(FWTable));
}

void fwTableAdd(FWTable * head, FWTable * newdata)
{
   FWTable * lastptr = head;
   
   while(lastptr != NULL){
      lastptr = lastptr->next;
   }
   lastptr->next = newdata;
}

int main()
{
   FWTable * head = createTable();
   head->addr = 1;
   head->out_link = 2;
   head->valid = 0;

   FWTable * other = createTable();
   other->addr = 2;
   other->out_link = 3;
   other->valid = 1;

   fwTableAdd(head, other);
   
   FWTable * iterate = head;
   while(iterate != NULL){
      printf("%s %n", head->addr);
      iterate = iterate->next;
   }


}

