#include <mysql.h>
#include <stdio.h>
#include <string.h>
int main() {
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;

   char *server = "127.0.0.1";
   char *user = "root";
   char *password = "copenhagen"; /* set me first */
   char *database = "tyrst";

   conn = mysql_init(NULL);

   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   printf("........successfully connected to db\n"); 
   char cmd_exec[1000]="mysqldump -u ";
   strcat(cmd_exec,user);
   strcat(cmd_exec," --password='");
   strcat(cmd_exec,password);	 
   strcat(cmd_exec,"' -h ");
   strcat(cmd_exec,server);
   strcat(cmd_exec," ");
   strcat(cmd_exec,database);
   strcat(cmd_exec," > db_backup.sql");
   printf("........creating backup\n");				
   system(cmd_exec);	


   /* send SQL query */
   /*if (mysql_query(conn, "select * from lol;")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   res = mysql_use_result(conn);

  
   printf("MySQL Tables in mysql database:\n");
   while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s \n", row[0]);

  
*/	

  // mysql_free_result(res);
   mysql_close(conn);
}
