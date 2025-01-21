#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10

int main()
{
    int arr[N], i;
    int num, index = -1, min_index, min;
    srand(time(0));

    // Generate and print random array
    for (i = 0; i < N; i++)
    {
        arr[i] = rand() % 100 + 1;
        printf("%d ", arr[i]);
    }
    printf("\n");
    // Maximum search
    int max = arr[0];
    int max_index = 0;
    for (i = 1; i < N; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            max_index = i;
        }
    }
    printf("Maximum value = %d found at index %d\n", max, max_index);
    // Linear search
    printf("Enter number to search: ");
    scanf("%d", &num);
    for (i = 0; i < N; i++)
    {
        if (arr[i] == num)
        {
            index = i;
            break; // Exit loop once number is found
        }
    }
    if (index != -1)
    {
        printf("Number %d found at index %d\n", num, index);
    }
    else
    {
        printf("Number %d not found\n", num);
    }

    // Minimum search
    min = arr[0];
    min_index = 0;
    for (i = 1; i < N; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            min_index = i;
        }
    }
    printf("Minimum value = %d found at index %d\n", min, min_index);

    // Second maximum search
    int max1, max2;
    max1 = max2 = -1;

    for (i = 0; i < N; i++)
    {
        if (arr[i] > max1)
        {
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2 && arr[i] != max1)
        {
            max2 = arr[i];
        }
    }

    if (max2 != -1)
    {
        printf("Second maximum value = %d\n", max2);
    }
    else
    {
        printf("No second maximum value found\n");
    }

    return 0;
}







