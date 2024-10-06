#include<bits/stdc++.h>
using namespace std;
string encrypyion(string s,string k){
    int idx = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]==' ')continue;
        s[i] =(((s[i]-'A')+(k[idx++]-'A')+1)%26 + 'A');
    }
    return s;
}
string decryption(string s, string k){
    int idx = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]==' ')continue;
        s[i] =((s[i]-'A')-(k[idx++]-'A')+25)%26+'A';
    }
    return s;
}
int main(){
    freopen("key.txt","r",stdin);
    string plaintext = "COMPUTER SCIENCE";
    string key;
    cin>>key;
    string cipher = encrypyion(plaintext,key);
    cout<<cipher<<endl;
    string plain = decryption(cipher,key);
    cout<<plain;


}