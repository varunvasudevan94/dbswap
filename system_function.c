#include "system_function.h"
#include "string.h"
#include <time.h>

int create_swap_directory(char *dir_name){
      char cmd_exec[1000]="mkdir ";
      FILE *fp=fopen(dir_name,"r");
      if (fp!=NULL){
	printf("directory already exists\n");
	return 1;	

      }			
      strcat(cmd_exec,dir_name);  
      if (system(cmd_exec)!=-1)
          return 0;
      return -1;
}

int command_git(char *cmd_exec,char *dir_name){
	char current_directory[1000]="cd ";

	strcat(current_directory,dir_name);
	system(current_directory);

        FILE *fp;
        char path[1035];

	strcat(current_directory," && ");
	strcat(current_directory,cmd_exec);
	printf("CURRENT DIRECTORY = %s",current_directory);

        fp = popen(current_directory, "r");
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


node* show_changes(char *dir_name){
	char cmd_exec[1000]="git log ";
	char current_directory[1000]="cd ";

	strcat(current_directory,dir_name);
	//system(current_directory);

        FILE *fp;
        char path[1000];

	strcat(current_directory," && ");
	strcat(current_directory,cmd_exec);
	

        fp = popen(current_directory, "r");
        if (fp == NULL) {
          printf("Failed to run command\n" );
          exit(1);
        } 

        /* Read the output a line at a time - output it. */

	int count=0;
	node *start;
	init_linked_list(&start);
        while (fgets(path, 1000, fp) != NULL) {
        
          	int val=count%6;
		char commit[1000];
		char message[1000];
	  	if (val==0){ 
		   //printf("%s\n", path);
		   strcpy(commit,"");
		   strcpy(message,"");	
		   strcpy(commit,path);

		}
		else if (val==4){ 
		   //printf("button val %s\n",path);
		   strcpy(message,path);
		   if (fp)	
		   insert_linked_list(&start,commit,message);	
		   	

		}



	 	 	
				
          //printf("%s count=%d\n", path,count);
	count++;	

        }
	
	printf("chucked jone\n");	

	//print_linked_list(start);
	node *new_list=NULL;
	reverse_linked_list(start,&new_list);
	//print_linked_list(new_list);
        //fill for false
        /* close */


       free(start);
        	
       pclose(fp);
	
        return new_list;

}




int init_dir(char *dir_name){
	 FILE *fp=fopen(dir_name,"r");
      	 if (fp!=NULL){
		printf("directory already exists\n");
		return 1;	

      	 }		

        char cmd_exec[1000]="git init ";
	command_git(cmd_exec,dir_name);
	
	return 0;	        
}

int add_swap_file(char *dir_name){
	char cmd_exec[1000]="git add -A  ";
	command_git(cmd_exec,dir_name);
	printf("$$$$$$$$$$$$$$$$$$$$$$$added successfully\n");
	return TRUE;
}

int commit_swap_file(char *dir_name,char *file_name){
	char cmd_exec[1000]="git commit -m  ";
	char commit_message[1000];

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	sprintf(commit_message,"'now: %d-%d-%d %d:%d:%d'", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	
	
	strcat(cmd_exec,commit_message);
	
	command_git(cmd_exec,dir_name);	


	return TRUE;

}


