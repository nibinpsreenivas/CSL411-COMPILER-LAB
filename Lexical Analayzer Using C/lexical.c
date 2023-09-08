#include<stdio.h>
#include<ctype.h>
#include<string.h>
 
int main()
{
 
	FILE *input, *output;
	int l=1,t=0,j=0,i,flag;
	char ch,str[20];
	input = fopen("input.txt","r");
	output = fopen("output.txt","w");
	char keyword[50][50] = {"int", "main", "if", "else", "while", "for", "return", "do", "switch", "FILE", "printf", "scanf"};
	
        fprintf(output,"Line no. \t Token no. \t\t Token \t\t Lexeme\n\n");
       
	while(!feof(input))
	{
		i=0;
		flag=0;
		ch=fgetc(input);
               if (ch == '/')
               {
                ch = fgetc(input);
                if (ch == '/')
                {
                   while ((ch = fgetc(input)) != '\n')
                   {
                       if (ch == '\n')
                        break;
                    }
                l++;
                }
             else if (ch == '*')
              {
                while ((ch = fgetc(input)) != '*')
                {
                    if (ch == EOF)
                        break;
                }
                ch = fgetc(input);
                if (ch == '/')
                {
                    continue;
                }
            }
        }


		if( ch=='+' || ch== '-' || ch=='*' || ch=='/' )
		{
			fprintf(output,"%7d\t\t %7d\t\t Operator\t %7c\n",l,t,ch);
			t++;
		}

		else if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' || ch=='@' ||ch=='!' || ch=='%')

		{

			fprintf(output,"%7d\t\t %7d\t\t Special symbol\t %7c\n",l,t,ch);
			t++;
		}

		else if(isdigit(ch))
		{
			fprintf(output,"%7d\t\t %7d\t\t Digit\t\t %7c\n",l,t,ch);
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
                       
			for(j=0;j<=50;j++)

			{
				if(strcmp(str,keyword[j])==0)
				{
					flag=1;
					break;
				}
			}

			if(flag==1)
			{
				fprintf(output,"%7d\t\t %7d\t\t Keyword\t %7s\n",l,t,str);
				t++;
			}

			else
			{
				fprintf(output,"%7d\t\t %7d\t\t Identifier\t %7s\n",l,t,str);
				t++;
			}
                        if( ch=='+' || ch== '-' || ch=='*' || ch=='/' )
		       {
			fprintf(output,"%7d\t\t %7d\t\t Operator\t %7c\n",l,t,ch);
			t++;
		        }
                        if( ch==';' || ch=='{' || ch=='}' || ch=='(' || ch==')' || ch=='?' || ch=='@' ||ch=='!' || ch=='%' ||ch=='=')
                       {

			fprintf(output,"%7d\t\t %7d\t\t Special symbol\t %7c\n",l,t,ch);
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
