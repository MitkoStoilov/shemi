package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Trip;

import java.util.List;
import java.util.stream.Collectors;

public class QueryWithMaxFlights extends AbstractTripQuery {

    private int flights;

    public QueryWithMaxFlights(int flights){
        this.flights = flights;
        function = (List<Trip> trips) -> {
            result = trips.stream()
                    .filter(trip -> trip.getFlightsCount() <= flights)
                    .collect(Collectors.toList());
            return result;
        };
    }
}
