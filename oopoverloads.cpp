#include<iostream>
using namespace std;
#include <string.h>

class concatenation{
    public:
    char s1[25], s2[25];
    concatenation(char s1[],char s2[]){
        strcpy(this->s1,s1);
        strcpy(this->s2,s2);
    }

    void operator +(){
        cout<<"The resulted concatenated string : "<<strcat(s1,s2);
    }

};
int main(){
    concatenation addtwostrings("Hello","World");
    +addtwostrings;


}