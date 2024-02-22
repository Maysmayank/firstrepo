#include <iostream>
#include <string>  // Include the header for string
using namespace std;
#include<bits/stdc++.h>
string rev(string str){
int i=0;
int j=str.size()-1;
while(i<=j){
    swap(str[i],str[j]);
    i++;
    j--;
}
return str;
}
char tolow(char ch){
    if(ch>='a' && ch<='z' || ch>='0' && ch<='9'){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }
    
}
bool palindrome(char arr[]){
    int i=0;
    int j=strlen(arr);
    while (i<j)
    {
    
    if(arr[i]!=arr[j]) {
        return 0;
    }
    else{
        i++;
        j--;
        }
    }
return 1;
}
int main() {
    char str[]="Madam";
    char temp[]="";
    int len=strlen(str);
    for(int i=0;i<len;i++){
        temp[i]+=tolow(str[i]);
        }
    cout<<temp;
    if(palindrome(temp)){
        cout<<"palindrome ";
    }
    else
    cout<<"not a palindrome";
    
    
    }
    
     