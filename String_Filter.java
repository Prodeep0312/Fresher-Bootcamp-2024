import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.Predicate;

class StringFilter {
    private final List<String> strings;

    public StringFilter(List<String> array) {
        this.strings = new ArrayList<>(array);
    }

    public List<String> searchWithCriteria(String criteria, Predicate<String> predicate) {
        List<String> matchingStrings = new ArrayList<>();
        for (String str : strings) {
            if (predicate.test(str)) {
                matchingStrings.add(str);
            }
        }
        return matchingStrings;
    }
}

class StringSorter {
    public List<String> sortStrings(List<String> stringsToSort) {
        List<String> sortedStrings = new ArrayList<>(stringsToSort);
        Collections.sort(sortedStrings);
        return sortedStrings;
    }
}

class TerminalDisplayer {
    public void displayOnTerminal(List<String> stringsToDisplay) {
        for (String str : stringsToDisplay) {
            System.out.println(str);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        List<String> stringArray = List.of("apple", "banana", "orange", "avocado", "kiwi");
        String endsWithCriteria = "o";

        StringFilter stringFilter = new StringFilter(stringArray);
        StringSorter stringSorter = new StringSorter();
        TerminalDisplayer terminalDisplayer = new TerminalDisplayer();

        System.out.println("Ends with 'o':");
        List<String> endsWithResult = stringFilter.searchWithCriteria(endsWithCriteria, str -> str.endsWith(endsWithCriteria));
        
        List<String> endsWithSorted = stringSorter.sortStrings(endsWithResult);
        
        terminalDisplayer.displayOnTerminal(endsWithSorted);
    }
}

