#include <iostream>
#include <omp.h>
#include <chrono>
#include <cmath>

int main() {
    int num_threads = omp_get_max_threads();
    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel num_threads(num_threads)
    {

        double result = 0.0;
        for (long long i = 0; i < 3 * 1e8; ++i) {
            result += std::sin(i) * std::cos(i);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Execution time: "
              << std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
              << " seconds\n";

    return 0;
}
