#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node
{
    int data;
    struct Node *prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node with value %d inserted at the end successfully.\n", value);
}

// Function to delete a specific value from the doubly linked list
void deleteSpecific(struct Node **head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = *head;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list. Cannot delete.\n", value);
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        *head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node with value %d deleted successfully.\n", value);
}

// Function to display the doubly linked list
void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }

    printf("Node with value %d inserted at the beginning successfully.\n", value);
}

// Function to insert a node after a specific value in the doubly linked list
void insertAfterValue(struct Node *head, int searchValue, int insertValue)
{
    struct Node *newNode = createNode(insertValue);

    while (head != NULL && head->data != searchValue)
    {
        head = head->next;
    }

    if (head == NULL)
    {
        printf("Value %d not found in the list. Cannot insert.\n", searchValue);
        return;
    }

    newNode->prev = head;
    newNode->next = head->next;

    if (head->next != NULL)
    {
        head->next->prev = newNode;
    }

    head->next = newNode;

    printf("Node with value %d inserted after %d successfully.\n", insertValue, searchValue);
}

// Function to delete a node from the end of the doubly linked list
void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }

    free(temp);
    printf("Node deleted from the end successfully.\n");
}

// Function to delete a node from the beginning of the doubly linked list
void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from the beginning.\n");
        return;
    }

    struct Node *temp = *head;
    *head = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = NULL;
    }

    free(temp);
    printf("Node deleted from the beginning successfully.\n");
}

// Function to search for a node in the doubly linked list
void search(struct Node *head, int value)
{
    while (head != NULL && head->data != value)
    {
        head = head->next;
    }

    if (head == NULL)
    {
        printf("Element %d not found in the list.\n", value);
    }
    else
    {
        printf("Element %d found in the list.\n", value);
    }
}

// Function to free memory allocated for the doubly linked list
void freeList(struct Node **head)
{
    struct Node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
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
