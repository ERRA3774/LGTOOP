#pragma once

#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>

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
    
    // Poate stie sa vorbeasca
    // Presupunem ca atunci cand doar vorbeste fara context, zice mereu un lucru random
    // si informatia e lasata in aer
    void Speak() const;

    // Poate stie sa vorbeasca in functie de contex
    // Presupunem ca daca stie sa raspunda la cateva formule matematica
    std::string Speak(const std::string& message);
    
    // Overloading de operatori
    // Functioneaza ca orice alta functie, putem specifica sa faca ce vrem noi
    // Presupunem ca operatorul ++ ii creste varsta
    void operator++(); // niciun parametru pentru ++obiect
    void operator++(int); // un parametru de tip int pentru obiect++

    // De ce functioneaza ca orice alta functie?
    // Pentru ca puteam face o functie care sa indeplineasca celasi lucru
    // De exemplu:
    
    void IncreaseAge();

    // Presupunem ca operatorul -- ii scade ocupatia
    void operator--();
    void operator--(int);

    void DecreaseOcupationScore();

    // Asta pentru atunci cand vrem sa folosim std::cout << obiect (si nu numai cout)
    friend std::ostream& operator<<(std::ostream& lhs, const PersonBase& rhs);

    std::string ToString() const;

private:
    // Astea toate se numesc proprietati

    std::string m_name;                                  // nume
    unsigned int m_age;                                  // varsta
    int   m_occupation;                                  // cu ce se ocupa
};

