#ifndef SCAN_H
#define SCAN_H
#include <string>
using namespace std;

enum token {
    t_read, t_write, t_id, t_literal, t_gets,
    t_add, t_sub, t_mul, t_div, t_lparen, t_rparen, t_eof,
    t_if, t_while, t_end, // for the extended calculator
    t_eq, t_neq, t_lt, t_gt, t_le, t_ge // for the extended calculator
};

const int MAX_TOKEN_LEN = 128;
extern string token_image;

token scan();

#endif
