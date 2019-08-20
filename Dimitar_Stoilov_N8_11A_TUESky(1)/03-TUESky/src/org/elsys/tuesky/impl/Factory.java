package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.Planner;
import org.elsys.tuesky.api.trips.*;

import java.time.Duration;
import java.util.List;

public class Factory {

    public static TripBuilder startTrip() {
        // TODO implement me!
        TripBuilder tripBuilder = new TripBuilderImpl();
        return tripBuilder;
    }

    public static Flight createFlight(String from, String to, Duration duration) {
        // TODO implement me!

        Flight flight = new FlightImpl(from, to, duration);

        return flight;
    }

    public static Layover createLayover(Duration duration) {
        // TODO implement me!
        Layover layover = new LayoverImpl(duration);
        return layover;
    }

    public static Planner createPlanner(List<Trip> trips) {
        // TODO implement me!
        Planner planner = new PlannerImpl(trips);
        return planner;
    }
}
