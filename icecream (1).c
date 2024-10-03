// Hussein ALsaidi
// Ice Cream Assignment


#include <stdio.h> 

// Function to get the ice cream flavor choice from the user
char getIceCreamFlavor() 
{
    char flavor;

    do 
    {
      // Display the ice cream flavor menu
      printf("\nChoose an ice cream flavor \n V - Vanilla\n C - Chocolate\n F - Fudge\n Q - Quit\n");
      scanf(" %c", &flavor);

      if (flavor == 'Q' || flavor == 'q'){
        break; // Exit the loop if the user wants to quit
      }
      else if (flavor == 'V' || flavor == 'v' || flavor == 'C' || flavor == 'c' || flavor == 'F' || flavor == 'f'){
        return flavor; // Return the flavor if it's a valid choice
      }
      else 
      {
        printf("Invalid flavor choice. Please try again.\n"); // Display an error message for an invalid choice
      } 

    } while (1);

    return flavor;
}

// Function to validate and get the number of scoops
int getNumberOfScoops()
{
    int scoops;
    printf("Enter the number of scoops (1-4): ");
    scanf("%d", &scoops);

    // Validate the number of scoops
    while (scoops < 1 || scoops > 4) {
        printf("Invalid number of scoops! Please choose between 1 and 4.\n");
        printf("Enter the number of scoops (1-4): ");
        scanf("%d", &scoops);
    }

    return scoops;
}

// Function to calculate the cost of the ice cream
float calculateCost(int scoops)
{
    // Cost of cone + Cost per scoop
    return 0.75 + (1.25 * scoops);
}

// Function to display the total statistics
void displayTotalStatistics(int totalCones, int totalVanilla, int totalChocolate, int totalFudge, float totalAmount) 
{
    // Display the total statistics
    printf("\nTotal Cones Sold: %d\n", totalCones);
    printf("Total Vanilla Scoops Sold: %d\n", totalVanilla);
    printf("Total Chocolate Scoops Sold: %d\n", totalChocolate);
    printf("Total Fudge Scoops Sold: %d\n", totalFudge);
    printf("Total Amount Collected: $%.2f\n", totalAmount);
}

int main()
{
    int totalCones = 0, totalVanilla = 0, totalChocolate = 0, totalFudge = 0;
    float totalAmount = 0;
    char choice;
    int scoops;

    do {
        choice = getIceCreamFlavor();
        if (choice == 'Q' || choice =='q'){
          break; // Exit the loop if the user wants to quit
        }
        else
        {
          scoops = getNumberOfScoops();

          // Update totals based on flavor and scoops
          switch (choice) {
              case 'V': case 'v':
                  totalVanilla += scoops;
                  break;
              case 'C': case 'c':
                  totalChocolate += scoops;
                  break;
              case 'F': case 'f':
                  totalFudge += scoops;
                  break;
          }

          totalCones++;
          totalAmount += calculateCost(scoops);
        }
        printf("Your ice cream cone cost $%.2f\n", calculateCost(scoops));  
    } while (1);

    // Display the total statistics
    displayTotalStatistics(totalCones, totalVanilla, totalChocolate, totalFudge, totalAmount);

    return 0;
}
// END //