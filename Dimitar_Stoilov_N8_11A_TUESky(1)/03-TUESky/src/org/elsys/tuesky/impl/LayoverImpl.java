package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.trips.Layover;

import java.time.Duration;
import java.util.Objects;

public class LayoverImpl implements Layover {

    private Duration duration;

    public LayoverImpl(Duration duration) {
        this.duration = duration;
    }

    public LayoverImpl() {

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
        return Objects.equals(duration, trip.getDuration());

    }

    @Override
    public int hashCode() {
        return Objects.hash(duration);
    }
}
