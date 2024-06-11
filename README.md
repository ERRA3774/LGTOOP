# OOP

PersonBase.h

```cpp

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

    // Dupa ce am scapat de boilerplate, ar trebui sa creem un constructor default
    // unde initializam fiecare variabila cu ceva default
    PersonBase();

    // Si inca un constructor unde initializam fiecare proprietate

    PersonBase(const std::string& name, unsigned int age, int occupation);

    // Dupa ce avem constructori, ar fii ok sa putem avea drepturi de citire si scriere
    // asupra proprietatilor. Adica getteri si setteri

    std::string GetName() const; // returneaza o copie si functia nu modifica nimic, deci o declaram const
    void SetName(const std::string& name);

    unsigned int GetAge() const; 
    void SetAge(unsigned int age);

    int GetOccupation() const; 
    void SetOccupation(int occupation);

    // Acum, cum e normal in POO, trebuie sa ne gandim la ce stie sa faca o persoana
    // Poate stie sa faca o persoana

private:
    // Astea toate se numesc proprietati

    std::string m_name;                                  // nume
    unsigned int m_age;                                  // varsta
    int   m_occupation;                                  // cu ce se ocupa
};


```

PersonBase.cpp

```cpp

#include "PersonBase.h"

// Chesiile astea trebuie invatate pe de rost:

PersonBase::PersonBase(const PersonBase& other) {
    *this = other;
}

PersonBase::PersonBase(PersonBase&& other) noexcept {
    *this = std::move(other);
}

PersonBase& PersonBase::operator=(const PersonBase& other) {
    if (this != &other) {
        m_name = other.m_name;
        m_age = other.m_age;
        m_occupation = other.m_occupation;
    }

    return *this;
}

PersonBase& PersonBase::operator=(PersonBase&& other) noexcept {
    if (this != &other) {
        // parametrul 2 e valoare de reset pentru functia std::exchange. Poate sa fie ce vreti voi sa fie valoare de reset
        m_name = std::exchange(other.m_name, std::string());
        m_age = std::exchange(other.m_age, 0);
        m_occupation = std::exchange(other.m_occupation, 0);
    }

    return *this;
}

/*

~PersonBase() = default;

Inseamna asta:

PersonBase::~PersonBase() {

}

Definesc un destructor care nu face nimic
Destructorul e apelat atunci cand o instanta a unui obiect iese din scope
*/

PersonBase::PersonBase() :
    m_name{}, m_age{}, m_occupation{} {

}

PersonBase::PersonBase(const std::string& name, unsigned int age, int occupation) :
    m_name{ name }, m_age{ age }, m_occupation{ occupation } {

}

std::string PersonBase::GetName() const {
    return m_name;
}

void PersonBase::SetName(const std::string& name) {
    m_name = name;
}

unsigned int PersonBase::GetAge() const {
    return m_age;
}

void PersonBase::SetAge(unsigned int age) {
    m_age = age;
}

int PersonBase::GetOccupation() const {
    return m_occupation;
}

void PersonBase::SetOccupation(int occupation) {
    m_occupation = occupation;
}

```
