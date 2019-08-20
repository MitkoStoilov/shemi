package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Trip;

import java.util.List;
import java.util.stream.Collectors;

public class QueryWithOrigin extends AbstractTripQuery {

    private String value;

    public QueryWithOrigin(String value) {
        this.value = value;
        function = (List<Trip> trips) -> {
            result = trips.stream()
                    .filter(trip -> trip.getOrigin() == value)
                    .collect(Collectors.toList());
            return result;
        };
    }
}
