#include<iostream>
using namespace std;
class second;
class first{
    int num=45;

    friend int findgreater(first,second);

};


 
class second{
    int num=100;
    friend int findgreater(first,second);

};

int findgreater(first f,second s){
    if (f.num>s.num)
    {
        cout<<"First number is greater than second"<<endl;
    }
    else{
        cout<<"Second number is greater than first number"<<endl;
    }
    

}

int main(){
    first obj1;
    second obj2;
    findgreater(obj1,obj2);

}