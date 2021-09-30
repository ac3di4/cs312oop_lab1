#include "matrix.hpp"

namespace math {
    Matrix::Matrix(size_t n, size_t m) : n(n), m(m), data(m) {}

    int Matrix::line_average(size_t i) const {
        int s = 0;
        for (size_t j = 0; j < n; ++j)
            s += get(i, j);
        return s / int(n);
    }

    int Matrix::line_sum_above_average(size_t i) const {
        int aver = line_average(i), s = 0;
        for (size_t j = 0; j < n; ++j) {
            int elem = get(i, j);
            s += elem > aver ? elem : 0;
        }
        return s;
    }

    std::ostream &operator<<(std::ostream &s, const Matrix &matrix) {
        s << "Size: " << matrix.n << "x" << matrix.m << std::endl << "Matrix: " << std::endl;
        for (size_t i = 0; i < matrix.m; ++i) {
            for (size_t j = 0; j < matrix.n; ++j)
                s << matrix.get(i, j) << " ";
            s << std::endl;
        }
        return s;
    }

    std::istream &operator>>(std::istream &s, Matrix &matrix) {
        for (size_t i = 0; i < matrix.m; ++i)
            for (size_t j = 0; j < matrix.n; ++j) {
                int n;
                s >> n;
                if (n != 0)
                    matrix.data[i][j] = n;
            }
        return s;
    }
}