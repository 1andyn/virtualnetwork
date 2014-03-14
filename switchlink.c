#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "link.h"
#include "switchlink.h"

#define LINK_ERROR -2

switchLinks * constructLink(LinkInfo in, LinkInfo out, int id)
{
   switchLinks * head;
   head = (switchLinks *) malloc(sizeof(switchLinks));
   head->linkin = in;
   head->linkout = out;
   return head;
}

void addLink(switchLinks ** head, switchLinks * newlink)
{
   /* Recursive Insertion */
   switchLinks * indexptr;
   if(head == NULL){
      printf("Something went wrong attempting to add new link");
      return;
   } else {
      indexptr = * head;
      if(indexptr == NULL) {
         *head = newlink;
      } else {
         addLink(&(indexptr->next), newlink);
      }
   }
}

//Returns Outlink
LinkInfo * linkSearch(switchLinks ** head, int in_id)
{
   /*Recursive Search*/
   switchLinks * index;
   if(*head == NULL){
      return NULL;
   } else {
      index = *head;
      if(index->linkin.linkID= in_id){
         return &(index->linkout);
      } else {
         return linkSearch(&(index->next), in_id);
      }
   }
}


LinkInfo * outputLink(switchLinks ** head, int out_id)
{
   /*Recursive Search*/
   switchLinks * index;
   if(*head == NULL){
      return NULL;
   } else {
      index = *head;
      if(index->linkout.linkID= out_id){
         return &(index->linkout);
      } else {
         return linkSearch(&(index->next), out_id);
      }
   }
}

void TestIterate(switchLinks ** head)
{
   switchLinks * ptr = *head;
   while(ptr != NULL) {
      printf("LinkID: %d, LinkID2: %d \n", (ptr)->linkout.linkID, 
      (ptr)->linkin.linkID);
      ptr = (ptr)->next;
   }
}

/*
//This is just drive code for testing purposes
int main()
{
   LinkInfo l_i;
   LinkInfo l_o;
   
   LinkInfo l_i2;
   LinkInfo l_o2;
   
   l_i.linkType = UNIPIPE;
   l_i.linkID = 0;
   l_i.uniPipeInfo.pipeType = NONBLOCKING;

   l_o.linkType = UNIPIPE;
   l_o.linkID = 1;
   l_o.uniPipeInfo.pipeType = NONBLOCKING;

   l_i2.linkType = UNIPIPE;
   l_i2.linkID = 3;
   l_i2.uniPipeInfo.pipeType = NONBLOCKING;

   l_o2.linkType = UNIPIPE;
   l_o2.linkID = 4;
   l_o2.uniPipeInfo.pipeType = NONBLOCKING;

   switchLinks * header = constructLink(l_i,l_o, 1);
   switchLinks * test = constructLink(l_i2,l_o2, 1);
   addLink(&header, test);
   TestIterate(&header);
   
   LinkInfo * tester = outputLink(&header, 4);
   printf("Tester: %d \n", tester->linkID);


}*/
