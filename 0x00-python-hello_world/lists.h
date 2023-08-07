#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: This is a structure for a singly linked list node used in a Holberton project.
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/**
 * Function: print_listint
 * Description: Prints all elements of a linked list.
 * @h: A pointer to the head of the linked list.
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h);

/**
 * Function: add_nodeint
 * Description: Adds a new node at the beginning of a linked list.
 * @head: A pointer to a pointer to the head of the linked list.
 * @n: The integer value to be stored in the new node.
 * Return: A pointer to the new head of the linked list.
 */
listint_t *add_nodeint(listint_t **head, const int n);

/**
 * Function: free_listint
 * Description: Frees all elements of a linked list.
 * @head: A pointer to the head of the linked list to be freed.
 */
void free_listint(listint_t *head);

/**
 * Function: check_cycle
 * Description: Checks if a linked list has a cycle in it.
 * @list: A pointer to the head of the linked list to be checked.
 * Return: 1 if there is a cycle, 0 otherwise.
 */
int check_cycle(listint_t *list);

#endif /* LISTS_H */

