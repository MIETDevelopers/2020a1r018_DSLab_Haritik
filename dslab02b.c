#include <stdio.h>  //taken help from samragyi
#include <stdlib.h> // for dynamic memory allocation and exit()
#include <conio.h>  // for getch()
// Structure representing stack
struct stack
{
    int *array; // stores the elements in the stack
    int top;    // index of the top element
    int Size;   // Total size of the stack
};
// For creating the stack and allocating the memory
struct stack *create_stack(int Size)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->Size = Size;
    s->top = -1; // initialization to -1 shows that the stack is empty
    s->array = (int *)malloc(s->Size * sizeof(int));
    return s;
}
// isFull() for checking if the stack is full
int isFull(struct stack *s)
{
    if (s->top == s->Size - 1)
    { // when top is equal to the last index, the stack is full
        return 1;
    }
    else
        return 0;
}
// isEmpty() for checking if the stack is empty
int isEmpty(struct stack *s)
{
    // when top is equal to -1, the stack is empty
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
// push() for pushing an element in the stack.
void push(struct stack *s, int element)
{
    if (isFull(s))
    { // calling the isFull() function to check if the stack is full
        printf("OVERFLOW !!! Stack is full! \n");
    }
    else
    {
        s->array[++s->top] = element; // incrementing top by 1
        printf("%d pushed to stack\n", element);
    }
}
// pop() for deleting/removing the top most element from the stack
int pop(struct stack *s)
{
    int ret;
    if (isEmpty(s))
    {   // calling the isEmpty() function to check if the stack is empty
        return -1;
    }
    else{
        ret = s->top;
        s->top--;       // decrementing top by 1
    }
    return ret ;
}
// for displaying the elements present in the stack
void display_elements(struct stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty! \n");
    }
    else
    {
        printf("Elements present in the stack are... \n");
        int temp;
        temp = s->top;
        while (temp != -1)
        {
            printf("%d \n", s->array[temp]);
            --temp;
        }
    }
}
int main()
{
    printf("\t\t STACK IMPLEMENTATION \n");
    int choice, element, popped, Size;
    printf("Enter the size of the stack : ");
    scanf("%d", &Size);
    struct stack *s = create_stack(Size);
    do
    {
        printf("\t OPERATIONS \n");
        printf(" 1. Push \n 2. Pop \n 3. Display elements \n 4. Exit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n \t Pushing in stack \n");
            printf("Enter the element you want to push in the stack : ");
            scanf("%d", &element);
            push(s, element); // calling the push function
            break;
        case 2:
            printf("\n \t Popping from stack \n");
            popped = pop(s);    // calling the pop function
            if(popped == -1){
                printf("UNDERFLOW!!! Stack is empty! \n");
            }else 
                printf("%d popped from the stack \n", s->array[popped]);
            break;
        case 3:
            display_elements(s); // calling the display function
            break;
        case 4:
            exit(0);
        default:
            printf("\n \t WRONG CHOICE ENTERED !! \n");
            break;
        }
        printf("Press enter to continue... \n");
        getch();
    } while (1);
    return 0;
}
