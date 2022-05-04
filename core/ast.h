
#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <llvm/IR/Module.h>

class Symbol;
class SymbolTable;
class AST;
class IntegerLiteral;
class DecimalLiteral;
class StringLiteral;
class Identifier;
class MathExpression;
class ComparisonExpression;
class Statement;
class SelectStatement;
class ForStatement;
class SubroutineDeclaration;
class SubroutineInvocation;
class AssignmentStatement;
class DisplayStatement;

class Generator {
public:
    virtual void declare(Symbol *) = 0;
    virtual llvm::Value* visit(IntegerLiteral *integer,void *param) =0;
    virtual llvm::Value* visit(DecimalLiteral *decimal,void *param) =0;
    virtual llvm::Value* visit(StringLiteral *string,void *param) =0;
    virtual llvm::Value* visit(Identifier *string,void *param) =0;
    virtual llvm::Value* visit(MathExpression *expression,void *param) =0;
    virtual llvm::Value* visit(Statement *statement,void *param) =0;
    virtual llvm::Value* visit(SelectStatement *select,void *param) =0;
    virtual llvm::Value* visit(ForStatement *loop,void *param) =0;
    virtual llvm::Value* visit(SubroutineDeclaration *subroutine,void *param) =0;
    virtual llvm::Value* visit(SubroutineInvocation *subroutine,void *param) =0;
    virtual llvm::Value* visit(AssignmentStatement *assignment,void *param) =0;
    virtual llvm::Value* visit(ComparisonExpression *expression,void *param) =0;
    virtual llvm::Value *visit(DisplayStatement *dsply,void *param)  = 0;
};

class Token {
public:
    enum Type {
        INT,
        DECIMAL,
        STRING,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        AND,
        OR,
        SYMBOL,
        SUBROUTINE,
        ASSIGNMENT,
        CALLS,
        SELECT,
        WHEN,
        OTHER,
        FOR,
        EQUAL,
        LT,GT,LE,GE,NE,
        DSPLY
    };

    Token(Type type, const std::string &text) : _type(type), _text(text) {}
    Type getType() const { return _type; }

    const std::string &getValue() const { return _text; }
    const std::string &toString() const { return _text; }

private:
    Type _type;
    std::string _text;
};

class Node {
public:
    Node(int line, const Token &token) : _line(line), _token(token) {}

    int getLine() const { return _line; }
    Token::Type getType() const { return _token.getType(); }
    const std::string &getValue() const { return _token.getValue(); }
    virtual  std::string toString() { return _token.toString(); }

    int addNode(std::shared_ptr<Node> node) { nodes.push_back(node); }

    const std::vector<std::shared_ptr<Node>> &getNodes() const { return nodes; }

    virtual llvm::Value *accept(Generator *v, void *param = nullptr) = 0;

private:
    int _line;
    Token _token;
    std::vector<std::shared_ptr<Node>>  nodes;

};

class Expression : public Node {
public:
    Expression(int line, const Token &token) : Node(line, token) {}

    llvm::Value *accept(Generator *v, void *param = nullptr) override {  }

};
