#include <string>

#include "HeavyContainer.h"

using std::string;

class RefrigeratedContainer : private HeavyContainer {
    private:
        float RefrigeratorCapacity;

    public:
        RefrigeratedContainer(int IdCode, float Capacity, float ExplosiveCapacity, float RefrigeratorCapacity);
        void SetRefrigeratedContainer(float refrigeratorCapacity);
        float GetRefrigeratorCapacity();
        string ToString();
};