#include "corr_common.h"
#include "signal.h"
#include <chrono>
#include <iostream>

using namespace params;

int main() {
    auto sig1 = generate_signal(harm, freq, inter, dt);
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    print_correlation(sig1, sig1);
    auto stop = high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<microseconds>(stop - start);
    std::cerr << "Calculated by " << duration.count() << "μs\n";
}
