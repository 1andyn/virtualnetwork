/*
 * switchlink.h
*/

typedef struct switchLinks {
   LinkInfo linkin; //Incoming Link (Receive Data)
   LinkInfo linkout; //Outgoing Link (Send Data)
   struct switchLinks * next;
} switchLinks;

switchLinks * constructLink(LinkInfo in, LinkInfo out, int id);
LinkInfo * linkSearch(switchLinks ** head, int id);
void addLink(switchLinks ** head, switchLinks * newlink);
