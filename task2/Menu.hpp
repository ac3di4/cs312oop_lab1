#ifndef CS312OOP_LAB1_MENU_HPP
#define CS312OOP_LAB1_MENU_HPP

#include <vector>
#include <iostream>

namespace ui {
    template <class T>
    class BaseCommand {
    public:
        /// read additional parameters from input
        virtual std::string eval(T &managed) = 0;
    };

    template <class T>
    class BaseMenuOption {
    protected:
        std::string label;
    public:
        explicit BaseMenuOption(const char *label) : label(std::string(label)) {}
        explicit BaseMenuOption(std::string &label) : label(label) {}

        [[nodiscard]] std::string get_label() const { return label; }

        virtual BaseCommand<T> *spawn() const = 0;

        std::string eval(T &managed) const {
            BaseCommand<T> *cmd = spawn();
            std::string result = cmd->eval(managed);
            delete cmd;
            return result;
        }
    };

    /// generic menu class for different menu commands options and uses
    /// easily extended, written for menu for one object.
    /// potentially options can be changed in runtime
    template <class T>
    class Menu {
    private:
        std::vector<BaseMenuOption<T> *> items;
        /// Managed object
        T managed;
    public:
        explicit Menu(std::vector<BaseMenuOption<T> *> &items) : items(items) {}

        template<class K>
        static K prompt(const char *mes) {
            K value;
            do {
                std::cout << "[" << mes << "]: ";
                std::cin >> value;
                if (std::cin.bad())
                    throw std::runtime_error("Read error");
                if (std::cin.eof())
                    throw std::runtime_error("Found EOF while reading");
            } while (std::cin.fail());
            return value;
        }

        void run() {
            size_t cmd = 0;
            while (true) {
                for (size_t i = 0; i < items.size(); ++i)
                    std::cout << i + 1 << ") " << items[i]->get_label() << std::endl;
                std::cout << "0) Exit" << std::endl << std::endl;

                while ((cmd = Menu<T>::template prompt<size_t>("option")) > items.size()) {}

                if (cmd == 0)
                    break;
                else
                    std::cout << items[cmd - 1]->eval(managed) << std::endl << std::endl;
            };
        }
    };
}


#endif //CS312OOP_LAB1_MENU_HPP
