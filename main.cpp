#include <iostream>
#include "point.h"
#include "fcollection.h"
#include "figure.h"
#include "pentagon.h"
#include "rhombus.h"
#include "hexagon.h"

int main(){
    FigureCollection FC;
    Pentagon P;
    Rhombus R;
    Hexagon H;
    std::cout << "Pentagon\n";
    std::cin >> P;
    std::cout << "Hexagon\n";
    std::cin >> H;
    std::cout << " Rhombus\n";
    std::cin >> R;
    FC.pushBack(&P);
    FC.pushBack(&R);
    FC.pushBack(&H);
    FC.displayGCenters();
    std::cout << std::endl;
    FC.displayAreas();
    std::cout << std::endl;
    std::cout << "SUM AREA = " << FC.getAllArea() <<std::endl;
    std::cout << FC;

    return 0;
}