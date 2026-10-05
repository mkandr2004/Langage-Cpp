#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>

class My_class {
private:
    std::string element;

public:
    My_class();
    My_class(std::string valeur);

    void print_my_element();
};

#endif
