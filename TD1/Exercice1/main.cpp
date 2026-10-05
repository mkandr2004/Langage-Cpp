#include <iostream>

#include "function.h"
#include "My_class.h"

int main() {
    print_string("Hello World !");

    My_class objet("Hello World !");
    objet.print_my_element();

    return 0;
}
