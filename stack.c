#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack* sp,int i){
    int arrindx = sp->top - i + 1;
    if(arrindx<0){
        printf("not a valid position");
        return -1;
    }
    else{
        return sp->arr[arrindx];
    }
}
int main(){
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    printf("!!!!!!Stack created successfully!!!!!!\n");

    printf("Before pushing, full %d\n", isFull(sp));
    printf("Before pushing, Empty %d\n", isEmpty(sp));

    push(sp,23);
    push(sp,29);
    push(sp,13);
    push(sp,93);
    push(sp,23);
    push(sp,29);
    push(sp,13);
    push(sp,93);
    push(sp,23);
    push(sp,29);

    for (int j = 1; j <=sp->top + 1; j++){
        printf("the value at position %d is %d\n",j, peek(sp, j));
    }

    //     printf("After pushing, full %d\n", isFull(sp));
    // printf("After pushing, Empty %d\n", isEmpty(sp));

    return 0;
}
