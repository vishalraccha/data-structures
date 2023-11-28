#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Queue structure
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to initialize the queue
void initialize(struct Queue *queue)
{
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *queue, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("Element %d enqueued into the queue.\n", value);
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow. Cannot dequeue from an empty queue.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *temp = queue->front;
    int dequeuedValue = temp->data;

    if (queue->front == queue->rear)
    {
        // If there is only one element in the queue
        queue->front = NULL;
        queue->rear = NULL;
    }
    else
    {
        queue->front = temp->next;
    }

    free(temp);

    printf("Element %d dequeued from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the elements of the queue
void display(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("The queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node *current = queue->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free memory allocated for the queue
void freeQueue(struct Queue *queue)
{
    while (queue->front != NULL)
    {
        struct Node *temp = queue->front;
        queue->front = temp->next;
        free(temp);
    }
}

int main()
{
    struct Queue queue;
    int choice, value;

    initialize(&queue);

    do
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to enqueue: ");
            scanf("%d", &value);
            enqueue(&queue, value);
            break;
        case 2:
            dequeue(&queue);
            break;
        case 3:
            display(&queue);
            break;
        case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free allocated memory before exiting
    freeQueue(&queue);

    return 0;
}
