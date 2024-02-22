#include<iostream>
#include<cstring>
using namespace std;
int binarysroccur(int arr[],int key,int size,bool searchfirst){
    int left=0,result=-1;      // -1 for not found 
    int right=size-1;

    while (left<=right){
        int mid=(left+right)/2;
        if(key==arr[mid])
        {
            result=mid;
            if (searchfirst)
            {
                right=mid-1;
            
            }
            else {
                left=mid+1;
        
            }
        }
        else if (key<arr[mid])
        {
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }


return result;
}
int main(){
    int arr[]={1,2,2,2,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=2;
    int firstocc=binarysroccur(arr,key,size,true);
    int lastocc=binarysroccur(arr,key,size,false);
    int count=lastocc-firstocc+1;
    if (firstocc!=-1)
    {
        cout<<"the occurences are : "<<count;
    }
    else{
        cout<<"-----key not found------";
    }
 return 0;

}

    

