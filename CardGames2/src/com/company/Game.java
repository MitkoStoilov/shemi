package com.company;
import java.util.*;

public class Game {
    public Deck deck_;
    public Integer p_count_;

    public Vector<Player> players_;

    public Deck table_;

    public Game()
    {
        p_count_ = 2;
        deck_ = new Deck();
        table_ = new Deck();
        players_ = new Vector<Player>(4,4);
    }

    public Game(Deck deck, Integer p_count)
    {
        p_count_ = p_count;
        deck_ = new Deck();
        deck_.copyAll(deck);
        table_ = new Deck();
        players_ = new Vector<Player>(4,4);
    }

    public Player deal(Integer player)
    {
        players_.add(new Player(player, deck_.deal()));
        return players_.get(player);
    }

    public Player deal(Integer player, Integer card_count)
    {
        players_.add(new Player(player, deck_.deal(card_count)));
        return players_.get(player);
    }

    public Card play(Integer player, Integer card_pos)
    {
        Card card = new Card();
        card = players_.get(player).cards_.pop(card_pos);
        return card;
    }

    public void cout()
    {
        for(int i = 0; i < p_count_; i++)
        {
            System.out.printf("Player %d: ", i);
            players_.elementAt(i).cout();

        }
    }

    public void coutt()
    {
        for(int i = 0; i < p_count_; i++)
        {
            System.out.printf("Player %d taken: ", i);
            players_.elementAt(i).coutt();
        }
    }
}
