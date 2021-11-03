#include <iostream>
#include <fstream>
#include <string>

#include "Container.h"

#define PORT "port.txt"

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