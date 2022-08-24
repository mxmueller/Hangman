// Linked list operations in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

const int max_length = 150;
char input[max_length];
char word[max_length];

// Create a node
struct Node
{
    char data[max_length];
    struct Node *next;
};

struct Node *head = NULL;

// Insert at the beginning
void insertAtBeginning(struct Node **head_ref, char new_data[max_length])
{
    // Allocate memory to a node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // insert the data
    strcpy(new_node->data, new_data);

    new_node->next = (*head_ref);

    // Move head to new node
    (*head_ref) = new_node;
}
void insertAfter(struct Node *prev_node, char new_data[max_length])
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->data, new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void insertAtEnd(struct Node **head_ref, char new_data[max_length])
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref; /* used in step 5*/

    strcpy(new_node->data, new_data);
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}
void deleteNode(struct Node **head_ref, char key[max_length])
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Find the key to be deleted
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL)
        return;

    // Remove the node
    prev->next = temp->next;

    free(temp);
}
int searchNode(struct Node **head_ref, char key[max_length])
{
    struct Node *current = *head_ref;

    while (current != NULL)
    {
        if (current->data == key)
            return 1;
        current = current->next;
    }
    return 0;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %s ", node->data);
        node = node->next;
    }
}

// Driver program
int main()
{
    void sequence();
    sequence();
}

char *getAndFilterInput()
{

    scanf("%s", input);
    int input_length;
    input_length = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            puts("Error1\n");
            break;
        }
        input_length++;
    }
    

    return input;
}

void sequence()
{
    strcpy(word, getAndFilterInput());
    insertAtEnd(&head, word);

    printf("List: ");
    printList(head);
    printf("%s", "\n");

    sequence();
}