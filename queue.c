#include<stdio.h>
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front=-1;
int rear =-1;

void enqueue(int element){
  if(rear==MAX_SIZE-1){
    printf("\nQueue is full\n");
    return;
  }
  if(front==-1){
    front=0;
  }
  rear++;
  queue[rear]=element;
}

int dequeue(){
  if(front==-1 || front>rear){
    printf("\nQueue is Empty\n");
    return -1;
  }
  int element=queue[front];
  front++;
  return element;
}

int main() {
  enqueue(10);
  enqueue(20);
  enqueue(30);
  

  printf("%d ",dequeue());

  return 0;
}