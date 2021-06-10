#include <iostream>
#include <vector>

using namespace std;

class IPrintable {
public:
    virtual void print() = 0;
};

class ToPrint : public IPrintable {
private:
    vector<IPrintable*> printable;
public:
    ToPrint() = default;
    void print() override {
        for (auto p : this->printable) {
            p->print();
        }
    }

    void add(IPrintable *next) {
        printable.push_back(next);
    }
};

class Sheet : public IPrintable {
private:
    string name;
public:
    explicit Sheet(string name) {
        this->name = name;
    };
    void print() override {
        cout << "Printing sheet " << this->name << endl;
    };
};

class Photo : public IPrintable {
private:
    string name;
public:
    explicit Photo(string name) {
        this->name = name;
    };
    void print() override {
        cout << "Printing photo " << this->name << endl;
    };
};

class Poster : public IPrintable {
private:
    string name;
public:
    explicit Poster(string name) {
        this->name = name;
    };
    void print() override {
        cout << "Printing poster " << this->name << endl;
    };
};


int main() {
    Sheet sheet1 = Sheet("sheet1");
    sheet1.print();

    IPrintable *poster1 = new Poster("poster1");
    IPrintable *sheet2 = new Sheet("sheet2");
    IPrintable *photo1 = new Photo("photo1");
    ToPrint toPrint = ToPrint();
    toPrint.add(poster1);
    toPrint.add(sheet2);
    toPrint.add(photo1);
    toPrint.print();
}
