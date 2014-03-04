/*
 * FWTable.h
 */

typedef struct FWTable {
   int dest_addr; //address of destination network
   int out_link; // outgoing link number
   int valid; // Is the entry valid?
   struct FWTable * next;
} FWTable;

FWTable * createTable();
void fwTableAdd(FWTable ** head, FWTable * new);
void fwTableUpdate(FWTable ** head, int des_addr, int new_link);
FWTable ** fwTablesearch(FWTable ** head, int source_addr); 
