# FIRST AND FOLLOW

# First() in Compiler Design
- **First()** is a grammatical function that specifies the set of terminal symbols (tokens) that can start a string derived from a production rule.
- It represents the first terminal that appears on the right-hand side of the production rule.
- For example, if we have a production rule: `T -> FT' / ε`, the First of T includes {, ε} because these are the terminals that can begin a string derived from the production T.

## Rules for Finding First():
1. If X is a terminal, then First(X) is {X}.
2. If X is a non-terminal and X produces α as a production, then add the First of α to the First of X.
3. If X produces ε (empty string), then add ε to the First of X.
4. If X produces a series of symbols YZ, and the First of Y contains ε, then the First of X includes everything in the First of Y except for ε, combined with the First of Z.
5. If X produces a series of symbols YZ, and the First of Y does not contain ε, then the First of X is the same as the First of Y.

# Follow() in Compiler Design
- **Follow()** is a grammatical function representing the set of terminal symbols that can appear just to the right of a non-terminal symbol in any sentence derived from the grammar.
- It helps determine what terminals can follow a non-terminal symbol in a production.
- For example, if we have productions like `E -> TE'` and `F -> (E) / id`, the Follow of E includes { ) } because ')' is the terminal that appears after E in the right-hand side of the production `F -> (E)`.

## Rules for Finding Follow():
1. $ (the end-of-input marker) is in the Follow of the start symbol (usually 'S').
2. If A produces αBβ (where β ≠ ε), then the First of β (excluding ε) is in the Follow of B.
3. If A produces αB or αBβ where First(β) contains ε, then everything in the Follow of A is in the Follow of B.

In summary, **First()** and **Follow()** sets are crucial in compiler design to guide parsing and ensure the correct recognition of grammar symbols and their relationships within a programming language's syntax. They help determine the valid structure of sentences and guide the compiler in making parsing decisions.

## Explanation For the Code
This C program calculates the FIRST and FOLLOW sets for a given context-free grammar (CFG). These sets are important in compiler design and parsing. Let's break down the code and explain it step by step:

1. **Include Headers**: The code starts by including necessary header files like `<stdio.h>`, `<string.h>`, and `<ctype.h>`.

2. **Global Variables**:
   - `nop`: Stores the number of productions in the grammar.
   - `m`: Counter variable used to keep track of the number of elements in the `res` array.
   - `prod[10][10]`: A 2D array to store the productions provided by the user.
   - `res[10]`: An array to store the result (FIRST or FOLLOW set) characters.

3. **Function Declarations**:
   - `void FIRST(char c)`: This function calculates the FIRST set for the given grammar symbol `c`.
   - `void FOLLOW(char c)`: This function calculates the FOLLOW set for the given grammar symbol `c`.
   - `void result(char c)`: This function stores the calculated result (characters) in the `res` array.

4. **`main` Function**:
   - The `main` function initializes variables, reads user input for productions, and performs the FIRST and FOLLOW calculations.
   - It reads the number of productions (`nop`) and the grammar productions from the user.

5. **Calculation of FIRST and FOLLOW**:
   - The `main` function then enters a loop where it calculates both FIRST and FOLLOW sets for a given grammar symbol.
   - It reads the grammar symbol `c` for which the sets need to be calculated.
   - It checks if `c` is an uppercase letter (non-terminal symbol). If not, it prints "Not Possible" and exits.
   
6. **FIRST(c) Function**:
   - This function calculates the FIRST set for the grammar symbol `c` using the provided grammar productions.
   - It iterates through the productions and checks if `c` matches the left-hand side of a production.
   - Depending on the production, it calculates the FIRST set according to the rules for FIRST sets mentioned earlier and stores the result in the `res` array.

7. **FOLLOW(c) Function**:
   - This function calculates the FOLLOW set for the grammar symbol `c` using the provided grammar productions.
   - It iterates through the productions and checks where `c` appears in the right-hand side of a production.
   - Depending on the position of `c` in the production and the rules for FOLLOW sets, it calculates the FOLLOW set and stores the result in the `res` array.

8. **Printing the Results**:
   - After calculating both FIRST and FOLLOW sets for the given grammar symbol `c`, the code prints the results.

9. **Loop Control**:
   - The code asks the user if they want to continue calculating sets for other grammar symbols by pressing `1` to continue.
   - If the user chooses to continue, the loop repeats; otherwise, the program terminates.

In summary, this code is a simple implementation to calculate the FIRST and FOLLOW sets for a given CFG based on user input. It follows the rules for calculating these sets and stores the results in the `res` array, which is then printed.

