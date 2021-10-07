#include "DeltoidMenu.hpp"

int main() {
    ui::Menu<curves::Deltoid> menu(deltoid_ui::menu_options());
    menu.run();
    return 0;
}