#ifndef CS312OOP_LAB1_MENU_HPP
#define CS312OOP_LAB1_MENU_HPP

#include <vector>
#include <iostream>
#include <functional>

namespace ui {
    template<class T>
    class Menu {
    public:
        /// Predefine Command.
        /// First arg - menu
        /// Second - object to change
        /// return string to print (command result)
        typedef std::string Command(Menu<T> &, T &);
        typedef std::pair<std::string, std::function<Command>> MenuOption;

    private:
        /// std::string - label
        std::vector<MenuOption> items;
        /// Managed object
        T managed;
        /// Input and output of the menu
        std::istream &in;
        std::ostream &out;
    public:
        explicit Menu(std::vector<MenuOption> options,
                      std::istream &input = std::cin, std::ostream &output = std::cout) : items(std::move(options)),
                                                                                          in(input), out(output) {}

        void run() {
            print_options();
            size_t cmd;
            try {
                while ((cmd = read_option())) {
                    eval_cmd(cmd);
                    print_options();
                }
            } catch (const std::runtime_error &e) {
                // read option or eval_cmd error
                throw e;
            }
        }

        void print_options() const {
            for (size_t i = 0; i < items.size(); ++i)
                out << i + 1 << ") " << items[i].first << std::endl;
            out << "0) Exit" << std::endl << std::endl;
        }

        [[nodiscard]] size_t read_option() const {
            size_t cmd;
            while ((cmd = prompt<size_t>("option")) > items.size())
                print("No such option");
            return cmd;
        }

        void eval_cmd(size_t cmd) {
            out << items[cmd - 1].second(*this, managed) << std::endl << std::endl;
        }

        /// One style read
        template<class K>
        K prompt(const char *mes) const {
            K value;
            do {
                out << "[" << mes << "]: ";
                in >> value;
                if (in.bad())
                    throw std::runtime_error("Menu read error");
                if (in.eof())
                    throw std::runtime_error("Found EOF while reading");
            } while (in.fail());
            return value;
        }

        /// One style print
        void print(const char *mes) const {
            out << ":" << mes << ":" << std::endl;
        }
    };
}

#endif //CS312OOP_LAB1_MENU_HPP
