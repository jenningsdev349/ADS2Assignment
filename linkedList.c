#include "h1.h" 

//2nd Commit - Partially implemented addCar method - CURRENTLY NOT WORKING
//3rd Commit - Fixed, is working
//adds 1 car to the linkedList
void addCar() {	
	int i;
	struct LinearNode *aNode;
	struct Data *anElement;

	if(size() >= SIZE){ //checks if the limit of cars has been reached.
		printf("Sorry, no more than %d cars can be added.\n\n", SIZE);
		return;
	}
    
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
			
	if (isEmpty()){  //add node to front of the list
		front = aNode;
		last = aNode;
		 }
	else {
		aNode->next = front;
		front = aNode;
		} //end else
}//end addCar


//3rd Commit - implemented this method
//sells a car specified by the car registration
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
			if (strcmp(tempCarReg, current->element->carInfo.carReg) == 0 && current->element->carInfo.reserved == true){//compares user input car reg with current car reg and checks if current car is reserved
				found = true;
				}	
			else {
				previous = current;
				current = current->next;
			}//end else
		} //end while
			
	if (!found)
		printf("\nError - there is no such car with Car Registration or car is unreserved %s\n", tempCarReg);
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
			printf("\nCar with Car Registration %s has been sold and removed from system\n", tempCarReg);
			}//end else
}//end method

//3rd commmit - implemented this method - currently no deposit feature
//4th commit - added deposit feature
//allows user to reserve/unreserve a car and pay a deposit between 500-1500
void carReserve(){
	struct LinearNode *current, *previous;
	int depositAmount;
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
		if(current -> element->carInfo.reserved == true){ //if car is already reserved, unreserve and remove deposit
			current -> element->carInfo.reserved = false;
			current ->element->carInfo.reserveAmount = 0;
			printf("\nCar with Car Registration %s has been unreserved\n\n", tempCarReg);
		}
		else{// if car unreserved, ask for deposit amount and set car as reserved
			do{
				printf("\nEnter deposit amount between 500-1500:\n\n");
				scanf("%d", &depositAmount);
			}while(depositAmount < 500 || depositAmount > 1500);
			current -> element->carInfo.reserveAmount = depositAmount;
			current -> element->carInfo.reserved = true;
			printf("\nCar with Car Registration %s has been reserved\n\n", tempCarReg);
		}
	}
}

//checks to see if linkedList is empty
bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}

//4th commit - added method to check size of Linked List to ensure more cars cannot be added than what is allowed.
int size() {
    int count = 0;
    struct LinearNode *current = front;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

//3rd Commit - implemented this method - currently no option to filter by category
//displays all cars in linkedList
void viewAllCars() { //While list is not empty and the current is not null, print off the value held in element
	struct LinearNode *current;

	if (isEmpty())
		printf("\nError - there are no cars in the list\n");
	else {
		current = front;
		while (current != NULL) {
			//display details
			printf("\nCar Registration is %s", current ->element->carInfo.carReg);
			printf("\nCar Make is %s", current->element->carInfo.carMake);
			printf("\nCar Model is %s", current->element->carInfo.carModel);
			printf("\nCar Colour is %s", current->element->carInfo.colour);
			printf("\nNumber of previous owners is %d", current->element->carInfo.previousOwners);
			if(current -> element->carInfo.reserved == true){ //changed in 4th commit - avoids printing boolean value directly
				printf("\nReserved : Yes");
				}
			else{
				printf("\nReserved : No");
				}
			printf("\nReserve Amount: %d\n", current->element->carInfo.reserveAmount);
				current=current->next;
			} //end while
		    }//end else
		printf("\nPress return to go back to menu\n\n");
		getchar();
		getchar();
} //end viewAllCars

//3rd Commit - Implemented this method
//views car specified by car registration
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
				//display details
				printf("\nCar Registration is %s", current->element->carInfo.carReg);
				printf("\nCar Make is %s", current->element->carInfo.carMake);
				printf("\nCar Model is %s", current->element->carInfo.carModel);
				printf("\nCar Colour is %s", current->element->carInfo.colour);
				printf("\nNumber of previous owners is %d", current->element->carInfo.previousOwners);
				if(current -> element->carInfo.reserved == true){
					printf("\nReserved : Yes");
				}
				else{
					printf("\nReserved : No");
				}
				printf("\nReserve Amount: %d", current->element->carInfo.reserveAmount);
    }//end else
}
//reads data from binary file and inputs it into linkedList
void getFromFile(FILE *fp) {
    struct Car car;
    struct LinearNode *current, *aNode;
	current = front;
	
    if (fp == NULL){//error checking, if the file doesn't exist then data will not be read.
		printf("File does not exist. Data cannot be read.");
	}
	else{
		fp = fopen("Car.dat", "rb");
	}

    while (fread(&car, sizeof(struct Car), 1, fp) != 0) {
        aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode)); //allocate memory for node
        aNode->element = (struct Car *)malloc(sizeof(struct Car)); //allocate memory for element in node, which will contain the car information.

        aNode->element->carInfo = car; //copies information into the node element
        aNode->next = NULL;

		//add node to linkedList
        if (front == NULL) {
            front = last = aNode;
        } else {
            last->next = aNode;
            last = aNode;
        }
    }

    fclose(fp);
    printf("Success! Cars read from file.\n");
}

