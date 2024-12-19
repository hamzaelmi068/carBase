#include <stdio.h>
#include "../include/headerA3.h"
#include "locale.h"

void printAll(struct car *headLL)
{
    /*if option 3 is selected, a function called printAll is called. This function prints the data of all cars
    currently in the LL.
    Note that if the linked list is empty, then the function must print a message “No cars found"*/

    
    struct car *current = headLL;

    // we need to check if the list is empty first, so lets go ahead and do that
    if (current == NULL)
    {
        printf("No cars Found\n");
        return;
    }

    // Iterate through the linked list
    while (current != NULL)
    { // While the current node is not NULL

        setlocale(LC_NUMERIC, "");
        static int counter = 0;          // makes counter a static var, retains its value inbetween calls
        counter++;                       // incremenets every time addnewCar is called
        printf("\nCar #%d: \n", counter); // indicating which car data # is added to the linked list

        // Print the details of the current car
        printf("\tCar Id: %d \n", current->carId);
        printf("\tModel: %s \n", current->model);              // Print the car's model
        printf("\tType: %s \n", current->type);                // Print the car's type
        printf("\tPrice: %'.2lf\n", current->price); // Use %'.2f for formatted price
        printf("\tYear of Manufacture: %d \n", current->year); // Print the car's year

        // moving onto the next node below
        current = current->nextCar;

        printf("\nCurrently, there are %d cars.\n", counter);
    }
}