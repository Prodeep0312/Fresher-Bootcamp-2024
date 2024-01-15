import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.Predicate;

public class Main {

    public static List<String> searchWithCriteria(List<String> stringItem, String criteria, Predicate<String> predicate) {
        List<String> matchingStrings = new ArrayList<>();
        for (String str : stringItem) {
            if (predicate.test(str)) {
                matchingStrings.add(str);
            }
        }
        return matchingStrings;
    }

    public static void loopAndSort(List<String> strings) {
        List<String> sortedStrings = new ArrayList<>(strings);
        Collections.sort(sortedStrings);
        for (String sortedStr : sortedStrings) {
            System.out.println(sortedStr);
        }
    }

    public static void main(String[] args) {

        List<String> stringArray = List.of("apple", "banana", "orange", "avocado", "kiwi");

        String startsWithCriteria = "a";
        String endsWithCriteria = "o";
        int lengthCriteria = 6;

        List<String> startsWithResult = searchWithCriteria(stringArray, startsWithCriteria, str -> str.startsWith(startsWithCriteria));

        List<String> endsWithResult = searchWithCriteria(stringArray, endsWithCriteria, str -> str.endsWith(endsWithCriteria));

        List<String> lengthResult = searchWithCriteria(stringArray, "", str -> str.length() == lengthCriteria);

        System.out.println("Starts with 'a':");
        loopAndSort(startsWithResult);

        System.out.println("\nEnds with 'o':");
        loopAndSort(endsWithResult);

        System.out.println("\nLength is 6:");
        loopAndSort(lengthResult);
    }
}
