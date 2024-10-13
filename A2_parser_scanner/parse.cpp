#include <iostream>
#include <cstdlib>
#include "scan.h"

const string names[] = {
    "read", "write", "id", "literal", "gets", "add", "sub", "mul", "div", "lparen", "rparen", "eof",
    "if", "while", "end", "eq", "neq", "lt", "gt", "le", "ge" // for the extended calculator
};

static token input_token;

void error() {
    cout << "syntax error" << endl;
    exit(1);
}

void match(token expected) {
    // cout << "debug: expecting: " << names[expected] << ", current token: " << names[input_token] << endl;
    if (input_token == expected) {
        cout << "matched " << names[input_token];
        if (input_token == t_id || input_token == t_literal)
            cout << ": " << token_image;
        cout << endl;
        input_token = scan();
        // cout << "debug: next token: " << names[input_token] << endl; // Debug output for the next token
    } else error();
}

void program();
void stmt_list();
void stmt();
void expr();
void term();
void term_tail();
void factor();
void factor_tail();
void add_op();
void mul_op();
void cond(); // for the extended calculator
void ro(); // for the extended calculator

void program() {
    // before implementing the extended calculator
    /*switch (input_token) {
        case t_id:
        case t_read:
        case t_write:
        case t_eof:
            cout << "predict program --> stmt_list eof" << endl;
            stmt_list();
            match(t_eof);
            break;
        default: error();
    }*/

    // for the extended calculator
    cout << "predict program --> stmt_list eof" << endl;
    stmt_list();
    match(t_eof);
}

void stmt_list() {
    switch (input_token) {
        case t_id:
        case t_read:
        case t_write:
        case t_if: // for the extended calculator
        case t_while: // for the extended calculator
            cout << "predict stmt_list --> stmt stmt_list" << endl;
            stmt();
            stmt_list();
            break;
        case t_end: // for the extended calculator
        case t_eof:
            cout << "predict stmt_list --> epsilon" << endl;
            break;
        default: error();
    }
}

void stmt() {
    switch (input_token) {
        case t_id:
            cout << "predict stmt --> id gets expr" << endl;
            match(t_id);
            match(t_gets);
            expr();
            break;
        case t_read:
            cout << "predict stmt --> read id" << endl;
            match(t_read);
            match(t_id);
            break;
        case t_write:
            cout << "predict stmt --> write expr" << endl;
            match(t_write);
            expr();
            break;
        case t_if: // for the extended calculator
            cout << "predict stmt --> if cond stmt_list end" << endl;
            match(t_if);
            cond();
            stmt_list();
            match(t_end);
            break;
        case t_while: // for the extended calculator
            cout << "predict stmt --> while cond stmt_list end" << endl;
            match(t_while);
            cond();
            stmt_list();
            match(t_end);
            break;
        default: error();
    }
}

void expr() {
    // cout << "debug: entering expr()" << endl;
    switch (input_token) {
        case t_id:
        case t_literal:
        case t_lparen:
            cout << "predict expr --> term term_tail" << endl;
            term();
            term_tail();
            break;
        default: 
            error();
    }
}

void term() {
    switch (input_token) {
        case t_id:
        case t_literal:
        case t_lparen:
            cout << "predict term --> factor factor_tail" << endl;
            factor();
            factor_tail();
            break;
        default: 
            error();
    }
}

void term_tail() {
    switch (input_token) {
        case t_add:
        case t_sub:
            cout << "predict term_tail --> add_op term term_tail" << endl;
            add_op();
            term();
            term_tail();
            break;
        // Allow relational operators to transition back to cond()
        case t_rparen:
        case t_id:
        case t_read:
        case t_write:
        case t_if:
        case t_while:
        case t_end:
        case t_eof:
        case t_gt:      // Add relational operators here as epsilon productions
        case t_eq:
        case t_neq:
        case t_lt:
        case t_le:
        case t_ge:
            cout << "predict term_tail --> epsilon" << endl;
            break;
        default: 
            error();
    }
}

void factor() {
    switch (input_token) {
        case t_literal:
            cout << "predict factor --> literal" << endl;
            match(t_literal);
            break;
        case t_id:
            cout << "predict factor --> id" << endl;
            match(t_id);
            break;
        case t_lparen:
            cout << "predict factor --> lparen expr rparen" << endl;
            match(t_lparen);
            expr();
            match(t_rparen);
            break;
        default: error();
    }
}

void factor_tail() {
    switch (input_token) {
        case t_mul:
        case t_div:
            mul_op();
            factor();
            factor_tail();
            break;
        // Allow relational operators to exit to cond() correctly
        case t_add:
        case t_sub:
        case t_rparen:
        case t_id:
        case t_read:
        case t_write:
        case t_if:
        case t_while:
        case t_end:
        case t_eof:
        case t_gt:     // Add these relational operators
        case t_eq:
        case t_neq:
        case t_lt:
        case t_le:
        case t_ge:
            cout << "predict factor_tail --> epsilon" << endl;
            break;
        default: 
            error();
    }
}

void add_op() {
    switch (input_token) {
        case t_add:
            cout << "predict add_op --> add" << endl;
            match(t_add);
            break;
        case t_sub:
            cout << "predict add_op --> sub" << endl;
            match(t_sub);
            break;
        default: error();
    }
}

void mul_op() {
    switch (input_token) {
        case t_mul:
            cout << "predict mul_op --> mul" << endl;
            match(t_mul);
            break;
        case t_div:
            cout << "predict mul_op --> div" << endl;
            match(t_div);
            break;
        default: error();
    }
}

// for the extended calculator
void cond() {
    cout << "predict cond --> expr ro expr" << endl;
    expr();
    // cout << "debug: token after expr (before ro()): " << names[input_token] << endl;
    ro();
    expr();
}

// for the extended calculator
void ro() {
    // cout << "debug: in ro(), current token: " << names[input_token] << endl;
    switch (input_token) {
        case t_eq: match(t_eq); break;
        case t_neq: match(t_neq); break;
        case t_lt: match(t_lt); break;
        case t_gt: match(t_gt); break;
        case t_le: match(t_le); break;
        case t_ge: match(t_ge); break;
        default: error();
    }
}

int main() {
    input_token = scan();
    program();
    return 0;
}
