#include <iostream>
#include <string.h>
#include <vector>
#include <random>
#include <unordered_set>
#include <stack>
#include <unordered_map>

int firstUniqueSymbol(std::string str) {
    int pos = -1;
    std::unordered_map<char, int> map;

    for (int i = 0; i < str.length(); i++) {
        map[str[i]]++;
    }

    for (int i = 0; i < str.length(); i++) {
        if (map[str[i]] == 1) {
            return i;
        }
    }

    return pos;
}

int main() {

    std::cout << firstUniqueSymbol("leopard");

}