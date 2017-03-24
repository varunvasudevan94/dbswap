#include "linked_list.h"



void init_linked_list(node **start){
	*start=NULL;

}


void insert_linked_list(node **start,char *commit,char *message){
	node *newnode=(node *)malloc(sizeof(node));
	strcpy(newnode->commit,commit);
	strcpy(newnode->message,message);
	

	if (*start==NULL){
		*start=newnode;		
		return;
	}

	newnode->next=*start;
	*start=newnode;

}

int count=0;
// modify this to the UI
void print_linked_list(node *start){
	
	node *temp=start;
	if (start==NULL)
		return;
	print_linked_list(start->next);
	printf("%s\n",temp->message);
	/*while (temp){
		printf("%s\n",temp->message);
		temp=temp->next;
	}*/



}

int main(){
	node *start;
	init_linked_list(&start);
	insert_linked_list(&start,"hi","1");
	insert_linked_list(&start,"hia","2");
	insert_linked_list(&start,"hib","3");
	insert_linked_list(&start,"hic","4");
	insert_linked_list(&start,"hid","5");
	print_linked_list(start);


	return 0;
}
