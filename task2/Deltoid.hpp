#ifndef LAB01_DELTOID_HPP
#define LAB01_DELTOID_HPP

#include <utility>
#include <cmath>
#include <string>
#include <iomanip>

namespace curves {
    class Deltoid {
    private:
        /// bigger circle radius
        double r;
    public:
        explicit Deltoid(double r) : r(r) {}

        /// get r
        [[nodiscard]] double get() const {
            return r;
        }

        /// set r
        void set(double radius) {
            r = radius;
        }

        /// length of intersection of the area bounded by the tangent
        [[nodiscard]] double intersect_len() const {
            return (4.0 / 3.0) * r;
        }

        /// length of a curve
        [[nodiscard]] double len() const {
            return (16.0 / 3.0) * r;
        }

        /// area inside deltoid curve
        [[nodiscard]] double area() const {
            return (2.0 / 9.0) * M_PI * r * r;
        }

        /// get x y from t
        [[nodiscard]] std::pair<double, double> xy(double t) const {
            double inner = r / 3;
            return std::make_pair(
                    2 * inner * std::cos(t) + inner * std::cos(2 * t),
                    2 * inner * std::sin(t) - inner * std::sin(2 * t)
            );
        }

        /// cartesian equation
        [[nodiscard]] std::string equation() const {
            std::stringstream s;
            double inner = r / 3;
            s << std::setprecision(2) << "(x^2 + y^2)^2 + 8 * " << inner << " * x (x^2 - 3 * y^2) + 18 * " << inner
              << "^2 * (x^2 + y^2) - 27 * " << inner << "^4 = 0";
            return s.str();
        }
    };
}


#endif //LAB01_DELTOID_HPP
