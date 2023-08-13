#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

int is_palindrome(listint_t **head) {
    if (*head == NULL) {
        return 1; // An empty list is considered a palindrome
    }

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev = NULL;
    listint_t *next = NULL;

    // Find the middle of the list using the two-pointer technique
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // If the list has odd number of nodes, move slow one step forward
    if (fast != NULL) {
        slow = slow->next;
    }

    // Compare the first half (prev) and the second half (slow)
    while (prev != NULL && slow != NULL) {
        if (prev->n != slow->n) {
            return 0; // Not a palindrome
        }
        prev = prev->next;
        slow = slow->next;
    }

    return 1; // It's a palindrome
}

// Helper function to create a new node
listint_t *newNode(int n) {
    listint_t *node = malloc(sizeof(listint_t));
    if (node != NULL) {
        node->n = n;
        node->next = NULL;
    }
    return node;
}

int main() {
    listint_t *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(2);
    head->next->next->next->next = newNode(1);

    int result = is_palindrome(&head);
    if (result) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    // Free the allocated memory
    while (head != NULL) {
        listint_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

