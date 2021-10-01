#ifndef CS312OOP_LAB1_DELTOIDMENU_HPP
#define CS312OOP_LAB1_DELTOIDMENU_HPP

#include "Deltoid.hpp"
#include "Menu.hpp"

using curves::Deltoid;

namespace deltoid_ui {
    class CommandGet : public ui::BaseCommand<Deltoid> {
    public:
        std::string eval(Deltoid &managed) override {
            std::stringstream out;
            out << std::setprecision(2) << managed.get();
            return out.str();
        }
    };

    class MenuOptionGet : public ui::BaseMenuOption<Deltoid> {
    public:
        explicit MenuOptionGet() : BaseMenuOption("Get (bigger circle radius)") {}
        [[nodiscard]] CommandGet *spawn() const override {
            return new CommandGet();
        }
    };

    class CommandSet : public ui::BaseCommand<Deltoid> {
    public:
        std::string eval(Deltoid &managed) override {
            double r;
            while ((r = ui::Menu<Deltoid>::prompt<double>("Bigger circle radius")) < 0) {}
            managed.set(r);
            return std::string("Ok");
        }
    };

    class MenuOptionSet : public ui::BaseMenuOption<Deltoid> {
    public:
        explicit MenuOptionSet() : BaseMenuOption("Set (bigger circle radius)") {}
        [[nodiscard]] CommandSet *spawn() const override {
            return new CommandSet();
        }
    };

    static std::vector<ui::BaseMenuOption<Deltoid> *> menu_options = {
            new MenuOptionGet,
            new MenuOptionSet
    };
}


#endif //CS312OOP_LAB1_DELTOIDMENU_HPP
