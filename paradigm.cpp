#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>


std::vector<std::string> searchWithCriteria(const std::vector<std::string>& stringitem, const std::string& criteria, std::function<bool(const std::string&)> predicate) {
    std::vector<std::string> matchingStrings;
    for (const std::string& str : stringitem) {
        if (predicate(str)) {
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

    
    auto startsWithResult = searchWithCriteria(stringArray, startsWithCriteria, [](const std::string& str) { return str.find(startsWithCriteria) == 0; });
    
    auto endsWithResult = searchWithCriteria(stringArray, endsWithCriteria, [](const std::string& str) { return str.rfind(endsWithCriteria) == str.length() - endsWithCriteria.length(); });
    
    auto lengthResult = searchWithCriteria(stringArray, "", [lengthCriteria](const std::string& str) { return str.length() == static_cast<size_t>(lengthCriteria); });

   
    std::cout << "Starts with 'a':" << std::endl;
    loopAndSort(startsWithResult);

    std::cout << "\nEnds with 'o':" << std::endl;
    loopAndSort(endsWithResult);

    std::cout << "\nLength is 6:" << std::endl;
    loopAndSort(lengthResult);

    return 0;
}
