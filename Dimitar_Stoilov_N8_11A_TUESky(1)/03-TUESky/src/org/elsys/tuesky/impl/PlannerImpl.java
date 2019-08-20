package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.Planner;
import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Trip;

import java.util.List;


public class PlannerImpl implements Planner {

    List<Trip> trips;

    public PlannerImpl(List<Trip> trips) {
        this.trips = trips;
    }

    @Override
    public List<Trip> search(TripQuery query) {
        AbstractTripQuery q = (AbstractTripQuery) query;
        List<Trip> result = q.getFunction().find(trips);

        return result;
    }

    @Override
    public boolean anyMatch(TripQuery query) {
        AbstractTripQuery q = (AbstractTripQuery) query;
        List<Trip> result = q.getFunction().find(trips);

        if(result.size() == 0) {
            return false;
        } else {
            return true;
        }
    }

    @Override
    public int count(TripQuery query) {
        AbstractTripQuery q = (AbstractTripQuery) query;
        List<Trip> result = q.getFunction().find(trips);

        return result.size();
    }
}
