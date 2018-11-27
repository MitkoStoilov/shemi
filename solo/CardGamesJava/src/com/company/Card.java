package com.company;
import java.util.*;

public class Card{
    Character power_;
    Character color_;

    public Card()
    {
        color_ = 0;
        power_ = 0;
    }

    public Card(Card other)
    {
        this.color_ = other.color_;
        this.power_ = other.power_;
    }

    public Card(Character color, Character power)
    {
        this.color_ = color;
        this.power_ = power;
    }

    public Card(String s)
    {
        color_ = s.charAt(0);
        s = s.substring(1, s.length());

        try {
            power_ = (char) Integer.parseInt(s);
        } catch (NumberFormatException nfe) {
            power_ = s.charAt(0);
        }
    }

    public void cout()
    {
        if(power_>= 0 && power_ <= 32)
            System.out.printf("%c%d", color_,(int) power_);
        else
            System.out.printf("%c%c", color_, power_);
    }

    public Character getPower_()
    {
        return power_;
    }

    public Character getColor_()
    {
        return color_;
    }

    public Boolean isEqual(Card other)
    {
        return this.color_ == other.color_ && this.power_ == other.power_;
    }

    public Boolean isValid(int req_power)
    {
        return power_ >= req_power;
    }

    public int calc(Deck d)
    {
        return d.pwrs.get(power_) + d.clrs.get(color_)*128;
    }
}
