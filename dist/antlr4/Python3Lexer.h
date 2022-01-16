
// Generated from Python3Lexer.g4 by ANTLR 4.9.2

#pragma once


#include "antlr4-runtime.h"




class  Python3Lexer : public Python3LexerBase {
public:
  enum {
    INDENT = 1, DEDENT = 2, STRING = 3, NUMBER = 4, INTEGER = 5, DEF = 6, 
    RETURN = 7, RAISE = 8, FROM = 9, IMPORT = 10, AS = 11, GLOBAL = 12, 
    NONLOCAL = 13, ASSERT = 14, IF = 15, ELIF = 16, ELSE = 17, WHILE = 18, 
    FOR = 19, IN = 20, TRY = 21, FINALLY = 22, WITH = 23, EXCEPT = 24, LAMBDA = 25, 
    OR = 26, AND = 27, NOT = 28, IS = 29, NONE = 30, TRUE = 31, FALSE = 32, 
    CLASS = 33, YIELD = 34, DEL = 35, PASS = 36, CONTINUE = 37, BREAK = 38, 
    ASYNC = 39, AWAIT = 40, NEWLINE = 41, NAME = 42, STRING_LITERAL = 43, 
    BYTES_LITERAL = 44, DECIMAL_INTEGER = 45, OCT_INTEGER = 46, HEX_INTEGER = 47, 
    BIN_INTEGER = 48, FLOAT_NUMBER = 49, IMAG_NUMBER = 50, DOT = 51, ELLIPSIS = 52, 
    STAR = 53, OPEN_PAREN = 54, CLOSE_PAREN = 55, COMMA = 56, COLON = 57, 
    SEMI_COLON = 58, POWER = 59, ASSIGN = 60, OPEN_BRACK = 61, CLOSE_BRACK = 62, 
    OR_OP = 63, XOR = 64, AND_OP = 65, LEFT_SHIFT = 66, RIGHT_SHIFT = 67, 
    ADD = 68, MINUS = 69, DIV = 70, MOD = 71, IDIV = 72, NOT_OP = 73, OPEN_BRACE = 74, 
    CLOSE_BRACE = 75, LESS_THAN = 76, GREATER_THAN = 77, EQUALS = 78, GT_EQ = 79, 
    LT_EQ = 80, NOT_EQ_1 = 81, NOT_EQ_2 = 82, AT = 83, ARROW = 84, ADD_ASSIGN = 85, 
    SUB_ASSIGN = 86, MULT_ASSIGN = 87, AT_ASSIGN = 88, DIV_ASSIGN = 89, 
    MOD_ASSIGN = 90, AND_ASSIGN = 91, OR_ASSIGN = 92, XOR_ASSIGN = 93, LEFT_SHIFT_ASSIGN = 94, 
    RIGHT_SHIFT_ASSIGN = 95, POWER_ASSIGN = 96, IDIV_ASSIGN = 97, SKIP_ = 98, 
    UNKNOWN_CHAR = 99
  };

  explicit Python3Lexer(antlr4::CharStream *input);
  ~Python3Lexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

  virtual void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;
  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPEN_PARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSE_PARENAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPEN_BRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSE_BRACKAction(antlr4::RuleContext *context, size_t actionIndex);
  void OPEN_BRACEAction(antlr4::RuleContext *context, size_t actionIndex);
  void CLOSE_BRACEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.
  bool NEWLINESempred(antlr4::RuleContext *_localctx, size_t predicateIndex);

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

