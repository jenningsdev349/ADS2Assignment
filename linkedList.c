#include "h1.h" 

//2nd Commit - Partially implemented addCar method - CURRENTLY NOT WORKING
//3rd Commit - Fixed, is working
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
		 scanf("%d", &anElement -> carInfo.previousOwners);
		 getchar();
		 
		 //previous number of owners cannot be greater than 3 or less than 0
		 while(anElement -> carInfo.previousOwners > 3 || anElement -> carInfo.previousOwners < 0){
			printf("Invalid! Car cannot have more than 3 previous owners or less than 0 previous owners.");
			printf("Enter Number of Previous Owners: ");
			scanf("%d", &anElement -> carInfo.previousOwners);
		 	getchar();

			anElement -> carInfo.reserved = false; //cars are set to unreserved by default
		}
		 
		 aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode)); // create space for new node

		if (aNode == NULL)
			printf("Error - no space for the new car\n");
		else{// add data part to the node
		 	aNode->next = NULL;
		 	aNode->element = anElement;
			}
			
		if (isEmpty())  //add node to front of the list
			{
				front = aNode;
				last = aNode;
		    }
			else {
				aNode->next = front;
				front = aNode;
			} //end else
		}//end else
	}//end addCar


//3rd Commit - implemented this method
void sellCar() {
	struct LinearNode *current, *previous;
	char tempCarReg[10];
	bool found = false;

	if (isEmpty()){
		printf("\nThere are no cars in the list!\n");
		return;
		}
	else{
			current = previous = front;
	}  
		printf("Enter the car registration you would like to search for:");
		scanf("%s", tempCarReg);

			while (!found && current != NULL) {
				if (strcmp(tempCarReg, current->element->carInfo.carReg) == 0){
					found = true;
				}	
				else {
						previous = current;
						current = current->next;
				}//end else
			} //end while

			if (!found)
				printf("\nError - there is no such car with Car Registration %s\n", tempCarReg);
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
				printf("\nCar with Car Registration %s has been deleted from the list\n", tempCarReg);
			}//end else
}//end method

//3rd commmit - implemented this method - currently no deposit feature
void carReserve(){
	struct LinearNode *current, *previous;
	char tempCarReg[10];
	bool found = false;

	if (isEmpty()){
		printf("\nThere are no cars in the list!\n");
		return;
		}
	else{
			current = previous = front;
	}  
		printf("Enter the car registration you would like to search for:");
		scanf("%s", tempCarReg);
			while (!found && current != NULL) {
				if (strcmp(tempCarReg, current->element->carInfo.carReg) == 0){
					found = true;
				}	
				else {
						previous = current;
						current = current->next;
				}//end else
			} //end while

	if(!found){
		printf("\nError - there is no such car with Car Registration %s\n", tempCarReg);
	}
	else{
		if(current -> element->carInfo.reserved == true){
			current -> element->carInfo.reserved = false;
			printf("Car with Car Registration %s has been unreserved", tempCarReg);
		}
		else{
			current -> element->carInfo.reserved = true;
			printf("Car with Car Registration %s has been reserved", tempCarReg);
		}
	}
}

void getFromFile(FILE *fp){

}

//checks to see if linkedList is empty
bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}

//3rd Commit - implemented this method - currently no option to filter by category
void viewAllCars() { //While list is not empty and the current is not null, print off the value held in element
	struct LinearNode *current;

	if (isEmpty())
		printf("\nError - there are no cars in the list\n");
	else {
			current = front;
			while (current != NULL) {
				printf("\nCar Registration is %s", current ->element->carInfo.carReg);
				printf("\nCar Make is %s", current->element->carInfo.carMake);
				printf("\nCar Model is %s", current->element->carInfo.carModel);
				printf("\nCar Colour is %s", current->element->carInfo.colour);
				printf("\nNumber of previous owners is %d", current->element->carInfo.previousOwners);
				printf("\nReserved? %s", current->element->carInfo.reserved);
				printf("\nReserve Amount: %d", current->element->carInfo.reserveAmount);
				current=current->next;
			} //end while
    }//end else
} //end viewAllCars

//3rd Commit - Implemented this method
void viewCar(){
	struct LinearNode *current, *previous;
	char tempCarReg[10];
	bool found = false;

	if (isEmpty()){
		printf("\nThere are no cars in the list!\n");
		return;
		}
	else{
			current = previous = front;
	}  
		printf("Enter the car registration you would like to search for:");
		scanf("%s", tempCarReg);

			while (!found && current != NULL) {
				if (strcmp(tempCarReg, current->element->carInfo.carReg) == 0){
					found = true;
				}	
				else {
						previous = current;
						current = current->next;
				}//end else
			} //end while

	if (!found)
		printf("\nError - there is no such car with Car Registration %s\n", tempCarReg);
	else {
				printf("\nCar Registration is %s", current ->element->carInfo.carReg);
				printf("\nCar Make is %s", current->element->carInfo.carMake);
				printf("\nCar Model is %s", current->element->carInfo.carModel);
				printf("\nCar Colour is %s", current->element->carInfo.colour);
				printf("\nNumber of previous owners is %d", current->element->carInfo.previousOwners);
				printf("\nReserved? %s", current->element->carInfo.reserved);
				printf("\nReserve Amount: %d", current->element->carInfo.reserveAmount);
    }//end else
}

//2nd commit - added menu
void main(){
	FILE *fp;
	int input;

	if((fp = fopen("car.dat", "rb") == NULL)){ //if car.dat does not exist, user must enter cars
		printf("There is no existing record of cars in the database. You will need to enter cars into the database.\n");
		printf("Entering cars...\n");
		addCar();
	}
	else{
	}

	printf("Car Showroom Management Software\n");
	printf("----------------------------------\n");
	printf("1. Add a car to the showroom\n");
	printf("2. Sell a car from the showroom\n");
	printf("3. Reserve/Unreserve a car from the showroom\n");
	printf("4. View all cars in the showroom\n");
	printf("5. View single car in the showroom\n");
	printf("6. UNIMPLEMENTED CUSTOM OPTION\n");
	printf("7. Exit Software\n\n");

	do{
		printf("\nPlease select an option:\n");
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
