//  L2Q2
//
//  author: Andrew Bishop

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// num: 013031997

int main() {
    
    // set width to desired length of digits, to avoid coercion to hex if leading zeros.
    cin >> setw(9);
    
    // get the input
    int initialNum;
    cout << "Enter the first 9 digits of an ISBN as integer: ";
    cin >> initialNum;
    
    // calculate number of digits in input
    int len = static_cast<int>(to_string(initialNum).length());
    
    // default parameters for calculating checksum (assume 9 digits)
    int checksumOperand = 1;
    int divModOperand = 100000000;
    
    // alter parameters of calculations based on number of digits in initialNum
    if (len < 9) {
        switch(len) {
            case 8:
                checksumOperand = 2;
                divModOperand = 10000000;
                break;
            case 7:
                checksumOperand = 3;
                divModOperand = 1000000;
                break;
            case 6:
                checksumOperand = 4;
                divModOperand = 100000;
                break;
            case 5:
                checksumOperand = 5;
                divModOperand = 10000;
                break;
            case 4:
                checksumOperand = 6;
                divModOperand = 1000;
                break;
            case 3:
                checksumOperand = 7;
                divModOperand = 100;
                break;
            case 2:
                checksumOperand = 8;
                divModOperand = 10;
                break;
            case 1:
                checksumOperand = 9;
                divModOperand = 1;
                break;
        }
    }
    
    int runningNum = initialNum;
    int checksum = 0;
    int checkFirst;

    while (runningNum > 0) {
        // pull out first digit
        checkFirst = (runningNum / divModOperand);

        // add calc to checksum
        checksum += (checkFirst * checksumOperand);
        
        // pop leading digit from runningNum
        runningNum %= divModOperand;
        
        // remove a trailing zero from divModOperand
        divModOperand /= 10;
        
        // increment checksumOperand
        checksumOperand++;
    }
    
    checksum %= 11;
    
    // account for leading zeros in initialNum
    int numZeros = 9 - len;
    string zeros;
    for (int i=0; i < numZeros; i++) {
        zeros += '0';
    }
    
    if (checksum == 10) {
        cout << "The ISBN-10 number is " << zeros << initialNum << "X" << endl;
    } else {
        cout << "The ISBN-10 number is " << zeros << initialNum << checksum << endl;
    }
    
    return 0;
}
