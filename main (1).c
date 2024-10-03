#include <stdio.h>

//

void initializeDisplayAndShiftArray() {

    // Initialize an array of floats

    float numbers[] = {18.56f, 24.32f, 99.14f, 70.78f, 35.90f, 6.65f};

    int size = sizeof(numbers) / sizeof(numbers[0]);



    // Display the original array

    printf("Original Array: ");

    for (int i = 0; i < size; i++) {

        printf("%.2f ", numbers[i]);

    }

    printf("\n");



    // Shift the numbers to the left

    float firstNumber = numbers[0];

    for (int i = 0; i < size - 1; i++) {

        numbers[i] = numbers[i + 1];

    }

    // Move the first number to the last position

    numbers[size - 1] = firstNumber;



    // Display the shifted array

    printf("Shifted Array: ");

    for (int i = 0; i < size; i++) {

        printf("%.2f ", numbers[i]);

    }

    printf("\n");

}











void evenNumbers(){



  int numbers[10];

  int evenCount = 0;



  printf("Enter 10 numbers\n");

  for (int i = 0; i <10 ; i++)

  {

    printf("enter a number\n", i+1);

    scanf("%d", &numbers[i]);

  }



  printf("Entered Numbers:\n");

  for (int i = 0; i <10 ; i++){

    printf("%d", numbers[i]);

    if (numbers[i] % 2 == 0){

      evenCount++;

    }

  }

  printf("\nEven numbers : %d\n", evenCount);



}





#include <stdio.h>



// Function to initialize and print an array

void initializeAndPrintArray() {

    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89};

    int size = sizeof(arr) / sizeof(arr[0]);



    printf("\nInitial Array:");

    for (int i = 0; i < size; i++) {

        printf("%d ", arr[i]);

    }

    printf("\n");

}



// Function to reverse an array and print its contents

void reverseArrayAndPrint() {

    int arr[] = {12, 23, 34, 45, 56, 67, 78, 89};

    int size = sizeof(arr) / sizeof(arr[0]);



    // Reverse the array in place

    for (int i = 0; i < size / 2; i++) {

        int temp = arr[i];

        arr[i] = arr[size - 1 - i];

        arr[size - 1 - i] = temp;

    }



    printf("\nReversed Array: ");

    for (int i = 0; i < size; i++) {

        printf("%d ", arr[i]);

    }

    printf("\n");

}









int main(){





   initializeDisplayAndShiftArray();

   initializeAndPrintArray();

   reverseArrayAndPrint();

   evenNumbers();





  return 0;

}

