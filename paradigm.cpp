
#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::string> searchStartsWith(const std::vector<std::string>& array, const std::string& prefix) {
    std::vector<std::string> matchingStrings;
    for (const std::string& str : array) {
        if (str.find(prefix) == 0) {
            matchingStrings.push_back(str);
        }
    }
    return matchingStrings;
}


std::vector<std::string> searchEndsWith(const std::vector<std::string>& array, const std::string& suffix) {
    std::vector<std::string> matchingStrings;
    for (const std::string& str : array) {
        if (str.rfind(suffix) == str.length() - suffix.length()) {
            matchingStrings.push_back(str);
        }
    }
    return matchingStrings;
}


std::vector<std::string> searchByLength(const std::vector<std::string>& array, int length) {
    std::vector<std::string> matchingStrings;
    for (const std::string& str : array) {
        if (str.length() == static_cast<size_t>(length)) {
            matchingStrings.push_back(str);
        }
    }
    return matchingStrings;
}

void loopAndSort(const std::vector<std::string>& strings) {
    std::vector<std::string> sortedStrings = strings;
    std::sort(sortedStrings.begin(), sortedStrings.end());
    for (const std::string& sortedStr : sortedStrings) {
        std::cout << sortedStr << std::endl;
    }
}

int main() {
    
    std::vector<std::string> stringArray = {"apple", "banana", "orange", "avocado", "kiwi"};

  
    std::string startsWithCriteria = "a";
    std::string endsWithCriteria = "o";
    int lengthCriteria = 6;

    
    std::vector<std::string> startsWithResult = searchStartsWith(stringArray, startsWithCriteria);
    std::vector<std::string> endsWithResult = searchEndsWith(stringArray, endsWithCriteria);
    std::vector<std::string> lengthResult = searchByLength(stringArray, lengthCriteria);

    
    std::cout << "Starts with 'a':" << std::endl;
    loopAndSort(startsWithResult);

    std::cout << "\nEnds with 'o':" << std::endl;
    loopAndSort(endsWithResult);

    std::cout << "\nLength is 6:" << std::endl;
    loopAndSort(lengthResult);

    return 0;
}
