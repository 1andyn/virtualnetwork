/*
 * Packet Queue 'pkqueue.h'
 */

typedef struct PKQueue {
   packetBuffer rcvPKB; //Stores Packetbuffers
   struct PKQueue * next;
} PKQueue;

typedef struct PacketQueue{
   struct PKQueue * head;
   struct PKQueue * tail;
} PacketQueue;


PacketQueue * createQueue();
void enQueue(PacketQueue * pq, packetBuffer rcv);//Adds to Queue
void deQueue(PacketQueue * pq);

//Support Functions
packetBuffer * front(const PacketQueue *pq);
int isEmpty(const PacketQueue * pq);

//Debug purpose only
//void TestIterate (const PacketQueue * pq);




