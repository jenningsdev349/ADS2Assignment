#ifndef H1_H
#define H1_H
#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h>

//Preprocessor Variable
#define SIZE 3
#endif 

//Stucture template for data part of the linked list
 struct Data {
 	char letter;
 };

//Stucture template for one node
struct LinearNode {
    struct Data *element;
	struct LinearNode *next;
};

//Structure template for a car
struct Car{
    char carMake[20];
    char carModel[20]; 
    char colour[20];
    int previousOwners;
    bool reserved;
    int reserveAmount;
};

// Function prototypes

// Global Variables
struct LinearNode *front = NULL; //front of the list

struct LinearNode *last = NULL; //pointer to last node in the list - not used in this code