typedef struct switchLinks{
   int hostid;
   LinkInfo linkin;
   LinkInfo linkout;
   struct switchLinks * next;
} switchLinks

switchLinks * constructLinks(LinkInfo in, Linkinfo out, int id);
void addLink(switchLinks ** head, switchLinks newlink);
