#include <stdio.h>
#include "../include/headerA3.h"

void addNewCar (struct car ** headLL){
    /* This option calls a function named addNewCar that prompts the user to enter car data from
    standard input and add their information to the end of the linked list passed as a parameter to
    this function. The user enters the model, type of the car, its price and year of manufacture
    This function must store new cars at the tail end of the current linked list.*/

    // we can start by creating a new node that'll hold the car info, and allocate memory too
    struct car *newNode = (struct car*)malloc(sizeof(struct car));
    // if the new car or node is empty, we need to check
    if (newNode == NULL){
        printf("memory couldnt be allocated\n");
        return;
    }
    printf("\nEnter car model: ");
    scanf("%s", newNode->model);
    printf("Enter car type: ");
    scanf("%s", newNode->type);
    printf("Enter its year of manufacture: ");
    scanf("%d", &newNode->year);
    printf("Enter price: CDN $ ");
    scanf("%lf", &newNode->price);

    int carId = 0;
    for (int j = 0; newNode->model[j] != '\0'; j++) {
        carId += newNode->model[j]; // Adding the ASCII value of each character
    }
    // Add the length of the car's type to carId
    carId += strlen(newNode->type);

    // Check if the carId is already used, and update it if necessary
    while (newNode->carId == carId) {
        carId = rand() % 999 + 1;
    }
    newNode->carId = carId;

    // need to assign the calculated carid to the new node
    newNode->carId = carId;

    // need to set the next ptr after the new node to null
    newNode->nextCar = NULL;
    if(*headLL == NULL){
        *headLL = newNode; // if the list is empty, we make the new node the head
    }
    else{
        struct car *lastCar = *headLL;
        while(lastCar->nextCar != NULL){
            lastCar = lastCar->nextCar; // we traverse to the last node
        }
        lastCar->nextCar = newNode; // linking the new node to the end of the list
    }
}