// Hussein Alsaidi
// 12-07-23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Owner
{
    char name[30];
    char phoneNumber[20];
    int carTagNumbers[3];

};

struct Car
{
    int tagNumber;
    int year;
    char make[20];
    char model[20];
    char color[20];
    int checkin;    // 0 not checked in    1 checked in

};

float printRegistrationInvoice(struct Owner carOwner, struct Car classicCars[], int numCarTags);
void getCheckInInfo(char name[],char phoneNumber[], int *numCarTags);
void loadCars(struct Car classicCars[]);
void loadOwners(struct Owner owners[]);
int validateCar(int carTag, struct Car classicCars[]);
void printReport(struct Car classicCars[]);

int main()
{

char name[30], phoneNumber[20];
int numCarTags, carTag, found;

struct Car classicCars[20];
struct Owner carOwner;
int totalCars=0;
float totalCollected = 0;

loadCars(classicCars);

char another = 'Y';
int x=0;

while (another == 'y' || another == 'Y')
{
    getCheckInInfo(name,phoneNumber, &numCarTags);

    strcpy(carOwner.name, name);
    strcpy(carOwner.phoneNumber, phoneNumber);
    carOwner.carTagNumbers[0] = 0;
    carOwner.carTagNumbers[1] = 0;
    carOwner.carTagNumbers[2] = 0;

    for (x = 0 ; x < numCarTags; x++)
    {
            printf("Enter car tag for car number #%d:  ", x+1);
            scanf("%d", &carTag);
            found = validateCar(carTag, classicCars);
            while (found == 0)
            {
                printf("\nInvalid car tag!  Please try again! ");
                printf("Enter car tag number:  ");
                scanf("%d", &carTag);
                found = validateCar(carTag, classicCars);
            }
           carOwner.carTagNumbers[x] = carTag;
    }

    totalCollected += printRegistrationInvoice(carOwner, classicCars, numCarTags);
    totalCars += numCarTags;

    printf("\nIs there another registrant Y/N ?  ");
    scanf("\n%c", &another);
    getchar();
}

    printf("\nTotal Collected:    $ %.2f", totalCollected);
    printf("\nTotal Cars checked in:  %d", totalCars);

    printReport(classicCars);


    return 0;
}

void printReport(struct Car classicCars[])
{

    FILE *fp;

    fp = fopen("unregisteredCars.txt", "w");
    if (fp == NULL)
    {
        printf("\nError loading cars.  Program Terminating...");
        exit(0);
    }

    fprintf(fp,"\n\n\tCars Not Checked In\n\n");

    for (int x=0 ; x < 20 ; x++)
    {
        if (classicCars[x].checkin == 0)
        {
            fprintf(fp,"%d:  %d %s %s %s \n", classicCars[x].tagNumber, classicCars[x].year, classicCars[x].color, classicCars[x].make, classicCars[x].model);

        }

    }

    printf("\nUnregistered Car Report Successfully Created!");
    fclose(fp);

}

void getCheckInInfo(char name[],char phoneNumber[], int *numCarTags)
{

    printf("Enter owners full name:  ");
    fgets(name, 30, stdin);
    printf("Enter owners phone number:  ");
    fgets(phoneNumber, 30, stdin);
    printf("How many car tags do you have (1-3)");
    scanf("%d", numCarTags);
    while (*numCarTags < 1 || *numCarTags > 3)
    {
        printf("\nInvalid number of car tags!  Please try again! ");
        printf("How many car tags do you have (1-3)");
        scanf("%d", numCarTags);
    }



};


int validateCar(int carTag, struct Car classicCars[])
{
    int found = 0;

   for (int x=0 ; x < 20 ; x++)
    {
        if (classicCars[x].tagNumber == carTag)
        {
            classicCars[x].checkin = 1;
            found = 1;
            break;
        }

    }

    return found;


}


float printRegistrationInvoice(struct Owner carOwner, struct Car classicCars[], int numCarTags)
{

    float total = 0;

     printf("\n\nOwner:   %s", carOwner.name);
     printf("\n\nPhone:   %s", carOwner.phoneNumber);


    for (int x=0 ; x < 20 ; x++)
    {
        if (classicCars[x].tagNumber == carOwner.carTagNumbers[0]  ||
            classicCars[x].tagNumber == carOwner.carTagNumbers[1]  ||
            classicCars[x].tagNumber == carOwner.carTagNumbers[2])
        {
          printf("\n%d:  %d %s %s %s ", classicCars[x].tagNumber, classicCars[x].year, classicCars[x].color, classicCars[x].make, classicCars[x].model);
        }

    }
    switch(numCarTags)
    {
        case 1:     total = 55.00;  break;
        case 2:     total = 85.00;  break;
        case 3:     total = 100.00;  break;
    }

    printf("\n\nTotal Registration Due:   $ %.2f",total);

 return total;

}


void loadCars(struct Car classicCars[])
{
    FILE *fp;

    fp = fopen("registeredCars.csv", "r");
    if (fp == NULL)
    {
        printf("\nError loading cars.  Program Terminating...");
        exit(0);
    }

    char line[100];
    char *sp;

    int x = 0;
    while (fgets(line, 100, fp) != NULL)
    {
        sp = strtok(line, ",");
        classicCars[x].tagNumber = atoi(sp);
        sp = strtok(NULL, ",");
        classicCars[x].year = atoi(sp);
        sp = strtok(NULL, ",");
        strcpy(classicCars[x].make, sp);
        sp = strtok(NULL, ",");
        strcpy(classicCars[x].model, sp);
        sp = strtok(NULL, ",");
        strcpy(classicCars[x].color, sp);

        classicCars[x].color[ strlen(classicCars[x].color)-1] = '\0';

        classicCars[x].checkin = 0;
        x++;
    }

    fclose(fp);


}
