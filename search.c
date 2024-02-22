#include<stdio.h>
int linear(int arr[],int data);
int main(){
    int arr1[]={23,5,4,0,2,3,6,67};
    int num;
    printf("ENter the number  : ");
    scanf("%d",&num);
    linear(arr1,num);
}
int linear(int arr[],int data){
 int found;
 int n=8;
 for(int i=0;i<n;i++){
    if (arr[i]==data)
    {
    printf("Found %d",i);
    }
    
 }
 return 0;

}