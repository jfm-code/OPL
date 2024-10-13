```scan.h```

- Defines an enumeration token representing different token types (like t_read, t_write, t_id, etc.).
- Declares a constant MAX_TOKEN_LEN to restrict the length of tokens.

- Declares an external variable token_image to store the image of the current token.
Declares the scan() function, which is responsible for tokenizing input.

```scantest.cpp```

- A test file for scan.cpp, which uses scan() to read tokens from standard input.
- It prints out the token type and token image (for identifiers and literals) until it reaches the end of the file (t_eof).

```scan.cpp```

- Implements the scan() function, which:
Reads characters from standard input, skipping any whitespace.
- Recognizes various tokens by character patterns, such as identifiers (t_id), literals (t_literal), and symbols (t_add, t_sub, etc.).
- Supports multi-character symbols (like := for t_gets) and handles syntax errors.
Stores the token's string representation in token_image.

```parse.cpp```

- Implements a simple recursive descent parser based on the tokens produced by scan().
Defines functions for different grammar rules, such as:
```program(), stmt_list(), stmt(), expr(), etc.,``` each responsible for parsing a particular language construct.
- Each function matches tokens and recursively calls others based on the expected grammar, with ```match()``` to confirm each token type.
- Grammar includes constructs for expressions and statements (assignment, read, write) with recursive calls for handling expressions (expr, term, etc.).
Error handling via error(), which terminates the program on syntax errors.
- The main function begins parsing by calling program() after an initial token scan.