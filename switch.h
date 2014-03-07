/*
 *switch.h
 * */

/*Things needed 
 * ForwardingTable Container
 * PacketQueue
*/

typedef struct {
   int physid; /* Physical ID */
   struct FWTable * ftable; //Container of forwarding data
   struct PacketQueue * recvPQ; //Container of packets
   struct switchLinks * sLinks; //Container of all connections   
} switchState;

void switchMain(switchState * sstate);
void switchSetLinkHead(switch * s_state, switchLinks * head);
