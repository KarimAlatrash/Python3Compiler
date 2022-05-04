#pragma once

#include <list>
#include "antlr4-runtime.h"
#include "../generated/Python3Lexer.h"
#include "../generated/Python3Parser.h"
#include "../generated/Python3ParserBaseVisitor.h"
#include "compiler.h"
#include "symboltable.h"

class Python3SymbolFactory {
public:
    Python3SymbolFactory(const Compiler *compiler) : compiler(compiler) {}

public:
    // Allows for the declaration of simple assignment statements (var = 5)
    std::shared_ptr<Symbol> create(Python3Parser::AnnassignContext* ctx);
    // Allows for +=, -= etc. assignments
    std::shared_ptr<Symbol> create(Python3Parser::AugassignContext* ctx);

    static std::string replace(std::string str, const std::string& from, const std::string& to) {
        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
        }
        return str;
    }
private:
    const Compiler* compiler;
    bool is_number(const std::string &s) {
        return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); } ) == s.end();
    }
};

class Python3DeclarationVisitor : public Python3Visitor {

public:
    Python3DeclarationVisitor(const std::string &filename, const Compiler *compiler);

    antlrcpp::Any visitAnnassign(Python3Parser::AnnassignContext *ctx) override;
    antlrcpp::Any visitAugassign(Python3Parser::AugassignContext *ctx) override;


private:
    std::shared_ptr<Python3SymbolFactory> symbolFactory;

    std::shared_ptr<Symbol> parseSymbol(Python3Parser::AnnassignContext *ctx);

};
