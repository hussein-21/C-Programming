#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Services{

  int serviceId;
  char service[50];
  int petType;
  float price;
};


struct Pet
{
  char petName[30];
  int petType;   // 1 Dog, 2 Cat
  char gender;
  char ownerName[30];
};


void readAllServices(struct Services allServices[]);
int readAllPets(struct Pet allPets[]);
int findPetRecord(char petName[],char ownerName[], struct Pet allPets[], int currentNumberOfPets);
struct Pet createNewPetRecord(char petName[], char ownerName[]);
int selectServices(struct Services allServices[],struct Services customerServices[], struct Pet onePet);
void getPaymentInfo(long int *cardNumber, int *expireMonth, int *expireYear, int *cvvCode);
float printReceipt(long int cardNumber,int expireMonth,int expireYear,int cvvCode,struct Services customerServices[],struct Pet onePet, int numServices);


int main()
{
  struct Services allServices[15];
  struct Services customerServices[4];

  struct Pet allPets[30];

  int currentNumberOfPets, totalCustomers=0;
  float totalCollected=0;
  char petName[30], ownerName[30], another='Y';
  long int cardNumber;
  int expireMonth, expireYear, cvvCode, location, numServices;

  readAllServices(allServices);
  currentNumberOfPets = readAllPets(allPets);

  while (another == 'Y' || another == 'y')
  {

    printf("Enter the pets name:  ");
    fgets(petName, 30, stdin);
    petName[strlen(petName) - 1] = '\0';

    printf("Enter the owner name:  ");
    fgets(ownerName, 30, stdin);

    location = findPetRecord(petName,ownerName, allPets, currentNumberOfPets);
    if (location == -1)
    {
      location = currentNumberOfPets;
      allPets[location] = createNewPetRecord(petName, ownerName);
      currentNumberOfPets++;
    }

    numServices = selectServices(allServices,customerServices, allPets[location]);


    getPaymentInfo(&cardNumber, &expireMonth, &expireYear, &cvvCode);

    totalCollected += printReceipt(cardNumber, expireMonth, expireYear, cvvCode,customerServices, allPets[location], numServices);
    totalCustomers++;

    printf("\nIs there another customer? Y/N");
    scanf("\n%c", &another);

    getchar();

  }	// end while

  printf("\nTotal number of pets served today:    %d", totalCustomers);
  printf("\nTotal amount collected today:     $%8.2f", totalCollected);

  return 0;
}


float printReceipt(long int cardNumber,int expireMonth,int expireYear,int cvvCode,struct Services customerServices[],struct Pet onePet, int numServices)
{
  float totalPaid = 0;
  int x;

  printf("\nPayment receipt for services on %s: \n\n", onePet.petName);
  for (x=0; x< numServices; x++)
  {
    printf("\n \t\t%d  %-25s   %8.2f", customerServices[x].serviceId, customerServices[x].service, customerServices[x].price);
    totalPaid += customerServices[x].price;
  }
  printf("\n \t\tTotal Paid:       $%8.2f\n", totalPaid);
  printf("\n\n \tCard Number:  	 %ld", cardNumber);
  printf("\n \tExpiration Date:  %d/%d",expireMonth,expireYear);
  printf("\n \tCVV Code:  	      %d", cvvCode);

  return totalPaid;
}


void getPaymentInfo(long int *cardNumber, int *expireMonth, int *expireYear, int *cvvCode)
{

  printf("\nEnter Payment Information:  ");
  printf("\nEnter credit card number:  ");
  scanf("%ld", cardNumber);
  printf("Enter card expiration Month:  ");
  scanf("%d", expireMonth);
  printf("Enter card expiration Year:  ");
  scanf("%d", expireYear);
  printf("Enter card cvv code:  ");
  scanf("%d", cvvCode);
}


int selectServices(struct Services allServices[],struct Services customerServices[], struct Pet onePet)
{
  int x, y = 0, serviceId;

  for (y = 0; y < 4; y++)
  {

    for (x=0; x < 15; x++)
    {
      if (allServices[x].petType == onePet.petType || allServices[x].petType == 3)
        printf("\n %d  %-25s   $%10.2f", allServices[x].serviceId, allServices[x].service, allServices[x].price);
    }
    printf("\nPlease choose a service code or 0 to quit: ");
    scanf("%d", &serviceId);
    if (serviceId == 0)
      break;
    for (x=0; x < 15; x++)
    {
      if (serviceId == allServices[x].serviceId)
        customerServices[y] = allServices[x];
    }
  }
   return y;
}


struct Pet createNewPetRecord(char petName[], char ownerName[])
{
  struct Pet newPet;
  printf("Owner and pet not found in system, creating new account!  ");
  strcpy(newPet.petName, petName);
  strcpy(newPet.ownerName, ownerName);

  printf("\nEnter 1 for Dog or 2 for Cat:  ");
  scanf("%d", &newPet.petType);
  while (newPet.petType < 1 || newPet.petType > 2)
  {
    printf("You have entered an invalid type, please try again!");
    printf("Enter 1 for Dog or 2 for Cat:  ");
    scanf("%d", &newPet.petType);
  }

  printf("Enter M for Male or F for Female:  ");
  scanf("\n%c", &newPet.gender);
  if (newPet.gender > 96)
    newPet.gender -= 32;
  while (newPet.gender != 'M' && newPet.gender != 'F')
  {
    printf("You have entered an invalid type, please try again!");
    printf("Enter M for Male or F for Female:  ");
    scanf("\n%c", &newPet.gender);
    if (newPet.gender > 96)
      newPet.gender += 32;
  }

  return newPet;
}


int findPetRecord(char petName[],char ownerName[], struct Pet allPets[], int currentNumberOfPets)
{
  int x;
  for (x=0; x < currentNumberOfPets; x++)
  {
    if (strcmp(petName, allPets[x].petName) == 0 && strcmp(ownerName, allPets[x].ownerName) == 0)
      return x;
  }

  return -1;
}


void readAllServices(struct Services allServices[])
{
    FILE *fp;

    fp = fopen("allServices.csv", "r");

    if (fp == NULL)
  {
      printf("Error reading services file.  Program terminating .... ");
      exit(0);
  }

  char line[100];
  char *sp;
  int x=0;

  while (fgets(line,100,fp) != NULL)
  {
    sp = strtok(line,",");
    allServices[x].serviceId = atoi(sp);

    sp = strtok(NULL,",");
    strcpy(allServices[x].service,sp);

    sp = strtok(NULL,",");
    allServices[x].petType = atoi(sp);

    sp = strtok(NULL,",");
    allServices[x].price = atof(sp);

    x++;
  }

  fclose(fp);
}


int readAllPets(struct Pet allPets[])
{
    FILE *fp;

    fp = fopen("allPets.csv", "r");

    if (fp == NULL)
  {
      printf("Error reading pets file.  Program terminating .... ");
      exit(0);
  }

  char line[100];
  char *sp;
  int x=0;

  while (fgets(line,100,fp) != NULL)
  {
    sp = strtok(line,",");
    strcpy(allPets[x].petName,sp);

    sp = strtok(NULL,",");
    allPets[x].petType = atoi(sp);

    sp = strtok(NULL,",");
    allPets[x].gender = *sp;

    sp = strtok(NULL,",");
    strcpy(allPets[x].ownerName,sp);

    x++;
  }

  fclose(fp);

  return x;
}
