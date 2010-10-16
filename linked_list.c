/*
 * List - Set of items organised sequentially
 * Linked list - A way to represent a list where by each item in the list
 *               part of a structure also contains a "link" to the structure
 *      containing the next item
 *
 * Basic operations on a linked list:
 *  1.Insert
 *  2.Traverse
 *  3.Search
 *  4.Display
 *  5.Delete
 */

/* PROGRAM TO PERFORM OPERATIONS ON A LINKED LIST */

#include<stdio.h>
#include<stdlib.h>

// Node structure

struct node {
  int d;

  struct node *next;
};

// Alias the node structure

typedef struct node* NODE;

// Initialize head pointer of the linked list to NULL
NODE head = NULL;

main()
{
  int ch;
  void insert();
  void display();
  void search();
  void delete();

  while (1) {
    printf("MENU\n1. Insert\n 2. Display\n 3. Search\n 4. Delete\n 5. Exit\nEnter choice: ");
    scanf("%d", &ch);

    switch (ch) {

      case 1:
        insert();
        break;

      case 2:
        display();
        break;

      case 3:
        search();
        break;

      case 4:
        delete();
        break;

      case 5:
        exit(0);

      default:
        printf("Invalid Option :-(\n");
        break;
    }
  }
}

void insert()
{
  int v;
  NODE new, temp;
  printf("Enter value: ");
  scanf("%d", &v);

  // Create new node
  new = (NODE)malloc(sizeof(struct node));
  // Store the value for the node
  new->d = v;
  new->next = NULL;

  if (head == NULL) {
    // List is empty
    head = new;
  } else {
    // Otherwise
    temp = head;

    while (temp->next != NULL)
      temp = temp->next;

    temp->next = new;
  }
}

void display()
{
  NODE temp;

  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  printf("Values in list: ");

  temp = head;

  // Iterate through the list and print the value at each node

  while (temp != NULL) {
    printf("%d ", temp->d);
    temp = temp->next;
  }

  printf("\n");
}

void search()
{
  int e;
  NODE temp;
  printf("Enter element: ");
  scanf("%d", &e);

  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  temp = head;

  // Iterate through the list to search for the element

  while (temp != NULL) {
    if (temp->d == e) {
      printf("Element found\n");
      break;
    }

    temp = temp->next;
  }

  if (temp == NULL)
    printf("Element not found\n");
}

void delete()
{
  int e;
  NODE temp, t;
  printf("Enter element: ");
  scanf("%d", &e);

  temp = head;

  // The item to be deleted is the first in the list

  if (temp->d == e) {
    head = temp->next;
    free(temp);
    printf("Deleted\n");
    return;
  }

  while (temp != NULL) {
    if (temp->d == e) {
      break;
    }

    t = temp;

    temp = temp->next;
  }

  // Item not present in the list
  if (temp == NULL)
    printf("Element not found\n");
  else {
    t->next = temp->next;
    free(temp);
    printf("Deleted\n");
  }
}




