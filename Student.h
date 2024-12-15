#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

// Структура для зберігання інформації про студента
struct StudentInfo {
    int id;
    std::string name;
    std::string address;
    std::string street;
    int houseNumber;
};

// Клас для управління студентами
class Student {
private:
    std::vector<StudentInfo> students; // Список студентів
    int nextId = 1;                    // Наступний доступний ID

public:
    Student();
    ~Student();

    void inputData();                 // Введення даних
    void outputData() const;          // Виведення даних
    void addStudent();                // Додавання студента
    void insertStudent(int position); // Вставка студента на позицію
    void clearStudents();             // Очищення списку студентів
    void findByStreet() const;        // Пошук студентів за вулицею

private:
    void setStudentData(StudentInfo& student); // Встановлення даних для студента
    bool validateHouseNumber(int houseNumber) const; // Перевірка номера будинку
    std::string getValidatedString(const std::string& prompt, bool allowNumbers = true, bool numbersOnly = false) const;
    int getValidatedNumber(const std::string& prompt) const;
};

#endif
