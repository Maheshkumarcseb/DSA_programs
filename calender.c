#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a day
struct Day
 {
    char* name;         // Dynamically allocated string for the day's name
    int date;
    char* activity;     // Dynamically allocated string for the day's activity
};

// Function to create the calendar
void create(struct Day calendar[7])
 {
    for (int i = 0; i < 7; i++)
 {
        calendar[i].name = NULL;
        calendar[i].activity = NULL;
    }
}

// Function to read data from the keyboard
void read(struct Day calendar[7])
 {
    for (int i = 0; i < 7; i++)
 {
        calendar[i].name = (char*)malloc(20 * sizeof(char));  // Allocate memory for the day's name
        calendar[i].activity = (char*)malloc(100 * sizeof(char)); // Allocate memory for the activity description

        printf("Enter the name of day %d: ", i + 1);
        scanf("%s", calendar[i].name);
        printf("Enter the date for %s: ", calendar[i].name);
        scanf("%d", &calendar[i].date);
        printf("Enter the activity for %s: ", calendar[i].name);
        scanf("%s", calendar[i].activity);
        printf("\n");
    }
}

// Function to display the calendar
void display(struct Day calendar[7]) 
{
    printf("\nCalendar for the week:\n\n");
    for (int i = 0; i < 7; i++) 
{
        printf("Day %d: %s (Date: %d) - Activity: %s\n\n", i + 1, calendar[i].name, calendar[i].date, calendar[i].activity);

   }
}

// Function to free allocated memory
void freeMemory(struct Day calendar[7]) 
{
    for (int i = 0; i < 7; i++)
 {
        free(calendar[i].name);
        free(calendar[i].activity);
    }
}

int main() 
{
    struct Day calendar[7];
    // Create the calendar
    create(calendar);

    // Read data from the keyboard
    read(calendar);

    // Display the calendar
    display(calendar);

    // Free allocated memory
    freeMemory(calendar);

    return 0;
}

