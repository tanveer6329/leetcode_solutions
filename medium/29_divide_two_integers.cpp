#include <iostream>
using namespace std;
/*
this algorithm uses bit wise manupulation to divide two number without using division sign

The key observation is that the quotient of a division is just the number of times that we can subtract
the divisor from the dividend without making it negative.

Suppose dividend = 15 and divisor = 3, 15 - 3 > 0. We now try to subtract more by shifting 3 to the 
left by 1 bit (6). Since 15 - 6 > 0, shift 6 again to 12. Now 15 - 12 > 0, shift 12 again to 24, which
is larger than 15. So we can at most subtract 12 from 15. Since 12 is obtained by shifting 3 to 
left twice, it is 1 << 2 = 4 times of 3. We add 4 to an answer variable (initialized to be 0).
The above process is like 15 = 3 * 4 + 3. We now get part of the quotient (4), with a remaining dividend 3.

Then we repeat the above process by subtracting divisor = 3 from the remaining dividend = 3 and obtain 0.
We are done. In this case, no shift happens. We simply add 1 << 0 = 1 to the answer variable.

This is the full algorithm to perform division using bit manipulations. The sign also needs to be taken 
into consideration. And we still need to handle one overflow case: dividend = INT_MIN and divisor = -1.

*/
int divide(int dividend, int divisor) {
	if (dividend == INT_MIN && divisor == -1) { // overflow check
    	return INT_MAX;
    }
    long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
    int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1; // '^': XOR operator
    while (dvd >= dvs) {
    	long temp = dvs, m = 1;
        while (temp << 1 <= dvd) {
        	temp <<= 1;
            m <<= 1;
        }
        dvd -= temp;
        ans += m;
    }
    return sign * ans;
}

int main(){

	return 0;
}
