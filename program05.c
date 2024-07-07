#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void shift_table(char p[],int t[])
{
    int i,m;
    /*length of pattern string*/
    m=strlen(p);
    /*initialize the table with pattern length*/
    for(i=0; i<128; i++)
        t[i]=m;
    /*find the distance of the first m-1 characters of the string from the last character*/
    for(i=0; i<=m-2; i++)
    {
        t[p[i]]=m-i-1;
    }

}
int horspool_pattern_match(char p[],char t[])
{
    int m,n,i,k,s[256];
    shift_table(p,s);

    m=strlen(p);
    n=strlen(t);
    i=m-1;

    while(i<=n-1)
    {
        k=0;
        while(k<=m-1 && t[i-k]==p[m-1-k])
        {
            k=k+1;
        }
        /*pattern found*/
        if(k==m)
            return i-m+1;
        /*No match,so shift the pattern towards right*/
        i=i+s[t[i]];
    }
    return -1;
}
void main()
{
    char p[50],t[100];
    int pos;

    printf("\nEnter the text string:\n");
    scanf("%s",t);

    printf("\nEnter the pattern string:\n");
    scanf("%s",p);

    pos=horspool_pattern_match(p,t);

    if(pos==-1)
    {
        printf("\nPattern string not found\n");
        exit(0);
    }
    printf("\nPattern string found at position %d\n",pos+1);
}
