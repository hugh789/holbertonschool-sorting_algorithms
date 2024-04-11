#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm
 * @list: Pointer to the head pointer of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)

{
    /*declares three pointers to nodes of type listin_t*/
    listint_t *current, *prev, *next;

    /*Intial check if list is valid and not empty, a list with zero or one element is already considered sorted*/
    if (list == NULL || *list == NULL || (*list)->next == NULL)
    return;

    /*Looping through list starting from 2nd until reaches end of list */
    current = (*list)->next;
    while (current != NULL)
    {
        next = current->next;
        while (current->prev != NULL && current->n < current->prev->n)
        {
        prev = current->prev;
        /*Swap nodes*/
        if (prev->prev != NULL)
        prev->prev->next = current;
        else
        *list = current;

        if (current->next != NULL)
        current->next->prev = prev;

        prev->next = current->next;
        current->prev = prev->prev;
        current->next = prev;
        prev->prev = current;

        /*Print list after swapping */
        print_list(*list);
        }
         current = next;
    }
}
