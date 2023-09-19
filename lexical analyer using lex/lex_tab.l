%{
    int COMMENT = 0;
    int line_number = 1;    // Initialize line number
    int token_number = 1;   // Initialize token number
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%%

#.* {
    printf("%d\t%d\tPreprocessor directive\t%s\n", line_number, token_number++, yytext);
}

int|float|char|printf|scanf|goto|while|do|for|if|else|return|struct {
    printf("%d\t%d\tKeyword\t\t\t%s\n", line_number, token_number++, yytext);
}

"/*" {
    COMMENT = 1;
    printf("%d\t%d\tComment\t\t%s\n", line_number, token_number++, yytext);
}

{identifier}([0-9]*)? {
    printf("%d\t%d\tIdentifier\t\t%s\n", line_number, token_number++, yytext);
}

\".*\" {
    if (!COMMENT) {
        printf("%d\t%d\tString\t\t\t%s\n", line_number, token_number++, yytext);
    }
}

[0-9]+ {
    printf("%d\t%d\tDigit\t\t\t%s\n", line_number, token_number++, yytext);
}

[+\-*/%=<>!&|] {
    if (!COMMENT) {
        printf("%d\t%d\tOperator\t\t%s\n", line_number, token_number++, yytext);
    }
}

[(),{}\[\];:\"\'] {
    if (!COMMENT) {
        printf("%d\t%d\tSpecial symbol\t\t%s\n", line_number, token_number++, yytext);
    }
}

[ \t]+ ; /* Ignore spaces and tabs */

\n {
    line_number++;   // Increment line number on newline
}

. {
    if (!COMMENT) {
        printf("%d\t%d\tUnrecognized token\t\t%s\n", line_number, token_number++, yytext);
    }
}

%%

int main(int argc, char **argv) {
    FILE *file;
    file = fopen("file.c", "r");
    if (!file) {
        printf("could not open the file");
        exit(0);
    }
    printf("Line\tToken no.\tToken\t\tLexeme\n");
    yyin = file;
    yylex();
    printf("\n");
    return (0);
}

int yywrap() {
    return (1);
}
