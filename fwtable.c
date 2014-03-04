#include <stdio.h>
#include <stdlib.h>
#include "fwtable.h"


// Creates a Table Entry for FWTable
FWTable * createTable(int dest, int link, int val)
{
   FWTable * entry;
   entry = (FWTable *) malloc(sizeof(FWTable));
   entry->dest_addr = dest;
   entry->out_link = link;
   entry->valid = val;
   return entry;
}

void fwTableAdd(FWTable ** head, FWTable * newentry)
{
   /* Recursive Insertion */
   FWTable * indexptr;
   if(head == NULL){
      printf("Something went wrong attempting to add node");
      return;
   } else {
      indexptr = *head;
      if(indexptr == NULL){
         *head = newentry;
      } else {
         fwTableAdd(&(indexptr->next), newentry); 
      }
   }
}

FWTable ** fwTableSearch(FWTable ** head, int dest)
{
   /* Recursive Search */
   FWTable * indexptr;
   if(*head == NULL){
       return NULL;
   } else {
      indexptr = *head;
      if(indexptr->dest_addr == dest){
         return head;
      } else {
         return fwTableSearch(&(indexptr->next), dest);
      }
   }
}

void fwTableUpdate(FWTable ** head, int des_addr, int new_link, int val)
{
   FWTable ** des_index;
   des_index = fwTableSearch(head, des_addr);
   (*des_index)->out_link = new_link;
   (*des_index)->valid = val;
}

void fwTableIterate(FWTable ** head)
{
   FWTable ** iterate = head;
   while(*iterate != NULL){
      printf("Addr: %d, Link:%d, Valid:%d \n", (*iterate)->dest_addr,
      (*iterate)->out_link, (*iterate)->valid);
      *iterate = (*iterate)->next;
   }
}
int main()
{
   FWTable * head = createTable(0, 0, 0);
   FWTable * other = createTable(1,1,0);
   FWTable * newt = createTable(2,2,0);
   FWTable * test = createTable(3,3,0);

   fwTableAdd(&head, other);
   fwTableAdd(&head, newt);
   fwTableAdd(&head, test);
   
   fwTableUpdate(&head, 2, 7, 1);

   fwTableIterate(&head);
}
