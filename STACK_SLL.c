#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Stack structure
struct Stack
{
    struct Node *top;
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;

    printf("Element %d pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;

    free(temp);

    printf("Element %d popped from the stack.\n", poppedValue);
    return poppedValue;
}

// Function to display the elements of the stack
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("The stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    struct Node *current = stack->top;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free memory allocated for the stack
void freeStack(struct Stack *stack)
{
    while (stack->top != NULL)
    {
        struct Node *temp = stack->top;
        stack->top = temp->next;
        free(temp);
    }
}

int main()
{
    struct Stack stack;
    int choice, value;

    initialize(&stack);

    do
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            pop(&stack);
            break;
        case 3:
            display(&stack);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free allocated memory before exiting
    freeStack(&stack);

    return 0;
}
