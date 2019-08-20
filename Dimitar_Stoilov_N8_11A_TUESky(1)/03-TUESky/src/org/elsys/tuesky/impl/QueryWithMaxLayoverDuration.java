package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Trip;

import java.time.Duration;
import java.util.List;
import java.util.stream.Collectors;

public class QueryWithMaxLayoverDuration extends AbstractTripQuery {
    private Duration duration;

    public QueryWithMaxLayoverDuration(Duration duration) {
        this.duration = duration;

        function = (List<Trip> trips) -> {
            result = trips.stream()
                    .filter(trip -> {
                        long time = trip.getLayoverDuration().getSeconds();
                        if(time <= duration.getSeconds()){
                            return true;
                        }else {
                            return false;
                        }
                    })
                    .collect(Collectors.toList());
            return result;
        };
    }
}
