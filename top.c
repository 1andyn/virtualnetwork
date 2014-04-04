#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void initTreeData(char file[])
{
   printf("You are initing a tree!\n");
}

void initStarData(char file[])
{
   printf("You are initing a star!\n");
}



int initializeTop()
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
      if(linesize == -1) {
         printf("Incorrect syntax detected..stopping.\n");
         fclose(file);
         return FAIL;
      } else {
         printf("%s", linebuff);
         printf("%s", tree_cmp);
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


