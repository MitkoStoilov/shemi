package org.elsys.tuesky.impl;

import org.elsys.tuesky.api.TUESkyException;
import org.elsys.tuesky.api.trips.Flight;
import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.api.trips.TripBuilder;
import org.elsys.tuesky.api.trips.TripUnit;

import java.time.Duration;
import java.util.ArrayList;

public class TripBuilderImpl implements TripBuilder {

    
    private ArrayList<FlightImpl> flights = new ArrayList<FlightImpl>();
    private ArrayList<LayoverImpl> layovers = new ArrayList<LayoverImpl>();

    
    @Override
    public TripBuilder then(TripUnit nextUnit) {
        FlightImpl flight = new FlightImpl();
        LayoverImpl layover = new LayoverImpl();

        if(nextUnit.getClass() == flight.getClass()) {
            flight = (FlightImpl) nextUnit;

            for(Flight f : flights){
                if(f.getOrigin() == flight.getOrigin()){
                    throw new TUESkyException();
                }
            }

            try {
                flights.add(flight);
            }catch(TUESkyException e){}

        } else if(nextUnit.getClass() == layover.getClass()){
            layover = (LayoverImpl) nextUnit;
            layovers.add(layover);
        }


        return this;
    }

    @Override
    public Trip end() {

        Duration duration = Duration.ZERO;
        long time = duration.getSeconds();
        for(FlightImpl f : flights){
             time += f.getDuration().getSeconds();
        }
        for(LayoverImpl l : layovers){
            time += l.getDuration().getSeconds();
        }
        duration = Duration.ofSeconds(time);

        Trip trip = new TripImpl(flights.get(0).getOrigin(),
                flights.get(flights.size()-1).getDestination(),
                duration,
                flights,
                layovers);
        return trip;
    }
}
