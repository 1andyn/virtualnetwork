/* 
 * This is the source code for the host.  
 * hostMain is the main function for the host.  It is an infinite
 * loop that repeatedy polls the connection from the manager and
 * its input link.  
 *
 * If there is command message from the manager,
 * it parses the message and executes the command.  This will
 * result in it sending a reply back to the manager.  
 *
 * If there is a packet on its incoming lik, it checks if
 * the packet is destined for it.  Then it stores the packet
 * in its receive packet buffer.
 *
 * There is also a 10 millisecond delay in the loop caused by
 * the system call "usleep".  This puts the host to sleep.  This
 * should reduce wasted CPU cycles.  It should also help keep
 * all nodes in the network to be working at the same rate, which
 * helps ensure no node gets too much work to do compared to others.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include <unistd.h>
#include <fcntl.h>

#include "main.h"
#include "utilities.h"
#include "link.h"
#include "man.h"
#include "host.h"
#include "fwtable.h"
#include "pkqueue.h"

#define EMPTY_ADDR  0xffff  /* Indicates that the empty address */
                             /* It also indicates that the broadcast address */
#define MAXBUFFER 1000
#define PIPEWRITE 1 
#define PIPEREAD  0
#define FIRST_ADDR 0
#define INVALID 0
#define VALID 1
#define LINK_OFFSET 1
#define NOT_FOUND -1

void switchInitState(switchState * sstate, int phys)
{
   sstate->recvPQ = createQueue();
   sstate->physid = phys;
}

void switchRecvPacketBuff(switchState * sstate, int lid, packetBuffer * pbuff)
{
   int src = pbuff->srcaddr;
   /* Update table entry */
   /* First Case Table is Empty */
   if(sstate->ftable == NULL){
      FWTable * fable = createTable(src, lid, VALID);
      sstate->ftable = fable;
   } else {
      FW ** search_index = fwTableSearch(&(sstate->ftable), src);
      //If the source address doesn't already exist
      //(we have not associated the address with a link yet)
      if(search_index == NULL){
         FWTable * fable == createTable(src, lid, VALID);
         fwTableAdd(&(s_state->fable), fable);
      }
   }
   //Add Packet to Buffer
   enQueue((s_state->recvPQ), &pbuff);
}

void switchSendPacketBuff(switchState * s_state)
{
   if(!isEmpty(s_state->recvPQ)){
      //Send data from top of queue
      //Packet from top of queue
      int destaddr, sourceaddr;
      packetBuffer * temp = front(s_state->recvPQ);
      destaddr = temp.dstaddr;
      sourceaddr = temp.srcaddr;

      //Forwarding Table Entry not found
      FWTable ** ft = fwTableSearch(&(s_state->ftable), destaddr);
      if(ft == NULL) {
         switchSendAll(s_state, sourceaddr);
      } else {
          
      }

   
   }
}


void switchSendAll(switchState * s_state)
{
   
}

void switchTransmitPacket(switchState * s_state)
{
   char dest[1000];
   int dstaddr;
   findWord(dest, word, 2);
   dstraddr = ascii2Int(dest);
   
   s_state->recvPQ
   
   s_state->sendBuffer.dstaddr = dstaddr;

   s_state->sendBuffer.srcaddr =  

}

void switchSetLinkHead(switchState * sstate, switchLinks * head)
{
   sstate->sLinks = head;
}

void switchSetPacketHead(switchState * sstate, FWTable * head)
{
   sstate->recvPq = head;
}

void switchMain(switchState * sstate)
{
   char buffer[1000];
   char word[1000];
   
   //Data Structures for switch
   FWTable * table;
   PacketQueue *
   switchLinks *

   
   while(1){
      LinkInfo *linkptr = 
      linkReceive(&(s_state 
     //does the switch sleep? 
      usleep(TENMILLISEC);  
   }
}
