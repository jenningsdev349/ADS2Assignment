#ifndef H1_H
#define H1_H
#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Preprocessor Variable
#define SIZE 1
#endif

//Stucture template for one node
struct LinearNode {
    struct Data *element;
	struct LinearNode *next;
};

//Structure template for a car
struct Car{
    char carReg[10];
    char carMake[20];
    char carModel[20]; 
    char colour[20];
    int previousOwners;
    bool reserved;
    int reserveAmount;
};

//Stucture template for data part of the linked list
 struct Data {
    struct Car carInfo;
 };

// Function prototypes
void addCar();
void sellCar();
void carReserve();
bool isEmpty();
void viewAllCars();
void viewCar();
void getFromFile(FILE *);

// Global Variables
struct LinearNode *front = NULL; //front of the list
struct LinearNode *last = NULL; //pointer to last node in the list - not used in this code