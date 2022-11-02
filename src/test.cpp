#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class Token{
    public:
    std::string literal; // the literal word e.g var abc func thisisa_function
    int linenum;   // line number
    std::string tokentype; // operator, keyword, identifier, integer
    Token *nextPtr;
    Token *prevPtr;
    Token(){
        literal = "";
        linenum = 0;
        tokentype = "";
        nextPtr = NULL;
        prevPtr = NULL;
    }
    Token(std::string Literal, int LineNum, std::string TokenType, Token* Prev, Token* Next){
        literal = Literal;
        linenum = LineNum;
        tokentype = TokenType;
        nextPtr = Next;
        prevPtr = Prev;
    }
};
int main(int argc, const char** argv) {
    Token token1("var", 1, "keyword", NULL, NULL);
    Token token2("string", 1, "datatype", &token1, NULL);
    Token token1fromptr = *(token2.prevPtr);
    std::cout << token1fromptr.tokentype << std::endl;
    std::cout << token1.literal << std::endl;
    return 0;
}