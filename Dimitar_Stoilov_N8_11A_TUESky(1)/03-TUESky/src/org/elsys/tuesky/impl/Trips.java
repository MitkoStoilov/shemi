package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.TripQuery;

import java.time.Duration;

public class Trips {

    public static TripQuery withOrigin(String origin) {
        QueryWithOrigin query1 = new QueryWithOrigin(origin);
        return query1;
    }

    public static TripQuery withDestination(String destination) {
        QueryWithDestination query = new QueryWithDestination(destination);
        return query;

    }

    public static TripQuery via(String via) {
        QueryWithVia query = new QueryWithVia(via);
        return query;

    }

    public static TripQuery withMaxDuration(Duration duration) {

        QueryWithMaxDuration query = new QueryWithMaxDuration(duration);
        return query;
    }

    public static TripQuery withMaxLayoverDuration(Duration duration) {
        QueryWithMaxLayoverDuration query = new QueryWithMaxLayoverDuration(duration);
        return query;
    }

    public static TripQuery withMaxFlights(int flights) {
        QueryWithMaxFlights query = new QueryWithMaxFlights(flights);
        return query;
    }
}
