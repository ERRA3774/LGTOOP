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