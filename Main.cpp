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
    cout << "0) Exit." << endl;
    cout << "Enter your choice: ";
}

void ShowPort(){
    ifstream port (PORT);
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
    port.open(PORT, ofstream::app);
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
    port.open(PORT, ofstream::app);
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
    port.open(PORT, ofstream::app);
    if(port.is_open()){
        port << newRefrigeratedContainer.ToString() << endl;
    }else{
        perror("Can't open file");
    }
}