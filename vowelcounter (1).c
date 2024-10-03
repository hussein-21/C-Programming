// Hussein Alsaidi
// 11-07-23
// Vowel Counter Program


#include <stdio.h>
#include <string.h>
#define maxLength 200

void vowelCount(char str[], int arr[], int *count) 
{
  int i = 0;
  while(str[i]!='\0') 
  {
    if(str[i]=='A' || str[i]=='a') 
    {
      *count = *count+1;
      arr[0]++;
    }
    else if(str[i]=='E' || str[i]=='e')
    {
      *count = *count+1;
      arr[1]++;
    }
    else if(str[i]=='I' || str[i]=='i') 
    {
      *count = *count+1;
      arr[2]++;
    }
    else if(str[i]=='O' || str[i]=='o') 
    {
      *count = *count+1;
      arr[3]++;
    }
    else if(str[i]=='U' || str[i]=='u')
    {
      *count = *count+1;
      arr[4]++;
    }
  i++;
  }
}
  
int main(void) {
  
  printf("Enter text:\n");
  
  char str[maxLength]; 
  scanf("%[^\n]%*c", str);
  
  int arr[] = {0, 0, 0, 0, 0}; 
  int count = 0; 
  vowelCount(str, arr, &count);
  
  printf("Total A's: %d\n", arr[0]);
  printf(" E's: %d\n", arr[1]);
  printf(" I's: %d\n", arr[2]);
  printf(" O's: %d\n", arr[3]);
  printf(" U's: %d\n", arr[4]);
  
  printf("\nTotal vowels: %d\n", count);
  return 0;
}