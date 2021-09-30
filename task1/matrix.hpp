#ifndef LAB01_MATRIX_HPP
#define LAB01_MATRIX_HPP

#include <unordered_map>
#include <vector>
#include <iostream>


namespace math {
    class Matrix {
    private:
        size_t n, m;
        // data[row][col] -> item
        std::vector<std::unordered_map<size_t, int>> data;
    public:
        Matrix(size_t, size_t);

        [[nodiscard]] int get(size_t i, size_t j) const {
            // check bounds
            if (!(i < m && j < n))
                throw std::out_of_range("Out of matrix size");
            // not [] and contains because we need read-only
            try {
                return data.at(i).at(j);
            } catch (const std::out_of_range &e) {
                return 0;
            }
        }

        [[nodiscard]] int line_average(size_t) const;

        [[nodiscard]] int line_sum_above_average(size_t) const;

        friend std::ostream &operator<<(std::ostream &, const Matrix &);

        friend std::istream &operator>>(std::istream &, Matrix &);
    };
}


#endif //LAB01_MATRIX_HPP
