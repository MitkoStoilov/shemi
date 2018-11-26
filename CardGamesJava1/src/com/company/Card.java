package com.company;
import java.util.*;

public class Card {
    public char color_;
    public int power_;

    public Card()
    {
        color_ = 0;
        power_ = 0;
    }

    public Card(char color, int power)
    {
        color_ = color;
        power_ = power;
    }

    public Card(String s) {
        color_ = s.charAt(0);
        s = s.substring(1, s.length());

        try {
            power_ = Integer.valueOf(s);
        } catch (NumberFormatException nfe) {
            if (s.equals("J"))
                power_ = 11;
            else if (s.equals("Q"))
                power_ = 12;
            else if (s.equals("K"))
                power_ = 13;
            else if (s.equals("A"))
                power_ = 14;
        }
    }

    public Card(Card other)
    {
        this.power_ = other.power_;
        this.color_ = other.color_;
    }

    public void cout()
    {
        System.out.printf("%c%d ", color_, power_);
    }

    public int getPower_()
    {
        return power_;
    }

    public char getColor_()
    {
        return color_;
    }

    public Boolean isEqual(Card other)
    {
        return ((this.color_==other.color_)&&(this.power_==other.power_));
    }

    int calc(Deck d)
    {
        return d.pwrs.get(power_) + d.clrs.get(color_)*52;
    }

    Boolean valid(int req_power)
    {
        return (power_ >= req_power);
    }
}