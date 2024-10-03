#include <stdio.h>

int calculateBMI(int weight, int height);  // Function prototype for calculating BMI
void practiceForLoop();  // Function prototype for practicing with a for loop
void practiceDoWhileLoop();  // Function prototype for practicing with a do-while loop
void practiceWhileLoop();  // Function prototype for practicing with a while loop

int main() {
    // Call functions to practice different loop types
    practiceForLoop();
    practiceDoWhileLoop();
    practiceWhileLoop();

    return 0;
}

int calculateBMI(int weight, int height) {
    // Calculate BMI using the formula: BMI = (weight * 703) / (height * height)
  
    return (weight * 703) / (height * height);
}

void practiceForLoop() {
    int bmi, weight, height;

    // Use a for loop to prompt the user for weight and height for 3 people
    for (int x = 1; x <= 3; x++) {
        printf("Enter your weight in pounds: ");
        scanf("%d", &weight);
        printf("Enter your height in inches: ");
        scanf("%d", &height);

        // Calculate and display BMI
        bmi = calculateBMI(weight, height);
        printf("\nYour current BMI is %d\n", bmi);
    }
}

void practiceDoWhileLoop() {
    int bmi, weight, height, x;

    x = 1;
    // Use a do-while loop to prompt the user for weight and height for up to 3 people
    do {
        printf("Enter your weight in pounds: ");
        scanf("%d", &weight);
        printf("Enter your height in inches: ");
        scanf("%d", &height);

        // Calculate and display BMI
        bmi = calculateBMI(weight, height);
        printf("\nYour current BMI is %d\n", bmi);
        x++;
    } while (x <= 3);
}

void practiceWhileLoop() {
    char again;
    int bmi, weight, height;

    // Use a while loop to prompt the user if they want to calculate BMI
    printf("Would you like to calculate a BMI Y/N?  ");
    scanf("\n%c", &again);

    while (again == 'Y' || again == 'y') {
        printf("Enter your weight in pounds: ");
        scanf("%d", &weight);
        printf("Enter your height in inches: ");
        scanf("%d", &height);

        // Calculate and display BMI
        bmi = calculateBMI(weight, height);
        printf("\nYour current BMI is %d\n", bmi);

        // Ask if the user wants to calculate another BMI
        printf("Would you like to calculate another BMI Y/N?  ");
        scanf("\n%c", &again);
    }
}
