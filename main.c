#include "mysql_client.h"
#include "system_function.h"
#include "linked_list.h"
#include <gtk/gtk.h>


/* Our new improved callback.  The data passed to this function
 * is printed to stdout. */
static void callback( GtkWidget *widget,
                      gpointer   data )
{
    g_print ("Hello again - %s was pressed\n", (gchar *) data);
}

/* another callback */
static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    gtk_main_quit ();
    return FALSE;
}

int create_widget_ui( int   argc,
          char *argv[],node *list ){
	

	 GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box1;

    gtk_init (&argc, &argv);

    
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

   
    gtk_window_set_title (GTK_WINDOW (window), "Hello Buttons!");

    
    g_signal_connect (window, "delete-event",
                      G_CALLBACK (delete_event), NULL);

   
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    
    box1 = gtk_hbox_new (FALSE, 0);

   while (list){  
    gtk_container_add (GTK_CONTAINER (window), box1);

    
    button = gtk_button_new_with_label (list->message);

   
    g_signal_connect (button, "clicked",
                      G_CALLBACK (callback), (gpointer) list->commit);

    
    gtk_box_pack_start (GTK_BOX(box1), button, TRUE, TRUE, 0);
	gtk_widget_show (button);

	list=list->next;	
    }
    
    /*gtk_widget_show (button);

    button = gtk_button_new_with_label ("Button 2");

    g_signal_connect (button, "clicked",
                      G_CALLBACK (callback), (gpointer) "button 2");

    gtk_box_pack_start(GTK_BOX (box1), button, TRUE, TRUE, 0);

    gtk_widget_show (button);
*/
    gtk_widget_show (box1);

    gtk_widget_show (window);

    gtk_main ();





}

int main( int   argc,
          char *argv[] )
{
 	
    MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;

   char *server = "127.0.0.1";
   char *user = "root";
   char *password = "copenhagen"; 
   char *database = "tyrst";

   if (create_swap_directory("../temp3011994")==-1){            //-1 for error 0 success 1 directory exists
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

   node *list=show_changes("../temp3011994");

   //print_linked_list(list);	
   create_widget_ui(argc,argv,list);   
    
    return 0;
}
