package com.company;
import java.util.*;

public class PlayBelote extends Game {

    public PlayBelote()
    {
        p_count_ = 4;
        deck_ = new Deck();
        players_ = new Vector<Player>(4,4);
    }

    public PlayBelote(Deck deck)
    {
        p_count_ = 4;
        deck_ = new Deck();
        deck_.copyAll(deck);
        players_ = new Vector<Player>(4,4);
    }

    public void cout()
    {
        for(int i = 0; i < p_count_; i++)
        {
            System.out.printf("Player %d: ", i);
            players_.elementAt(i).cout();
            System.out.printf("Taken   : ", i);
            players_.elementAt(i).taken_.cout();
            System.out.printf("%n");
        }
        System.out.printf("Table   : ");
        table_.cout();
    }

    public void put(Integer player, Integer card_number)
    {
        Card temp = new Card();
        temp = players_.elementAt(player).cards_.pop(card_number);
        table_.push(temp);
    }
}
