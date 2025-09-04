#include <iostream>

using namespace std;

void fill_stack(int depth) {
    const size_t BUFFER_SIZE = 1024 * 100; // 100KB per call
    char buffer[BUFFER_SIZE];

    char sum;
    for (auto& byte : buffer) {
        sum += byte;
    }
    int KiB = depth * 100;

    std::cerr << KiB << "[KiB] Allocated in the stack" << endl;
    fill_stack(depth + 1);

}

int main() {
    fill_stack(1);
    return 0;
}