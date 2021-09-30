#include <iostream>
#include <vector>

#include "matrix.hpp"


using math::Matrix;

int main() {
    // read matrix size
    std::cout << "[matrix size]: ";
    size_t n, m;
    std::cin >> n >> m;
    if (!std::cin.good())
        return -1;

    // read matrix
    std::cout << "[matrix]:" << std::endl;
    Matrix matrix(n, m);
    std::cin >> matrix;
    if (!std::cin.good())
        return -1;

    // vector is not a sparse matrix (so it's not Matrix)
    std::vector<int> vec(m);
    for (size_t i = 0; i < m; ++i)
        vec[i] = matrix.line_sum_above_average(i);

    // print all
    std::cout << matrix << "Vector:" << std::endl;
    for (auto e: vec)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}