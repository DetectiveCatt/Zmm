#include <iostream>
#include <fstream>
#include <vector>
#include "utils.h"
#include <string>
#include <unordered_map>


int main(int argc, const char** argv) {
    std::string data;
    std::fstream file;
    file.open("code.zmm");
    std::string tmp;
    while(getline(file, tmp)){
        data.append("\n");
        data.append(tmp);
    }
    file.close();
    int numoftokens;
    std::vector<Token> tokens = lex(data, numoftokens);
    std::cout << "what" << std::endl;
    for (int i = 0; i < numoftokens; i++){
        tokens[i].printtoken();
    }

    return 0;
}