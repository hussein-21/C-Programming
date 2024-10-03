#include <stdio.h>

// Function prototypes
int makeReservation(int excursions[]);
float calculatePrice(int people, char tripType);
void displayFinalTotals(float totalCollected, int totalPeople, int morningCount, int afternoonCount, int morningExcursion[],int afternoonExcursion[]);

int main() {
  // Arrays to store available capacity for morning and afternoon excursions
  int morningExcursion[10] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20};
  int afternoonExcursion[10] = {20, 20, 20, 20, 20, 20, 20, 20, 20, 20};

  char tripType, again = 'Y';
  int people = 0, morningCount = 0, afternoonCount = 0, totalPeople = 0;
  float total = 0, totalCollected = 0;

  // Program greeting
  printf("\nWelcome to TrainTrippers Day Excursions!\n");

  while (again == 'Y' || again == 'y') 
  {
    // User chooses a trip type (morning or afternoon)
    printf("\nWould you like a (M)orning trip or an (A)fternoon trip?  ");
    scanf("\n%c", &tripType);

    // Validate the user's choice
    while (tripType != 'M' && tripType != 'm' && tripType != 'A' &&
           tripType != 'a') {
      printf("\nYou have entered an invalid choice!  Please try again!");
      printf("\nWould you like a (M)orning trip or an (A)fternoon trip?  ");
      scanf("\n%c", &tripType);
    }

    // Make a reservation based on the chosen trip type
    if (tripType == 'M' || tripType == 'm')
      people = makeReservation(morningExcursion);
    else
      people = makeReservation(afternoonExcursion);

    // Calculate and display the total cost for the reservation
    total = calculatePrice(people, tripType);
    printf("\nYour total cost is $ %.2f", total);

    // Update counts and totals
    totalCollected += total;
    totalPeople += people;
    if (tripType == 'M' || tripType == 'm')
      morningCount += people;
    else
      afternoonCount += people;

    // Ask if the user wants to make another reservation
    printf("\nIs there another reservation? ");
    scanf("\n%c", &again);
  } // end while

  // Display the final totals and available capacity
  displayFinalTotals(totalCollected, totalPeople, morningCount, afternoonCount,
                     morningExcursion, afternoonExcursion);

  return 0;
}

// Function to make a reservation
int makeReservation(int excursions[]) {
  int people, x, trainCar;

  // Ask the user how many people to make a reservation for
  printf("\nHow many people would you like to make a reservation for? (1-20)");
  scanf("%d", &people);

  // Validate the number of people
  while (people < 1 || people > 20) {
    printf(
        "\nYou have entered an invalid number of people!  Please try again!");
    printf(
        "\nHow many people would you like to make a reservation for? (1-20)");
    scanf("%d", &people);
  }

  // Display available train cars and their current capacity
  printf("\nHere are the available train cars and their current capacity:  ");
  printf("\n\nTrain Car# - Available Seats\n");

  for (x = 0; x < 10; x++) {
    if (people <= excursions[x])
      printf("\n   #%2d     -\t %d", x+1 , excursions[x]);
  }

  // Ask the user to choose a train car (no validation for simplicity)
  printf("\n\nWhich train car would you like to be on? ");
  scanf("%d", &trainCar);

  // Update available capacity for the chosen train car
  excursions[trainCar-1 ] -= people;

  // Display the reservation details
  printf("\nYou are reserved on train car #%d for %d people. ", trainCar,
         people);

  return people;
}

// Function to calculate the reservation price
float calculatePrice(int people, char tripType) {
  // Define trip costs
  float totalCost;

  switch (tripType) {
  case 'M':
  case 'm':
    totalCost = people * 18.50; // Morning trip cost per person: $18.50
    break;
  case 'A':
  case 'a':
    totalCost = people * 23.75; // Afternoon trip cost per person: $23.75
    break;
  }

  // Apply a 20% discount for 10 or more people
  if (people >= 10)
    totalCost = totalCost - (totalCost * 0.20);

  return totalCost;
}

// Function to display final totals and available capacity
void displayFinalTotals(float totalCollected, int totalPeople, int morningCount,
                        int afternoonCount, int morningExcursion[],
                        int afternoonExcursion[]) 
{
  int x;

  // Display the final totals
  printf("\nTotal amount collected:              $ %6.2f", totalCollected);
  printf("\nTotal seats reserved for Morning:      %7d", morningCount);
  printf("\nTotal seats reserved for Afternoon:    %7d", afternoonCount);
  printf("\nTotal seats reserved for the day:      %7d", totalPeople);

  // Display the current capacity for morning and afternoon trains
  printf("\n\nCurrent Capacity for Morning Train: \n\n ");
  for (x = 0; x < 10; x++)
    printf("\n   #%2d     -\t %d", x + 1, morningExcursion[x]);

  printf("\n\nCurrent Capacity for Afternoon Train: \n\n ");
  for (x = 0; x < 10; x++)
    printf("\n   #%2d     -\t %d", x + 1, afternoonExcursion[x]);
}
