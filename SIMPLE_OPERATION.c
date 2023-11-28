#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Function to display the elements of the list
void display(int arr[], int size)
{
    if (size == 0)
    {
        printf("The list is empty.\n");
    }
    else
    {
        printf("List elements: ");
        for (int i = 0; i < size; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

// Function to insert an element into the list
int insert(int arr[], int *size, int value)
{
    if (*size == MAX_SIZE)
    {
        printf("List is full. Cannot insert.\n");
        return 0; // Return 0 to indicate failure
    }

    arr[*size] = value;
    (*size)++;

    printf("Element %d inserted into the list.\n", value);
    return 1; // Return 1 to indicate success
}

// Function to delete an element from the list
int delete(int arr[], int *size, int value)
{
    if (*size == 0)
    {
        printf("List is empty. Cannot delete.\n");
        return 0; // Return 0 to indicate failure
    }

    int found = 0;
    int index = 0;

    // Find the index of the value to delete
    while (index < *size && arr[index] != value)
    {
        index++;
    }

    if (index == *size)
    {
        printf("Element %d not found in the list. Cannot delete.\n", value);
        return 0; // Return 0 to indicate failure
    }

    // Shift elements to fill the gap
    for (int i = index; i < *size - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    printf("Element %d deleted from the list.\n", value);
    return 1; // Return 1 to indicate success
}

int main()
{
    int arr[MAX_SIZE];
    int size = 0;
    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &value);
            insert(arr, &size, value);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            delete (arr, &size, value);
            break;
        case 3:
            display(arr, size);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
