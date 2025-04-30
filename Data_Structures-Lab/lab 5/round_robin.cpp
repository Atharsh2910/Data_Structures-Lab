// C++ program to implement a round robin scheduling algorithm using a circularly linked list


#include <stdio.h>
#include <stdlib.h>
#include "5_Circularly_Linked_List.h"

#define FIXED_TIME 5

int main()
{
    int choice, stop = 0;
    int time, val;
    list round_robin;
    
    while (!stop)
    {
        printf("\n\nMENU :\n");
        printf("1. Insert Process\n");
        printf("2. Execute\n");
        print("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            printf("Enter duration of process (minutes): ");
            scanf("%d", &time);
            round_robin.insertEnd(time);
            break;

        case 2:
            val = round_robin.deleteBeg();
            if (val == -1)
            {
                printf("No processes in queue.\n");
            }
            else if (val > FIXED_TIME)
            {
                printf("Process Executed. %d minutes remaining.\n", val - FIXED_TIME);
                round_robin.insertEnd(val - FIXED_TIME);
            }
            else
            {
                printf("Process Completed.\n");
            }
            break;

        case 3:
            stop = 1;
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Enter again.\n");
            break;
        }
    }
    return 0;
}
