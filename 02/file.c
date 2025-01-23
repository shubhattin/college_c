#include <stdio.h>

void print();
int main() { print(); }

struct Student
{
  char name[30];
  int subjects[5];
  int total;
  float perc;
};

void print()
{
  FILE *fp;
  fp = fopen("a.txt", "w");
  struct Student students[5];
  char SUBJECT_NAMES[5][20] = {"English", "Mathematics", "Computer", "Physics",
                               "Chemistry"};
  int i, j;
  // taking input
  for (i = 0; i < 5; i++)
  {
    printf("\n\nEnter Details for Student %d:\n", i + 1);
    printf("Enter Name : ");
    scanf(" %[^\n]", students[i].name);
    for (j = 0; j < 5; j++)
    {
      printf("Enter Marks in %s = ", SUBJECT_NAMES[j]);
      scanf("%d", &students[i].subjects[j]);
    }
    students[i].total = 0;
    for (j = 0; j < 5; j++)
      students[i].total += students[i].subjects[j];
    students[i].perc = students[i].total / 500.0 * 100.0;
  }
  // Writing Output to file
  for (i = 0; i < 5; i++)
  {
    fprintf(fp, "Name : %s\n", students[i].name);
    for (j = 0; j < 5; j++)
      fprintf(fp, "Marks in %s : %d\n", SUBJECT_NAMES[j],
              students[i].subjects[j]);
    if (i != 4)
      fprintf(fp, "\n------------------------------------------------------------"
                  "------------\n\n");
  }
  fclose(fp);
}
