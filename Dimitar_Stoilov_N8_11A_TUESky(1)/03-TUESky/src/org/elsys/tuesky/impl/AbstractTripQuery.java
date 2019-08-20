package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.planner.TripQueryFunction;
import org.elsys.tuesky.api.trips.Trip;

import java.util.ArrayList;
import java.util.List;

public abstract class AbstractTripQuery implements TripQuery {

    TripQueryFunction function;
    List<Trip> result = new ArrayList<>();
    private List<TripQueryFunction> operations = new ArrayList<>();


    public TripQueryFunction getFunction() {
        return function;
    }

    @Override
    public boolean matches(Trip trip) {
        ArrayList<Trip> trips = new ArrayList<>();
        List<Trip> result;
        trips.add(trip);
        result = function.find(trips);
        if(result.size() == 0) {
            return false;
        }else{
            return true;
        }
    }

    @Override
    public TripQuery and(TripQuery query) {
        AbstractTripQuery q = (AbstractTripQuery) query;

        TripQueryFunction oldFunction = this.function;
        operations.add(oldFunction);

        function = (List<Trip> trips) -> {
            for(TripQueryFunction f : operations){
                result = f.find(trips);
            }
            result = q.getFunction().find(result);
            return result;
        };


        return this;
    }

    @Override
    public TripQuery or(TripQuery query) {
        AbstractTripQuery q = (AbstractTripQuery) query;

        TripQueryFunction oldFunction = this.function;
        operations.add(oldFunction);

        function = (List<Trip> trips) -> {
            for(TripQueryFunction f : operations){
                result = f.find(trips);
            }
            result.addAll(q.getFunction().find(trips));
            return result;
        };

        return this;
    }


    @Override
    public TripQuery not() {

        TripQueryFunction oldFunction = this.function;
        operations.add(oldFunction);

        function = (List<Trip> trips) -> {

            List<Trip> allTrips = trips;
            List<Trip> unwantedTrips = operations.get(operations.size()-1).find(allTrips);

            allTrips.removeAll(unwantedTrips);

            result = allTrips;

            for(int i = 0; i < operations.size()-1; i++){
                result = operations.get(i).find(result);
            }
            return result;
        };
        return this;
    }
}
