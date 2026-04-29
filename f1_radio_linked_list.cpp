#include <iostream>
#include <string>

using namespace std;

class radioMessage{
    public:
        string message;
        string driverName;
        class radioMessage* next;

        radioMessage(string message, string driverName){
            this->message = message;
            this->driverName = driverName;
            this->next = nullptr;
        }
};

radioMessage* addMessage(radioMessage* root, string message, string driverName);
void showMessage(radioMessage* root);
void deleteMessages(radioMessage* root);

int main()
{
    radioMessage* root = nullptr;

    root = addMessage(root, "Grip level is low.", "Max");
    root = addMessage(root, "This car is amazing!", "Max");
    root = addMessage(root, "What's the problem? He cut me off! You always have to leave the space!", "Fernando");

    showMessage(root);
    deleteMessages(root);

    return 0;
}

radioMessage* addMessage(radioMessage* root, string message, string driverName){
    radioMessage* newMessage = new radioMessage(message, driverName);

    if(root == NULL){
        return newMessage;
    }

    radioMessage* temp = root;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newMessage;

    return root;
}

void showMessage(radioMessage* root){
    radioMessage* temp = root;

    while(temp != NULL){
        cout << temp->driverName << ": " << temp->message << endl;
        temp = temp->next;
    }
}

void deleteMessages(radioMessage* root){
    radioMessage* temp = root;
    radioMessage* back = temp;

    while(temp != NULL){
        back = temp;
        temp = temp->next;
        delete back;
    }
}