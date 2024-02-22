#include<iostream>
using namespace std;
#include<string>
#include <bits/stdc++.h>
#include<ctype.h>

/*int dectobin(int n){
    int i=0;
    int arr[11];
    while(n!=0){
        arr[i]=n%2;
        i++;
        n=n/2;
        }
    cout<<"Binary number is "<<endl;
    for(int k=i-1;k>=0;k--){
        cout<<arr[k];
    }
    
}
class Fraction{
    public:
    int num;
    int deno;

    Fraction(int num,int deno){
        this->num=num;
        this->deno=deno;

    }
    void add(Fraction F){
        int temp=this->deno;
        int tempF=F.deno;
        this->deno=this->deno * F.deno;
        int res1=this->deno/temp;
        int res2=this->deno/tempF;
        this->num=(this->num*res1)+(res2*F.num);             
    }
    void print(){
        cout<<this->num<<"/"<<this->deno;
    }
};
int main(){
    
     Fraction F1(1,4);
     Fraction F2(3,5);
     F1.add(F2);
     F1.print();         
}*/
#include<string>
int getlength(int x){
    int cnt=0;
    while (x!=0)
    {
        x=x/10;
   cnt++; }
    cout<<cnt;
}
int main(){
int x=122163;
getlength(x);
}