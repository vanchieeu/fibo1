#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int convertToNum(char a) {
    return (int)(a - '0');
}

char convertToChar(int a) {
    return (char)(a+48);
}

void compareTwoStrings(string &a, string &b) {
    int la = a.length();
    int lb = b.length();

    if (la >= lb)
        b.insert(0, la-lb, '0');
    else
        a.insert(0, lb-la, '0');  
}

string sum(string a, string b) {
    string s = "";

    compareTwoStrings(a, b);

    int l = a.length() - 1;
    int res = 0;
    for (int i = l; i >= 0; i--) {
        res += convertToNum(a[i]) + convertToNum(b[i]);

        s.insert(0, 1, convertToChar(res%10));

        res /= 10;
    }
    if (res != 0)
        s.insert(0, 1, convertToChar(res));

    return s;
}

int main() {
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    string fibo[10001];
    fibo[0] = "1";
    fibo[1] = "1";
    
    for (int i = 2; i <= 10000; i++) {
        fibo[i] = sum(fibo[i-1], fibo[i-2]);
    }

    for (int i = 0; i < n; i++)
        cout << fibo[a[i]] << endl;

    return 0;
}