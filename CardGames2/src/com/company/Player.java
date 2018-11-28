package com.company;

public class Player {
    public Integer id_;
    public String name_;
    public Deck cards_;
    public Deck taken_;

    public Player(Integer id, String name, Deck cards)
    {
        cards_ = new Deck();
        taken_ = new Deck();
        id_ = id;
        name_ = name;
        cards_.copyAll(cards);
    }

    public Player(Integer id, Deck cards)
    {
        cards_ = new Deck();
        taken_ = new Deck();
        id_ = id;
        cards_.copyCards(cards);
    }

    public void cout()
    {
        cards_.cout();
    }

    public void coutt()
    {
        taken_.cout();
    }
}
