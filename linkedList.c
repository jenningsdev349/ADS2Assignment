/**************************************************************/
/*                                                            */
/*   Program to demonstrate the implmentation of a simple     */
/*   linked list of letters with a delete option.					  */
/*                                                            */
/**************************************************************/

#include "h1.h"
	
/**********ADD THREE NODES TO THE LIST******************/
// Each new node is added to the front of the front 

void addNodes() {	
	int i;
	char value;
	struct LinearNode *aNode;
	struct Data *anElement;

	// add SIZE nodes to the front
	for (i=0; i<SIZE; i++) {
		printf("Enter a letter for node : ");
		value= getchar();
        getchar(); //clear the scanner
         //create space for new data element
         anElement = (struct Data *)malloc(sizeof(struct Data));
         
		// create space for new node
		aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

         //add aNumber to data node
         anElement->letter= value; 
     
		if (aNode == NULL)
			printf("Error - no space for the new node\n");
		else { // add data part to the node
		 	aNode->next = NULL;
		 	aNode->element = anElement;

			//add node to front of the node
			if (isEmpty())  
			{
				front = aNode;
				last = aNode;
		    }
			else {
				aNode->next = front;
				front = aNode;
			} //end else
		}//end else
	}//end for
} //end addNodes
 			

void viewAllNodes() {
	struct LinearNode *current;

	if (isEmpty())
		printf("\nError - there are no nodes in the list\n");
	else {
			current = front;
			while (current != NULL) {
				printf("\nNode value is %c\n", current->element->letter);
				current=current->next;
			} //end while
    }//end else
} //end viewAllNodes


void deleteNode(char value) {
	struct LinearNode *current, *previous;
	bool found = false;

	if (isEmpty())
		printf("\nError - there are no nodes in the list\n");
	else  {
			current = previous = front;

			while (!found && current != NULL) {
				if (value == current->element->letter)
					found = true;
				else {
						previous = current;
						current = current->next;
				}//end else
			} //end while

			if (!found)
				printf("\nError - there is no such node with value %d\n", value);
			else  { //find out the position of the node to delete
				if (current == front) {
					front = front->next;
					free(current);
				} //end else
				else if (current == last){
					last = previous;
					last->next=NULL;
					free(current);
				}
				else { //delete an element in the middle of the list
						previous->next= current->next;
						free(current);
				} //end else
				printf("\nNode with value %c has been deleted from the list\n", value);
			}//end else
		}//end else
}// end deleteNode


bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}

void main(){
	
}
