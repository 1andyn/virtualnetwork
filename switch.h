/*
 *switch.h
 * */

/*Things needed 
 * ForwardingTable Container
 * PacketQueue
*/

typedef struct {
   struct FWTable;
   //struct PackQueue;   
} switchState;

//does a switch need an id?
void switchMain(switchState * sstate);
