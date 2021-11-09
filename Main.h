#include <iostream>
#include <fstream>
#include <string>

#include "Container.h"
#include "HeavyContainer.h"
#include "RefrigeratedContainer.h"
#include "Ship.h"

#define CONTAINERS "containers.txt"
#define SHIPS "ships.txt"

using std::cin;
using std::cout;
using std::perror;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

void ShowMainMenu();

void ShowPort();

void AddNewContainer();

void AddNewHeavyContainer();

void AddNewRefrigeratedContainer();

void AddNewShip();

void SaveShip(Ship* ship);