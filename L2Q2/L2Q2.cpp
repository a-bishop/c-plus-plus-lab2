//  L2Q2
//
//  author: Andrew Bishop

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// num: 013031997

int main() {
    
    // get the input
    int initialNum;
    cout << "Enter the first 9 digits of an ISBN as integer: ";
    cin >> initialNum;
    
    // calculate number of digits in input
    int len = static_cast<int>(to_string(initialNum).length());
    
    int checksumOperand = 1;
    int divModOperand = 100000000;
    
    string zeros;
    
    // account for leading zeros in initialNum
    if (len < 9) {
        int numZeros = 9 - len;
        for (int i=0; i < numZeros; i++) {
            zeros += '0';
        }
        checksumOperand += numZeros;
        divModOperand /= (numZeros * 10);
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
    
    if (checksum == 10) {
        cout << "The ISBN-10 number is " << zeros << initialNum << "X" << endl;
    } else {
        cout << "The ISBN-10 number is " << zeros << initialNum << checksum << endl;
    }
    
    return 0;
}
