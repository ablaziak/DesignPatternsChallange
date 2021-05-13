#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Observer {
public:
    virtual void update(string notification){}
};

class User : public Observer{
private:
    string email_address;
public:
    User(string emailAddress) : email_address(emailAddress) {}

    void update(string notification) {
        cout << email_address << " received: " << endl;
        cout << notification << endl;
    }

    string getEmailAddress() {
        return email_address;
    }
};

class Newsletter{
private:
    vector<Observer*> observers;
public:
    void addUser(Observer* user) {
        observers.push_back(user);
    }
    void removeUser(Observer* user) {
        for(int i = 0; i<observers.size(); i++) {
            if (observers[i] == user) {
                observers.erase(observers.begin()+i);
            }
        }
    }
    void notify(string notification) {
        for (auto o : observers) {
            o->update(notification);
        }
    }

    void newNotification(string notification) {
        notify(notification);
    }
};

int main() {
    User *user1 = new User("user1@user1.com");
    User *user2 = new User("user2@user2.com");
    Newsletter nl = Newsletter();
    nl.addUser(user1);
    nl.addUser(user2);
    nl.newNotification("New notification!");
}
