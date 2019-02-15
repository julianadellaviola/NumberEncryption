//purpose: the functions below are called by a tester to encrypt an integer > 99999
//encryption: each digit increases by 4 (only the ones place (digit + 4) is used), and shifted left
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//purpose: validates the number inputted, and prompts user for another input until valid
void input(int *num)
{
    do {
    printf("Please enter an integer greater than 99999: ");
    scanf("%d", num);
    
    if(*num <= 99999) {
        printf("Incorrect input.\n");
    }
    
    } while(*num <= 99999);
}

//purpose: isolates ones place digit
int findDigits(int fullNum) 
{
    int digit = 0; 
    digit = fullNum % 10; 
    return digit;
}

//purpose: adds 4 to each digit of inputted number
int add4(int num)
{
    int addedFour = 0, digit = 0, power10 = 0;

    do {
        digit = findDigits(num);
        num /= 10; //decreases inputted number by a factor of 10
        
        if(digit >= 6) { 
            digit -= 6; //if adding 4 to digit surpasses 9, subtract 10
        } else {
            digit += 4; //if adding 4 does not surpass 9
        }
        
        digit *= pow(10, power10); //changes digit to correct power of 10
        power10++; 
        addedFour += digit; //becomes the value of adding 4 to each digit
        
        
    } while (num > 0);
    
    return addedFour;
}

//purpose: to find the highest power of 10 the addedFour number reaches
int powerOf10(int addedFour)
{
    int power10 = 0;
    
    do {
        addedFour /= 10;
        power10++;
    } while(addedFour > 10);
    
    return power10;
}

//purpose: shifts each digit of the addedFour value 1 place left
int shift(int addedFour)
{
    int power10 = powerOf10(addedFour), digit = 0, shifted = 0, i = 1;
  
    do {
        digit = findDigits(addedFour); 
        addedFour /= 10;
        
        if(i <= power10) {
			digit *= pow(10, i);
			shifted += digit; 
			i++;
        }

    } while(addedFour > 0);
    
    shifted += digit; //adds the digit originally with the highest power of 10 last  
    
    return shifted;
}

//purpose: to display the number entered, label the number entered as the original, and the encrypted number
void printOutput(int encryptNum, int originalNum)
{
    printf("The number entered is %d\n", originalNum);
    printf("Original number: %d\n", originalNum);
    printf("Encrypted number: %d\n", encryptNum);
}


