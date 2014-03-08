/*
 * switchlink.h
*/

typedef struct switchLinks {
   LinkInfo linkin;
   LinkInfo linkout;
   struct switchLinks * next;
} switchLinks;

switchLinks * constructLink(LinkInfo in, LinkInfo out, int id);
switchLinks ** linkSearch(switchLinks ** head, int id);
void addLink(switchLinks ** head, switchLinks * newlink);
