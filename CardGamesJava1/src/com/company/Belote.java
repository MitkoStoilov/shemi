package com.company;
import java.util.*;

public class Belote extends Deck {
    public Belote()
    {
        size_ = 0;
        msize_ = 32;
        h_size_ = 8;
        min_p_ = 7;
        pwrs = new HashMap<Integer, Integer>();
        clrs = new HashMap<Character, Integer>();
        cards = new Vector<Card>(msize_, msize_);
        pwrs.put(7,7);
        pwrs.put(8,8);
        pwrs.put(9,9);
        pwrs.put(10, 13);
        pwrs.put(11, 10);
        pwrs.put(12, 11);
        pwrs.put(13, 12);
        pwrs.put(14, 14);
    }
}
