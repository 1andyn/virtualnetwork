/*
 *switch.h
 * */

/*Things needed 
 * ForwardingTable Container
 * PacketQueue
*/

typedef struct {
   int physid; /* Physical ID */
   struct FWTable; //Container of forwarding data
   struct PacketQueue; //Container of packets
   struct switchLinks; //Container of all connections   
} switchState;

void switchMain(switchState * sstate);
