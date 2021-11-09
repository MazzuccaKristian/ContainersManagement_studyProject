#include "Main.h"

int main(){
    bool isStillWorking = true;
    int userChoice;

    while(isStillWorking){
        ShowMainMenu();
        cin >> userChoice;
        switch(userChoice){
            case 0:
                cout << "Program ended. Please, wait..." << endl;
                isStillWorking = false;
                break;

            case 1:
                ShowPort();
                break;

            case 2:
                AddNewContainer();
                break;

            case 3:
                AddNewHeavyContainer();
                break;

            case 4:
                AddNewRefrigeratedContainer();
                break;

            case 5:
                AddNewShip();
                break;

            //TODO: Implements ships. Implements load/unload logic.
        }
    }
    return 0;
}

void ShowMainMenu(){
    cout << "MAIN MENU" << endl;
    cout << "1) Show port's detail;" << endl;
    cout << "2) Add new container;" << endl;
    cout << "3) Add new heavy container;" << endl;
    cout << "4) Add new refrigerated container;" << endl;
    cout << "5) Add new ship;" << endl;
    cout << "0) Exit." << endl;
    cout << "Enter your choice: ";
}

void ShowPort(){
    ifstream port (CONTAINERS);
    if(port.is_open()){
        string line;
        cout << endl;
        while(getline(port, line)){
            cout << line << endl;
        }
        cout << endl;
    }else{
        perror("Can't open file");
    }
}

void AddNewContainer(){
    int id;
    float capacity;
    ofstream port;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter max capacity: ";
    cin >> capacity;
    Container newContainer(id, capacity);
    port.open(CONTAINERS, ofstream::app);
    if(port.is_open()){
        port << newContainer.ToString() << endl;
    }else{
        perror("Can't open file");
    }
    port.close();
}

void AddNewHeavyContainer(){
    ofstream port;
    int id;
    float capacity, explCapacity;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter max capacity: ";
    cin >> capacity;
    cout << "Enter max capacity (explosives): ";
    cin >> explCapacity;
    HeavyContainer newHeavyContainer(id, capacity, explCapacity);
    port.open(CONTAINERS, ofstream::app);
    if(port.is_open()){
        port << newHeavyContainer.ToString() << endl;
    }else{
        perror("Can't open file");
    }
    port.close();
}

void AddNewRefrigeratedContainer(){
    ofstream port;
    int id;
    float capacity, explCapacity, refrigCapacity;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter max capacity: ";
    cin >> capacity;
    cout << "Enter max capacity (explosives): ";
    cin >> explCapacity;
    cout << "Enter max capacity (refrigerator): ";
    cin >> refrigCapacity;
    RefrigeratedContainer newRefrigeratedContainer(id, capacity, explCapacity, refrigCapacity);
    port.open(CONTAINERS, ofstream::app);
    if(port.is_open()){
        port << newRefrigeratedContainer.ToString() << endl;
    }else{
        perror("Can't open file");
    }
    port.close();
}

void AddNewShip(){
    int id, maxContainers;
    bool explosive = false, refrigerator = false;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter max containers: ";
    cin >> maxContainers;
    cout << "Can it ship explosives? [y/n]: ";
    cin.ignore();
    char temp1 = std::getchar();
    if(temp1 == 'y' || temp1 == 'Y'){
        explosive = true;
    }
    cin.ignore();
    cout << "Can it ship refrigerated containers? [y/n]: ";
    char temp2 = std::getchar();
    if(temp2 == 'y' || temp2 == 'Y'){
        refrigerator = true;
    }
    Ship newShip(id, maxContainers, explosive, refrigerator);
    SaveShip(&newShip);
}

void SaveShip(Ship* ship){
    ofstream ships;
    ships.open(SHIPS, ofstream::app);
    if(ships.is_open()){
        ships << "CHECK" << endl;
    }else{
        perror("Can't open file");
    }
    ships.close();
}