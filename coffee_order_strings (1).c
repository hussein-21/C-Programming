// Hussein Alsaidi
// 11-20-23
// Coffee Order Strings

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void getFlavor(char* flavor) 
{
  char flavors[5][20] = 
  {"House", "Iced", "Vanilla", "Hazelnut", "Mocha"};
  printf("Available flavors: House, Iced, Vanilla, Hazelnut, Mocha\n");
  printf("Enter the flavor: ");
  scanf("%s", flavor);
  for (int i = 0; i < 5; i++) 
  {
    if (strcasecmp(flavor, flavors[i]) == 0) 
    {
      return;
    }
  }

  printf("Invalid flavor. Please try again.\n");
  getFlavor(flavor);
}

char getSize(char* size) 
{
  printf("Available sizes: (S)mall, (M)edium, (L)arge\n");
  printf("Enter the size S, M, L:");
  scanf(" %s", size);

  for (int i = 0; size[i]; i++)
  {
    size[i] = tolower(size[i]);
  }

  if (strcmp(size, "s") == 0 || strcmp(size, "m") == 0 || strcmp(size, "l") == 0)
  {
    return size[0]; 
  }
  
  printf("Invalid size. Please try again.\n");
  return getSize(size);
}

bool getCreamOption() 
{
  char option;

  printf("Do you want cream? (Y/N): ");
  scanf(" %c", &option);

  option = tolower(option);

  if (option == 'y')
  {
    return true;
  } 
  else if (option == 'n') 
  {
    return false;
  }

  printf("Invalid option. Please try again.\n");
  return getCreamOption();
}

bool getSugarOption() {
  char option;

  printf("Do you want sugar? (Y/N): ");
  scanf(" %c", &option);

  option = tolower(option);

  if (option == 'y') 
  {
    return true;
  } else if (option == 'n') 
  {
    return false;
  }

    
  printf("Invalid option. Please try again.\n");
  return getSugarOption();
}

float calculatePrice(char* size) {
  if (strcmp(size, "s") == 0) 
  {
    return 3.00;
  } 
  else if (strcmp(size, "m") == 0) 
  {
    return 4.50;
  } 
  else if (strcmp(size, "l") == 0) 
  {
    return 6.00;
  }

    return 0.00;
}

void displayOrder(char* flavor, char* size, bool hasCream, bool hasSugar, float price)
{
  if(size[0] == 's')
    printf("Small ");
  if(size[0] == 'm')
    printf("Medium");
  if(size[0] == 'l')
    printf("Large");
  printf("Your coffee order:\n");
  printf("%s %s coffee", size[0] == 's'? "Small" : size[0] == 'm'? "Medium" : "Large", flavor);

  if (hasCream)
    printf(" with cream");

  if (hasSugar)
    printf(" and sugar");

  printf("\nTotal due: $ %.2f\n", price);
}


void orderCoffee() 
{
  char flavor[20];
  char size[10];
  bool hasCream;
  bool hasSugar;

  getFlavor(flavor);
  getSize(size);
  hasCream = getCreamOption();
  hasSugar = getSugarOption();

  float price = calculatePrice(size);

  displayOrder(flavor, size, hasCream, hasSugar, price);
}

int main() 
{
  char continueOrder;

  do{
    orderCoffee();
    
    printf("\nDo you want to place another order? (Y/N): ");
    scanf(" %c", &continueOrder);
    continueOrder = tolower(continueOrder);
    } while (continueOrder == 'y');

    return 0;
}
