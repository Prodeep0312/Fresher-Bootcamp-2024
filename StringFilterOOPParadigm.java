import java.util.*;

/*class StringFilter {
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
}*/

interface SearchStrategy {
    public boolean invoke(String item);
}



class StartsWithStratergy implements SearchStrategy {
	private String startsWithCriteria;

	public void setStartsWith( String key){

		this.startsWithCriteria=key;
	}

	 public boolean invoke(String item){
        return item.startsWith(startsWithCriteria);
    }


}

class ConsoleDisplayController {

	private List<String> context;

	public void setContent(List<String> msg){
	{
		this.context=msg;

	}
	}

	public void displayonTerminal(){

		if (context == null) {
    throw new NullPointerException("stringList must not be null");
  }

		for (String str : context) {
           		 System.out.println(str);
        }

	

}}




class StringListFilterController{
    
     SearchStrategy predicate;
    public StringListFilterController(SearchStrategy searchStrategyObj){
        this.predicate = searchStrategyObj;
    }

StartsWithStratergy startsWithStratergy =new StartsWithStratergy();

public List<String> filter( List<String> stringList){

  List<String> filteredArray = new ArrayList<>();
        startsWithStratergy.setStartsWith("o");
        for(String word: stringList){
            if(startsWithStratergy.invoke(word)) filteredArray.add(word);
        }
        return filteredArray;
    }

 

}
public  class Main{
    public static void main (String[] args) {
        List<String> stringArray = List.of("apple", "banana", "orange", "avocado", "kiwi");
        
        
        StartsWithStratergy Obj = new StartsWithStratergy();
     Obj.setStartsWith("o");

         StringListFilterController stringListFilterControllerObj = new StringListFilterController(Obj);
     List<String> filteredArr = stringListFilterControllerObj.filter(stringArray);
      
      ConsoleDisplayController consoleDisplayControllerObj = new ConsoleDisplayController();
      consoleDisplayControllerObj.setContent(filteredArr);
      consoleDisplayControllerObj.displayonTerminal();
    }
}


