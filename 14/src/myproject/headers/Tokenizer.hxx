#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Tokenizer {

private:
    vector<string> tokens;
    int token_num;
    bool is_quote;

public:
    vector<string> tokenize(const string& line);

    static vector<string> clear_spaces(vector<string> line);
};