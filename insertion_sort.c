/*
 * Input  : A sequence of n numbers <a1, a2, ..., an>
 * Output : Sorted list <a1', a2', ..., an'>
 *          of the input sequence in ascending order
 * Method : For any element, we assume all the elements
 *          to its left are already sorted. Shifting all
 *          the elements greater to it, in the left to one
 *          position right and then insert the key selected
 *          in the right position.
 */

#include<stdio.h>
#include<stdlib.h>

main()
{
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
  insertion_sort(array, n);

  // Display sorted array
  printf("sorted array:");

  for (i = 0;i < n;i++)
    printf("%d ", array[i]);

  printf("\n");
}

/*
 * Sorts the elements of the array in ascending order
 */
insertion_sort(int *arr, int num)
{
  int i, j, key;

  for (i = 1;i < num;i++) {
    // Select the element to be inserted to its
    // correct position
    key = arr[i];

    for (j = i - 1;j >= 0;j--) {
      if (arr[j] > key)
        arr[j+1] = arr[j];
      else
        break;
    }

    // Inserting to the right position
    arr[j+1] = key;
  }
}
