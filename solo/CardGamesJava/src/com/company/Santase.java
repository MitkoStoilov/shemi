package com.company;
import java.util.*;

public class Santase extends Deck {

    public Santase() {
        msize_ = 24;
        h_size_ = 6;
        pwrs = new HashMap<Character, Integer>();
        clrs = new HashMap<Character, Integer>();
        cards = new Vector<Card>(msize_, msize_);

        pwrs.put((char)9, 9);
        pwrs.put((char)10, 13);
        pwrs.put('J', 10);
        pwrs.put('Q', 11);
        pwrs.put('K', 12);
        pwrs.put('A', 14);

        clrs.put('S', 4);
        clrs.put('H', 3);
        clrs.put('D', 2);
        clrs.put('C', 1);
    }
}