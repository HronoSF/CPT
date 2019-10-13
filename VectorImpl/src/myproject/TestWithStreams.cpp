#include "Vector.h"
#include <fstream>
#include <random>
#include <algorithm>

int main() {
    Vector<std::ofstream> streams;
    for (int i = 1; i < 11; i++) {
        std::string nameOfCurrentStream = std::to_string(i) + ".txt";
        streams.push_back(std::ofstream(nameOfCurrentStream));
    }
    shuffle(streams.begin(), streams.end(), std::random_device());
    int j = 1;
    for (auto &currentStream: streams) {
        currentStream << j;
        currentStream.close();
        j++;
    }
    return 0;
}
