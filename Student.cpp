#include "Student.h"
#include <algorithm> // Для std::find_if

Student::Student() {
    std::cout << "Конструктор викликано." << std::endl;
}

Student::~Student() {
    std::cout << "Деструктор викликано." << std::endl;
}

void Student::inputData() {
    int count = getValidatedNumber("Скільки студентів потрібно додати? ");
    for (int i = 0; i < count; ++i) {
        addStudent();
    }
}

void Student::outputData() const {
    if (students.empty()) {
        std::cout << "Список студентів порожній." << std::endl;
        return;
    }

    for (const auto& s : students) {
        std::cout << "\n--- Інформація про студента ---\n";
        std::cout << "ID: " << s.id << std::endl;
        std::cout << "Ім'я: " << s.name << std::endl;
        std::cout << "Поштова адреса: " << s.address << std::endl;
        std::cout << "Вулиця: " << s.street << std::endl;
        std::cout << "Номер будинку: " << s.houseNumber << std::endl;
    }
}

void Student::addStudent() {
    StudentInfo student;
    student.id = nextId++;
    setStudentData(student);
    students.push_back(student);
}

void Student::insertStudent(int position) {
    if (position < 0 || position > students.size()) {
        std::cerr << "Помилка: некоректна позиція для вставки." << std::endl;
        return;
    }

    StudentInfo student;
    student.id = nextId++;
    setStudentData(student);
    students.insert(students.begin() + position, student);
}

void Student::clearStudents() {
    students.clear();
    std::cout << "Список студентів очищено." << std::endl;
}

void Student::setStudentData(StudentInfo& student) {
    student.name = getValidatedString("Введіть ім'я студента: ", false);
    student.address = getValidatedString("Введіть поштову адресу студента: ", true, true);
    student.street = getValidatedString("Введіть вулицю студента: ", false);
    student.houseNumber = getValidatedNumber("Введіть номер будинку студента: ");
}

bool Student::validateHouseNumber(int houseNumber) const {
    return houseNumber > 0;
}

std::string Student::getValidatedString(const std::string& prompt, bool allowNumbers, bool numbersOnly) const {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);

        bool hasInvalidCharacters = false;

        if (numbersOnly) {
            for (char c : input) {
                if (!std::isdigit(c)) {
                    hasInvalidCharacters = true;
                    break;
                }
            }
            if (input.empty() || std::stoi(input) <= 0) {
                hasInvalidCharacters = true;
            }
        } else if (!allowNumbers) {
            for (char c : input) {
                if (std::isdigit(c)) {
                    hasInvalidCharacters = true;
                    break;
                }
            }
        }

        if (!input.empty() && input.find_first_not_of(' ') != std::string::npos && !hasInvalidCharacters) {
            return input;
        }

        std::cerr << "Помилка: введення не може бути порожнім або некоректним. Спробуйте ще раз." << std::endl;
    }
}

int Student::getValidatedNumber(const std::string& prompt) const {
    int number;
    while (true) {
        std::cout << prompt;
        if (std::cin >> number && number > 0) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return number;
        }
        std::cerr << "Помилка: введене число має бути додатнім. Спробуйте ще раз." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void Student::findByStreet() const {
    std::string street = getValidatedString("Введіть назву вулиці для пошуку: ", false);

    bool found = false;
    for (const auto& s : students) {
        if (s.street == street) {
            std::cout << "Знайдено студента: " << s.name
                      << ", Поштова адреса: " << s.address
                      << ", Номер будинку: " << s.houseNumber << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "На цій вулиці немає студентів." << std::endl;
    }
}