// C program to Construct of recursive descent parsing for
// the following grammar
// E->TE’
// E’->+TE'/@
// T->FT’
// T`->*FT’/@
// F->(E)/id where @ represents null character


#include<stdio.h>
#include<ctype.h>
#include<string.h>
char input[100];
int i, l;

int E();
int EP();
int T();
int TP();
int F();
void process();
int set=0;
int sum=0;

void main()
{
    printf("\nRecursive descent parsing for the following grammar\n");
    printf("\nE->TE'\nE'->+TE'/@\nT->FT'\nT'->*FT'/@\nF->(E)/ID\n");
    printf("\nEnter the string to be checked:");
    scanf("%s", input);
    if (E())
    {
        if(input[i] =='-' ||input[i] =='/')
        {
           printf("\nString is not accepted");
        }
        else if (input[i + 1] == '\0')
        {
            printf("\nString is accepted");
            printf("\n the processed data is :%d",sum);
        }
        else
        {
            printf("\nString is not accepted");
           
        }
    }
    else if(input[i-1] =='+' ||input[i-1] =='*')
    {
            printf("\nString is accepted");
            printf("\n the processed data is :%d",sum);
    }
    else
        printf("\nString not accepted");
}
int E()
{
    if (T())
    {
        if (EP())
            return (1);
        else
            return (0);
    }
    else
        return (0);
}
int EP()
{
    if (input[i] == '+')
    {
        i++;
        if (T())
        {
            if (EP())
                return (1);
            else
                return (0);
        }
        else
            return (0);
    }
    else
        return (1);
}
int T()
{
    if (F())
    {
        if (TP())
            return (1);
        else
            return (0);
    }
    else
        return (0);
}
int TP()
{
    if (input[i] == '*')
    {
        i++;
        if (F())
        {
            if (TP())
                return (1);
            else
                return (0);
        }
        else
            return (0);
    }
    else
        return (1);
}
int F()
{
    if (input[i] == '(')
    {
        i++;
        if (E())
        {
            if (input[i] == ')')
            {
                i++;
                return (1);
            }
            else
                return (0);
        }
        else
            return (0);
    }
    else if (input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z')
    {
        i++;
        return (1);
    }
    else if (input[i] >= '1' && input[i] <= '9' )
    {
        set++;
        i++;
        if(set==2)
        {
          process();
        }
        else if(input[i]=='\0'||input[i-2]=='+'||input[i-2]=='*')
        {
           if(input[i-2]=='+')
           {
            sum=sum+(input[i-1]-48);
           }
           else if(input[i-2]=='*')
           {
              sum=sum*(input[i-1]-48);
           }
        }
        
        return (1);
    }
    else
        return (0);
}
void process()
{
    set=0;
    
    
    if(input[i-2]=='+')
    {
       
        sum=input[i-3]-48+input[i-1]-48;
    }
    else if(input[i-2]=='*')
    {
      
       sum=(input[i-3]-48)*(input[i-1]-48);
    }
    
    
 }
