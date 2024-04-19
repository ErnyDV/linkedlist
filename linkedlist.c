#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "node.h"

node * makeLL(int argc, char *argv[]);
void printLL(node *list);
void searchLL(int num, node *list);
void appendLL(int num, node *list);


int main(int argc , char *argv[])
{
    if(argc < 2)
    {
        printf("Usage ./linkedlist 123..");
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        if(atoi(argv[i]) == 0)
        {
                printf("Please only enter numbers, anything above 0 or below.");
                printf("%s",argv[i]);
                return 2;
        }
    }

    node *list = makeLL(argc, argv);
    if(list == NULL)
    {
        printf("Could not allocate memory");
        return 3;
    }

    appendLL(2,list);
    printLL(list);
    appendLL(3, list);
    printLL(list);

}



node * makeLL(int argc, char *argv[])
{
    node *list = malloc(sizeof(node));
    if (list == NULL)
    {
        return NULL;
    }
    node *start = list;
    

    for(int i = 1; i < argc; i++)
    {
        node *temp = malloc(sizeof(node));
        if(temp == NULL)
        {
            return NULL;
        }
        temp->next = NULL;
        temp->num = 0;
        list->num = atoi(argv[i]);
        if (i != (argc - 1))
        {
            list->next = temp;
            list = list->next;
        }
    }
    list->next = NULL;

    return start;
}

void printLL(node *list)
{
    while(list != NULL)
    {
        printf("%i",list->num);
        list = list->next;
    }
    printf("\n");
}

void searchLL(int num, node *list)
{
    while(list != NULL)
    {
        if(num == list->num)
        {  

            printf("\nNumber %i at address: %p\n",list->num,list);
            return;
        }
        list = list->next;
    }
    printf("\nNumber not found\n");
    return;
}

void appendLL(int num, node *list)
{
     while(list != NULL)
    {
        if (list->next == NULL)
        {
            list->next = malloc(sizeof(node));
            list->next->num = num;
            list->next->next = NULL;
            return;
        }
        list = list->next;
    }
}