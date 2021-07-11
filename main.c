#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *next;
};

void printLinkedList(struct Node *Head)
{
    struct Node *tmp;

    tmp = Head;

    while (tmp != NULL)
    {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

struct Node *bubbleSort(struct Node *inputHead)
{
    int tmpVal;
    struct Node *curr, *next, *temp, *ourHead;
    bool hasSwapped = true;
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    while (hasSwapped)
    {
        curr = inputHead;
        hasSwapped = false;
        while (curr->next != NULL)
        {
            next = curr->next;
            if ((curr->data > next->data))
            {
                hasSwapped = true;

                tmpVal = curr->data;
                curr->data = next->data;
                next->data = tmpVal;
            }
            curr = curr->next;
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time spent: %f seconds \n", cpu_time_used);
    return inputHead;
}

int main()
{
    int amountElements, elementData, whatAlgorithm, r;

    struct Node *Head, *newNode, *currNode;

    printf("How many elements do you want to sort? (Greater than 0): ");
    scanf("%d", &amountElements);

    if (amountElements < 1)
    {
        printf("Value was not greater than 0");
    }
    else
    {
        Head = (struct Node *)malloc(sizeof(struct Node));
        r = rand() % 20;
        Head->data = r;
        Head->next = NULL;
        currNode = Head;

        //This for loop enters the valeus to the linked list
        for (int i = 1; i < amountElements; i++)
        {
            newNode = (struct Node *)malloc(sizeof(struct Node));
            r = rand() % 20;
            newNode->data = r;
            newNode->next = NULL;
            currNode->next = newNode;
            currNode = newNode;
        }
        currNode = Head;
    }

    printf("You entered the values: ");
    while (currNode != NULL)
    {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }

    printf("\nWhat sorting algorithm do you want to use? \n");
    printf("1. Bubblesort\n");
    printf("9. Print the list\n");
    scanf("%d", &whatAlgorithm);
    switch (whatAlgorithm)
    {
    case 1:
    {
        struct Node *sorted = bubbleSort(Head);
        printf("The sorted list: \n");
        printLinkedList(sorted);
        break;
    }
    case 9:
    {
        printLinkedList(Head);
        break;
    }
    default:
    {
        printf("Invalid input");
        break;
    }
    }
}
