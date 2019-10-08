#include "Vector.h"
#include <fstream>
#include <random>
#include <algorithm>

int main() {
    Vector<std::ofstream *> streams;
    const int numStreams = 10;

    for (int i = 0; i < numStreams; i++) {
        std::ofstream *out = new std::ofstream;
        std::string fileName = std::to_string(i);
        out->open(fileName.c_str());
        streams.push_back(out);
    }

    shuffle(streams.begin(), streams.end(), std::random_device());

    int i = 0;
    for (auto stream : streams) {
        (*stream) << i;
        stream->close();
        delete stream;
        i++;
    }

    return 0;
}
