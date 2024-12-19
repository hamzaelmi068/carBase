#include <stdio.h>
#include "../include/headerA3.h"

int lookForCarModelType (struct car * headLL, char key [100]){
    /* If option 6 is selected, a function called lookForCarModelType is called to do the following: the
    function takes 2 parameters (i.e., a linked list and a single string that stores the car model and
    type), it then searches the given LL for this car model and type. If found, its position in the given
    LL is returned, otherwise the function returns -1*/

    // initializing pointer current to the head of our LL
    struct car *current = headLL;

    // If the linked list is empty, return -1
    if (current == NULL){
        printf("LL is empty\n");
        return -1;
    }

    // initializing position to 0
    int position = 0;
    // splitting the key string into model and type
    char *model = strtok(key, " "); 
    char *type = strtok(NULL, " ");

    // traversing through the LL while it isnt empty
    while (current != NULL) {
        char combined[MAX_LENGTH]; // Ensure enough space for both strings and the space
        strcpy(combined, current->model); // Copy the model into the combined string
        strcat(combined, " "); // Add a space between model and type
        strcat(combined, current->type); // Append the type to the combined string

        // if the model and type is equal to the the user input
    if (strcmp(current->model, model) == 0 && strcmp(current->type, type) == 0){
            return position;
        }
        // moving onto the next car
        current = current->nextCar;
        position++;
    }
    printf("The position of your model and type: %d\n", position);
    return -1;
}