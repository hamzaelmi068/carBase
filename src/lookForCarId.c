#include <stdio.h>
#include "../include/headerA3.h"


int lookForCarId(struct car * headLL, int key){
    /* If option 5 is selected, a function called lookForCarId is called to do the following: lookForCarId
    takes 2 parameters (i.e., a linked list and a carId), it then searches the given LL for this carId. If
    found, its position in the given LL is returned, otherwise the function returns -1*/

    // intializing the head to current
    struct car *current = headLL;

    // checking if the the LL is empty
    if (current == NULL){
        printf("The linked list is empty\n");
        return -1;
    }

    int position = 1;
    // while the starting point isnt empty
    while(current != NULL){
        if (current->carId == key){
            return position;
        }
        // move onto the next node
        current = current->nextCar;
        position = position + 1;
    }
    
    printf("The position is %d\n", position);
    // if we cant find the car, we have to return -1
    return -1;
   
}
