// Modular Exponentiation 

#include <bits/stdc++.h>
using namespace std;

int pow(int b, int e, int d) {
    if (d == 1) return 0;

    long long ans = 1;
    long long base = b;

    base = base % d;
    if (base < 0) base += d;

    while (e > 0) {
        if (e & 1) {
            ans = (ans * base) % d;
            e--;
        } else {
            e /= 2;
            base = (base * base) % d;
        }
    }

    return (int)(ans % d);
}