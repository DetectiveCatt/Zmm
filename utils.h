#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

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
        nextPtr;
        prevPtr;
    }
    Token(std::string Literal, int LineNum, std::string TokenType, Token* Prev, Token* Next){
        literal = Literal;
        linenum = LineNum;
        tokentype = TokenType;
        nextPtr = Next;
        prevPtr = Prev;
    }
    void printtoken(){
        std::cout  << literal << " " << linenum << " " << tokentype << prevPtr->literal <<" "<< nextPtr->literal << std::endl;
        return;
    }
};

int findvector(std::vector<std::string> list, std::string stringtofind){
    for (int i=0; i< list.capacity(); i++){
        if (stringtofind == list.at(i)){
            return 1;
            break;
        }
    }
    return 0;
}
std::vector<std::string> split_string(const std::string& s)
{
    std::vector<std::string> splitted;
    bool flag = false;
    std::string tmp;
    for (int i=0; i<s.capacity(); i++){
        tmp += s[i];
        if (s[i] == '"' && flag == false){
            flag = true;
        } else if (s[i] == '"' && flag == true){
            flag = false;
            splitted.push_back(tmp);
        } else if (s[i] == ' ' && flag == false){
            tmp.pop_back();
            splitted.push_back(tmp);
            tmp.clear();
        } else if (s[i] == ' ' && flag == true){
            
        } 
         else if (s[i] == ';' && flag == false){
            tmp.pop_back();
            splitted.push_back(tmp);
            splitted.push_back(";");
            tmp.clear();
        } else if (s[i] == '<' && flag == false){
            tmp.pop_back();
            splitted.push_back(tmp);
            splitted.push_back("<");
            tmp.clear();
        } else if (s[i] == '>' && flag == false){
            tmp.pop_back();
            splitted.push_back(tmp);
            splitted.push_back(">");
            tmp.clear();
        }
    }
    return splitted;
}

std::vector<Token> lex(std::string data, int &num){
    std::vector<std::string> keywords = {"var", "func", "cout", "cin"};
    std::vector<std::string> split_tokens = split_string(data);
    std::vector<Token> result;
    int linenum = 0;
    Token *curprevtoken;
    Token *curnexttoken;
    int numoftokens = 0;
    for (int i=0; i<split_tokens.capacity(); i++){
        if (split_tokens[i] == ";"){
            linenum +=1;
        }
        std::cout << split_tokens[i] << std::endl;
        if (findvector(keywords, split_tokens[i])){
            Token token(split_tokens[i], linenum, "keyword", curprevtoken, curnexttoken);
            curprevtoken->nextPtr = &token;
            curprevtoken = &token;
               
        }
        try
        {
            int x;
            sscanf(split_tokens[i].c_str(), "%d", x);
            Token token(split_tokens[i], linenum, "integer", curprevtoken, curnexttoken);
            curprevtoken->nextPtr = &token;
            curprevtoken = &token;
        }
        catch(const std::exception& e)
        {
            if (split_tokens[i].substr(0,1) == "\"" && split_tokens[i].substr(split_tokens[1].length()-1, split_tokens[i].length()) == "\""){
                Token token(split_tokens[i], linenum, "string", curprevtoken, curnexttoken);
                curprevtoken->nextPtr = &token;
                curprevtoken = &token;

            }
        }
        numoftokens += 1;
        
    }
    std::cout  << "what" << std::endl;
    num = numoftokens;
    return result;
    std::cout  << "what" << std::endl;

}