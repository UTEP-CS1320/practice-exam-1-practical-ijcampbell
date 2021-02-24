/*
*   PRACTICE EXAM #1: PRACTICAL PART
*   Filename: main.c
*   This file allows a user to run any of the 3 problems for Practical Exam #1
*   Last modified by: Angel F. Garcia (2/19/2021)
*/
#include <stdio.h>

int main(void) {
  long x = 10;

  printf("%ld", x);

  int opt;
  printf("Enter 1 to test P1, 2 to test P2, 3 to test P3: ");
  scanf("%d", &opt);
  
  if(opt == 1) {
    /***************************
     *  Problem 1: Last Digits
     ***************************/
    int x, y;
    scanf("%d %d", &x, &y);

    // Taking the mod 100 of a decimal number yields the last two digits.
    int x_digit = x % 100;
    int y_digit = y % 100;

    if (x_digit == y_digit) {
      printf("TRUE\n");
    }
    else {
      printf("FALSE\n");
    }
    /* Problem 1 End */
  }

  else if(opt == 2) {
    /***************************
     *  Problem 2: Lotto
     ***************************/
    char winner[5] = "7239";
    char ticket[5];
    scanf("%s", ticket);
    
    int numMatches = 0;
    for (int n=0; n<4; n+=1) { // Compare the nth numbers.
      if (ticket[n] == winner[n]) { // A match!
        numMatches += 1;
      }
    }
    switch (numMatches) {
      case 4: // 4 matches.
        printf("1st Prize!\n");
        break;
      case 3: // 3 matches.
        printf("2nd Prize!\n");
        break;
      case 2: // 2 matches.
        printf("3rd Prize!\n");
        break;
      default: // 1 or 0 matches.
        printf("No Prize! Better luck next time!\n");
        break;
    }
    /* Problem 2 End */
  }
  
  else if(opt == 3) {
    /***************************
     *  Problem 3: Hex2Dec
     ***************************/
    char hex_in[5];
    scanf("%s", hex_in);

    int decimalValue, dec_out = 0, validHex = 1;
    // The integer validHex is a test variable, rather than using the <bool.h> library.
    for (int d=0; d<4; d+=1) {
      // For the following if-else branches, the index 3-d is used to start from the last element of hex_in.
  
      if ((hex_in[3-d] >= 48) && (hex_in[3-d] <= 57)) {
        // Using ASCII code to cehck for 0-9.
        decimalValue = hex_in[3-d] - 48;
        // 0-9~48-57, so subtracting 48 puts 0-9~0-9.
      }
      else if ((hex_in[3-d] >= 65) && (hex_in[3-d] <= 70)) {
        // Using ASCII code to chec for A-F.
        decimalValue = hex_in[3-d] - 55;
        // A-F~65-70, so subtracting 55 puts A-F~10-15.
      }
      else if ((hex_in[3-d] >= 97) && (hex_in[3-d] <= 102)) {
        // Using ASCII code to check for a-f.
        decimalValue = hex_in[3-d] - 87;
        // a-f~97-102, so substracting 87 puts a-f~10-15.
      }
      else { // Invalid hex character.
        validHex = 0; // Do not attempt to calculate dec_out.
        printf("ERROR\n");
        break;
      }
  
      for (int p=0; p<d; p+=1) { // Essentially, implementing the pow(x,y) function, from math library.
        decimalValue *= 16; // End result is decimalValue * 16^d.
      }
      dec_out += decimalValue;
    }
    if (validHex == 1) { // If an error has not occured, do this.
      printf("%d\n", dec_out);
    }
    /* Problem 3 End */
  }
  
  return(0);
}