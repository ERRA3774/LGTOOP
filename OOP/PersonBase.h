#pragma once

#include <string>

/*
    Luigi presupune ca fiecare persoana are:
        un nume
        o varsta
        o ocupatie

    Luigi o sa defineasca ocupatia ca un int momentan
*/

class PersonBase {
public:

/*
    Cand e vorba de POO in C++, exista o regula de aur care trebuies respectata la 
    clasele pe care le creezi. Se numeste the rule of fifth sau ceva de genul.
    Basically, boilerplate pe care trebuie sa il tii minte pe de rost si sa il scrii de
    fiecare data la o clasa
*/
    PersonBase(const PersonBase& other);                // Boilerplate item 1
    PersonBase(PersonBase&& other) noexcept;            // Boilerplate item 2

    PersonBase& operator=(const PersonBase& other);     // Boilerplate item 3
    PersonBase& operator=(PersonBase&& other) noexcept; // Boilerplate item 4

    ~PersonBase() = default;                            // Boilerplate item 5

private:
    std::string m_name;                                  // nume
    unsigned int m_age;                                  // varsta
    int   m_occupation;                                  // cu ce se ocupa
};




