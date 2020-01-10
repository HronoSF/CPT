#include "../headers/Tokenizer.hxx"

vector<string> Tokenizer::tokenize(const string &line) {
    tokens = {""};
    token_num = 0;
    quote = false;
    for (char i : line) {
        if (!quote && (i == '\"' || i == '\'')) {
            quote = true;
        } else if (quote && (i == '\"' || i == '\'')) {
            quote = false;
        } else if (!quote && i == ' ') {
            tokens.emplace_back("");
            token_num++;
        } else if (!quote && (i == '<' || i == '>' || i == '|')) {
            tokens.emplace_back(1, i);
            tokens.emplace_back("");
            token_num += 2;
        } else {
            tokens[token_num] = tokens[token_num] + i;
        }
    }
    tokens = clean_spaces(tokens);
    return tokens;
}

vector<string> Tokenizer::clean_spaces(vector<string> line) {
    for (int i = 0; i < line.size(); i++) {
        if (line[i].empty()) {
            line.erase(line.begin() + i);
        }
    }
    return line;
}
