/*
 * Packet Queue 'pkqueue.h'
 */

typedef struct PKQueue {
   packetBuffer rcvPKB; //Stores Packetbuffers
   struct PKQueue * next;
} PKQueue;

typdef struct PacketQueue{
   struct PKQueue * head;
   struct PKQueue * tail;
} PacketQueue;


PacketQueue * createQueue();
PacketQueue * freeQueue(PacketQueue * pq); //Deallocates Queue
PacketQueue * enQueue(PacketQueue * pq, packetBuffer rcv);//Adds to Queue
packetBuffer * deQueue(PacketQueue * pq);

//Support Functions
packetBuffer * front(PacketQueue *pq);
bool isEmpty(const PacketQueue * pq);

//Debug purpose only
void TestIterate (const PacketQueue * pq);




