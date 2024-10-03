#include <stdio.h>

// Function prototypes
int askHospitalDays(int medicalID, char firstInitial, char lastInitial);
int askSurgeryLevel(int medicalID, char firstInitial, char lastInitial);
float askMedication(int medicalID, char firstInitial, char lastInitial, float medicationsPrice[]);
void calcAndPrintHospitalBill(int medicalID, char firstInitial, char lastInitial, int days, int surgery, int medication, float medicationsPrice[], float surgicalFees, float labFees);

int main()
{
    // Arrays to store surgery and lab prices for different levels
    float surgicalPrices[5] = {1500.00, 3250.00, 6579.99, 12999.99, 25450.00}, surgicalFees;
    float labPrices[5] = {500.00, 1025.00, 2500.99, 5290.00, 9875.99}, labFees;

    int medicalID;
    char lastInitial, firstInitial;
    int days, surgery, medication;

    // Array to store medication prices
    float medicationsPrice[10];

    // Collect patient information
    printf("Enter Patient's Medical ID:\n");
    scanf("%d", &medicalID);

    printf("Enter Patient's last initial:\n");
    scanf(" %c", &lastInitial);

    printf("Enter Patient's first initial:\n");
    scanf(" %c", &firstInitial);

    // Call functions to get necessary information
    days = askHospitalDays(medicalID, lastInitial, firstInitial);
    surgery = askSurgeryLevel(medicalID, lastInitial, firstInitial);
    medication = askMedication(medicalID, lastInitial, firstInitial, medicationsPrice);

    surgicalFees = surgicalPrices[surgery - 1];
    labFees = labPrices[surgery - 1];

    // Calculate and print the hospital bill
    calcAndPrintHospitalBill(medicalID, firstInitial, lastInitial, days, surgery, medication, medicationsPrice, surgicalFees, labFees);

    return 0;
}

// Function to ask for the number of hospital days
int askHospitalDays(int medicalID, char firstInitial, char lastInitial)
{
    int days;

    printf("How many days did patient %c.%c.%d stay in the hospital? \n", firstInitial, lastInitial, medicalID);
    scanf("%d", &days);

    while (days < 1 || days > 21)
    {
        printf("\n Invalid number of days. Try again!\n");
        printf("How many days did patient %c.%c.%d stay in the hospital? \n", firstInitial, lastInitial, medicalID);
        scanf("%d", &days);
    }
    return days;
}

// Function to ask for the surgery level
int askSurgeryLevel(int medicalID, char firstInitial, char lastInitial)
{
    int surgery;

    printf("What level of surgery did patient %c.%c.%d have (1-5):\n", firstInitial, lastInitial, medicalID);
    scanf("%d", &surgery);

    while (surgery < 1 || surgery > 5)
    {
        printf("Invalid choice. Try again!\n");
        printf("What level of surgery did patient %c.%c.%d have (1-5):\n", firstInitial, lastInitial, medicalID);
        scanf("%d", &surgery);
    }

    return surgery;
}

// Function to ask for medication information
float askMedication(int medicalID, char firstInitial, char lastInitial, float medicationsPrice[])
{
    int medication;

    printf("How many medications were used for patient %c.%c.%d? (up to 10):\n", firstInitial, lastInitial, medicalID);
    scanf("%d", &medication);

    while (medication < 1 || medication > 10)
    {
        printf("Invalid choice. Try again!");
        printf("How many medications were used for patient %c.%c.%d? (up to 10):\n", firstInitial, lastInitial, medicalID);
        scanf("%d", &medication);
    }

    for (int medsNum = 0; medsNum < medication; medsNum++)
    {
        printf("Enter price for medication %d: \n", medsNum + 1);
        scanf("%f", &medicationsPrice[medsNum]);
    }

    return medication;
}

// Function to calculate and print the hospital bill
void calcAndPrintHospitalBill(int medicalID, char firstInitial, char lastInitial, int days, int surgery, int medication, float medicationsPrice[], float surgicalFees, float labFees)
{
    float total = 0;

    printf("Billing Statement for Level %d Surgical Procedure.\n", surgery);
    printf("Patient: %c.%c.%d\n", firstInitial, lastInitial, medicalID);
    printf("Daily Charge: $%.2f\n", 350.0 * days);

    for (int medsNum = 0; medsNum < medication; medsNum++)
        total += medicationsPrice[medsNum];

    printf("Medication Charges: $%.2f\n", total);
    printf("Surgical Charges: $%.2f\n", surgicalFees);
    printf("Lab Charges: %.2f\n", labFees);
    printf("Total Due: $%.2f\n", total + surgicalFees + labFees + days * 350.0);
}
