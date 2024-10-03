// Hussein Alsaidi

#include <stdio.h>

char displayMenu() {
  char category;
  int choice = 0;

  while (choice != 1) {
    printf("Please choose from the following menu categories:\n");
    printf("T - Tacos\nB - Burritos\nQ - Quesadillas\nN - Nachos\n");
    scanf(" %c", &category);

    switch (category) {
    case 'T':
    case 't':

      return category;
    case 'B':
    case 'b':

      return category;
    case 'Q':
    case 'q':

      return category;
    case 'N':
    case 'n':

      return category;
    }
  }
  return displayMenu();
}

float tacoMenu() {
  int taco;

  printf("\n1 - Regular Taco    $1.99\n");
  printf("2 - Super Taco      $2.99\n");
  printf("3 - Veggie Taco     $1.99\n");
  printf("Choose a Taco: ");
  scanf("%d", &taco);

  switch (taco) {
  case 1:
    return 1.99;
  case 2:
    return 2.99;
  case 3:
    return 1.99;
  default:
    printf("\nInvalid Choice!\nPlease try again!\n");
  }
  return tacoMenu();
}

float burritosMenu() {
  int burrito;

  printf("\n1 - Regular Burrito               $2.99\n");
  printf("2 - Super Burrito                 $3.99\n");
  printf("3 - Veggie Burrito                $2.99\n");
  printf("4 - Bean & Rice Burrito           $1.99\n");
  printf("5 - Bean, Rice, & Cheese Burrito  $1.99\n");
  printf("6 - Burrito Bowl                  $4.99\n");
  printf("Choose a Burrito: ");
  scanf("%d", &burrito);

  switch (burrito) {
  case 1:
    return 2.99;
  case 2:
    return 3.99;
  case 3:
    return 2.99;
  case 4:
    return 1.99;
  case 5:
    return 1.99;
  case 6:
    return 4.99;
  default:
    printf("Invalid Choice! Please try again! Choose a Burrito: ");
  }
  return burritosMenu();
}

float quesadillasMenu() {
  int quesadillas;

  printf("\n1 - Regular Quesadilla  $1.99\n");
  printf("2 - Meat Quesadilla     $2.99\n");
  printf("3 - Beef Quesadilla     $3.99\n");
  printf("4 - Super Quesadilla    $4.99\n");
  printf("Choose a Quesadilla: ");
  scanf("%d", &quesadillas);

  switch (quesadillas) {
  case 1:
    return 1.99;
  case 2:
    return 2.99;
  case 3:
    return 3.99;
  case 4:
    return 4.99;
  default:
    printf("Invalid Choice! Please try again! Choose a Quesadilla: ");
  }
  return quesadillasMenu();
}

float nachosMenu() {
  int nachos;
  char extraCheese; // EXTRA PRICE FOR ADDED CHEESE
  float price = 0;

  printf("\n1 - Regular Nacho       $3.99\n");
  printf("2 - Super Nacho         $5.99\n");
  printf("Choose a Nacho: ");
  scanf("%d", &nachos);

  switch (nachos) {
  case 1:
    price += 3.99;
    break;
  case 2:
    price += 5.99;
    break;
  default:
    printf("Invalid Choice! Please try again! Choose a Nacho: ");
    return nachosMenu();
  }

  printf("Would you like extra cheese for $1.00? Y/N\n");
  scanf(" %c", &extraCheese);

  switch (extraCheese) {
  case 'Y':
  case 'y':
    price += 1.00;
    break;
  case 'N':
  case 'n':
    break;
  }

  return price;
}

void displayTotal(int totalTacos, int totalBurritos, int totalQuesadillas,
                  int totalNachos, float total) {
  printf("Your order consists of:\n");
  if (totalTacos != 0)
    printf("Total Tacos:\t %d\n", totalTacos);
  if (totalBurritos != 0)
    printf("Total Burritos:\t %d\n", totalBurritos);
  if (totalQuesadillas != 0)
    printf("Total Quesadillas:\t %d\n", totalQuesadillas);
  if (totalNachos != 0)
    printf("Total Nachos:\t %d\n", totalNachos);

  printf("Total Due:\t $%.2f\n", total);
  printf("Thank you for choosing Tomas Taco Truck!\n");
}

int main() {
  char choice = 'Y';
  int totalTacos = 0, totalBurritos = 0, totalQuesadillas = 0, totalNachos = 0;
  float total = 0;
  char item, addToOrder;
  

  while (choice == 'Y' || choice == 'y') {
    printf("Welcome to Tomas Taco Truck!\n");
    printf("Would you like to place an order? Y/N\n ");
    scanf(" %c", &choice);

    switch (choice) {
    case 'Y':
    case 'y':
      item = displayMenu();
      break;
    case 'N':
    case 'n':
      displayTotal(totalTacos, totalBurritos, totalQuesadillas, totalNachos, total);
      return 0;
    }

    switch (item) {
    case 'T':
    case 't':
      totalTacos += 1;
      total += tacoMenu();
      break;
    case 'B':
    case 'b':
      totalBurritos += 1;
      total += burritosMenu();
      break;
    case 'Q':
    case 'q':
      totalQuesadillas += 1;
      total += quesadillasMenu();
      break;
    case 'N':
    case 'n':
      totalNachos += 1;
      total += nachosMenu();
      break;
    }

    printf("Would you like to add to your order? Y/N\n");
    scanf(" %c", &addToOrder);

    switch (addToOrder) {
    case 'Y':
    case 'y':
      item = displayMenu();
      break;
    case 'N':
    case 'n':
      displayTotal(totalTacos, totalBurritos, totalQuesadillas, totalNachos, total);
      break;
    }
  }

  return 0;
}