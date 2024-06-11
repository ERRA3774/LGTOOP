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

void PersonBase::Speak() const {

    std::vector<std::string> knownPhrases{
        "a^2 – b^2 = (a – b)(a + b)",
        "(a + b)^2 = a2 + 2ab + b2",
        "a^2 + b^2 = (a + b)^2 – 2ab",
        "(a – b)^2 = a^2 – 2ab + b^2",
        "(a + b + c)^2 = a^2 + b^2 + c^2 + 2ab + 2bc + 2ca",
        "(a – b – c)^2 = a^2 + b^2 + c^2 – 2ab + 2bc – 2ca",
        "(a + b)^3 = a^3 + 3a^2b + 3ab^2 + b^3",
        "(a – b)^3 = a^3 – 3a^2b + 3ab^2 – b^3",
        "a^3 – b^3 = (a – b)(a^2 + ab + b^2)",
        "a^3 + b^3 = (a + b)(a^2 – ab + b^2)",
        "(a + b)^4 = a^4 + 4a^3b + 6a^2b^2 + 4ab^3 + b^4",
        "(a – b)^4 = a^4 – 4a^3b + 6a^2b^2 – 4ab^3 + b^4",
        "a^4– b^4 = (a – b)(a + b)(a^2 + b^2)",
        "(a^m)(a^n) = a^m + n",
        "(ab)^m = a^mb^m",
        "(a^m)^n = a^mn",
    };

    // Asa se face un numar random folosind <random>
    std::random_device rd; // Ai un random device
    std::mt19937 gen(rd()); // Ai un generator
    std::uniform_int_distribution<> dis(0, knownPhrases.size() - 1); // Ai un range de distributie
    size_t randIdx = dis(gen); // O sa ne genereze un numar random

    std::cout << m_name << " says: '" << knownPhrases.at(randIdx) << '\'' << std::endl;
}

std::string PersonBase::Speak(const std::string& message) {

    std::unordered_map<std::string, std::string> answers{
        { {"a^2 – b^2"}, {"(a – b)(a + b)"} },
        { {"(a + b)^2"}, {"a2 + 2ab + b2"} },
        { {"a^2 + b^2"}, {"(a + b)^2 – 2ab"} },
        { {"(a – b)^2"}, {"a^2 – 2ab + b^2"} },
        { {"(a + b + c)^2"}, {"a^2 + b^2 + c^2 + 2ab + 2bc + 2ca"} },
        { {"(a – b – c)^2"}, {"a^2 + b^2 + c^2 – 2ab + 2bc – 2ca"} },
        { {"(a + b)^3"}, {"a^3 + 3a^2b + 3ab^2 + b^3"} },
        { {"(a – b)^3"}, {"a^3 – 3a^2b + 3ab^2 – b^3"} },
        { {"a^3 – b^3"}, {"(a – b)(a^2 + ab + b^2)"} },
        { {"a^3 + b^3"}, {"(a + b)(a^2 – ab + b^2)"} },
        { {"(a + b)^4"}, {"a^4 + 4a^3b + 6a^2b^2 + 4ab^3 + b^4"} },
        { {"(a – b)^4"}, {"a^4 – 4a^3b + 6a^2b^2 – 4ab^3 + b^4"} },
        { {"a^4– b^4"}, {"(a – b)(a + b)(a^2 + b^2)"} },
        { {"(a^m)(a^n)"}, {"a^m + n"} },
        { {"(ab)^m"}, {"a^mb^m"} },
        { {"(a^m)^n"}, {"a^mn"} }
    };

    std::string answer = "I don't know.";

    if (answers.find(message) != answers.end()) {
        answer = answers.at(message);
    }

    return answer;
}

void PersonBase::operator++() {
    ++m_age;
}

void PersonBase::operator++(int) {
    m_age++;
}

void PersonBase::IncreaseAge() {
    ++m_age;
}

void PersonBase::operator--() {
    --m_occupation;
}

void PersonBase::operator--(int) {
    m_occupation--;
}

void PersonBase::DecreaseOcupationScore() {
    --m_occupation;
}

std::ostream& operator<<(std::ostream& lhs, const PersonBase& rhs) {
    return lhs << "PersonBase: { name=" << rhs.m_name << ", " <<
           "age=" << rhs.m_age << ", " <<
           "occupation=" << rhs.m_occupation << " }";
}

std::string PersonBase::ToString() const {
    return std::string("PersonBase: { name=" + m_name + ", " +
        "age=" + std::to_string(m_age) + ", " +
        "occupation=" + std::to_string(m_occupation)) + " }";
}