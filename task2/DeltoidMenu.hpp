#ifndef CS312OOP_LAB1_DELTOIDMENU_HPP
#define CS312OOP_LAB1_DELTOIDMENU_HPP

#include "Deltoid.hpp"
#include "Menu.hpp"

using curves::Deltoid, ui::BaseCommand, ui::BaseMenuOption;

namespace deltoid_ui {
    static std::string double_to_str(double value) {
        std::stringstream out;
        out << std::setprecision(2) << value;
        return out.str();
    }

    class CommandGet : public BaseCommand<Deltoid> {
    public:
        std::string eval(Deltoid &managed) override {
            return double_to_str(managed.get());
        }
    };

    class MenuOptionGet : public BaseMenuOption<Deltoid> {
    public:
        explicit MenuOptionGet() : BaseMenuOption("Get (bigger circle radius)") {}
        [[nodiscard]] CommandGet *spawn() const override {
            return new CommandGet();
        }
    };

    class CommandSet : public BaseCommand<Deltoid> {
    public:
        std::string eval(Deltoid &managed) override {
            double r;
            while ((r = ui::Menu<Deltoid>::prompt<double>("Bigger circle radius")) < 0)
                std::cout << "Value must be greater or equal than 0" << std::endl;
            managed.set(r);
            return {"Ok"};
        }
    };

    class MenuOptionSet : public BaseMenuOption<Deltoid> {
    public:
        explicit MenuOptionSet() : BaseMenuOption("Set (bigger circle radius)") {}
        [[nodiscard]] CommandSet *spawn() const override {
            return new CommandSet();
        }
    };

    class CommandIntersect : public BaseCommand<Deltoid> {
    public:
        std::string eval(Deltoid &managed) override {
            return double_to_str(managed.intersect_len());
        }
    };

    class MenuOptionIntersect : public BaseMenuOption<Deltoid> {
    public:
        explicit MenuOptionIntersect() : BaseMenuOption("Tangent intersection length") {}
        [[nodiscard]] CommandIntersect *spawn() const override {
            return new CommandIntersect();
        }
    };

    class CommandLen : public BaseCommand<Deltoid> {
    public:
        std::string eval(Deltoid &managed) override {
            return double_to_str(managed.len());
        }
    };

    class MenuOptionLen : public BaseMenuOption<Deltoid> {
    public:
        explicit MenuOptionLen() : BaseMenuOption("Deltoid length") {}
        [[nodiscard]] CommandLen *spawn() const override {
            return new CommandLen();
        }
    };

    class CommandArea : public BaseCommand<Deltoid> {
    public:
        std::string eval(Deltoid &managed) override {
            return double_to_str(managed.area());
        }
    };

    class MenuOptionArea : public BaseMenuOption<Deltoid> {
    public:
        explicit MenuOptionArea() : BaseMenuOption("Deltoid area") {}
        [[nodiscard]] CommandArea *spawn() const override {
            return new CommandArea();
        }
    };

    class CommandParameter : public BaseCommand<Deltoid> {
    public:
        std::string eval(Deltoid &managed) override {
            double t;
            while ((t = ui::Menu<Deltoid>::prompt<double>("Parameter t")) < 0) {}
            auto xy = managed.xy(t);
            std::stringstream out;
            out << std::setprecision(2) << xy.first << " " << xy.second;
            return out.str();
        }
    };

    class MenuOptionParameter : public BaseMenuOption<Deltoid> {
    public:
        explicit MenuOptionParameter() : BaseMenuOption("Get xy from parameter") {}
        [[nodiscard]] CommandParameter *spawn() const override {
            return new CommandParameter();
        }
    };


    class CommandEquation : public BaseCommand<Deltoid> {
    public:
        std::string eval(Deltoid &managed) override {
            return managed.equation();
        }
    };

    class MenuOptionEquation : public BaseMenuOption<Deltoid> {
    public:
        explicit MenuOptionEquation() : BaseMenuOption("Cartesian equation") {}
        [[nodiscard]] CommandEquation *spawn() const override {
            return new CommandEquation();
        }
    };

    static std::vector<ui::BaseMenuOption<Deltoid> *> menu_options = {
            new MenuOptionGet(),
            new MenuOptionSet(),
            new MenuOptionIntersect(),
            new MenuOptionLen(),
            new MenuOptionArea(),
            new MenuOptionParameter(),
            new MenuOptionEquation()
    };
}


#endif //CS312OOP_LAB1_DELTOIDMENU_HPP
