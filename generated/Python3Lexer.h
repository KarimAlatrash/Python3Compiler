
  #include "Python3Parser.h"


// Generated from /Users/karimalatrash/Documents/CodePlayground/compilers/AntlrPython/Python3Lexer.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  Python3Lexer : public antlr4::Lexer {
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

  Python3Lexer(antlr4::CharStream *input);
  ~Python3Lexer();


    private:
    // A queue where extra tokens are pushed on (see the NEWLINE lexer rule).
    std::vector<std::unique_ptr<antlr4::Token>> m_tokens;
    // The stack that keeps track of the indentation level.
    std::stack<int> m_indents;
    // The amount of opened braces, brackets and parenthesis.
    int m_opened = 0;
    // The most recently produced token.
    std::unique_ptr<antlr4::Token> m_pLastToken = nullptr;
    
    public:
    virtual void emit(std::unique_ptr<antlr4::Token> newToken) override {
      m_tokens.push_back(cloneToken(newToken));
      setToken(std::move(newToken));
    }

    std::unique_ptr<antlr4::Token> nextToken() override {
      // Check if the end-of-file is ahead and there are still some DEDENTS expected.
      if (_input->LA(1) == EOF && !m_indents.empty()) {
        // Remove any trailing EOF tokens from our buffer.
        for (int i = m_tokens.size() - 1; i >= 0; i--) {
          if (m_tokens[i]->getType() == EOF) {
            m_tokens.erase(m_tokens.begin() + i);
          }
        }

        // First emit an extra line break that serves as the end of the statement.
        emit(commonToken(Python3Parser::NEWLINE, "\n"));

        // Now emit as much DEDENT tokens as needed.
        while (!m_indents.empty()) {
          emit(createDedent());
          m_indents.pop();
        }

        // Put the EOF back on the token stream.
        emit(commonToken(EOF, "<EOF>"));
      }

      std::unique_ptr<antlr4::Token> next = Lexer::nextToken();

      if (next->getChannel() == antlr4::Token::DEFAULT_CHANNEL) {
        // Keep track of the last token on the default channel.
        m_pLastToken = cloneToken(next);
      }

      if (!m_tokens.empty())
      {
        next = std::move(*m_tokens.begin());
        m_tokens.erase(m_tokens.begin());
      }

      return next;
    }

    private:
    std::unique_ptr<antlr4::Token> createDedent() {
      std::unique_ptr<antlr4::CommonToken> dedent = commonToken(Python3Parser::DEDENT, "");
      return dedent;
    }

    std::unique_ptr<antlr4::CommonToken> commonToken(size_t type, const std::string& text) {
      int stop = getCharIndex() - 1;
      int start = text.empty() ? stop : stop - text.size() + 1;
      return _factory->create({ this, _input }, type, text, DEFAULT_TOKEN_CHANNEL, start, stop, m_pLastToken ? m_pLastToken->getLine() : 0, m_pLastToken ? m_pLastToken->getCharPositionInLine() : 0);
    }

    std::unique_ptr<antlr4::CommonToken> cloneToken(const std::unique_ptr<antlr4::Token>& source) {
        return _factory->create({ this, _input }, source->getType(), source->getText(), source->getChannel(), source->getStartIndex(), source->getStopIndex(), source->getLine(), source->getCharPositionInLine());
    }


    // Calculates the indentation of the provided spaces, taking the
    // following rules into account:
    //
    // "Tabs are replaced (from left to right) by one to eight spaces
    //  such that the total number of characters up to and including
    //  the replacement is a multiple of eight [...]"
    //
    //  -- https://docs.python.org/3.1/reference/lexical_analysis.html#indentation
    static int getIndentationCount(const std::string& spaces) {
      int count = 0;
      for (char ch : spaces) {
        switch (ch) {
          case '\t':
            count += 8 - (count % 8);
            break;
          default:
            // A normal space char.
            count++;
        }
      }

      return count;
    }

    bool atStartOfInput() {
      return getCharPositionInLine() == 0 && getLine() == 1;
    }

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

