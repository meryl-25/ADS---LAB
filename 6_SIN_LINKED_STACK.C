#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void push();
void pop();
void display();


struct node{
int data;
struct node *next;
}*top;

void main(){

	int ch;
	clrscr();

    do
    {

        printf("SELECT\n1.PUSH\n2.POP\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            continue;

        case 2:
            pop();
            continue;

        case 3:
            display();
            continue;

        default:
            exit(0);
        }

    } while (ch != 0);
}


void push(){

    struct node *newnode;
    int data;

    printf("Enter node value\n");
    scanf("%d", &data);

    // if list is empty
    if (top->data == NULL)
    {
        top = malloc(sizeof(struct node));
        top->data = data;
        top->next = NULL;
        printf("Node Inserted\n");
    }
    // if list contain atleast one element
    else
    {
        newnode = malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = top;
        top = newnode;
        printf("Node Inserted\n");
    }
}

void pop()
{
    struct node *temp;

    if (top == NULL)

        printf("\nNo Element to Delete\n\n");

    else if (top->next == NULL)
    {
        printf("\nThe node deleted is %d\n\n", top->data);
        top = NULL;
    }
    else
    {
        printf("\nThe node deleted is %d\n\n", top->data);
        temp=top;
        top = top->next;
        free(temp);
    }
}


void display()
{
    struct node *curr;

    if (top == NULL)
	printf("Stack is Empty\n");

    else
    {

        curr = top;
	printf("\nThe Stack is \n");
        while (curr != NULL)
        {
	    printf("%d\n", curr->data);
            curr = curr->next;
        }
    }

    printf("\n\n");
}