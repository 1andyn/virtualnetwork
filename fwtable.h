typedef struct {
   int addr;
   int out_link;
   int valid;
   struct FWTable * next;
} FWTable;

void fwTableAdd(FWTable * head, FWTable * new); 
