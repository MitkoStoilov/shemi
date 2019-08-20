package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.planner.TripQuery;
import org.elsys.tuesky.api.trips.Trip;

import java.time.Duration;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class TripImpl implements Trip {

    private String origin;
    private String destination;
    private Duration duration;
    private ArrayList<FlightImpl> flights;
    private ArrayList<LayoverImpl> layovers;

    public TripImpl(String origin, String destination, Duration duration,
                    ArrayList<FlightImpl> flights, ArrayList<LayoverImpl> layovers) {
        this.origin = origin;
        this.destination = destination;
        this.duration = duration;
        this.flights = flights;
        this.layovers = layovers;
    }

    public ArrayList<String> getStops() {
        ArrayList<String> stops = new ArrayList<>();

        for(int i =0; i<flights.size()-1; i++){
            stops.add(flights.get(i).getDestination());
        }

        return stops;
    }

    @Override
    public String getOrigin() {
        return origin;
    }

    public ArrayList<FlightImpl> getFlights() {
        return flights;
    }

    public ArrayList<LayoverImpl> getLayovers() {
        return layovers;
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
    public Duration getLayoverDuration() {
        Duration duration = Duration.ZERO;
        long time = duration.getSeconds();
        for(LayoverImpl l : layovers){
            time += l.getDuration().getSeconds();
        }
        duration = Duration.ofSeconds(time);

        return duration;
    }

    @Override
    public int getFlightsCount() {
        return flights.size();
    }

    @Override
    public boolean matches(TripQuery query) {
        ArrayList<Trip> trip = new ArrayList<>();
        List<Trip> result;
        trip.add(this);
        AbstractTripQuery q = (AbstractTripQuery) query;
        result = q.getFunction().find(trip);
        if(result.size() == 0) {
            return false;
        }else{
            return true;
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        TripImpl trip = (TripImpl) o;

        return Objects.equals(origin, trip.getOrigin()) &&
                Objects.equals(destination, trip.getDestination()) &&
                Objects.equals(duration, trip.getDuration()) &&
                Objects.equals(this.getStops(), trip.getStops());
    }

    @Override
    public int hashCode() {
        return Objects.hash(origin, destination, duration, this.getStops());
    }
}
