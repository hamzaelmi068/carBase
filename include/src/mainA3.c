#include <stdio.h>
#include "../include/headerA3.h"

int main()
{

    /* task 1 vars*/
    struct car *headLL = NULL;

    /* task 2 vars */
    char fileName[MAX_LENGTH] = "inputFile.txt";
    // already declared from task 1: struct car *headLL = NULL;

    /* task 3 vars */
    // already declared: struct car *headLL;

    /* task 4 vars */
    // struct car * headLL; (already declared)
    int whichOneTask4;

    /* task 5 vars */
    // struct car * headLL;
    int carIdKey = 0;

    /* task 6 vars*/
    // int key

    /* task 7 vars */
    // char modelTypeKey[100];
    int resultTask7;

    /* task 8 vars*/
    // a3Car *headLL;

    /* task 9 vars*/
    // struct car **headLL;
    int whichOneTask9;

    /* task 10 vars*/
    // a3Car **headLL;
    //  a3Car ** headLL;

    int option;

    do
    {
        printf("\n1. Add data on a new car\n");
        printf("2. Load data on cars from a given text file\n");
        printf("3. Print data of all cars\n");
        printf("4. Print data of the nth car\n");
        printf("5. Search car data based on carId\n");
        printf("6. Search car data based on model and type\n");
        printf("7. Count the total number of cars in the list\n");
        printf("8. Sort the cars in the list based on carId\n");
        printf("9. Remove data of the nth car\n");
        printf("10. Remove all car data\n");
        printf("11. Exit...\n");

        printf("Choose a menu option: ");
        scanf("%d", &option);

        if (option > 11 || option < 1)
        {
            printf("Invalid choice, please re enter your choice\n");
            continue;
        }

        switch (option)
        {
        case 1:
            // we call task 1 here
            addNewCar(&headLL); // double ptr
            break;

        case 2:
            // call task 2 here
            loadCarData(&headLL, fileName); // double ptr
            break;

        case 3:
            // calling task 3 here
            printAll(headLL); // headLL already holds an address, we dont need & here, single ptr in func paramter
            break;
        case 4:
            // call task 4 here
            printf("\nEnter a position: ");
            scanf("%d", &whichOneTask4);
            // Update resultTask7 with the current total number of cars
            resultTask7 = countCars(headLL);

            // Using a do-while loop to ensure the user enters a valid position
            do
            {
                if (whichOneTask4 > resultTask7)
                {
                    printf("Invalid position. Please enter a position less than or equal to %d.\n", resultTask7);
                    printf("Enter a position: ");
                    scanf("%d", &whichOneTask4);
                }
            } while (whichOneTask4 > resultTask7);

            // Now that we have a valid position, call printOne
            printOne(headLL, whichOneTask4);
            break;

        case 5:
            // call task 5 here
            printf("Enter the carID to search for in the LL: ");
            scanf("%d", &carIdKey);
            int positionOfCar = lookForCarId(headLL, carIdKey);
            // if the function doesnt return one, we can print the info of the car based on the carId entered
            if (positionOfCar != -1)
            {
                printOne(headLL, positionOfCar);
            }
            else
            {
                // if it isnt found, user can try again
                printf("Car Id with %d wasnt found, try again\n", carIdKey);
            }
            break;

        case 6:
            // calling task 6
            printf("Enter the model and type (seperated by a space): ");
            char modelTypeKey[100];
            int clearBuffer;
            while ((clearBuffer = getchar() != '\n' && clearBuffer != EOF))
            {
            } // reviewed how to using this website : https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
            fgets(modelTypeKey, sizeof(modelTypeKey), stdin);
            // removing the \n character below
            modelTypeKey[strcspn(modelTypeKey, "\n")] = '\0';
            // calling the lookforcarmodeltype function
            int positionOfCarModelType = lookForCarModelType(headLL, modelTypeKey);
            // if the function doesnt return -1, we print that position
            if (positionOfCarModelType != -1)
            {
                printOne(headLL, positionOfCarModelType + 1); // linked list is indexted at 1, need to add 1
            }
            else
            {
                // if it isn't found...
                printf("Car with model and type '%s' wasn't found, try again\n", modelTypeKey);
            }
            break;
        case 7:
            // calling task 7
            resultTask7 = countCars(headLL);
            // for testing purposes, remove before submitting (dont need to print anything for this function)
            printf("\nTotal number of cars: %d\n", resultTask7);
            break;
        case 8:
            // call task8
            sortCarId(&headLL); // double ptr, use &
            // printing all the carid data we just sorted, in order
            printAll(headLL);
            break;
        case 9:
            int totalCars = countCars(headLL);
            printf("Currently there are %d cars\n", totalCars);
            printf("Which car do you wish to remove -- enter a value between 1 and 5: ");
            scanf("%d", &whichOneTask9);
            // input validation for the value the user enters

            while (whichOneTask9 < 1 || whichOneTask9 > totalCars)
            {
                printf("Please enter a valid number between 1 and the total number of cars (which is %d):   ", totalCars);
                // prompt the user again
                scanf("%d", &whichOneTask9);
            }
            // calling the onelesscar, double ptr so '&' is used
            oneLessCar(&headLL, whichOneTask9);
            // printf("Car [Id: %d] removed", );
            printf("Car id at position %d got removed", whichOneTask9);
            printf("\nThere are now %d cars remaining.\n", countCars(headLL));
            break;

        case 10:
            //char option10; //char option10[10]; was causing problems lol
            //scanf(" %c", &option10);
            // input validation for the user, its gotta be 'y' or 'n'
            /*do
            {
                printf("Are you sure you want to remove all car data (enter y for yes, n for no):");
                scanf(" %c", &option10);
            } while (option10 != 'y' && option10 != 'n');*/

            //if (option10 == 'y') {
            noMoreCars(&headLL);
                //printf("All removed. Linked list is now empty.");
            //}
            //else if(option10 == 'n'){
            //    printf("No cars will be removed, menu is reprinted below\n");
            //}
            break;
        }

    } while (option != 11);

    return 0;
}