//4th commit - implemented this method
//saves cars from linkedList into binary file
void saveToFile(FILE *fp){
	struct LinearNode *current = front;
	if (fp == NULL){//error checking, if the file doesn't exist then data will not be written.
		printf("File does not exist. Data cannot be written.");
	}
	else{
		fp = fopen("Car.dat", "wb");
	}

	while(current != NULL){//while current isn't null, write the info from carInfo into the binary file.
		fwrite(&(current->element->carInfo), sizeof(struct Car), 1, fp);
		current = current->next;
	}

	printf("\nCars written to binary file successfully.\n");
	getchar();
}

//4th commit - custom method. Allows user to search list by car registration and update make, model, colour or amount of previous owners
void updateDetails(){
	struct LinearNode *current, *previous;
	char tempCarReg[10];
	bool found = false;
	int input = 0;

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
		if (strcmp(tempCarReg, current->element->carInfo.carReg) == 0){ // compare user input car reg and car reg currently held to see if they are the same
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
		//print current car details 
		printf("Car Found! Details of car:\n");
        printf("Car Registration: %s\n", current->element->carInfo.carReg);
        printf("Car Make: %s\n", current->element->carInfo.carMake);
        printf("Car Model: %s\n", current->element->carInfo.carModel);
        printf("Car Colour: %s\n", current->element->carInfo.colour);
        printf("Number of Previous Owners: %d\n", current->element->carInfo.previousOwners);

		do{
			//display menu and allow user to input new details for any individual category. returns to main menu when 5 is selected
			printf("\nType 1 to change car make, 2 to change car model, 3 to change colour and 4 to change previous number of owners. 5 returns to menu.\n");
			scanf("%d", &input);
			switch(input){
				case 1:
				printf("Enter new details for car make:");
				scanf("%s", current->element->carInfo.carMake);
				printf("\nChanges made successfully.\n");
				break;
				case 2:
				printf("Enter new details for car model:");
				scanf("%s", current->element->carInfo.carModel);
				printf("\nChanges made successfully.\n");
				break;
				case 3:
				printf("Enter new details for car colour:");
				scanf("%s", current->element->carInfo.colour);
				printf("\nChanges made successfully.\n");
				break;
				case 4:
				do{
					printf("Enter new details for number of previous owners:");
					scanf("%d", current->element->carInfo.previousOwners);
				}while(current->element->carInfo.previousOwners > 3 || current->element->carInfo.previousOwners < 0);
				printf("\nChanges made successfully.\n");
				break;
				default:
				printf("Invalid option! Please enter a new input.");
			}
		}while(input != 5);
	}//end else
}//end updateDetails()

//2nd commit - added menu
//4th commit - file handling added
//main method has file handling and menu that allows user to select methods.
void main(){
	FILE *fp;
	int input;
	char tempCarReg[10];
	struct LinearNode *current, *previous;
	bool found = false;

	fp = fopen("Car.dat", "rb"); //opens car.dat in read binary file mode
	if((fp == NULL)){ //if car.dat does not exist, user must enter cars
		printf("There is no existing record of cars in the database. You will need to enter cars into the database.\n");
		printf("Entering cars...\n");
		for(int i=0;i<SIZE;i++){
			addCar();
		}
	}
	else{
		printf("Retrieving cars from Car.dat...\n");
		getFromFile(fp); //reads data from binary file and inputs it into the linkedList
		fclose(fp);
	}

	do{
		//display menu, displays and enters methods until user selects option 7
		printf("Car Showroom Management Software\n");
		printf("----------------------------------\n");
		printf("1. Add a car to the showroom\n");
		printf("2. Sell a car from the showroom\n");
		printf("3. Reserve/Unreserve a car from the showroom\n");
		printf("4. View all cars in the showroom\n");
		printf("5. View single car in the showroom\n");
		printf("6. Update car details\n");
		printf("7. Exit Software\n\n");
		
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
			viewCar();
			break;
		case 6:
			updateDetails();
			break;
		case 7:
			printf("\nExiting car showroom program... \n");
			printf("Cars are being saved to binary file..");
			fp = fopen("Car.dat", "wb"); //opens Car.dat in write to binary file mode
			saveToFile(fp); //saves cars to file
			fclose(fp);
			break;
		default:
		printf("This is an invalid option! Please try again.\n");
		}//end switch
	}while(input != 7);
}//end main
