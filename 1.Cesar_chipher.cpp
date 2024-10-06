#include<bits/stdc++.h>
using namespace std;
string Encryption(string message){
    for(int i=0;i<message.size();i++){
        if(message[i]==' ')continue;
        char temp = (message[i]+3);
        if(!isalpha(temp)) temp-=26;
        message[i] = temp;
    }
    return message;

}
string Decryption(string ciphertext){
     for(int i=0;i<ciphertext.size();i++){
        if(ciphertext[i]==' ')continue;
        char temp = (ciphertext[i]-3);
        if(!isalpha(temp)) temp+=26;
        ciphertext[i] = temp;
    }
    return ciphertext;

}
int main(){
    freopen("inp_cesar.txt","r",stdin);
    string message;
    getline(cin,message);
    string ciphertext = Encryption(message);
    cout<<"Ciphertext : "<<ciphertext<<endl;
    string plaintext = Decryption(ciphertext);
    cout<<"Message : "<<plaintext;


}