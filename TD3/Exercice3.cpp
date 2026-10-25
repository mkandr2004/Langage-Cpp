#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input) {
    queue<char> normalOrder;
    stack<char> reverseOrder;

    for (char character : input) {
        if (isalnum(static_cast<unsigned char>(character))) {
            character = static_cast<char>(tolower(character));
            normalOrder.push(character);
            reverseOrder.push(character);
        }
    }

    while (!normalOrder.empty()) {
        if (normalOrder.front() != reverseOrder.top()) {
            return false;
        }

        normalOrder.pop();
        reverseOrder.pop();
    }

    return true;
}

int main() {
    cout << boolalpha;

    cout << "Is 'racecar' a palindrome? "
         << isPalindrome("racecar") << endl;

    cout << "Is 'hello' a palindrome? "
         << isPalindrome("hello") << endl;

    return 0;
}
