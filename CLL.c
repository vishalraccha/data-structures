#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }

    printf("Node with value %d inserted at the end successfully.\n", value);
}

// Function to delete a specific value from the circular linked list
void deleteSpecific(struct Node **head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;

    // Find the node with the specified value
    do
    {
        if (current->data == value)
        {
            break;
        }
        prev = current;
        current = current->next;
    } while (current != *head);

    if (current == *head && current->data != value)
    {
        printf("Value %d not found in the list. Cannot delete.\n", value);
        return;
    }

    if (current == *head)
    {
        // If the node to be deleted is the head
        prev = *head;
        while (prev->next != *head)
        {
            prev = prev->next;
        }
        *head = current->next;
        prev->next = *head;
    }
    else
    {
        // If the node to be deleted is not the head
        prev->next = current->next;
    }

    free(current);
    printf("Node with value %d deleted successfully.\n", value);
}

// Function to display the elements of the circular linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = *head;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }

    printf("Node with value %d inserted at the beginning successfully.\n", value);
}

// Function to insert a node after a specific value in the circular linked list
void insertAfterValue(struct Node *head, int searchValue, int insertValue)
{
    struct Node *newNode = createNode(insertValue);
    struct Node *temp = head;

    // Find the node with the specified value
    do
    {
        if (temp->data == searchValue)
        {
            break;
        }
        temp = temp->next;
    } while (temp != head);

    if (temp == head && temp->data != searchValue)
    {
        printf("Value %d not found in the list. Cannot insert.\n", searchValue);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node with value %d inserted after %d successfully.\n", insertValue, searchValue);
}

// Function to delete a node from the end of the circular linked list
void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    // Find the last node
    while (temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == *head)
    {
        // If there is only one node in the list
        free(temp);
        *head = NULL;
    }
    else
    {
        prev->next = *head;
        free(temp);
    }

    printf("Node deleted from the end successfully.\n");
}

// Function to delete a node from the beginning of the circular linked list
void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from the beginning.\n");
        return;
    }

    struct Node *temp = *head;

    // Find the last node
    while (temp->next != *head)
    {
        temp = temp->next;
    }

    if (temp == *head)
    {
        // If there is only one node in the list
        free(temp);
        *head = NULL;
    }
    else
    {
        temp->next = (*head)->next;
        free(*head);
        *head = temp->next;
    }

    printf("Node deleted from the beginning successfully.\n");
}

// Function to search for a node in the circular linked list
void search(struct Node *head, int value)
{
    if (head == NULL)
    {
        printf("The list is empty. Element %d not found.\n", value);
        return;
    }

    struct Node *temp = head;

    do
    {
        if (temp->data == value)
        {
            printf("Element %d found in the list.\n", value);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Element %d not found in the list.\n", value);
}

// Function to free memory allocated for the circular linked list
void freeList(struct Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node *current = *head;
    struct Node *next;

    do
    {
        next = current->next;
        free(current);
        current = next;
    } while (current != *head);

    *head = NULL;
}

int main()
{
    struct Node *head = NULL;
    int choice, value, searchValue, insertValue, deleteValue;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Delete Specific Value\n");
        printf("3. Display\n");
        printf("4. Insert at Beginning\n");
        printf("5. Insert After a Value\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Beginning\n");
        printf("8. Search\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to insert at the end: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
            break;
        case 2:
            printf("Enter the value to delete: ");
            scanf("%d", &deleteValue);
            deleteSpecific(&head, deleteValue);
            break;
        case 3:
            display(head);
            break;
        case 4:
            printf("Enter the value to insert at the beginning: ");
            scanf("%d", &value);
            insertAtBeginning(&head, value);
            break;
        case 5:
            printf("Enter the value to search: ");
            scanf("%d", &searchValue);
            printf("Enter the value to insert after %d: ", searchValue);
            scanf("%d", &insertValue);
            insertAfterValue(head, searchValue, insertValue);
            break;
        case 6:
            deleteFromEnd(&head);
            break;
        case 7:
            deleteFromBeginning(&head);
            break;
        case 8:
            printf("Enter the value to search: ");
            scanf("%d", &searchValue);
            search(head, searchValue);
            break;
        case 9:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 9);

    // Free allocated memory before exiting
    freeList(&head);

    return 0;
}
