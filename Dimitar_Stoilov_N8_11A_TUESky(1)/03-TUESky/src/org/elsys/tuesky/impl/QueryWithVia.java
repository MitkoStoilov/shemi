package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Trip;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class QueryWithVia extends AbstractTripQuery {
    private String value;

    public QueryWithVia(String value) {
        this.value = value;
        function = (List<Trip> trips) -> {
            result = trips.stream()
                    .filter(trip -> {
                        boolean check = false;
                        TripImpl t = (TripImpl) trip;
                        ArrayList<String> stops = t.getStops();
                        for(String stop : stops){
                            if(stop == value){
                                check = true;
                                break;
                            }
                        }
                        return check;
                    })
                    .collect(Collectors.toList());
            return result;
        };
    }
}
