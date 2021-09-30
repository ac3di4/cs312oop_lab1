#include <iostream>
#include <iomanip>

#include "Deltoid.hpp"

using curves::Deltoid;

int main() {
    // dialog program
    std::cout << "Deltoid bigger circle radius R=3r=";
    double r;
    std::cin >> r;
    if (!std::cin.good() || r < 0)
        return -1;

    Deltoid d(r);
    std::cout << std::setprecision(2)
              << "Intersection with tangent length: " << d.intersect_len() << std::endl
              << "Curve length: " << d.len() << std::endl
              << "Curve area: " << d.area() << std::endl
              << "Cartesian equation: " << d.equation() << std::endl;

    std::cout << "Enter t parameter: ";
    double t;
    std::cin >> t;
    if (!std::cin.good())
        return -1;

    auto pos = d.xy(t);
    std::cout << "Deltoid curve coordinates for t=" << t
              << ": (" << pos.first << ", " << pos.second << ")" << std::endl;

    return 0;
}
