#include <string>

using std::string;

class Container{
    private:
        int IdCode;
        float Capacity;

    public:
        Container(int idCode, float capacity);
        void SetContainer(int idCode, float capacity);
        int GetId();
        float GetCapacity();
        string ToString();
};