#include<bits/stdc++.h>
using namespace std;

int p = 47, q=71, e=79, d;
int n = p*q;
int phi = (p-1)*(q-1);

int InverseMod(int ex, int ph) {
    int t = 0, newT = 1;
    int r = ph, newR = ex;

    while(newR != 0) {
        int cotient = r/newR;
        t = t - cotient*newT;
        swap(t, newT);
        r = r - cotient*newR;
        swap(r, newR);
    }
    if(r > 1) return 0;
    if(t<0) t = ph+t;
    return t;
}
int encryption(int message) {
    int cipher = 1;
    for(int i = 0; i < e; i++) {
        cipher = (cipher*message)%n;
    }
    return cipher;
}

int decryption(int message) {
    
    int plain = 1;
    for(int i = 0; i < d; i++) {
        plain = (plain*message)%n;
    }
    return plain;
}
int main(){
    freopen("input_rsa.txt","r",stdin);
    freopen("ouput_rsa.txt","w",stdout);
    string message;
    cin >> message;
    cout<<message;
    d = InverseMod(e,phi);
    cout<<e<<" "<<d<<endl;
    vector<int>text;
    vector<int>cipher;
    string temp = "";
    int block_size = to_string(n).size()-1;
    for(auto a:message){
        temp+=a;
        if(temp.size()==block_size){
            text.push_back(stoi(temp));
            temp = "";
        } 

    }
    if(temp.size()>0) text.push_back(stoi(temp));
    //encryption
    cout<<"Chiphertext = ";
    for(auto a:text){
        int ci = encryption(a);
        cipher.push_back(ci);
        cout<<ci;
    }
    cout<<endl;

    //decryption

    cout<<"plaintext = ";
    for(auto a:cipher){
        int pi = decryption(a);
        cout<<pi;
    }
    cout<<endl;
}