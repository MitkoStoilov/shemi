package com.company;
import java.util.*;


public class Main {

    public static Vector<String> parse(String str, String Delimeter)
    {
        Vector<String> parsed = new Vector<String>(10, 10);
        parsed = new Vector<String>(Arrays.asList(str.split(Delimeter, 52)));
        return parsed;
    }


    public static void main(String[] args) {
        HashMap<String, Deck> decks = new HashMap<String, Deck>();

        Deck main = new Deck();
        Santase santase = new Santase();
        Belote belote = new Belote();
        War war = new War();
        decks.put("War", war);
        decks.put("Belote", belote);
        decks.put("Santase", santase);



        Scanner scan = new Scanner(System.in);
        String s;
        System.out.printf("> ");
        s = scan.nextLine();
        Vector<String> parsed = new Vector<String>(52, 52);
        parsed = parse(s, " ");

        for(int i = 0; i < parsed.size(); i++)
        {
            main.push(new Card(parsed.elementAt(i)));
        }

        for(HashMap.Entry<String, Deck> entry : decks.entrySet())
        {
            entry.getValue().copyCards(main);
            entry.getValue().seed();
        }

        Deck current = new Deck();
        while(true)
        {
            System.out.printf("> ");
            s = scan.next();
            Deck currentcopy = new Deck();
            currentcopy.copyAll(current);
            try {
                if (decks.containsKey(s)) {
                    current.copyAll(decks.get(s));
                }
                else if (s.equals("size")) {
                    System.out.printf("%d%n", current.size());
                }

                else if (s.equals("draw_top_card")) {
                    current.pop(0).cout();
                    System.out.printf("%n");
                }
                else if (s.equals("draw_bottom_card")) {
                    current.pop(current.size() - 1).cout();
                    System.out.printf("%n");
                }
                else if (s.equals("top_card")) {
                    current.at(0).cout();
                    System.out.printf("%n");
                }
                else if(s.equals("bottom_card"))
                {
                    current.at(current.size()-1).cout();
                    System.out.printf("%n");
                }
                else if (s.equals("shuffle")) {
                    current.shuffle();
                    current.cout();
                }
                else if (s.equals("sort")) {
                    current.sort();
                    current.cout();
                }
                else if (s.equals("deal")) {
                    current.deal().cout();
                } else if (s.equals("show")) {
                    current.cout();
                } else if (s.equals("quit")) {
                    break;
                } else {
                    System.out.printf("ERROR: Unknown operation%n");
                }
            }
            catch(ArrayIndexOutOfBoundsException exception)
            {
                System.out.printf("ERROR: Not enough cards in deck%n");
                current.copyAll(currentcopy);
            }
        }
    }
}
