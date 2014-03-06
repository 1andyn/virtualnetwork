#include <sdio.h>
#include <stdlib.h>
#include "links.h"
#include "switchlink.h"

void constructLinks(LinkInfo in, Linkinfo out, int id)
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
