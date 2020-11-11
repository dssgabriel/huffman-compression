#include "../lib/ArbreB.hpp"

int main() {
    Sommet s('a', 1.0);
    ArbreB a(&s);
    a.insert_right('b', 1.5);
    a.insert_left('c', 0.5);

    std::cout << a.get_root()->get_data() << ": " << a.get_root()->get_freq();
    std::cout << a.get_root()->get_right()->get_data() << ": " << a.get_root()->get_right()->get_freq();
    std::cout << a.get_root()->get_left()->get_data() << ": " << a.get_root()->get_left()->get_freq();

    return 0;
}
