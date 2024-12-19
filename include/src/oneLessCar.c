#include <stdio.h>
#include "../include/headerA3.h"

// remember to go through the cases for this function:
/* first case when the inputted number is 1 and there are more than 1 nodes so i’m replacing the head
case 2 if they remove the last node
case 3 if they remove a node in between the first and last node - this one was a little harder cuz you had to store the node before the one to be removed and point it to the node after the removed one
case 4 if there is only one element in the list so that you can equal headLL to null 
*/

void oneLessCar (a3Car ** headLL, int whichOne){
    /* In this option, a function called oneLessCar is called. This function takes 2 parameters, a linked
    list and an int value to indicate the node number to remove. It then removes that node (and the
    car information stored in it) from the LL*/

    // intialize current to the head of the LL
    a3Car * current = *headLL;
    a3Car *prev = NULL;

    // initialize current to the ha

    if (current == NULL){
        printf("The LL is empty\n");
        return;
    }

    int i = 1;
    // finding the node before the node to be deleted
    while(current != NULL && i < whichOne - 1){
        // traversing to the next node
        current = current->nextCar;
    }

    // if position is more then the number of nodes, or if the LL is empty
    if (current == NULL || current->nextCar == NULL){
        printf("Position is more than the number of cars in the list.\n");
        return;
    }

    // node temp points to the node being deleted
    a3Car *temp = current->nextCar;
    
    // store car id
    int storeId = temp->carId;

    // if the node to remove is the first car
    if (prev == NULL){
        *headLL = current->nextCar;
    }
    else{
        prev->nextCar = current->nextCar;
    }

    // unlink node from LL
    current->nextCar = temp->nextCar;

    free(temp); // free memory of removed node

    // print the id of the removed car
    printf("Car [ID: %d] removed.\n", storeId);

}