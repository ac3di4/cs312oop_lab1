#ifndef CS312OOP_LAB1_DELTOIDMENU_HPP
#define CS312OOP_LAB1_DELTOIDMENU_HPP

#include "Deltoid.hpp"
#include "Menu.hpp"

using curves::Deltoid;
using Menu = ui::Menu<Deltoid>;

namespace deltoid_ui {
    /// convert double to str with precision = 2
    static std::string double_to_str(double value) {
        std::stringstream out;
        out << std::setprecision(2) << value;
        return out.str();
    }

    std::string command_set(Menu &m, Deltoid &managed) {
        double r;
        while ((r = m.prompt<double>("Bigger circle radius")) < 0)
            m.print("Value must be grater or equal than 0");
        managed.set(r);
        return {"Ok"};
    }

    std::string command_parameter(Menu &m, Deltoid &managed) {
        auto t = m.prompt<double>("Parameter t");
        auto xy = managed.xy(t);
        std::stringstream out;
        out << std::setprecision(2) << xy.first << " " << xy.second;
        return out.str();
    }

    std::vector<Menu::MenuOption> menu_options() {
        static std::vector<Menu::MenuOption> inner{
            {
                "Get (bigger circle radius)",
                [](Menu &_m, Deltoid &d) { return double_to_str(d.get()); }
            },
            {
                "Set (bigger circle radius)",
                command_set
            },
            {
                "Tangent intersection length",
                [](Menu &_m, Deltoid &d) { return double_to_str(d.intersect_len()); }
            },
            {
                "Deltoid length",
                [](Menu &_m, Deltoid &d) { return double_to_str(d.len()); }
            },
            {
                "Deltoid area",
                [](Menu &_m, Deltoid &d) { return double_to_str(d.area()); }
            },
            {
                "Get xy from parameter",
                command_parameter
            },
            {
                "Cartesian equation",
                [](Menu &_m, Deltoid &d) { return d.equation(); }
            }
        };
        return inner;
    }
}


#endif //CS312OOP_LAB1_DELTOIDMENU_HPP
