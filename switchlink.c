#include <sdio.h>
#include <stdlib.h>
#include "links.h"
#include "switchlink.h"

switchLink * constructLinks(LinkInfo in, Linkinfo out, int id)
{
   switchLinks * head;
   head = (switchLinks *) malloac(sizeof(switchLinks));
   head->linkin = in;
   head->linkout = out;
   head->hostID = id;
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
         addLink(&(head->next), newlink);
      }
   }
}

switchLink ** linkSearch(switchLinks ** head, int ID)
{
   /*Recursive Search*/
   switchLink * index;
   if(*head == NULL){
      return NULL;
   } else {
      index = *head;
      if(index->hostID = ID){
         return head;
      } else {
         return linkSearch(&(index->next), ID);
      }
   }
}

void TestIterate(const switchLinks ** head)
{
   switchLinks ** ptr = head;
   while(*ptr != NULL) {
      printf("",);
      *ptr = (*ptr)->next;
   }
}

//This is just drive code for testing purposes
int main()
{
   LinkInfo l_i;
   LinkInfo l_o;
   
   l_i.linkType = UNIPIPE;
   l_i.linkID = 0;
   link.uniPipeInfo.PipeType = NONBLOCKING;
   linkCreate(&l_i);
   


}
