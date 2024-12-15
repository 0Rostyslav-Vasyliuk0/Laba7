#include "Student.h"

int main() {
    Student group;

    group.inputData();
    std::cout << "\nСписок студентів:" << std::endl;
    group.outputData();

    std::cout << "\nПошук студентів за вулицею:" << std::endl;
    group.findByStreet();

    std::cout << "\nОновлений список студентів:" << std::endl;
    group.outputData();

    return 0;
}
