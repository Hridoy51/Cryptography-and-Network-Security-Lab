#include<bits/stdc++.h>
using namespace std;

int p = 353, a = 3;

int modExp(int base, int ex, int mod) {
    int ans = 1;
    for(int i = 0; i < ex; i++) {
        ans = (ans*base) % mod;
    }
    return ans;
}
int main() {
    srand(time(0));
    // int Xa = rand()%(p-1)+1;
    // int Xb = rand()%(p-1)+1;
    int Xa = 97;
    int Xb = 233;

    int Sa = modExp(a, Xa, p);
    int Sb = modExp(a, Xb, p);

    int C1 = modExp(Sb, Xa, p);
    int C2 = modExp(Sa, Xb, p);
    
    cout<< C1 <<" "<<C2;
}