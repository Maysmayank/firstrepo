#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char input();
char output();
void main(){
    printf("1> Enter string");
    printf("2. Get read\n");
    int opt;
    scanf("%d",&opt);
    switch (opt)
    {
    case 1:
        input();
        break; 
    case 2:
        output();
    default:
        break;
    }
   /* FILE *fp;
    fp=fopen("file.txt","w");
    if(fp==NULL){
    printf("error");
    exit(1);
    }
    char str[100];
    printf("ENter the text : ");
    gets(str);
    for (int i = 0; i!=strlen(str); i++)    // also can use   |
    {                                       //                |                 fputs(str,fp)
        fputc(str[i],fp);                   //                |
    }
    
    fclose(fp);*/
   /* FILE *fp=NULL;
    char ch;
    fp=fopen("file.txt","r");
    if(fp==NULL){
    printf("error");
    exit(1);
    }
    while (!feof(fp))
    {
    ch=fgetc(fp);
    printf("%c",ch);
    }
    fclose(fp); */
   
}
char input(){
    FILE *fp;
    fp=fopen("file.txt","w");
    if(fp==NULL){
    printf("error");
    exit(1);
    }
    char str[100];
    printf("ENter the text : ");
    fputs(str,fp);
    fclose(fp);

}
char output(){
    FILE *fp=NULL;
    char ch;
    fp=fopen("file.txt","r");
    if(fp==NULL){
    printf("error");
    exit(1);
    }
    while (!feof(fp))
    {
    ch=fgetc(fp);
    printf("%c",ch);
    }
    fclose(fp); 
}