#include "linked_list.h"



void init_linked_list(node **start){
	*start=NULL;

}


void insert_linked_list(node **start,char *commit,char *message){
	node *newnode=(node *)malloc(sizeof(node));
	if (commit!=NULL)
	strcpy(newnode->commit,commit);
	if (message!=NULL)
	strcpy(newnode->message,message);
        newnode->next=NULL;	

	if (*start==NULL){
		*start=newnode;		
		return;
	}

	newnode->next=*start;
	*start=newnode;

}


// modify this to the UI
void print_linked_list(node **start){
	
	
	if (start==NULL)
		return;
	print_linked_list(start->next);
	printf("%s\n",start->message);
	


}


