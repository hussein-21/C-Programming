// Hussein Alsaidi
// 10-25-23
// Statistical Analysis Assignment

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Function prototypes
void getData(int data[], int size);
void displayData(int data[], int size);
void displayLargest(int data[], int size);
void displaySmallest(int data[], int size);
void displayAverage(int data[], int size);
void displayRange(int data[], int size);
void displayMedian(int data[], int size);
void displayMode(int data[], int size);

int main() {
    int data[MAX];

    getData(data, MAX);
    displayData(data, MAX);
    displayLargest(data, MAX);
    displaySmallest(data, MAX);
    displayAverage(data, MAX);
    displayRange(data, MAX);
    displayMedian(data, MAX);
    displayMode(data, MAX);

    return 0;
}

void getData(int data[], int size) {
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &data[i]);
    }
}

void displayData(int data[], int size) {
    printf("Data in the array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void displayLargest(int data[], int size) {
    int max = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    printf("Largest number: %d\n", max);
}

void displaySmallest(int data[], int size) {
    int min = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }
    printf("Smallest number: %d\n", min);
}

void displayAverage(int data[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    double average = (double)sum / size;
    printf("Average: %.2f\n", average);
}

void displayRange(int data[], int size) {
    int max = data[0];
    int min = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
        if (data[i] < min) {
            min = data[i];
        }
    }
    printf("Range: %d\n", max - min);
}

void displayMedian(int data[], int size) {
    int temp[MAX];
    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                int swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    if (size % 2 == 0) {
        int middle1 = temp[size / 2 - 1];
        int middle2 = temp[size / 2];
        double median = (double)(middle1 + middle2) / 2.0;
        printf("Median: %.2f\n", median);
    } else {
        int middle = temp[size / 2];
        printf("Median: %d\n", middle);
    }
}

void displayMode(int data[], int size) {
    int maxCount = 0;
    int mode = data[0];

    for (int i = 0; i < size; i++) {
        int count = 1;

        for (int j = i + 1; j < size; j++) {
            if (data[i] == data[j]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            mode = data[i];
        }
    }

    printf("Mode(s): ");
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (data[i] == data[j]) {
                count++;
            }
        }
        if (count == maxCount) {
            printf("%d ", data[i]);
        }
    }
    printf("\n");
}
