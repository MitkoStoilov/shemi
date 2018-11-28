package com.company;
import java.util.*;


public class War extends Deck {
    public War() {
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
}
