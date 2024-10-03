#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dogs {
  char dogName[30];
  int dogWeight;
  int dogAge;
  char size[20];
  int dogYears;
};

// Function prototypes
void getDogInfo(struct dogs alldogs[], int dogNums);
int calcDogYears(struct dogs alldogs[], int dogNums);
void printOut(struct dogs alldogs[], int dogNums);
void saveToFile(struct dogs alldogs[], int dogNums, char *filename);
void readFromFile(struct dogs alldogs[], int *dogNums, char *filename);

int main() {
  int dogNums, choice;
  printf("How many dogs do you have? (1-10): ");
  scanf("%d", &dogNums);

  while (dogNums < 1 || dogNums > 10) {
    printf("How many dogs do you have? (1-10): ");
    scanf("%d", &dogNums);
  }

  struct dogs alldogs[10];
  getDogInfo(alldogs, dogNums);
  calcDogYears(alldogs, dogNums);

  printf("Would you like to enter information about their dogs (Enter 1) or do you wish to read this information from a file (Enter 2): ");
  scanf("%d", &choice);

  if (choice == 1) {
    printOut(alldogs, dogNums);
  } else if (choice == 2) {
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);
    saveToFile(alldogs, dogNums, filename);
  } else {
    printf("Invalid choice. Exiting...\n");
    return 1;
  }

  return 0;
}

void getDogInfo(struct dogs alldogs[], int dogNums) {
  for (int i = 0; i < dogNums; i++) {
    printf("Enter dog name: ");
    scanf("%s", alldogs[i].dogName);

    printf("Enter dog Weight: ");
    scanf("%d", &alldogs[i].dogWeight);

    while (alldogs[i].dogWeight <= 0) {
      printf("Invalid weight...\nEnter dog Weight: ");
      scanf("%d", &alldogs[i].dogWeight);
    }

    printf("Enter dog Age: ");
    scanf("%d", &alldogs[i].dogAge);
  }
}

int calcDogYears(struct dogs alldogs[], int dogNums) {
  for (int i = 0; i < dogNums; i++) {
    if (alldogs[i].dogWeight < 20) {
      strcpy(alldogs[i].size, "Small Dog");
    } else if (alldogs[i].dogWeight <= 50) {
      strcpy(alldogs[i].size, "Medium Dog");
    } else {
      strcpy(alldogs[i].size, "Large Dog");
    }

    if (strcmp(alldogs[i].size, "Small Dog") == 0) {
      if (alldogs[i].dogAge == 1) {
        alldogs[i].dogYears = 15;
      } else if (alldogs[i].dogAge == 2) {
        alldogs[i].dogYears = 23;
      } else if (alldogs[i].dogAge == 3) {
        alldogs[i].dogYears = 28;
      } else {
        alldogs[i].dogYears = 28 + 4 * alldogs[i].dogAge - 3;
      }
    } else if (strcmp(alldogs[i].size, "Medium Dog") == 0) {
      if (alldogs[i].dogAge == 1) {
        alldogs[i].dogYears = 14;
      } else if (alldogs[i].dogAge == 2) {
        alldogs[i].dogYears = 23;
      } else if (alldogs[i].dogAge == 3) {
        alldogs[i].dogYears = 30;
      } else {
        alldogs[i].dogYears = 30 + 5 * alldogs[i].dogAge - 3;
      }
    } else {
      if (alldogs[i].dogAge == 1) {
        alldogs[i].dogYears = 12;
      } else if (alldogs[i].dogAge == 2) {
        alldogs[i].dogYears = 21;
      } else if (alldogs[i].dogAge == 3) {
        alldogs[i].dogYears = 29;
      } else {
        alldogs[i].dogYears = 29 + 7 * alldogs[i].dogAge - 3;
      }
    }
  }
  return 0; 
}

void printOut(struct dogs alldogs[], int dogNums) {
  printf("\n\n%-15s%-15s%-20s%-20s\n", "Dog Name", "Dog Size", "Years in Human", "Years in Dog");

  for (int i = 0; i < dogNums; i++) {
    printf("%-15s%-15s%-20d%-20d\n", alldogs[i].dogName, alldogs[i].size, alldogs[i].dogAge, alldogs[i].dogYears);
  }
}

void saveToFile(struct dogs alldogs[], int dogNums, char *filename) {
  FILE *file;
  char csvName[100];
  snprintf(csvName, sizeof(csvName), "%s.csv", filename);
  file = fopen(csvName, "w");

  
  if (file == NULL) {
    printf("Error opening file for writing. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  fprintf(file, "Dog Name,Dog Weight,Years In Human,Years In Dog\n");
  for (int i = 0; i < dogNums; i++) {
    fprintf(file, "%s,%s,%d,%d\n", alldogs[i].dogName, alldogs[i].size, alldogs[i].dogAge, alldogs[i].dogYears);
  }

  fclose(file);
  printf("Data saved to %s successfully.\n", filename);
}

void readFromFile(struct dogs alldogs[], int *dogNums, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file for reading. Exiting...\n");
    exit(EXIT_FAILURE);
  }

  int count = 0;
  fscanf(file, "%*[^,],%*[^,],%*[^,],%*[^\n]\n"); 
  while (fscanf(file, "%29[^,],%d,%d,%d%*c", alldogs[count].dogName, &alldogs[count].size, &alldogs[count].dogAge, &alldogs[count].dogYears) == 4) {
    count++;
  }

  fclose(file);
  *dogNums = count;
  printf("%d dogs loaded from %s.\n", count, filename);
}
