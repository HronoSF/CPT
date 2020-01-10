#include "../headers/Tokenizer.hxx"

vector<string> Tokenizer::tokenize(const string &line) {
    tokens = {""};
    token_num = 0;
    is_quote = false;
    for (char i : line) {
        if (!is_quote && (i == '\"' || i == '\'')) {
            is_quote = true;
        } else if (is_quote && (i == '\"' || i == '\'')) {
            is_quote = false;
        } else if (!is_quote && i == ' ') {
            tokens.emplace_back("");
            token_num++;
        } else if (!is_quote && (i == '<' || i == '>' || i == '|')) {
            tokens.emplace_back(1, i);
            tokens.emplace_back("");
            token_num += 2;
        } else {
            tokens[token_num] = tokens[token_num] + i;
        }
    }
    tokens = clear_spaces(tokens);
    return tokens;
}

vector<string> Tokenizer::clear_spaces(vector<string> line) {
    for (unsigned long i = 0; i < line.size(); i++) {
        if (line[i].empty()) {
            line.erase(line.begin() + i);
        }
    }
    return line;
}
