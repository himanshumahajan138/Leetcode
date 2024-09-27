// Sweep Line - Approach

class MyCalendarTwo {
public:
    map<int, int> events;
    
    MyCalendarTwo() {
        // Nothing to do here
    }
    
    bool book(int start, int end) {
        // First Add the event
        // Increment start by +1 (start of booking)
        events[start]++;
        // Decrement end by -1 (end of booking)
        events[end]--;
        
        // sum of all booking at particular event
        int activeBookings = 0;
        
        // Sweep through the events in chronological order
        for (auto &event : events) {
            // get all the sum
            activeBookings += event.second;
            
            // If we have 3 or more overlapping bookings, it's a triple booking
            if (activeBookings >= 3) {
                // Revert the changes, as the booking is not valid
                events[start]--;
                events[end]++;
                
                // delete from map, as they are not of need
                if (events[start] == 0) {events.erase(start);}
                if (events[end] == 0) {events.erase(end);}

                return false;
            }

            if(event.first > end){
                break;
            }
        }
        
        // Booking is successful if no triple booking is found
        return true;
    }
};