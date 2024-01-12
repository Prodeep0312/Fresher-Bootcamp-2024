
import java.util.*;
abstract class DocumentPart
{
    String name;
    String position;
    
    public abstract void paint();
    public abstract void save();
    public abstract void convert(ConverterInterface iConverter);
}

class Header extends DocumentPart
{
    String title;
    
    public void paint() {
        System.out.println("painting header");
    }
    
    public void save() {
        System.out.println("saving header");
    }
    
    public void convert(ConverterInterface iConverter) {
        iConverter.convert(this);
    }
}

class Paragraph extends DocumentPart
{
    String content;
    String lines;
    
    public void paint() {
        System.out.println("painting paragraph");
    }
    
    public void save() {
        System.out.println("saving paragraph");
    }
    
    public void convert(ConverterInterface iConverter) {
        iConverter.convert(this);
    }
}

class HyperLink extends DocumentPart
{
    String url;
    String text;
    
    public void paint() {
        System.out.println("painting hyperlink");
    }
    
    public void save() {
        System.out.println("saving hyperlink");
    }
    
    public void convert(ConverterInterface iConverter) {
        iConverter.convert(this);
    }
}

class Footer extends DocumentPart
{
    String text;
    
    public void paint() {
        System.out.println("painting footer");
    }
    
    public void save() {
        System.out.println("saving footer");
    }
    
    public void convert(ConverterInterface iConverter) {
        iConverter.convert(this);
    }
}

class WordDocument
{
    DocumentPart[] documentParts;
    
    WordDocument(DocumentPart[] dP) {
        documentParts = dP;
        
    }
    
    public void open() {
        for (DocumentPart i : documentParts) {
            i.paint();
            i.save();
        }
    }
    
    public void convert(ConverterInterface iConverter) {
        for (DocumentPart i : documentParts) {
            i.convert(iConverter);
        }
    }
}

interface ConverterInterface
{
    public void convert(Header headerItem);
    public void convert(Paragraph paragraphItem);
    public void convert(HyperLink hyperlinkItem);
    public void convert(Footer footerItem);
}

class HTMLConverter implements ConverterInterface
{
    public void convert(Header headerItem) {
        System.out.println("Converting <header>....");
    }
    
    public void convert(Paragraph paragraphItem) {
        System.out.println("Converting <p> ...");
    }
    
    public void convert(HyperLink hyperlinkItem) {
        System.out.println("Converting <a>...");
    }
    
    public void convert(Footer footerItem) {
        System.out.println("Converting <footer>...");
    }
}

class Main
{
    public static void main(String[] args) {
        DocumentPart h = new Header();
        DocumentPart f = new Footer();
        DocumentPart hyperlink = new HyperLink();
        DocumentPart p = new Paragraph();
        
       
        
        DocumentPart[] documentPartList = new DocumentPart[]{h, p, hyperlink, f};
        WordDocument wordDocument = new WordDocument(documentPartList);
        ConverterInterface htmlConverter = new HTMLConverter();
        
        wordDocument.convert(htmlConverter);
    }
}