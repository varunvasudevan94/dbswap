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
          char *argv[] ){
	

	 GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box1;

    gtk_init (&argc, &argv);

    /* Create a new window */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    /* This is a new call, which just sets the title of our
     * new window to "Hello Buttons!" */
    gtk_window_set_title (GTK_WINDOW (window), "Hello Buttons!");

    /* Here we just set a handler for delete_event that immediately
     * exits GTK. */
    g_signal_connect (window, "delete-event",
                      G_CALLBACK (delete_event), NULL);

    /* Sets the border width of the window. */
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);

    /* We create a box to pack widgets into.  This is described in detail
     * in the "packing" section. The box is not really visible, it
     * is just used as a tool to arrange widgets. */
    box1 = gtk_hbox_new (FALSE, 0);

    /* Put the box into the main window. */
    gtk_container_add (GTK_CONTAINER (window), box1);

    /* Creates a new button with the label "Button 1". */
    button = gtk_button_new_with_label ("Button 1");

    /* Now when the button is clicked, we call the "callback" function
     * with a pointer to "button 1" as its argument */
    g_signal_connect (button, "clicked",
                      G_CALLBACK (callback), (gpointer) "button 1");

    /* Instead of gtk_container_add, we pack this button into the invisible
     * box, which has been packed into the window. */
    gtk_box_pack_start (GTK_BOX(box1), button, TRUE, TRUE, 0);

    /* Always remember this step, this tells GTK that our preparation for
     * this button is complete, and it can now be displayed. */
    gtk_widget_show (button);

    /* Do these same steps again to create a second button */
    button = gtk_button_new_with_label ("Button 2");

    /* Call the same callback function with a different argument,
     * passing a pointer to "button 2" instead. */
    g_signal_connect (button, "clicked",
                      G_CALLBACK (callback), (gpointer) "button 2");

    gtk_box_pack_start(GTK_BOX (box1), button, TRUE, TRUE, 0);

    /* The order in which we show the buttons is not really important, but I
     * recommend showing the window last, so it all pops up at once. */
    gtk_widget_show (button);

    gtk_widget_show (box1);

    gtk_widget_show (window);

    /* Rest in gtk_main and wait for the fun to begin! */
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

	
   create_widget_ui(argc,argv);   
    
    return 0;
}
