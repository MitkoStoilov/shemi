package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Flight;

import java.time.Duration;
import java.util.Objects;

public class FlightImpl implements Flight {

    private String origin;
    private String destination;
    private Duration duration;

    public FlightImpl(String origin, String destination, Duration duration) {
        this.origin = origin;
        this.destination = destination;
        this.duration = duration;
    }

    public FlightImpl() {

    }

    @Override
    public String getOrigin() {
        return origin;
    }

    @Override
    public String getDestination() {
        return destination;
    }

    @Override
    public Duration getDuration() {
        return duration;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TripImpl trip = (TripImpl) o;
        return Objects.equals(origin, trip.getOrigin()) &&
                Objects.equals(destination, trip.getDestination()) &&
                Objects.equals(duration, trip.getDuration());
    }

    @Override
    public int hashCode() {
        return Objects.hash(origin, destination, duration);
    }
}
