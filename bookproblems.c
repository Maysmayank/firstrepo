
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
              // -------------books questions----------------------------               
float area(int x,int y,int z){
    float s=(x+y+z)/2; // to find s            #impliciting here ( conversion )
    float area =sqrt(s*(s-x)*(s-y)*(s-z));
    printf("perimeter is %.2f\n",s);
    printf("area is : %.2f",area);
    }

int distance(int a,int b,int c,int d){
    int dis;
    int first=b-a;
    int sec=d-c;                                                                                                   
    dis=sqrt(pow(first,2)+pow(sec,2));
    printf("The distance is : %d ",dis);
}

int roots(int a ,int b, int c){
   int det=b*b-4*a*c;
    printf("discriminant is : %d\n ",det);
    double r1,r2;
    if (det>0)
    {
        r1=(-b+sqrt(det))/(2*a);
        r2=(-b-sqrt(det))/(2*a);
        printf("Roots are real and distinct. \n");
        printf("root 1  :  %.2lf\n",r1);
        printf("root 2  :  %.2lf\n",r2);
    }
    else if (det=0){
        r1=r2=(-b)/(2*a);
        printf("Roots are equal.\n ");
        printf("root 1  :  %.2lf\n",r1);
        printf("root 2  :  %.2lf\n",r2);
    }
    else{
        double real=(-b)/(2*a);
        double img= sqrt(-det)/2*a;
        printf("roots are complex and distinct.\n");
        printf("%.2lf + i %.2lf\n",real,img);
        printf("%.2lf - i %.2lf\n",real,img);

    }
return 0;

}

int revdigit(int n){
    int rev=0;
    while (n!=0)
    {
        int last=n%10;
        rev=(rev*10)+last;
        n/=10;
    }
    printf("the digit is : %d",rev);
    
} 

int decbin(int n){
    int i=0,rev=0;
    while(n!=0){

        int bit=(n&1);

        //reverse the bits
        rev=(bit*pow(10,i))+rev;
        n>>=1;
        i++;
    }
    printf("The binary number is : %d",rev);
}
int bindec(int num){
    int digit;
    int ans=0,i=0;
    while(num!=0){
        digit=num%10;
        if (digit==1) 
        {  ans=ans+pow(2,i);  }
        i++;
        num/=10;
    }
    printf("The decimal number is : %d",ans);
}

int compliment(int x){
    int n=x;
    int mask=0;
    if (n==0)    { return 1; }   //edge case    
    while(n!=0){
        mask=(mask<<1)|1; 
        n=n>>1;
    }
    int res=(~n)&mask;
    return res;
}

int sumdigit(int n){
   int sum=0;
   for (int i = 0; n!=0 ; i++)
   {
       int x=n%10;
       sum=sum+x;
       n=n/10;

   }
   printf("sum is : %d",sum);
   
}


int main()
{                     // -------------------------------main----------------------------------------------
    int opt;
    char choice;
    int a,b,c,d;
    float amt,interest,value;
    int year,period,num,sum,num2;
    printf("1. find area of triangle ..\n");
    printf("2. distance between two points \n");
    printf("3. calculate the interest rate upto period \n");
    printf("4. Trempertaure conversions\n");
    printf("5. sum of n natural numbers\n");
    printf("6. find the roots of quadratic equation.\n ");
    printf("7. reverse a digit \n");
    printf("8. decimal to binary.\n");
    printf("9. compliment using bitwsie op.\n");
    printf("10. ");
    printf("Enter the option : ");
    scanf("%d",&opt);
    switch (opt)
    {
    case 1:
        printf("enter value first : ");
        scanf("%d",&a);
        printf("enter value swconf  : ");
        scanf("%d",&b);
        printf("enter value third  : ");
        scanf("%d",&c);
        area(a,b,c);
        break;
    case 2:
        printf(" Enter x1 and x2 ");
        scanf("%d%d",&a,&b);
        printf("enter y1 and y2");
        scanf("%d%d",&c,&d);
        distance(a,b,c,d);
        break;
    case 3:
    do{
        printf("enter amount, interst rate , period(years)\n ");
        scanf("%f %f %d",&amt,&interest,&period);
        year=1;       
        printf("year\tamount(Rs)\n");
        for (int i=1;year<=period;i++)
        {
            value=amt+(amt*interest);
            printf(" %d yrs\tRs. %.1f\n",year,amt);
            amt=value;
            year++;
  
        }
        printf("\ndo you want to continue : ");
        scanf(" %c",&choice); 
    }while(choice=='y');

    break;

    case 4:
    printf("1. fahrenheit to celsiues\n");
    printf("2. celsius to fahrenheit\n");
    printf("Enter the option :  ");
    scanf("%d",&opt);
    float fahren,cels;
        switch (opt)
            {
                case 1:
                    do{
                    printf("Enter the fahrenheit temperature : ");
                    scanf(" %.2f",&fahren);
                    cels=(fahren-32)/1.8;
                    printf(" the temperature in celsius is %.2f degrees \n",cels);

                    getchar();// why we used getchare here ?(scanf wasn't taking input so we used this) 
                    /* The issue with the scanf function not working as expected is due to the newline character ('\n') 
                    in the input buffer after reading the option opt. When you use scanf to read a numeric value using %d, 
                    it reads the number but leaves the newline character in the input buffer. 
                    and to read a character using %c, it immediately consumes the newline character present in the buffer
                    from the previous input, resulting in skipping the input prompt.
                    To fix this, you can modify the scanf statement to consume the newline character before reading the character
                    choice. You can add a space before %c to consume any leading whitespace characters (incl. \n chars)*/
                    
                    printf("Wanna continue...  : ");
                    scanf(" %c",&choice);
                    }while(choice=='y');
                     break;
                case 2:

                    printf("Enter the temperature in celsius : ");
                     scanf("%.2f",cels);
                    fahren=(cels*(9/5))+32;
                    printf("THe temperature in fahrenheit is %.2f F",fahren);
                    break;
                    
                default:
                    printf("Enter the listed choices above.");
                    break;
            }
    case 5:
       do{
       printf("Enter the number to find the sum : ");
       scanf("%d",&num);
       sum=0;
       for (int i = 1; i <=num ; i++)
       {
             sum=sum+i;    }
        printf("THe sum is : %d\n ",sum);
        getchar();
        printf("do you want to continue press (y) or do you want to find the sum between two numbers press(n) \n");
        scanf("%c",&choice);
       }while(choice=='y');

        if (choice!='y'){
        printf("ENter the start number : ");
        scanf("%d",&num);
        printf("ENter the last number : ");
        scanf("%d",&num2);
        sum=0;
        for (int i = num; i <= num2; i++)
        {
            sum=sum+i;
        }
        printf("THe sum is : %d",sum);
        
        }
    case 6:
       printf("Enter the coefficients (a,b,c) : ");
       scanf("%d%d%d",&a,&b,&c);
       roots(a,b,c);
    break;
    case 7:
        printf("Enter the number : ");
        scanf("%d",&num);
        revdigit(num);
    case 8:
       printf("ENter the number : ");
       scanf("%d",&num);
       decbin(num);
       getchar();
       printf("\ntry binary to decimal(y/n) : ");
       scanf("%c",&choice);
       if (choice=='y')
       {
        printf("Enter the binary number : ");
        scanf("%d",&a);
        bindec(a);
       }
    case 9:
    printf("Enter the number : ");
    scanf("%d",&num);
    printf("The compliment is : %d ",compliment(num));
    
    case 10:
    printf("enter the number : ");
    scanf("%d",&num);
    sumdigit(num);
    break;
    case 11:
    
    

}
 