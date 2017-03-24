#include "system_function.h"

int create_swap_directory(char *dir_name){
      char cmd_exec[1000]="mkdir ";
      strcat(cmd_exec,dir_name);  
      if (system(cmd_exec)!=-1)
          return TRUE;
        return FALSE;
}

int init_dir(char *dir_name){
        char cmd_exec[1000]="git init ";
        strcat(cmd_exec,dir_name);

        FILE *fp;
        char path[1035];


        fp = popen(cmd_exec, "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        } 

        /* Read the output a line at a time - output it. */
        while (fgets(path, sizeof(path)-1, fp) != NULL) {
          printf("%s", path);
        
        }
        //fill for false
        /* close */
        pclose(fp);
        return TRUE;
}


