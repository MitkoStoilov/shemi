package org.elsys.tuesky.impl.planner;

import org.elsys.tuesky.api.TUESkyException;
import org.elsys.tuesky.api.planner.Planner;
import org.elsys.tuesky.api.trips.Trip;
import org.elsys.tuesky.impl.AbstractTripQuery;
import org.elsys.tuesky.impl.Factory;
import org.elsys.tuesky.impl.Trips;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.time.Duration;
import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class PlannerTest {

    public Planner createPlanner(){
        Trip trip1 = Factory.startTrip()
                .then(Factory.createFlight("Varna", "Athens", Duration.ofHours(1)))
                .end();
        Trip trip2 = Factory.startTrip()
                .then(Factory.createFlight("Sofia", "Varna", Duration.ofHours(1)))
                .end();

        Trip trip3 = Factory.startTrip()
                .then(Factory.createFlight("Sofia", "Eindhoven", Duration.ofHours(1)))
                .then(Factory.createLayover(Duration.ofMinutes(90)))
                .then(Factory.createFlight("Eindhoven", "London", Duration.ofHours(1)))
                .then(Factory.createLayover(Duration.ofMinutes(210)))
                .then(Factory.createFlight("London", "Havana", Duration.ofHours(10)))
                .end();

        Trip trip4 = Factory.startTrip()
                .then(Factory.createFlight("Sofia", "Eindhoven", Duration.ofHours(1)))
                .then(Factory.createLayover(Duration.ofMinutes(90)))
                .then(Factory.createFlight("Eindhoven", "Havana", Duration.ofHours(10)))
                .end();

        Trip trip5 = Factory.startTrip()
                .then(Factory.createFlight("Sofia", "London", Duration.ofHours(1)))
                .then(Factory.createLayover(Duration.ofMinutes(90)))
                .then(Factory.createFlight("London", "Havana", Duration.ofHours(10)))
                .end();

        List<Trip> trips = new ArrayList<>();
        trips.add(trip1);
        trips.add(trip2);
        trips.add(trip3);
        trips.add(trip4);
        trips.add(trip5);

        Planner planner = Factory.createPlanner(trips);
        return  planner;
    }

    @Test
    public void testOriginSearch() {

        Planner planner = createPlanner();

        List<Trip> result = planner.search(Trips.withOrigin("Sofia"));
        assertEquals(4, result.size());

    }


    @Test
    public void testOriginAndDestinationSearch() {

        Planner planner = createPlanner();

        List<Trip> result = planner.search(Trips.withOrigin("Sofia")
                .and(Trips.withDestination("Havana")));

        assertEquals(3, result.size());
    }

    @Test
    public void testAndWithAnd() {

        Planner planner = createPlanner();

        List<Trip> result = planner.search(Trips.withOrigin("Sofia")
                .and(Trips.withDestination("Havana").and(Trips.via("London"))));

        assertEquals(2, result.size());
    }

    @Test
    public void testSearchWithOr() {

        Planner planner = createPlanner();

        List<Trip> result = planner.search(Trips.withOrigin("Sofia")
                .and(Trips.withDestination("Havana").or(Trips.withDestination("Varna"))));

        assertEquals(4, result.size());
    }

    @Test
    public void testMaxDuration() {

        Planner planner = createPlanner();

        List<Trip> result = planner.search(Trips.withOrigin("Sofia")
                .and(Trips.withDestination("Havana").and(Trips.withMaxDuration(Duration.ofHours(14)))));

        assertEquals(2, result.size());
    }

    @Test
    public void testMaxLayoverDuration() {

        Planner planner = createPlanner();

        List<Trip> result = planner.search(Trips.withOrigin("Sofia")
                .and(Trips.withDestination("Havana").and(Trips.withMaxLayoverDuration(Duration.ofMinutes(90)))));

        assertEquals(2, result.size());
    }


    @Test
    public void testMaxFlights() {

        Planner planner = createPlanner();

        List<Trip> result = planner.search(Trips.withOrigin("Sofia")
                .and(Trips.withDestination("Havana").and(Trips.withMaxFlights(2))));

        List<Trip> result2 = planner.search(Trips.withMaxFlights(2));


        assertEquals(2, result.size());
        assertEquals(4, result2.size());
    }

    @Test
    public void testNot() {
        Planner planner = createPlanner();

        List<Trip> result = planner.search(Trips.withOrigin("Sofia")
                .and(Trips.withDestination("Havana").not()));

        assertEquals(1, result.size());
    }

    @Test
    public void testCount() {
        Planner planner = createPlanner();

        int count = planner.count(Trips.withOrigin("Sofia")
                .and(Trips.withDestination("Havana")));

        assertEquals(3, count);
    }

    @Test
    public void testAnyMatch() {
        Planner planner = createPlanner();

        boolean anyMatch = planner.anyMatch(Trips.withOrigin("Varna")
                .and(Trips.withDestination("Athens")));

        boolean anyMatch2 = planner.anyMatch(Trips.withOrigin("Sofia")
                .and(Trips.withDestination("New York")));

        assertTrue(anyMatch);
        assertFalse(anyMatch2);
    }

    @Test
    public void testTripMatches() {
        Trip trip = Factory.startTrip()
                .then(Factory.createFlight("Sofia", "Varna", Duration.ofHours(1)))
                .end();

        boolean match = trip.matches(Trips.withOrigin("Sofia").and(Trips.withDestination("Varna")));
        assertTrue(match);
    }

    @Test
    public void testQueryMatches() {
        Trip trip = Factory.startTrip()
                .then(Factory.createFlight("Sofia", "Varna", Duration.ofHours(1)))
                .end();

        boolean match = Trips.withOrigin("Sofia").matches(trip);
        assertTrue(match);
    }
}
