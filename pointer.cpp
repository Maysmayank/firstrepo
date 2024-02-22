#include<iostream>
using namespace std;
#define Elements 'c', \
                 'h', \
                'helle' \


int change(int *p){
    int a=10;
    p=&a;
    *p =(*p) * (*p);
}

void swap(char*x,char *y){
    char *t= x;
    x=y;
    y=t;
    cout<<*t;
}
int main(){
char arr[]={Elements};   
for (int i = 0; i < 3; i++)
{
    cout<<arr[i]<<endl;
}
   
   /* char ch[]="xyz";            // important 
    char *c=ch;
    cout<<*c<<endl;
    cout<<c<<endl; differtent values


float arr[5]={10.2,23.3,45.2,23.4,33.2};
float *p1=&arr[0];
float *p2=p1+3;
cout<<p2-p1; // important think output;

int a=10;
change(&a);
cout<<a;              //it doesnt print 100; different adreses in scopes;


char *x="ninjasquiz";
char *y="codingninjas";
char *t;
swap(x,y); 
int a=10;
int *p=&a;
(*p)++;
cout<<a;

*/

}
    
