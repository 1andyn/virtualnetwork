#include <stdio.h>
#include <stdlib.h>
#include "main.h" //PacketBuffer

PacketQueue * createQueue()
{
   PacketQueue * queue;
   queue = (Queue *) malloc(sizeof(PacketQueue));
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
      printf("Error: Could not allocate memory for PacketBuffer\n");
   } else {
      //Assign element Data
      pkq->rcvPKB = rcv;
      pkq->next = NULL;
      
      //Head is empty
      if(pq->head == NULL) {
         pq->head = pq->tail = pkq;
      } else { //Else
         pk->tail->next = pkq;
         pk->tail = pkq; //Update Tail 
      }
   }
}

packetBuffer * front(const PacketQueue * pq)
{
   if(pq != NULL){
      return &(pq->head.rcvPKB);
   } else {
      return NULL;
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
   temp.payload = 'hello';
   temp.sendsrv = 9;
   /* Test Packet Buffer*/
   
   PacketQueue * queue = NULL;
   queue = createQueue();
   enQueue(queue, temp);
   
   TestIterate(queue); 

}


