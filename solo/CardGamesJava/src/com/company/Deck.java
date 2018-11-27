package com.company;
import java.util.*;

public class Deck {
    Vector<Card> cards;
    HashMap<Character, Integer> pwrs;
    HashMap<Character, Integer> clrs;
    Integer msize_;
    Integer h_size_;

    public Deck() {
        msize_ = 52;
        h_size_ = 26;
        pwrs = new HashMap<Character, Integer>();
        clrs = new HashMap<Character, Integer>();
        cards = new Vector<Card>(msize_, msize_);
        for (int i = 2; i <= 10; i++) {
            pwrs.put((char) i, i);
        }

        pwrs.put('J', 11);
        pwrs.put('Q', 12);
        pwrs.put('K', 13);
        pwrs.put('A', 14);


        clrs.put('S', 4);
        clrs.put('H', 3);
        clrs.put('D', 2);
        clrs.put('C', 1);
    }

    public void copyCards(Deck other) {
        cards = (Vector<Card>)other.cards.clone();
    }

    public void copyAll(Deck other) {
        cards = (Vector<Card>)other.cards.clone();
        msize_ = other.msize_;
        h_size_ = other.h_size_;
        pwrs = other.pwrs;
        clrs = other.clrs;
    }

    public Card pop(int index) {
        Card temp = cards.elementAt(index);
        cards.remove(index);
        return temp;
    }

    public Card at(int index) {
        return cards.elementAt(index);
    }

    public Card top() {
        return at(0);
    }

    public int size(){
        return cards.size();
    }

    public Card bottom() {
        return at(size() - 1);
    }

    public void shuffle() {
        Collections.shuffle(cards);
    }

    public Deck deal() {
        Deck temp = new Deck();

        for (int i = 0; i < h_size_; i++) {
            temp.push(at(0));
            pop(0);
        }

        return temp;
    }

    public Deck deal_peek() {
        Deck temp = new Deck();

        for (int i = 0; i < h_size_; i++) {
            temp.push(at(i));
        }

        return temp;
    }

    public void cout() {
        for (Card card : cards) {
            card.cout();
            System.out.printf(" ");
        }

        System.out.printf("%n");
    }

    public void push(Card card) {
        cards.add(card);
    }

    public void seed() {
        Vector<Card> temp = new Vector<Card>(size(), size());
        for (Card card : cards) {
            if (pwrs.containsKey(card.power_) && clrs.containsKey(card.color_)) {
                temp.add(card);
            }
        }
        cards = temp;
    }

    public int cmpc(Card c1, Card c2, Deck d) {
        if (c1.calc(d) > c2.calc(d))
            return 1;
        if (c1.calc(d) == c2.calc(d))
            return 0;
        if (c1.calc(d) < c2.calc(d))
            return -1;
        return 0;
    }

    public void sort()
    {
        for(int k = 0; k < size(); k++)
        {
            for(int i = 0; i < size() - 1; i++)
            {
                if(cmpc(at(i), at(i+1), this) == -1)
                {
                    Collections.swap(cards, i, i+1);
                }
            }
        }
    }
}