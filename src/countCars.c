#include <stdio.h>
#include "../include/headerA3.h"

int countCars(a3Car *headLL)
{
    /*  This function takes a LL as its only parameter, counts,
    and returns the total number of cars (i.e., nodes) in the given LL.
    Note that this function does not print any information. In the sample shown below for menu
    option 7, a message with total number of cars is printed in main; is shown here only for demo.
    In the given sample, red font indicates user input.
    Choose a menu option: 7
    Total number of cars = 2*/

    // initialize current below to the head of the linked list
    a3Car *newHead = headLL;

    if (newHead == NULL)
    {
        printf("LL is empty\n");
    }

    // need a counter to keep track of # of cars
    int counter = 0;

    // to count the number of cars, we should traverse through the LL
    while (newHead != NULL)
    {
        // moving onto the next car , or node in our LL
        newHead = newHead->nextCar;

        // incrementing the counter for each node
        counter++;
    }
    // return our counter
    return counter;
}