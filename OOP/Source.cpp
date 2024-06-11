#include <iostream>

#include "PersonBase.h"

int main() {

    PersonBase pb;

    pb.SetName("Marcel");
    pb.SetAge(19);
    pb.SetOccupation(0);

    std::cout << pb << std::endl;

    /*
    PersonBase: { name=Marcel, age=19, occupation=0 }
    */

    return 0;
}