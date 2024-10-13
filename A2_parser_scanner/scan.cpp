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
        else if (token_image == "if") return t_if; // for the extended calculator
        else if (token_image == "while") return t_while; // for the extended calculator
        else if (token_image == "end") return t_end; // for the extended calculator
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
            case '=': // for the extended calculator
                c = cin.get(); 
                return t_eq;
            case '<': // for the extended calculator
                c = cin.get();
                if (c == '>') { 
                    c = cin.get(); return t_neq; 
                }
                else if (c == '=') { 
                    c = cin.get(); return t_le; 
                }
                else return t_lt;
            case '>': // for the extended calculator
                c = cin.get();
                if (c == '=') { 
                    c = cin.get(); return t_ge; 
                }
                else return t_gt;
            default:
                cerr << "syntax error" << endl;
                exit(1);
        }
    }
}
