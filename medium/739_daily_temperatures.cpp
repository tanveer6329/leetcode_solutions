
#include <bits/stdc++.h> // for reverse function
#include <vector>
#include <stack>
using namespace std;

// need more improvement
// spcace complexity is high
vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st; // for saving the index in a stack
        vector<int> res;
        int n = T.size();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && T[st.top()] <= T[i]){
                st.pop();
            }
            if(st.size() == 0) res.push_back(0);
            else res.push_back(st.top() - i);
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;
}


int main () {
    vector<int> temp {30,60,90};
    vector<int> res;
    res = dailyTemperatures(temp);

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<" ";
    }
    return 0;
}