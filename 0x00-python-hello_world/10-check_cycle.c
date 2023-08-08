#include "lists.h"

/**
 * check_cycle - Checks if a linked list contains a cycle.
 * @list: The linked list to check for cycles.
 *
 * Return: 1 if the list has a cycle, 0 if it doesn't.
 */
int check_cycle(listint_t *list)
{
    listint_t *slow_ptr = list;
    listint_t *fast_ptr = list;

    if (!list)
        return (0);

    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
            return (1);
    }

    return (0);
}

