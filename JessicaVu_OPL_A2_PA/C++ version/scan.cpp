#include <iostream>
#include <cstdlib>
#include <cctype>
#include "scan.h"

string token_image;

token scan() {
    static int c = ' ';
    int i = 0;

    while (isspace(c)) {
        c = cin.get();
    }
    if (c == EOF)
        return t_eof;
    
    if (isalpha(c)) {
        token_image.clear();
        do {
            token_image += c;
            if (i++ >= MAX_TOKEN_LEN) {
                cerr << "max token length exceeded" << endl;
                exit(1);
            }
            c = cin.get();
        } while (isalpha(c) || isdigit(c) || c == '_');
        
        if (token_image == "read") return t_read;
        else if (token_image == "write") return t_write;
        else return t_id;
    }
    else if (isdigit(c)) {
        token_image.clear();
        do {
            token_image += c;
            c = cin.get();
        } while (isdigit(c));
        return t_literal;
    } else {
        switch (c) {
            case ':':
                if ((c = cin.get()) != '=') {
                    cerr << "syntax error" << endl;
                    exit(1);
                } else {
                    c = cin.get();
                    return t_gets;
                }
            case '(': c = cin.get(); return t_lparen;
            case ')': c = cin.get(); return t_rparen;
            case '+': c = cin.get(); return t_add;
            case '-': c = cin.get(); return t_sub;
            case '*': c = cin.get(); return t_mul;
            case '/': c = cin.get(); return t_div;
            default:
                cerr << "syntax error" << endl;
                exit(1);
        }
    }
}
