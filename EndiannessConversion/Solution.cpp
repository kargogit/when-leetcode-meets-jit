#include <cstdint>
#include <iostream>
using namespace std;

uint32_t reverseBits(uint32_t n){
    uint32_t tempNum = n;
    uint32_t retNum = 0;
    for ( int i = 0; i < 32; i++ ) {
        retNum = (retNum << 1);
        if ( (tempNum & 1) == 1 ) {
             retNum += 1;
        }
        tempNum = tempNum >> 1;
    }
    return retNum;
}


int main ( void ) {
    uint32_t input;
    if ( cin >> input ) {
        cout << reverseBits( input );
    }
    return 0;
}
