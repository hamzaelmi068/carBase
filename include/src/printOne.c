#include <stdio.h>
#include "../include/headerA3.h"
#include "locale.h"

void printOne(struct car *headLL, int whichOne)
{
    /* If option 4 is selected, a function called printOne is called. This function takes a position number
    (i.e., an int) as its input parameter and prints the data of the car at that position in the current
    LL. Assume that the head of the linked list is at position 1.
    For example: if there are 2 cars in the current LL as shown in menu option 2, and the position
    entered is 2,

    In the given sample, red font indicates user input.
    Choose a menu option: 4
    Enter a position: 2
    Car id: 645
    Model: Toyota
    Type: Camry
    Price: CDN $55,000.00
    Year of Manufacture: 2022
    <Reprint the menu>*/

    // we start by initializing current to the head of the linked list
    struct car *current = headLL;
    int position = 1; // were given to assume the LL starts at position 1

    if (current == NULL)
    {
        printf("The linked list is empty, couldnt find the car you selected\n");
        return;
    }

    // iterating through the linked list, if it isnt empty, and the position is less then the n value from the user, we keep going to the next car
    for (position = 1; current != NULL && position < whichOne; position++)
    {
        current = current->nextCar;
    }
    if (current != NULL)
    {   
        setlocale(LC_NUMERIC, "");
        printf("\nCar Id: %d \n", current->carId);
        printf("Model: %s \n", current->model);
        printf("Type: %s \n", current->type);
        printf("Price: %'.2f\n", current->price); // Use %'.2f for formatted price
        printf("Year of Manufacture: %d \n", current->year);
    }
    else
    {
        printf("couldnt find the car your looking for at posiition %d\n", whichOne);
    }
}
