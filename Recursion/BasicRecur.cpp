#include <iostream>
#include<chrono>
using  std::cout;
using namespace std::chrono;

void recur(int a) {
    if (a  == 0)
        return;
    
    cout << a << '\n';
    recur(a - 1);
}


int main() {
    
    auto start = high_resolution_clock::now();
    recur(5);
    auto end = high_resolution_clock::now();
    auto result = duration_cast<nanoseconds>(end-start);
    
    cout << '\n' << "Execution time: " << result.count() << "ns "  << '\n';
    return 0;
}
