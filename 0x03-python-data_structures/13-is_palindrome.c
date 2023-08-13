#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * reverse_listint - Reverses a linked list.
 * @head: A pointer to the pointer of the first node in the list.
 *
 * Description: This function reverses a singly linked list by changing the
 * direction of the next pointers of nodes. It updates the head of the list
 * to point to the new first node.
 * Return: Void. The head pointer is modified in place.
 */
void reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

/**
 * is_palindrome - Checks if a linked list is a palindrome.
 * @head: A double pointer to the linked list.
 *
 * Description: This function checks if a singly linked list is a palindrome,
 * meaning it reads the same forwards and backwards. It uses a two-pointer
 * approach to compare elements symmetrically from the start and end.
 *
 * Return: 1 if the list is a palindrome, 0 if it is not.
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *temp = *head, *dup = NULL;

    // If the list is empty or has only one element, it is a palindrome
    if (*head == NULL || (*head)->next == NULL)
        return (1);

    // Move slow and fast pointers to find the middle of the list
    while (1)
    {
        fast = fast->next->next;
        if (!fast)
        {
            dup = slow->next;
            break;
        }
        if (!fast->next)
        {
            dup = slow->next->next;
            break;
        }
        slow = slow->next;
    }

    // Reverse the second half of the list
    reverse_listint(&dup);

    // Compare elements of the reversed second half with the first half
    while (dup && temp)
    {
        if (temp->n == dup->n)
        {
            dup = dup->next;
            temp = temp->next;
        }
        else
            return (0);
    }

    // If the second half is completely traversed, it's a palindrome
    if (!dup)
        return (1);

    return (0);
}

