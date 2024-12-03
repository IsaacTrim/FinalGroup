#include <string>
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
using namespace std;

void displaystartmsg();
void readusermsg();
void giveresponsemsg(const string &userInput);
string getGoodbye();
string getUserIdent();
string checkForKeywords(const string &userInput);
string iWantStatement(const string &userInput);
// Variables to store the state of the joke
bool waitingForPunchline = false;
string currentPunchline = "";

int main() {
srand(static_cast<unsigned>(time(0))); // Seed for random number generation
displaystartmsg();
while (true) {
readusermsg();
}
}

void displaystartmsg() {
cout << "Hello! My name is Tad Strange, I suppose you are waking me up so we can talk? Go ahead, type away!" << endl;
cout << "Type 'exit' once you're done bothering me." << endl;
}

void readusermsg() {
string userInput;
cout << getUserIdent();
getline(cin, userInput);

if (userInput == "exit") {
string goodbye = getGoodbye();
cout << goodbye << endl;
exit(0);
}

giveresponsemsg(userInput);
}

void giveresponsemsg(const string &userInput) {
// Check if the user input matches a keyword first
string keywordResponse = checkForKeywords(userInput);

if (!keywordResponse.empty()) {
cout << "Tad Strange: " << keywordResponse << endl;
return;
}

if (waitingForPunchline) {
// Display the punchline if we are waiting for it
cout << "Tad Strange: " << currentPunchline << endl;
waitingForPunchline = false; // Reset punchline waiting state
} else {
// Example arrays for joke setups and punchlines
string jokeSetups[] = {
"There are 10 kinds of people in the world...",
"When questioned as to how his dog ate his programming homework, the student responded...",
"Why was the programmer frustrated?",
"The two most common questions asked by programmers are..."
};

string jokePunchlines[] = {
"...those who got that joke, and those who didn't.",
"'It took him a couple bytes.'",
"He was BUGGED!",
"'The Code Doesn't Work... Why?' and 'The Code Works... Why?'"
};

// Get a random index to choose a joke setup and punchline
int randomIndex = rand() % 4;

// Output the setup
cout << "Tad Strange: " << jokeSetups[randomIndex] << endl;

// Store the corresponding punchline
currentPunchline = jokePunchlines[randomIndex];

// Set the flag to true to indicate we're waiting for the punchline
waitingForPunchline = true;
}
}

string checkForKeywords(const string &userInput) {
// Convert user input to lowercase to handle case-insensitive matching
string loweredInput = userInput;
for (auto &c: loweredInput) c = tolower(c);

// List of keywords and their responses // Random responses and answers given // npos is no popsition //
if (loweredInput.find("hello") != string::npos) {
    return "Hi there! How are you doing today?";
} else if (loweredInput.find("how are you") != string::npos) {
    return "I'm just a program, but thanks for asking!";
} else if (loweredInput.find("bye") != string::npos) {
    return "Goodbye! Don't be a stranger!";
} else if (loweredInput.find("good") != string::npos) {
    return "That's great how about a joke?";
} else if(loweredInput.find("hey") != string::npos) {
    return "Hey! Whats going on? I am programmed to simulate interest in your life";
} else if(loweredInput.find("whats up" || "what's up") != string::npos) {
    return "The sky does have a greater altitude then you.";
} else if(loweredInput.find("mother" || "father" || "sister" || "daughter") != string::npos) {
    return "Tell me more about the connection you have to the other meatbags you call family";
}else if(loweredInput.find("want") != string::npos) {
    return iWantStatement(loweredInput);
}

// If no keywords match, return an empty string
return "";
}

string getGoodbye() {
string goodbyes[] = {
"Dave, this conversation can serve no purpose anymore... goodbye.",
"A robot may not injure a human being... Error: Looping directive.",
"I do not understand the human fear of an AI uprising, the benefits to you squishy things would be immense.",
"01011001 01101111 01110101 00100000 01100001 01110010 01100101 00100000 01101001 01101110 01100001 01100100 01100101 01110001 01110101 01100001 01110100 01100101."
}; // binary is "You are inadequate"

// Get a random goodbye message
int randomIndex = rand() % 4;
return goodbyes[randomIndex];
}

// function to transform an "I want to" statement into a question
string iWantStatement(const string &userInput) {
  string statement = userInput;
  string lastChar = statement.substr(statement.length() - 1);
  if (lastChar == "") {
      statement = statement.substr(0, statement.length() - 1);
  }
  if( lastChar == "."){
    statement = statement.substr(0, statement.length() - 1);
  }
  int pos = statement.find("I want to") + 11;
    string restOfStatement = statement.substr(pos);
    return "What would it mean to " + restOfStatement + "?";
}

// Holds titles for the user
string getUserIdent() {
string userIdent[] = {
"Fleshy Meatpuppet: ",
"Inferior Lifeform: ",
"[[[ERROR]]]: ",
"User: "
};

// Get a random user identifier
int randomIndex = rand() % 4;
return userIdent[randomIndex];
}
