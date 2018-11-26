package com.company;
import java.util.*;

public class Deck{
    Vector<Card> cards;
    HashMap<Integer, Integer> pwrs;
    HashMap<Character, Integer> clrs;
    Integer size_;
    Integer msize_;
    Integer h_size_;
    Integer min_p_;

    public Deck()
    {
        size_ = 0;
        msize_ = 52;
        h_size_ = 26;
        min_p_ = 2;
        pwrs = new HashMap<Integer, Integer>();
        clrs = new HashMap<Character, Integer>();
        cards = new Vector<Card>(msize_, msize_);
        for(Integer i = 2; i <= 14; i++)
        {
            pwrs.put(i, i);
        }
    }

    public void copyCards(Deck other)
    {
        size_ = other.size_;
        cards = other.cards;
    }

    public void copyAll(Deck other)
    {
        size_ = other.size_;
        cards = other.cards;
        msize_ = other.msize_;
        h_size_ = other.h_size_;
        min_p_ = other.min_p_;
        pwrs = other.pwrs;
        clrs = other.clrs;
        cards = other.cards;
    }

    public void push(Card card)
    {
        cards.add(card);
        size_++;
    }

    public Card pop(Integer index)
    {
        Card temp = cards.elementAt(index);
        cards.remove(index);
        size_--;
        return temp;
    }

    public Card at(int index)
    {
        return cards.elementAt(index);
    }

    public Boolean empty()
    {
        return size_ == 0;
    }

    public Card top_card()
    {
        return at(0);
    }

    public Card bottom_card()
    {
        return at(size_-1);
    }

    public void shuffle()
    {
        Collections.shuffle(cards);
    }

    public Deck deal()
    {
        Deck temp = new Deck();

        for(int i = 0; i < h_size_; i++)
        {
            temp.push(at(0));
            pop(0);
        }
        return temp;
    }

    public void cout()
    {
        for(int i = 0; i < size_; i++)
        {
            at(i).cout();
        }
        System.out.printf("%n");
    }

    public void seed()
    {
        Vector<Card> temp = new Vector<Card>(52, 52);
        for(int i = 0; i < size_; i++)
        {
            if(at(i).valid(min_p_))
            {
                temp.add(at(i));
            }
        }
        size_ = temp.size();
        cards = temp;
    }

    public int cmpv(Card c1, Card c2, Deck d)
    {
        if(c1.calc(d) > c2.calc(d))
            return 1;
        if(c1.calc(d) == c2.calc(d))
            return 0;
        if(c1.calc(d) < c2.calc(d))
            return -1;
        return 0;
    }
}
