#include <stdio.h>
#include <stdlib.h>

struct Node {
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
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted successfully.\n");
}

void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
    {
        // If there is only one node in the list
        free(temp);
        *head = NULL;
    }
    else
    {
        prev->next = NULL;
        free(temp);
    }

    printf("Node deleted from the end successfully.\n");
}
void insertAtBeginning(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;

    printf("Node inserted at the beginning successfully.\n");
}
void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete from the beginning.\n");
        return;
    }

    struct Node *temp = *head;
    *head = temp->next;
    free(temp);

    printf("Node deleted from the beginning successfully.\n");
}

// Function to insert a node after a specific value in the singly linked list
void insertAfterValue(struct Node *head, int searchValue, int insertValue)
{
    struct Node *temp = head;

    while (temp != NULL && temp->data != searchValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list. Cannot insert.\n", searchValue);
        return;
    }

    struct Node *newNode = createNode(insertValue);
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node with value %d inserted after %d successfully.\n", insertValue, searchValue);
}
void deleteSpecific(struct Node **head, int value)
{
    if (*head == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found in the list. Cannot delete.\n", value);
        return;
    }

    if (prev == NULL)
    {
        // If the node to be deleted is the first node
        *head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
    printf("Node with value %d deleted successfully.\n", value);
}

void search(struct Node *head, int value) {
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", value);
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, searchValue, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at End\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("5. Insert at Beginning\n");
        printf("6. Delete from end\n");
        printf("7. Insert after a specific value\n");
        printf("8. Delete from beginning\n");
        printf("9. Delete specific\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;
            case 3:
                display(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            case 5:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                printf("Enter the value to search: ");
                scanf("%d", &searchValue);
                printf("Enter the value to insert after %d: ", searchValue);
                scanf("%d", &value);
                insertAfterValue(head, searchValue, value);
                break;
            case 8:
                deleteFromBeginning(&head);
                break;
            case 9:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteSpecific(&head, value);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
