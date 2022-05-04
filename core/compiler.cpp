#include "compiler.h"

#include <iostream>
#include <memory>
#include "antlr4-runtime.h"
#include "../generated/Python3Lexer.h"
#include "../generated/Python3Parser.h"
#include "compiler.h"
#include "declaration.h"

void Compiler::addSource(const char* filename) {
    this->sources.push_back(filename);
}

void Compiler::readSource(const std::string  &filename,std::string &file_contents)  {
    std::string str;
    std::ifstream stream;

    stream.open(filename);
    std::string m = filename;

    /*  read the input line by line to avoid any linux/windows/mac newline problem */
    while (getline(stream, str))
    {
       // Pad the string
       if(str.size() < 80)
           str.append( 80 - str.size(), ' ');
       file_contents += str;
       file_contents.push_back('\n');
    }

    stream.close();
}

int Compiler::compile() {
    std::string file_contents;
    
    for (std::string const &file: this->sources) {
        std::cerr << "Compiling file:" << file << "\n";

        readSource(file, file_contents);

        antlr4::ANTLRInputStream input(file_contents);

        Python3Lexer lexer(&input);

        antlr4::CommontokenStream tokens(&lexer);

        Python3Parser parser(&tokens);

        parser.removeErrorListeners();

        Python3Parser::RContext *tree = parser.r();

        //CALL DECLARATION VISITOR

        //CALL CODE VISITOR

        //GENERATE LLVM IR
    }
}