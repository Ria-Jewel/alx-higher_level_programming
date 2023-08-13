#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: The head of the singly linked list.
 *
 * Description: This function determines whether a singly linked list is a
 * palindrome by comparing elements symmetrically from the start and end of
 * the list.
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
    listint_t *start = NULL, *end = NULL;
    unsigned int i = 0, len = 0, len_cyc = 0, len_list = 0;

    // Check for invalid input
    if (head == NULL)
        return (0);

    // An empty list is considered a palindrome
    if (*head == NULL)
        return (1);

    // Initialize pointers and lengths
    start = *head;
    len = listint_len(start);
    len_cyc = len * 2;
    len_list = len_cyc - 2;
    end = *head;

    // Compare elements symmetrically
    for (; i < len_cyc; i = i + 2)
    {
        if (start[i].n != end[len_list].n)
            return (0);

        len_list = len_list - 2;
    }

    return (1);
}

/**
 * get_nodeint_at_index - Gets a node from a linked list.
 * @head: The head of the linked list.
 * @index: The index to find in the linked list.
 *
 * Description: This function retrieves the node at a specified index in the
 * linked list.
 *
 * Return: The specific node of the linked list, or NULL if not found.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
    listint_t *current = head;
    unsigned int iter_times = 0;

    // Iterate through the linked list to find the specified index
    if (head)
    {
        while (current != NULL)
        {
            if (iter_times == index)
                return (current);

            current = current->next;
            ++iter_times;
        }
    }

    return (NULL);
}

/**
 * listint_len - Counts the number of elements in a linked list.
 * @h: The linked list to count.
 *
 * Description: This function calculates the number of elements in a linked list.
 *
 * Return: Number of elements in the linked list.
 */
size_t listint_len(const listint_t *h)
{
    int length = 0;

    // Iterate through the linked list and count elements
    while (h != NULL)
    {
        ++length;
        h = h->next;
    }

    return (length);
}

