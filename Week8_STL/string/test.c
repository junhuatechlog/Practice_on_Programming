#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXTOKENS 100
#define MAXTOKENLEN 64

enum type_tag 
{

    IDENTIFIER,
    QUALIFIER,
    TYPE
};

struct token 
{

    char type;
    char string[MAXTOKENLEN];
};

int top = -1;
struct token stack[MAXTOKENS];
struct token current;

#define pop stack[top--]
#define push(s) stack[++top] = s

enum type_tag classify_string(void)
    /* figure out the identifier type */

{

    char *s = current.string;
    if (!strcmp(s, "const")) 
    {

        strcpy(s, "read-only");
        return QUALIFIER;
    }
    if (!strcmp(s, "volatile")) return QUALIFIER;
    if (!strcmp(s, "void")) return TYPE;
    if (!strcmp(s, "char")) return TYPE;
    if (!strcmp(s, "signed")) return TYPE;
    if (!strcmp(s, "unsigned")) return TYPE;
    if (!strcmp(s, "short")) return TYPE;
    if (!strcmp(s, "int")) return TYPE;
    if (!strcmp(s, "long")) return TYPE;
    if (!strcmp(s, "float")) return TYPE;
    if (!strcmp(s, "double")) return TYPE;
    if (!strcmp(s, "struct")) return TYPE;
    if (!strcmp(s, "union")) return TYPE;
    if (!strcmp(s, "enum")) return TYPE;
    return IDENTIFIER;
}

void gettoken(void) /* read next token into "current" */
{

    char *p = current.string;

    /* read past any spaces */
    while ((*p = getchar()) == ' ')
        ;

    if (isalnum(*p)) 
    {

        /* it starts with A-Z,0-9 read in identifier */

        while (isalnum(*++p = getchar()))
            ;
        ungetc(*p, stdin);
        *p = '\0';
        current.type = classify_string();
        return;
    }

    if (*p == '*') 
    {

        strcpy(current.string, "pointer to");

    }
}
