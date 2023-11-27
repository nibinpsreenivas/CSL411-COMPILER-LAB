%{
    int COMMENT = 0;
%}

identifier [a-zA-Z_][a-zA-Z0-9_]*

%%

#.* {printf("\n%s is a preprocessor directive", yytext);}

int|float|char|printf|scanf|goto|while|do|for|if|else|return|struct {if (!COMMENT) printf("\n%s is a Keyword", yytext);}

"/*" {COMMENT = 1; printf("\n%s Comment code", yytext);}
"*/" {COMMENT = 0;}

"//" {COMMENT = 1; printf("\n Comment Code");}
\n {COMMENT = 0;}

{identifier}([0-9]*)? {if (!COMMENT) printf("\n%s is an identifier", yytext);}

\".*\" {if (!COMMENT) printf("\n%s is a STRING", yytext);}

[0-9]+ {if (!COMMENT) printf("\n%s is a Digit", yytext);}

[+\-*/%=\<>!&|] {if (!COMMENT) printf("\n%s is an Operator", yytext);} /* Recognize operators */

\'[a-zA-Z0-9]\' {if (!COMMENT) printf("\n%s is a Character Literal", yytext);} /* Recognize character literals */

[,{}()\[\];:"'] {if (!COMMENT) printf("\n%s is a Special symbol", yytext);}

[ \t\n]+ ; /* Ignore spaces, tabs, and newlines */

. {if (!COMMENT) printf("\n%s is an unrecognized token", yytext);}

%%

int main(int argc, char **argv) {
    FILE *file;
    file = fopen("file.c", "r");
    if (!file) {
        printf("could not open the file");
        exit(0);
    }
    yyin = file;
    yylex();
    printf("\n");
    return (0);
}

int yywrap() {
    return (1);
}
