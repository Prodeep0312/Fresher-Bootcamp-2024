#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class LengthCriteria {
public:
    LengthCriteria(int length) : length(length) {}

    bool operator()(const string& str) {
        return str.length() == length;
    }

private:
    int length;
};

class StartsWithCriteria {
public:
    StartsWithCriteria(const string& prefix) : prefix(prefix) {}

    bool operator()(const string& str){
        return str.find(prefix) == 0;
    }

private:
    string prefix;
};

class EndsWithCriteria {
public:
    EndsWithCriteria(const string& suffix) : suffix(suffix) {}

    bool operator()(const string& str) {
        return str.rfind(suffix) == (str.length() - suffix.length());
    }

private:
    string suffix;
};

void displayStrings(const vector<string>& strings, const string& message, function<bool(const string&)> criteria) {
    cout << message << ":" << endl;
    for (const auto& str : strings) {
        if (criteria(str)) {
            cout << str << endl;
        }
    }
    cout << endl;
}

int main() {
    vector<string> stringArray = {"apple", "banana", "orange", "avocado", "kiwi"};

    LengthCriteria lengthCriteria(4);
    StartsWithCriteria startsWithCriteria("a");
    EndsWithCriteria endsWithCriteria("o");

    displayStrings(stringArray, "Strings with length 4", lengthCriteria);
    displayStrings(stringArray, "Strings starting with 'a'", startsWithCriteria);
    displayStrings(stringArray, "Strings ending with 'o'", endsWithCriteria);

    return 0;
}