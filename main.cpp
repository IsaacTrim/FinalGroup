#include <string>
#include <iostream>
using namespace std;
void displaystartmsg();
void readusermsg();
void giveresponsemsg(const string& userInput);
int main() {
    displaystartmsg();
    while (true) {
        readusermsg();
    }
}
void displaystartmsg() {
    cout << "Hello I am Chat Bot. Lets talk!" << endl;
    cout << "Type 'exit' to quit the chat anytime." << endl;
}
void readusermsg() {
    string userInput;
    cout << "You";
    getline(cin, userInput);

    if (userInput == "exit") {
        cout << "Goodbye!" << endl;
        exit(0);
    }
    giveresponsemsg(userInput);
}
void giveresponsemsg(const string& userInput) {
    string questions[] = { "how are you","what is your name", "what can you do","hello"};
    string response[] = { questions[0], questions[1], questions[2], questions[3] };

}