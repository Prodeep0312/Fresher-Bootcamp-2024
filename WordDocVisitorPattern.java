/* OLDER CODE

import java.util.*;
class WordDocument{
   List<DocumentPart> parts =new ArrayList<>();
   
   public void open(){
       for(DocumentPart dp :parts)
       {
           dp.paint();
       }
   }
   public void save(){
        for(DocumentPart dp:parts)
       {
           dp.save();
       }
   }
    
    
}

abstract class DocumentPart{
    String name;
    double position;
    abstract void paint();
    abstract void save();
}

class Header extends DocumentPart {
    
    String title;
    
    void paint()
    {
        System.out.println("Displaying header");
        
    }
    
     void save()
    {
        System.out.println("Saving  header");
        
    }
}

class Footer extends DocumentPart {
    
    String text;
    
    void paint()
    {
        System.out.println("Displaying Footer");
        
    }
    
     void save()
    {
        System.out.println("Saving  Footer");
        
    }
}

class Hyperlink extends DocumentPart {
    
    String url;
    String text;
    
    void paint()
    {
        System.out.println("Displaying hyperlink");
        
    }
    
     void save()
    {
        System.out.println("Saving  hyperlink");
        
    }
}

class Paragraph extends DocumentPart {
    
    String content;
    
    
    void paint()
    {
        System.out.println("Displaying paragraph");
        
    }
    
     void save()
    {
        System.out.println("Saving  paragraph");
        
    }
}

class Main{
    public static void main(String[] args){
        WordDocument document = new WordDocument();

        
        Header header = new Header();
        header.title = "Document Title";
        document.parts.add(header);

        Paragraph paragraph = new Paragraph();
        paragraph.content = "This is a sample paragraph.";
        document.parts.add(paragraph);

        Footer footer = new Footer();
        footer.text = "Page 1";
        document.parts.add(footer);

        Hyperlink hyperlink = new Hyperlink();
        hyperlink.url = "https://example.com";
        hyperlink.text = "Visit our website";
        document.parts.add(hyperlink);

        
        document.open();
        document.save();
    }
}

*/
import java.util.*;
class WordDocument{
   List<DocumentPart> parts =new ArrayList<>();
   
   public void open(){
       for(DocumentPart dp :parts)
       {
           dp.paint();
       }
   }
   public void save(){
        for(DocumentPart dp:parts)
       {
           dp.save();
       }
   }
       
    public void convert(ConvertorInterface iConverter) {
        for (DocumentPart dp : parts) {
            dp.convert(iConverter);
        }
    }
   
    
    
}

abstract class DocumentPart{
    String name;
    double position;
    abstract void paint();
    abstract void save();
    abstract void convert(ConvertorInterface iConverter);
}

class HTMLConvertor implements ConvertorInterface
{
    public void convert(Header header) {
        System.out.println("<header> created ... ");
    }
    
    public void convert(Paragraph paragraph) {
        System.out.println("<p> converted");
    }
    
    public void convert(Hyperlink hyperlink) {
        System.out.println("<a> converted");
    }
    
    public void convert(Footer footer) {
        System.out.println("<footer> converted");
    }
}
class Header extends DocumentPart {
    
    String title;
    
    void paint()
    {
        System.out.println("Displaying header");
        
    }
    
     void save()
    {
        System.out.println("Saving  header");
        
    }
    
     public void convert(ConvertorInterface iConverter) {
        iConverter.convert(this);
    }
}

class Footer extends DocumentPart {
    
    String text;
    
    void paint()
    {
        System.out.println("Displaying Footer");
        
    }
    
     void save()
    {
        System.out.println("Saving  Footer");
        
    }
     public void convert(ConvertorInterface iConverter) {
        iConverter.convert(this);
    }
}

class Hyperlink extends DocumentPart {
    
    String url;
    String text;
    
    void paint()
    {
        System.out.println("Displaying hyperlink");
        
    }
    
     void save()
    {
        System.out.println("Saving  hyperlink");
        
    }
     public void convert(ConvertorInterface iConverter) {
        iConverter.convert(this);
    }
}

class Paragraph extends DocumentPart {
    
    String content;
    
    
    void paint()
    {
        System.out.println("Displaying paragraph");
        
    }
    
     void save()
    {
        System.out.println("Saving  paragraph");
        
    }
    
     public void convert(ConvertorInterface iConverter) {
        iConverter.convert(this);
    }
}

interface ConvertorInterface
{
    public void convert(Header header);
    public void convert(Paragraph paragraph);
    public void convert(Hyperlink hyperlink);
    public void convert(Footer footer);
}


class Main{
    public static void main(String[] args){
        WordDocument document = new WordDocument();

        
        Header header = new Header();
        header.title = "Document Title";
        document.parts.add(header);

        Paragraph paragraph = new Paragraph();
        paragraph.content = "This is a sample paragraph.";
        document.parts.add(paragraph);

        Footer footer = new Footer();
        footer.text = "Page 1";
        document.parts.add(footer);

        Hyperlink hyperlink = new Hyperlink();
        hyperlink.url = "https://example.com";
        hyperlink.text = "Visit our website";
        document.parts.add(hyperlink);
        
        ConvertorInterface htmlimplementation=new HTMLConvertor();
        

        
        document.open();
        document.save();
        document.convert(htmlimplementation);
    }
}
