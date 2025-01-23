#include <stdio.h>
#include <string.h>

#define MAX_NAMES 5
#define MAX_LENGTH 50

void bubbleSort(char names[][MAX_LENGTH], int n)
{
    char temp[MAX_LENGTH];
    int i, j;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                // Swap names
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
}

int main()
{
    char names[MAX_NAMES][MAX_LENGTH];
    int i;

    printf("Enter %d names:\n", MAX_NAMES);
    for (i = 0; i < MAX_NAMES; i++)
    {
        printf("Enter name %d: ", i + 1);
        scanf(" %[^\n]", names[i]);
    }

    bubbleSort(names, MAX_NAMES);

    printf("\nNames in ascending order:\n");
    for (i = 0; i < MAX_NAMES; i++)
        printf("%d. %s\n", i + 1, names[i]);

    return 0;
}