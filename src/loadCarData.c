#include <stdio.h>
#include "../include/headerA3.h"

void loadCarData(struct car **headLL, char fileName[MAX_LENGTH])
{
    /* If option 2 is selected, a function called loadCarData is called. This function loads car data from
    a given text file and adds them to the current linked list. It is safe for you to assume that the
    carIds for all car data in the file are unique from each other. But if the carId data loaded from
    the file for a given car is the same as any of the carIds in the existing linked list, then you must
    use the same rule for uniqueness as given in menu option 1*/

    FILE *fptr;
    // opening the inputfile.txt here, hardcoded the name in main
    fptr = fopen(fileName, "r");

    // checking if the file is empty
    if (fptr == NULL)
    {
        printf("the file doesnt exist\n");
        return;
    }

    // newnocde of struct car
    struct car *newNode;
    int carId, year;
    char model[MAX_LENGTH], type[MAX_LENGTH];
    double price;

    // we'll loop through each line from the file
    while (fscanf(fptr, "%d,%[^,],%[^,],%d,%lf", &carId, model, type, &year, &price) == 5)
    {
        // initializing temp to the head
        struct car *temp = *headLL;
        // check for duplicates
        while (temp != NULL)
        {
            if (temp->carId == carId)
            {
                // we handle this case based on the uniqueness rule for carids given in the outline
                carId = 0;
                for (int j = 0; j < strlen(model); j++)
                {
                    carId = carId + model[j];
                }
                for (int i = 0; i < strlen(type); i++)
                {
                    carId = carId + type[i];
                }
            }
            // need to assign the calculated carid to the new temp node
            temp = temp->nextCar;
        }
        // allocate memory for new nodes and set it to our members
        newNode = (struct car *)malloc(sizeof(struct car));
        newNode->carId = carId;
        strcpy(newNode->model, model);
        strcpy(newNode->type, type);
        newNode->year = year;
        newNode->price = price;
        newNode->nextCar = NULL;

        // finally, add the new node to the linked list
        // if the list is empty, set the head of the list to the new node
        if (*headLL == NULL){
            *headLL = newNode;
        }
        else{
            // if the list isnt empty, start from the head of the list
            temp = *headLL;
            // we then traverse until reaching the very end
            while(temp->nextCar != NULL){
                // moving to next node in the list
                temp = temp->nextCar;
            }
            // once the last node is found, have to set nextCar ptr to newNode
            temp->nextCar = newNode;
        }
    }
    // closing the file
    fclose(fptr);
}