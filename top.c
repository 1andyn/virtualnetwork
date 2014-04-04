#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STAR 0
#define TREE 1
#define FAIL -1
#define SUCCESS 1
#define FILENAMESIZE 100
#define TREE_SIZE 4
#define STAR_HOST 3
#define TREE_HOST 5
#define STAR_SWITCH 1
#define TREE_SWITCH 4

char tree_cmp[] = "tree";
char star_cmp[] = "star";

void initTopo(topo *topology)
{
   topology->numlinks = 0;
   topology->numhosts = 0;
   topology->type = -1;
}

void initTreeData(char file[])
{
   printf("You are initing a tree!\n");
   FILE *top = fopen(file,"r");
   if(!file
}

void initStarData(char file[])
{
   printf("You are initing a star!\n");
}

void removeNewLine(char *line){
   line[strcspn (line, "\n")] = '\0';
}

int initializeTop(topo *topology)
{
   char filename[] = "";
   char *linebuff = NULL; 
   size_t length = 0;
   ssize_t linesize;

   printf("Enter file name for topology: ");
   scanf("%s", &filename);

   FILE *file = fopen(filename,"r");
   if(!file){
      printf("ERROR: File not found..\n");
      return FAIL;
   } else {
      linesize = getline(&linebuff, &length, file);
      removeNewLine(linebuff);
      if(linesize == -1) {
         printf("Incorrect syntax detected..stopping.\n");
         fclose(file);
         return FAIL;
      } else {
         if(strcmp(linebuff, tree_cmp) == 0) {
            //Remember to close file
            fclose(file);
            initTreeData(filename);
            return SUCCESS;
         } else if (strcmp(linebuff, star_cmp) == 0) {
            fclose(file);
            initStarData(filename);
            return SUCCESS;
         } else {
            printf("Incorrect syntax detected..stopping.\n");
            fclose(file);
            return FAIL;
         }
      }
   }
}

int main()
{
   initializeTop();
}


