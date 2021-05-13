#include <iostream>
#include <string>

using namespace std;


class WaterTank {
private:
    float amount;

    bool boil(float amountToBoil) {
        if (amount >= amountToBoil) {
            cout << "Boiling water..." << endl;
            return true;
        } else {
            return false;
        }
    }
public:
    WaterTank(float amount) : amount(amount) {};

    void pour(float amountToPour) {
        bool isBoiled = boil(amountToPour);
        if (amount >= amountToPour && isBoiled) {
            cout << "Pouring water..." << endl;
        } else {
            cout << "You have to fill water tank!" << endl;
        }
    }
};

class SugarContainer {
private:
    float amount;
public:
    SugarContainer(float amount) : amount(amount) {};

    void pour(float amountOfSugar) {
        if (amount >= amountOfSugar) {
            cout << "Pouring " << amountOfSugar << " grams of sugar..." << endl;
        } else {
            cout << "You have to fill sugar container!" << endl;
        }

    }
};

class MilkTank {
private:
    float amount;
public:
    MilkTank(float amount) : amount(amount) {};

    void pour(float amountToPour) {
        if (amount >= amountToPour) {
            cout << "Pouring milk..." << endl;
        } else {
            cout << "You have to fill milk tank!" << endl;
        }
    }
};

class CoffeeBeansContainer {
private:
    float amount;
public:
    CoffeeBeansContainer(float amount) : amount(amount) {};

    bool fillGrinder() {
        if (amount > 0) {
            cout << "Pouring coffee to grinder..." << endl;
            return true;
        } else {
            cout << "You have to fill coffee beans container!" << endl;
            return false;
        }
    }
};

class CoffeeGrinder {
private:
    CoffeeBeansContainer coffeeBeansContainer = CoffeeBeansContainer(100);
public:
    void grindCoffee(string coffeeType) {
        bool isFilled = coffeeBeansContainer.fillGrinder();
        if (isFilled) {
            if (coffeeType == "strong") {
                cout << "Grinding " << 15 << " grams of coffee beans..." << endl;
            } else if (coffeeType == "normal") {
                cout << "Grinding " << 10 << " grams of coffee beans..." << endl;
            } else {
                cout << "Grinding " << 5 << " grams of coffee beans..." << endl;
            }
            cout << "Pouring ground coffee..." << endl;
        }

    }
};

class CoffeeMachine {
private:
    CoffeeGrinder grinder = CoffeeGrinder();
    MilkTank milkTank = MilkTank(100);
    SugarContainer sugarContainer = SugarContainer(100);
    WaterTank waterTank = WaterTank(100);
public:
    bool makeCoffee(string coffeeType, float amountOfSugar, bool milk) {
        grinder.grindCoffee(coffeeType);
        sugarContainer.pour(amountOfSugar);
        waterTank.pour(0.35);
        if (milk) {
            milkTank.pour(0.15);
        }
        cout << "Done!" << endl;
        return true;
    }
};

class User {
private:
    CoffeeMachine* cm;
public:
    User(CoffeeMachine* cm) {
        this->cm = cm;
    };
    bool makeCoffee() {
        string type;
        short milk;
        float sugarAmount;
        cout << "Choose type strong/normal/weak:" << endl;
        cin >> type;
        cout << "Do you want milk? 0/1: " << endl;
        cin >> milk;
        cout << "How much sugar do you want (in grams)? " << endl;
        cin >> sugarAmount;
        bool done = cm->makeCoffee(type, sugarAmount, milk);
        return done;
    }

    void takeCoffee() {
        cout << "Thank you for using our Coffee Machine!" << endl;
    }
};


int main() {
    CoffeeMachine *coffeeMachine = new CoffeeMachine();
    User user = User(coffeeMachine);
    bool done = user.makeCoffee();
    if (done) {
        user.takeCoffee();
    }
    return 0;
}
