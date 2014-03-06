#include <stdio.h>
#include <stdlib.h>
#include "main.h" //PacketBuffer
#include "pkqueue.h"
#include <string.h>

PacketQueue * createQueue()
{
   PacketQueue * queue;
   queue = (PacketQueue *) malloc(sizeof(PacketQueue));
   if(queue == NULL){
      printf("Error: PacketQueue Allocation failed.\n");
      exit(1);
   }
   // Initialize to NULL
   queue->head = queue->tail = NULL;
   return queue;
}

void enQueue(PacketQueue * pq, packetBuffer rcv)
{
   PKQueue * pkq = (PKQueue *) malloc(sizeof(PKQueue));
   if(pkq == NULL){
      free(pkq);
      printf("Error: Could not allocate memory for PacketBuffer\n");
   } else {
      //Assign element Data
      pkq->rcvPKB = rcv;
      pkq->next = NULL;
      
      //Head is empty
      if(pq->head == NULL) {
         pq->head = pq->tail = pkq;
      } else { //Else
         pq->tail->next = pkq;
         pq->tail = pkq; //Update Tail 
      }
   }
}

packetBuffer * front(const PacketQueue * pq)
{
   if(pq != NULL){
      return &(pq->head->rcvPKB);
   } else {
      return NULL;
   }
}

void TestIterate(const PacketQueue * pq)
{
   PKQueue * ptrptr = pq->head;
   while(ptrptr != NULL){
      printf("Payload, '%s' \n", ptrptr->rcvPKB.payload);
      ptrptr = ptrptr->next;
   }
}

int IsEmpty(const PacketQueue *pq)
{
   if(pq->head == NULL) {
      return 1;
   } else {
      return 0;
   }
}

int main()
{
   /* Test Packet Buffer */
   packetBuffer temp;
   temp.valid = 2;
   temp.new = 3;
   temp.srcaddr = 1;
   temp.dstaddr = 6;
   temp.length = 5;
   strcpy(temp.payload, "hello");
   temp.sendrcv = 9;
   
   /* Test Packet Buffer 2*/
   packetBuffer temp2;
   temp2.valid = 2;
   temp2.new = 3;
   temp2.srcaddr = 1;
   temp2.dstaddr = 6;
   temp2.length = 5;
   strcpy(temp2.payload, "good day");
   temp2.sendrcv = 9;
   
   /* Test Packet Buffer 3*/
   packetBuffer temp3;
   temp3.valid = 2;
   temp3.new = 3;
   temp3.srcaddr = 1;
   temp3.dstaddr = 6;
   temp3.length = 5;
   strcpy(temp3.payload, "greetings");
   temp3.sendrcv = 9;
   
   PacketQueue * queue = NULL;
   queue = createQueue();
   
   if(IsEmpty(queue)){
      printf("Queue is currently empty. \n");
   }

   printf("\n\nAttempting to break front()\n");
   
   packetBuffer * mypacket = front(queue);
   if(mypacket == NULL) {
      printf("Found null \n");
   } else {
      printf("Front payload: %s \n", mypacket->payload); 
   }
   printf("\n\n");
   
   enQueue(queue, temp);
   enQueue(queue, temp2);
   enQueue(queue, temp3);
 
   printf("Enqueued some packets...\n"); 
   if(!IsEmpty(queue)){
      printf("Queue is NOT currently empty. \n");
   }

   printf("First Iteration: \n"); 
   TestIterate(queue);
   
   mypacket = front(queue);
   printf("Front payload: %s \n", mypacket->payload); 

}


