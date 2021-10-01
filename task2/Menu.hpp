#ifndef CS312OOP_LAB1_MENU_HPP
#define CS312OOP_LAB1_MENU_HPP

#include <vector>
#include <iostream>

namespace ui {
    /// Command for evaluation
    /// Call Menu::prompt for reading additional parameters
    template <class T>
    class BaseCommand {
    public:
        virtual std::string eval(T &managed) = 0;
    };

    /// Command Evaluator. Needed for extensibility
    /// Inherit, make constructor and override spawn
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

    /// Universal menu class;
    /// easily extended, written for menu for one object, reading from stdin&stdout
    /// potentially options can be changed in runtime
    ///
    /// For creating commands inherit from BaseMenuOption,
    /// BaseCommand and use fabric pattern
    template <class T>
    class Menu {
    private:
        std::vector<BaseMenuOption<T> *> items;
        /// Managed object
        T managed;
    public:
        explicit Menu(std::vector<BaseMenuOption<T> *> &items) : items(items) {}

        /// promp input from cin using cout
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
            print_options();
            size_t cmd;
            // it stops if it's zero
            while ((cmd = read_option()))
                eval_cmd(cmd);
        }

        void print_options() const {
            for (size_t i = 0; i < items.size(); ++i)
                std::cout << i + 1 << ") " << items[i]->get_label() << std::endl;
            std::cout << "0) Exit" << std::endl << std::endl;
        }

        [[nodiscard]] size_t read_option() const {
            size_t cmd;
            while ((cmd = Menu<T>::template prompt<size_t>("option")) > items.size())
                std::cout << "No such option." << std::endl;
            return cmd;
        }

        void eval_cmd(size_t cmd) {
            std::cout << items[cmd - 1]->eval(managed) << std::endl << std::endl;
        }
    };
}


#endif //CS312OOP_LAB1_MENU_HPP
