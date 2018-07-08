#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct links
{
    char link[100];
    struct links *next;
};
void downloadSeed(char ch[100])
{
    char c[1000]="wget -O temp1.txt ";
    strcat(c,ch);
    system(c);
}
void findlinks()
{
    FILE *fptr;
    int i=0;
    char ch;
    fptr=fopen("temp1.txt","r");
    fseek(fptr, 0L, SEEK_END);
    int siz = ftell(fptr);
    rewind(fptr);

    char *c=(char*)malloc(siz*sizeof(char));
    do{
    ch=fgetc(fptr);
    c[i]=ch;
    i++;
    }while(ch!=EOF);
    for(i=0;i<siz;i++)
    {printf("%c",c[i]);i++;}
 fclose(fptr);
    printf("size:%d",siz);



}
int main()
{
char ch[100];
printf("Enter Your LINK:");
//scanf("%s",ch);
//downloadSeed(ch);
findlinks();
}
