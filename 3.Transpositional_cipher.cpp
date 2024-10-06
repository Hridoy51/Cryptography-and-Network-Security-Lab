#include<bits/stdc++.h>
using namespace std;

string encp(string text, int width){
    string ans = "";
    for(int i=0;i<width;i++){
        for(int j=i;j<text.size();j+=width){
            ans+=text[j];
        }
    }
    return ans;
}
string decp(string text, int width){
    int idx = 0;
    string ans =  text;
    for(int i=0;i<width;i++){
        for(int j=i;j<text.size();j+=width){
            ans[j] = text[idx++];
        }
    }
    return ans;
}
int main(){
    string plaintext = "DEPARTMENT OF COMPUTER SCIENCE AND ENGINNERING";
    int colsize = 10;
    string ciphertext = encp(plaintext,colsize);
    cout<<ciphertext<<endl;
    string plaintext_after_Decription = decp(ciphertext,colsize);
    cout<<plaintext_after_Decription;
    
    
}