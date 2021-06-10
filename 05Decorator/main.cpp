#include <iostream>
#include <vector>

using namespace std;

class IBIOS {
public:
    virtual void runSystem() = 0;
};

class BIOS : public IBIOS {
public:
    void runSystem() override {
        cout << "Running system: ";
    }
};

class BIOSDecorator : public IBIOS {
public:
    BIOS* biosInterface;
    explicit BIOSDecorator(BIOS* biosInterface) {
        this->biosInterface = biosInterface;
    }
    void runSystem() override {
        biosInterface->runSystem();
    }
};

class Linux : public BIOSDecorator {
public:
    explicit Linux(BIOS *biosInterface) : BIOSDecorator(biosInterface) {}

    void runSystem() override {
        BIOSDecorator::runSystem();
        cout << "Linux" << endl;
    }
};

class Mac : public BIOSDecorator {
public:
    explicit Mac(BIOS *biosInterface) : BIOSDecorator(biosInterface) {}

    void runSystem() override {
        BIOSDecorator::runSystem();
        cout << "Mac" << endl;
    }
};

class Windows : public BIOSDecorator {
public:
    explicit Windows(BIOS *biosInterface) : BIOSDecorator(biosInterface) {}

    void runSystem() override {
        BIOSDecorator::runSystem();
        cout << "Windows" << endl;
    }
};


int main() {
    vector<IBIOS*> operating_systems;
    IBIOS *linux = new Linux(new BIOS());
    operating_systems.push_back(linux);
    IBIOS *windows = new Windows(new BIOS());
    operating_systems.push_back(windows);
    IBIOS *mac = new Mac(new BIOS());
    operating_systems.push_back(mac);
    for (auto s : operating_systems) {
        s->runSystem();
    }
    return 0;
}
