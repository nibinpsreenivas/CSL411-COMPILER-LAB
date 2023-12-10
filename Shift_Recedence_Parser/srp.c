#include <stdio.h>
#include <string.h>
int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10]; //stk means stack and act/ac means action description
void check();
int main()
{

    puts("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id");
    puts("enter input string ");
    scanf("%s", a);
    c = strlen(a);
    strcpy(act, "SHIFT");
    puts("stack \t input \t action");
    for (k = 0, i = 0; j < c; k++, i++, j++)
    {
        if (a[j] == 'i' && a[j + 1] == 'd')
        { printf("\n$%s\t%s$\t%s", stk, a, act);
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            check();
        }
        else
        { printf("\n$%s\t%s$\t%s", stk, a, act);
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            check();
        }
    }
    
        printf("\n$%s\t%s$\tAccept", stk, a);
    
    printf("\n");
}
void check()
{
    strcpy(ac, "REDUCE by E");
    for (z = 0; z < c; z++)
        if (stk[z] == 'i' && stk[z + 1] == 'd')
        {printf("\n$%s\t%s$\t%s->id", stk, a, ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            j++;
        }
    for (z = 0; z < c; z++)
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E')
        {printf("\n$%s\t%s$\t%s->E+E", stk, a, ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            i = i - 2;
        }
    for (z = 0; z < c; z++)
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')
        {printf("\n$%s\t%s$\t%s->E*E", stk, a, ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            i = i - 2;
        }
    for (z = 0; z < c; z++)
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
        {printf("\n$%s\t%s$\t%s->(E)", stk, a, ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            i = i - 2;
        }
}