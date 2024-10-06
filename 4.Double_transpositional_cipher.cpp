#include<bits/stdc++.h>
using namespace std;
string encryption(string plaintext,int colsize){
    string ciphertext = "";
    int rows = plaintext.size()/colsize;
    if(plaintext.size()%colsize)rows++;
    vector<string>row;
    string temp = "";
    for(int i=0;i<plaintext.size();i++){
        temp+=plaintext[i];
        if(temp.size()==colsize){
            row.push_back(temp);
            temp.clear();
        }
    }
    row.push_back(temp);
    for(int i=0;i<colsize;i++){
        for(int j=0;j<rows;j++){
            if(i<row[j].size()){
                
                ciphertext+=row[j][i];
            }
        }
        
    }
    return ciphertext;
}
string decription(string ciphertext,int colsize){
      vector<string>row;
      int left = ciphertext.size()%colsize;
      int rowsize = ciphertext.size()/colsize;
      string temp = "";
      for(int i=0;i<ciphertext.size();i++){
        temp+=ciphertext[i];
        if(temp.size()==rowsize){
            if(left){
                i++;
                temp+=ciphertext[i];
                left--;
            }
            row.push_back(temp);
            temp.clear();
        }
      }
      row.push_back(temp);
      string plaintext="";
      for(int i=0;i<rowsize+1;i++){
        for(int j=0;j<colsize;j++){
            if(i<row[j].size())
                plaintext+=row[j][i];
        }
      }
      return plaintext;

}
int main(){
    string plaintext = "DEPARTMENTOFCOMPUTERSCIENCEANDENGINNERING";
    int colsize = 10;
    string ciphertext_first_step = encryption(plaintext,colsize);
    string ciphertext = encryption(ciphertext_first_step,colsize);
    cout<<ciphertext<<endl;
    string plaintext_first_step = decription(ciphertext,colsize);
    string plaintext_atfer_decription = decription(plaintext_first_step,colsize);
    cout<<plaintext_atfer_decription;
    
    
}