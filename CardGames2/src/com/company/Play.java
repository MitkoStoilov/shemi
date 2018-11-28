package com.company;
import java.util.*;

public class Play {
    public static Vector<String> parse(String str, String Delimeter)
    {
        Vector<String> parsed = new Vector<String>(10, 10);
        parsed = new Vector<String>(Arrays.asList(str.split(Delimeter, 52)));
        return parsed;
    }

    public static void main(String[] args) {
        Deck deck = new Belote();

        Scanner scan = new Scanner(System.in);
        String s;
        s = scan.nextLine();
        Vector<String> parsed = new Vector<String>(52, 52);
        parsed = parse(s, " ");

        HashMap<Card, Integer> table_players = new HashMap<Card, Integer>();

        Integer current_player = 0;

        for(int i = 0; i < parsed.size(); i++)
        {
            deck.push(new Card(parsed.elementAt(i)));
        }

        deck.seed();
        deck.shuffle();
        PlayBelote game = new PlayBelote(deck);

        for(int i = 0; i < game.p_count_; i++)
        {
            game.deal(i);
        }

        while(true)
        {
            if(game.table_.size()==game.p_count_)
            {
                game.cout();
                Integer winner = table_players.get(game.table_.getMax());
                System.out.printf("%nPlayer %d won!%n%n", winner);
                for(int i = 0; i < game.p_count_; i++)
                {
                    game.players_.elementAt(winner).taken_.push(game.table_.pop(0));
                }
            }
            game.cout();
            System.out.printf("Player %d says: ", current_player);
            s = scan.nextLine();
            parsed = parse(s, " ");
            if(parsed.elementAt(0).equals("put"))
            {
                table_players.put(game.players_.elementAt(current_player).cards_.at(Integer.parseInt(parsed.elementAt(1))), current_player);
                game.put(current_player, Integer.parseInt(parsed.elementAt(1)));

                current_player = (current_player + 1)%game.p_count_;
            }
            else if(parsed.elementAt(0).equals("taken"))
            {
                game.coutt();
            }

        }

    }

}
