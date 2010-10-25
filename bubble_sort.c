/*
 * Input  : A sequence of n numbers <a1, a2, ..., an>
 * Output : Sorted list <a1', a2', ..., an'>
 *          of the input sequence in ascending order
 * Method : Compare each pair of adjacent items and swap if
 *          they are in the wrong order. The pass through the
 *          list is repeated untill no swaps are required.
 */

#include<stdio.h>
#include<stdlib.h>

int main()
{
  // Function declaration
  void bubble_sort(int *, int);

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

  // Invoke insertion_sort
  bubble_sort(array, n);

  // Display sorted array
  printf("sorted array:");
  for (i = 0;i < n;i++)
    printf("%d ", array[i]);
  printf("\n");

  return 0;
}

/*
 * Sorts the elements of the array in ascending order
 */
void bubble_sort(int *arr, int num)
{
  int i, j, temp;

  for (i = 0;i < num;i++) {
    for (j = i + 1;j < num;j++) {
      if (arr[i] > arr[j]) { // swapping
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
