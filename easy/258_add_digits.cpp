using namespace std;

#include <iostream>

// time: O(n)
// space: O(1)

int addDigits(int num) {
    int sum = 0;
    int digit = 0;

    while(num>0){
        digit = num%10;
        sum += digit;
        num /= 10;

        if (num==0 && sum>9){
            num=sum;
            sum=0;
        }
    }
    return sum;
}


int main() {
    int n;
    cout << "Enter the vlaue of n: " << endl;
    cin >> n;
    int sum = addDigits(n);
    cout << sum << endl;

}
