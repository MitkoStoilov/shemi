package org.elsys.tuesky.api.planner;

import org.elsys.tuesky.api.trips.Trip;

import java.util.List;

public interface TripQueryFunction  {

    List<Trip> find(List<Trip> trips);
}

