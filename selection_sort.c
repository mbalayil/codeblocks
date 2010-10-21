/*
 * Input  : A sequence of n numbers <a1, a2, ..., an>
 * Output : Sorted list <a1', a2', ..., an'>
 *          of the input sequence in ascending order
 * Method : Find the minimum value in the list and swap
 *          it with the first position. Repeat the same for
 *          the remainder of the list, starting with the second
 *          position and advancing each time.
 */

#include<stdio.h>
#include<stdlib.h>

main()
{
  // Function declaration
  void selection_sort(int *, int);

  int *array = NULL; // Pointer to int, initialize to nothing.
  int n, i;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  // Dynamically allocate memory for n elements
  array = (int *)calloc(n, sizeof(int));

  // Reading the elements
  printf("\nEnter the elements:");

  for (i = 0;i < n;i++)
    scanf("%d", &array[i]);

  // Invoke selection_sort
  selection_sort(array, n);

  // Display sorted array
  printf("sorted array:");

  for (i = 0;i < n;i++)
    printf("%d ", array[i]);

  printf("\n");
}

selection_sort(int *arr, int num)
{
  int i, j, small, pos, temp;

  for (i = 0;i < num;i++) {
    small = arr[i];
    pos = i;

    for (j = i;j < num;j++) {
      if (arr[j] < small) {
        small = arr[j];
        pos = j;
      }
    }

    temp = arr[i];
    arr[i] = small;
    arr[pos] = temp;
  }
}
