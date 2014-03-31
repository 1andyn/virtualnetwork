typedef struct {
   int numlinks;
   int numhosts;
   int type;
   struct link_container *head;
} topo;

typedef struct {
   int in;
   int out;
   struct link_container *next;
} link_container;
