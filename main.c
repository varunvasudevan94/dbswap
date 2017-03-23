#include "mysql_client.h"


int main() {
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;

   char *server = "127.0.0.1";
   char *user = "root";
   char *password = "copenhagen"; /* set me first */
   char *database = "tyrst";

  
   if (!check_db_info(server,database,user,password)){
         printf("DATABASE does not exist\n");
         exit(1);

   }

   if (!create_dump(server,database,user,password)){
         printf("DUMP did not create successfully");
         exit(1);

   }




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
