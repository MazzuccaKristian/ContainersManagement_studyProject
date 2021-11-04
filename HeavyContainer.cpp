#include "HeavyContainer.h"

HeavyContainer::HeavyContainer(int IdCode, float Capacity, float ExplosiveCapacity)
    : Container::Container(IdCode, Capacity){
    SetHeavyContainer(ExplosiveCapacity);
}

void HeavyContainer::SetHeavyContainer(float explosiveCapacity){
    ExplosiveCapacity = explosiveCapacity;
}

float HeavyContainer::GetExplosiveCapacity(){
    return ExplosiveCapacity;
}

string HeavyContainer::ToString(){
    string line = Container::ToString() + " Explosives: " + std::to_string(this -> GetExplosiveCapacity());
    return line;
}