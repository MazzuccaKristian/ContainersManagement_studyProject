#include "Container.h"

Container::Container(int IdCode, float Capacity){
    SetContainer(IdCode, Capacity);
}

void Container::SetContainer(int idCode, float capacity){
    IdCode = idCode;
    Capacity = capacity;
}

int Container::GetId(){
    return IdCode;
}

float Container::GetCapacity(){
    return Capacity;
}

string Container::ToString(){
    string line = "Id: " + std::to_string(this -> GetId()) + " Capacity: " + std::to_string(this -> GetCapacity());
    return line;
}