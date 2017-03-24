#include "mysql_client.h"

int check_db_info(char *server,char *database,char *user,char *password){
       MYSQL *conn;
       conn = mysql_init(NULL);
       if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
         fprintf(stderr, "%s\n", mysql_error(conn));
         return FALSE;
       }
       printf("........successfully connected to db\n"); 
   
       return TRUE;

}

int create_dump(char *server,char *database,char *user,char *password){
      char cmd_exec[1000]="mysqldump -u ";
      strcat(cmd_exec,user);
      strcat(cmd_exec," --password='");
      strcat(cmd_exec,password);  
      strcat(cmd_exec,"' -h ");
      strcat(cmd_exec,server);
      strcat(cmd_exec," ");
      strcat(cmd_exec,database);
      strcat(cmd_exec," > temp3011994/db_backup.sql");
      printf("........creating backup\n");            
      if (system(cmd_exec)!=-1){

         return TRUE;
      } 
   
      return FALSE;

}