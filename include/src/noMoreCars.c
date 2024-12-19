#include <stdio.h>
#include "../include/headerA3.h"

void noMoreCars(a3Car **headLL)
{
    /* In this option, a function called noMoreCars is called. This function first prompts the user to
    confirm with a y or n, and then removes all cars from the current LL. Note that user must be
    repeatedly prompted to enter a valid value of ‘y’ or ‘n’. It then prints the message “All
    removed. Linked list is now empty”.*/
    char option10;
    do
    {
        printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
        scanf(" %c", &option10);
    } while (option10 != 'y' && option10 != 'n');

    if (option10 == 'y' ){
        // intitialize current to the head of the LL, and next to traverse the LL
        a3Car *current = *headLL;
        a3Car *nextNode;

        // checking if the LL is empty
        if (current == NULL){
            printf("The current LL is empty\n");
            return;
        }

    // traversing through the LL and freeing each node
    while(current != NULL){
        nextNode = current->nextCar; // saving the next car
        free(current); // freeing memory of current node
        current = nextNode; // move on to the next node
    }
    
    // updating the head pointer
    *headLL = NULL; 
    printf("All removed. Linked list is now empty.\n");
    }   
    else if (option10 == 'n'){ // if the user enters n, we dont remove anything, and just return;
        printf("No cars will be removed, menu is reprinted below\n");
        return;
    }
}