#include <bits/stdc++.h>
using namespace std;
vector<string> split(string s) {
  vector<string> v;
  string temp = "";
  for (auto a : s) {
    if (a == ' ') {
      v.push_back(temp);
      temp = "";
      continue;
    }
    temp += a;
  }
  v.push_back(temp);
  return v;
}
string Encryption(string message, int block_size, map<string, string> &EMP) {
  string temp = "";
  string ciphertext = "";
  for (int i = 0; i < message.size(); i++) {
    if (temp.size() == block_size) {
      ciphertext += EMP[temp];
      temp = "";
    }
    temp += message[i];
  }
  ciphertext += EMP[temp];
  return ciphertext;
}

string Decryption(string ciphertext, int block_size, map<string, string> &DMP) {
  string temp = "";
  string plaintext = "";
  for (int i = 0; i < ciphertext.size(); i++) {
    if (temp.size() == block_size) {
      plaintext += DMP[temp];
      temp = "";
    }
    temp += ciphertext[i];
  }
  plaintext += DMP[temp];
  return plaintext;
}
int main() {
  freopen("exp2.txt", "r", stdin);
  string message ;
  getline(cin,message);
  int block_size = 3;
  map<string, string> EMP;
  map<string, string> DMP;
  
  string s;
  while (getline(cin, s)) {
    vector<string> v;
    v = split(s);
    EMP[v[0]] = v[1];
    DMP[v[1]] = v[0];
  }

  cout << "MESSAGE : " << message << endl;
  string ciphertext = Encryption(message, block_size, EMP);
  string plaintext = Decryption(ciphertext, block_size, DMP);
  cout << "CIPHERTEXT : " << ciphertext << endl
       << "PLAINTEXT/MESSAGE : " << plaintext;
}