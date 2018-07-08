#include<stdlib.h>
#include<string.h>
#include<stdio.h>
int i=0;
struct links
{
    char *link;
    struct links *next;
};
char *fileName()
{
    char *filen=(char*)malloc(sizeof(char)*10);
    *filen=i+'0';
    i++;
    strcat(filen,".txt");
    return filen;
}
void downloadSeed(char ch[100],char ch1[20])
{
    char  c2[100]="wget -q --spider ";
    char c[1000]="wget -O ";
    strcat(c,ch1);
    strcat(c2,ch);
    if(system(c2))
    {
        printf("You Entered Invalid URL");
        return ;
    }
    strcat(c," ");
    strcat(c,ch);
    system(c);
}
void findstring(char ch1[20])
{
    FILE *fptr;
    int j=0;
    char ch;
    fptr=fopen(ch1,"r");
    if(fptr==NULL){printf("File Not Exist"); return; }
    fseek(fptr, 0L, SEEK_END);
    int siz = ftell(fptr);
    rewind(fptr);
    char *c=(char*)malloc(siz*sizeof(char));
    do{
    ch=fgetc(fptr);
    c[j]=ch;
    j++;
    }while(ch!=EOF);
    c[j]='\0';
    fclose(fptr);
    return c;
}
void findlink(char *html,char *seedurl)
{
    char ch1[5]='<a';


}
int main()
{
char *ch1,*ch2;
ch1=fileName();
char ch[100];
printf("Enter Your LINK:");
scanf("%s",ch);
downloadSeed(ch,ch1);
ch2=findstring(ch1);
findlink(ch2,ch);
}
