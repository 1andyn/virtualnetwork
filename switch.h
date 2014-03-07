/*
 *switch.h
 * */

/*Things needed 
 * ForwardingTable Container
 * PacketQueue
*/

typedef struct {
   int physid; /* Physical ID */
   packetBuffer sendBuffer;
   struct FWTable ftable; //Container of forwarding data
   struct PacketQueue recvPQ; //Container of packets
   struct switchLinks sLinks; //Container of all connections   
} switchState;

void switchMain(switchState * sstate);
