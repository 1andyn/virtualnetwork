/*
 * Packet Queue 'pkqueue.h'
 */

typedef struct PKQueue {
   packetBuffer rcvPKB; //Stores Packetbuffers
   struct PKQueue * next;
} PKQueue;

PKQueue * init_queue();
PKQueue * create_entry(packetBuffer recv);//Instantiate a PKQueue entry
PKQueue ** pop_queue(PKQueue ** head); // Removes head, and returns new head
void push_queue(PKQueue ** head, PKQueue new_entry); //Adds packet to back


