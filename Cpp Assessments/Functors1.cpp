#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class LengthCriteria {
public:
    LengthCriteria(int length) : length(length) {}

    bool operator()(const string& str) const {
        return str.length() == length;
    }

private:
    int length;
};

class StartsWithCriteria {
public:
    StartsWithCriteria(const string& prefix) : prefix(prefix) {}

    bool operator()(const string& str) const {
        return str.find(prefix) == 0;
    }

private:
    string prefix;
};

class EndsWithCriteria {
public:
    EndsWithCriteria(const string& suffix) : suffix(suffix) {}

    bool operator()(const string& str) const {
        return str.rfind(suffix) == (str.length() - suffix.length());
    }

private:
    string suffix;
};


vector<string> filterStrings(const vector<string>& strings, const function<bool(const string&)>& criteria) {
    vector<string> filteredStrings;
    for (const auto& str : strings) {
        if (criteria(str)) {
            filteredStrings.push_back(str);
        }
    }
    return filteredStrings;
}


void displayStrings(const vector<string>& strings, const string& message) {
    cout << message << ":" << endl;
    for (const auto& str : strings) {
        cout << str << endl;
    }
    cout << endl;
}

int main() {
    vector<string> stringArray = {"apple", "banana", "orange", "avocado", "kiwi"};

    LengthCriteria lengthCriteria(4);
    StartsWithCriteria startsWithCriteria("a");
    EndsWithCriteria endsWithCriteria("o");

    
    vector<string> filteredLengthStrings = filterStrings(stringArray, lengthCriteria);
    vector<string> filteredStartsWithStrings = filterStrings(stringArray, startsWithCriteria);
    vector<string> filteredEndsWithStrings = filterStrings(stringArray, endsWithCriteria);

    
    displayStrings(filteredLengthStrings, "Strings with length 4");
    displayStrings(filteredStartsWithStrings, "Strings starting with 'a'");
    displayStrings(filteredEndsWithStrings, "Strings ending with 'o'");

    return 0;
}
