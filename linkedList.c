#include "h1.h" 

//2nd Commit - Partially implemented addCar method - CURRENTLY NOT WORKING
void addCar() {	
	int i;
	struct LinearNode *aNode;
	struct Data *anElement;

	for (i=0; i<SIZE; i++) {
         anElement = (struct Data *)malloc(sizeof(struct Data)); //create space for new data element

		 //Enter Car information
		 printf("Enter Car Registration: ");
		 scanf("%s", anElement -> carInfo.carReg);
		 getchar();
		 getchar();

		 printf("Enter Car Make: ");
		 scanf("%s", anElement -> carInfo.carMake);
		 getchar();

		 printf("Enter Car Model: ");
		 scanf("%s", anElement -> carInfo.carModel);
		 getchar();

		 printf("Enter Car Colour: ");
		 scanf("%s", anElement -> carInfo.colour);
		 getchar();

		 printf("Enter Number of Previous Owners: ");
		 scanf("%d", anElement -> carInfo.previousOwners);
		 getchar();
		 
		 aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode)); // create space for new node

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

void sellCar() {
	char value;
	struct LinearNode *current, *previous;
	bool found = false;

	if (isEmpty())
		printf("\nError - there are no nodes in the list\n");
	else  {
			current = previous = front;

			while (!found && current != NULL) {
				if (value == current->element)
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

void carReserve(){

}

bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}

void viewAllCars() {
	struct LinearNode *current;

	if (isEmpty())
		printf("\nError - there are no nodes in the list\n");
	else {
			current = front;
			while (current != NULL) {
				printf("\nNode value is %c\n", current->element);
				current=current->next;
			} //end while
    }//end else
} //end viewAllNodes

//2nd commit - added menu
void main(){
	int input;

	printf("Car Showroom Management Software\n");
	printf("1. Add a car to the showroom\n");
	printf("2. Sell a car from the showroom\n");
	printf("3. Reserve/Unreserve a car from the showroom\n");
	printf("4. View all cars in the showroom\n");
	printf("5. View single car in the showroom\n");
	printf("6. UNIMPLEMENTED CUSTOM OPTION\n");
	printf("7. Exit Software\n\n");

	do{
		printf("Please select an option:\n");
		scanf("%d", &input);
		switch(input){
		case 1:
			addCar();
			break;
		case 2:
			sellCar();
			break;
		case 3:
			carReserve();
			break;
		case 4:
			viewAllCars();
			break;
		case 5: 
			viewAllCars();
			break;
		case 6:
			break;
		case 7:
			printf("Exiting car showroom program... ");
			break;
		default:
		printf("This is an invalid option! Please try again.\n");
	}
	}while(input != 7);
}
