#include <iostream>
#include <std
#include "antlr4-runtime.h"
#include "dist/antlr4/Python3Lexer.h"
#include "dist/antlr4/Python3Parser.h"

int main(int argc, const char* argv[]) {

    // Provide the input text in a stream
    antlr4::ANTLRInputStream input("6*(2+3)");
    
    // Create a lexer from the input
    Python3Lexer lexer(&input);
    
    // Create a token stream from the lexer
    antlr4::CommonTokenStream tokens(&lexer);
    
    // Create a parser from the token stream
    Python3Parser parser(&tokens);    

    // Display the parse tree
    std::cout << parser.expr()->toStringTree() << std::endl;
    return 0;
}
