#include <iostream>
using namespace std;

int mySqrt(int x){
	// newton raphson method for finding square root of a number
	// first we need to create a function
	// x = sqrt(a)
	// x^2 = a
	// x^2 - a = 0
	// thus f(x) = x^2 - a
	// f'(x) = 2x
	// newton raphson method:
	// x(n+1) = x(n) - f(x)/f'(x)
	// x(n+1) = x(n) - (x^2-a)/2x
	// x(n+1) = 0.5(x(n) - a/x(n))

	long long r = x; //taking long long for getting only the integer value i.e avoiding the decimal value
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
}


int main(){
	int x;
	cin>>x;
	cout<<mySqrt(x)<<endl;
}
