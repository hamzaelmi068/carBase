#include <stdio.h>
#include "../include/headerA3.h"

void sortCarId (struct car ** headLL){
    /* Call function sortCarId for this option. This function takes a LL and sorts it based on carId.
    In the given sample, red font indicates user input.
    Choose a menu option: 8
    Note that this function does not print any information. In the sample shown below for menu
    option 8, the linked list is printed in main and is shown here only for demo.
    Note that it is a coincidence that the car data used in this option is already sorted, do not
    assume that this is always the case). */

    // assinging ptrs to null, so they dont point to unneccesary memory locations
    struct car *current = NULL;
    struct car *index = NULL;

    // temp variable for the swapping we do later
    struct car temp;

    if (*headLL == NULL){
        printf("The LL is empty\n");
        return; // void for return is just return
    }

    // https://courselink.uoguelph.ca/d2l/le/content/869864/viewContent/3778880/View - Slide 32 - Bubble sort
    // iterating through each node in the linked list, as long as the LL isnt empty, we move onto the next car
    for (current = *headLL; current->nextCar != NULL; current = current->nextCar){
        // for each node that current points to, we compare current with with every node that comes after in the LL
        for (index = current->nextCar; index != NULL;  index = index->nextCar){
            // if the current carid is greater then the index node, then we need to swap them   
            if (current->carId > index->carId){
                temp =  *current;
                *current = *index;
                *index = temp;

                // reseting the nextcar pointers of the nodes we just swapped
                temp.nextCar = current->nextCar;
                current->nextCar = index->nextCar;
                current->nextCar = index->nextCar;
                index->nextCar = temp.nextCar;
            }
        }
    }
}