#pragma once

#include <cinttypes>
#include <string>

typedef std::basic_string <char16_t> U16String;

namespace halang {
    typedef int32_t uc32;

    // runtime definition
    typedef double TNumber;
    typedef int TSmallInt;
    typedef bool TBool;

#define VM_STACK_SIZE 256

#define OPERATOR_LIST(V) \
    V(ADD, "+", 10) \
    V(SUB, "-", 10) \
    V(MUL, "*", 11) \
    V(DIV, "/", 11) \
    V(MOD, "%", 12) \
    V(POW, "**", 13) \
    V(NOT, "!", 15) \
    V(EQ, "==", 8) \
    V(GT, ">", 8) \
    V(LT, "<", 8) \
    V(GTEQ, ">=", 8) \
    V(LTEQ, "<=", 8) \
    V(LG_AND, "&", 5) \
    V(LG_OR, "|", 5) \
    V(ILLEGAL_OP, "", 0)

#define TOKEN_LIST(V) \
    V(GET) \
    V(SET) \
    V(GETTER) \
    V(SETTER) \
    V(ACCESSOR) \
    V(DOT) \
    V(AT) \
    V(ARROW) \
    V(COMMA) \
    V(SEMICOLON) \
    V(ILLEGAL) \
    V(IF) \
    V(ELSE) \
    V(WHILE) \
    V(BREAK) \
    V(CONTINUE) \
    V(ASSIGN) \
    V(IDENTIFIER) \
    V(STRING) \
    V(OPEN_PAREN) \
    V(CLOSE_PAREN) \
    V(OPEN_BRACKET) \
    V(CLOSE_BRACKET) \
    V(OPEN_SQUARE_BRACKET) \
    V(CLOSE_SQUARE_BRACKET) \
    V(NUMBER) \
    V(LET) \
    V(CLASS) \
    V(FUN) \
    V(DEF) \
    V(AND) \
    V(OR) \
    V(RETURN) \
    V(DO) \
    V(END) \
    V(THEN) \
    V(ENDFILE)


#define E(NAME, STR, PRE) NAME,
    enum OperatorType {
        OPERATOR_LIST(E)
        OP_NUM
    };
#undef E


#define E(NAME, STR, PRE) PRE,
    const int OpreatorPrecedence[OperatorType::OP_NUM] =
            {
                    OPERATOR_LIST(E)
            };
#undef E

#define E(NAME, STR, PRE) #NAME ,
#define ET(NAME) #NAME ,
    const static char *TokenName[] =
            {
                    OPERATOR_LIST(E)
                    TOKEN_LIST(ET)
            };
#undef E
#undef ET

    inline int GetPrecedence(OperatorType ot) {
        if (ot >= OperatorType::OP_NUM || ot < 0) return 0;
        return OpreatorPrecedence[ot];
    }

};
