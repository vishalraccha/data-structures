#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Stack structure
struct Stack
{
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack overflow. Cannot push element %d.\n", value);
    }
    else
    {
        stack->arr[++stack->top] = value;
        printf("Element %d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
    }
    else
    {
        int poppedValue = stack->arr[stack->top--];
        printf("Element %d popped from the stack.\n", poppedValue);
    }
}

// Function to display the elements of the stack
void display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("The stack is empty.\n");
    }
    else
    {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; ++i)
        {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
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

    return 0;
}
