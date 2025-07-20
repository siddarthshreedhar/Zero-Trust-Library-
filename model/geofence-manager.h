#ifndef GEOFENCE_MANAGER_H
#define GEOFENCE_MANAGER_H

#include <vector>

class GeofenceManager {
public:
    struct Coordinates {
        double latitude;
        double longitude;
    };

    explicit GeofenceManager(const std::vector<Coordinates>& boundary);
    
    bool IsInsideGeofence(double lat, double lon) const;

private:
    std::vector<Coordinates> geofenceBoundary;
};

#endif

