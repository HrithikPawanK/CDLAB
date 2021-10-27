#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    FILE *input, *output;
    int l=1;
    int t=0;
    int j=0;
    int i,flag;
    char ch,str[20];
    input = fopen("test.c","r");
    output = fopen("output.txt","w");
    char keyword[30][30] = {"int","main","if","else","do","while"};
    fprintf(output,"Line no.\t\tToken no.\t\t          Token\t\t          Lexeme\n\n");
    while(!feof(input))
    {
        i=0;
        flag=0;
        ch=fgetc(input);
        if( ch=='+' || ch== '-' || ch=='*' || ch=='/' )
        {
            fprintf(output,"%8d\t\t%9d\t\t%15s\t\t%16c\n",l,t,"Operator",ch);
            t++;
        }
        else if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' || ch=='@' || ch=='!' || ch=='%')
        {
            fprintf(output,"%8d\t\t%9d\t\t%15s\t\t%16c\n",l,t,"Special Symbol",ch);
            t++;
        }
        else if(isdigit(ch))
        {
            fprintf(output,"%8d\t\t%9d\t\t%15s\t\t%16c\n",l,t, "Digit",ch);
            t++;
        }
        else if(isalpha(ch))
        {
            str[i]=ch;
            i++;
            ch=fgetc(input);
            while(isalnum(ch) && ch!=' ')
            {
                str[i]=ch;
                i++;
                ch=fgetc(input);
            }
            str[i]='\0';
            for(j=0;j<=5;j++)
            {
                if(strcmp(str,keyword[j])==0)
                {
                        flag=1;
                        break;
                }
            }
            if(flag==1)
            {
                fprintf(output,"%8d\t\t%9d\t\t%15s\t\t%16s\n",l,t, "keyword",str);
                t++;
            }
            else
            {
                fprintf(output,"%8d\t\t%9d\t\t%15s\t\t%16s\n",l,t, "Identifier",str);
                t++;
            }
        }
        else if(ch=='\n')
        {
            l++;
        }
    }
    fclose(input);
    fclose(output);
    return 0;
}