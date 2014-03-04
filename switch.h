/*
 *switch.h
 * */

/*Things needed 
 * ForwardingTable Container
 * PacketQueue
*/

typedef struct {
   int physid; /* Physical ID */
   struct FWTable;
   struct PackQueue;
   
   //Does this need to be an container (multiple links in and out?)
   LinkInfo linkin; //Incoming communication link
   LinkInfo linkout; //Outgoing communication link
} switchState;

//does a switch need an id?
void switchMain(switchState * sstate);
