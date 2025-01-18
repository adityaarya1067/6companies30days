#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve_test_case(string x,string s){
    if (x.find(s) != string::npos) {
        return 0;
    }
    string current=x;
    const int MAX_OPERATIONS = 5;
    for (int i = 1; i <= MAX_OPERATIONS; i++) {
        current +=  current;
        if (current.find(s) != string::npos) {
            return i;
        }
        if (current.length() >= 2*s.length() && i >= 2) {
            int middle = current.length() / 2;
            string first_half = current.substr(0, middle);
            string second_half = current.substr(middle);
            if (first_half == second_half && first_half.find(s) == string::npos) {
                return -1;
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin>>n>>m;
        string x,s;
        cin>>x>>s;  
        cout<<solve_test_case(x, s)<<endl;
    }
    return 0;
}