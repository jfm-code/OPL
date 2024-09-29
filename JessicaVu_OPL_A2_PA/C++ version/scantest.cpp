#include <iostream>
#include "scan.h"

const string names[] = {"read", "write", "id", "literal", "gets",
                             "add", "sub", "mul", "div", "lparen", "rparen", "eof"};

static token input_token;

int main() {

    do {
        input_token = scan();
        cout << "scanned " << names[input_token];
        if (input_token == t_id || input_token == t_literal)
            cout << ": " << token_image;
        cout << endl;
    } while (input_token != t_eof);

    return 0;
}
