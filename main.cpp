#include <string>
#include<iostream>
#include<vector>
#include <algorithm> 
#include <math.h>
using namespace std;

int strtoi(string x) {
  int num = 0;
  for (int i = 0; i < x.length(); i++) {
    num = num * 10 + (int(x[i]) - 48);
  }
  return num;
}

string conv(int n, int m)
{
    string num = "";
    int rest;
    if(n == 0){
        num +='0';
    }
    while (n != 0) {
        rest = n % m;
        if (rest > 9)
            num += rest + 55;
        else
            num += rest + 48;
        n /= m;
    }
    
    reverse(num.begin(), num.end());
    return num;
}

int main(){
    vector<string> vec;
    string input_string = "0", hex_num_str, final_hex;
    int dec_num;

    while(input_string.compare("-1") != 0){
        cin >> input_string;
        dec_num = 0;

        if(input_string[0] == '0' && input_string[1] == 'x'){
            for(int i = input_string.size()-1; i > 1; i--){   
                if(input_string.substr(i,1) == "A"){
                    dec_num += (pow(16, (((input_string.size()-1)-i)))) * 10;
                }else if(input_string.substr(i,1) == "B"){
                    dec_num += (pow(16, (((input_string.size()-1)-i)))) * 11;
                }else if(input_string.substr(i,1)=="C"){
                    dec_num += (pow(16, (((input_string.size()-1)-i)))) * 12;
                }else if(input_string.substr(i,1)=="D"){
                    dec_num += (pow(16, (((input_string.size()-1)-i)))) * 13;
                }else if(input_string.substr(i,1)=="E"){
                    dec_num += (pow(16, (((input_string.size()-1)-i)))) * 14;
                }else if(input_string.substr(i,1)=="F"){
                    dec_num += (pow(16, (((input_string.size()-1)-i)))) * 15;
                }else{
                    dec_num += pow(16, (((input_string.size()-1)-i))) * strtoi(input_string.substr(i,1));
                }         
            }
            
            vec.push_back(conv(dec_num, 10));
        }else{
            dec_num = strtoi(input_string);
            hex_num_str = conv(dec_num, 16);
            final_hex = "0x";
            for(int i=0; i < hex_num_str.length(); i++){
                final_hex.push_back(hex_num_str[i]);
            }
            
            vec.push_back(final_hex);
        }
    }
    for(int i = 0; i < vec.size()-1; i++){
        
        cout << vec[i] << "\n";
    }

}
