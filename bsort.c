#include<stdio.h>
#include<stdbool.h>
int bubble(int arr[],int n);
int insort(int arr[],int n);
int main(){
int choice;
int barray[100],m,inarr[100];
 printf("1 bubble sort ");
 printf("2 insertion sort");
 scanf("%d",&choice);

 switch (choice)
 {
 case 1:
    printf("Enter size array ");
    scanf("%d",&m);
    printf("Enter the array : ");
    for (int i=0;i<m;i++)
    {
        scanf("%d",&barray[i]);
    }
   
    printf("THe sorted array is :  ");
    bubble(barray,m);                        // callin 
  
    break;
case 2 :
    printf("Enter size array ");
    scanf("%d",&m);
    printf("Enter the array : ");
    for (int i=0;i<m;i++)
    {
        scanf("%d",&inarr[i]);
    }
   
    printf("THe sorted array is :  ");
    insort(inarr,m);                        // callin 

 default:
 printf("choose correct option ...");
    break;
 }
 return 0;

}

int bubble(int arr[],int n){

    bool swapped;
    int temp;
    for (int i = 0; i < n-1; i++)
    {    swapped=false;
        for (int j = 0; j <n-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                temp=arr[j];                              // i is number of passes and j is the swapped times 
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if(swapped==false){
        break;}
        
    }
    for (int i=0;i<n;i++){
        printf("%d  ",arr[i]);
        
    }
    return 0;
    
}

int insort(int arr[],int n){
    int temp;
    for (int i = 1; i < n; i++)
    {  temp=arr[i];
       int j=i-1;
       while (j>=0 && temp<arr[j])
       {
        arr[j+1]=arr[j];
        j--;
       }
       arr[j+1]=temp;
       
    }
    for (int i=0;i<n;i++){
        printf("%d  ",arr[i]);
        
    }
    return 0;
}