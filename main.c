#include <gtk/gtk.h>
#include "mysql_client.h"
#include "system_function.h"
#include "exampleapp.h"

int
main (int argc, char *argv[])
{

	MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;

   char *server = "127.0.0.1";
   char *user = "root";
   char *password = "copenhagen"; /* set me first */
   char *database = "tyrst";

   if (create_swap_directory("../temp3011994")==-1){		//-1 for error 0 success 1 directory exists
      //printf("Something wrong with directory creation");
      exit(1);

   }

  if (!init_dir("../temp3011994")){
      printf("problem with initing directory");
      //exit(1);

  }      


   if (!check_db_info(server,database,user,password)){
         printf("DATABASE does not exist\n");
         exit(1);

   }

   if (!create_dump(server,database,user,password)){
         printf("DUMP did not create successfully");
         exit(1);

   }

   if (!add_swap_file("../temp3011994")){
	printf("dump not added to repository");
	exit(1);
   }	

   if (!commit_swap_file("../temp3011994","db_backup.sql")){
	printf("not committed successfully");
	exit(1);
   }	


  return g_application_run (G_APPLICATION (example_app_new ()), argc, argv);
}
