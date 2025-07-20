#include "geofence-manager.h"
#include <iostream>

GeofenceManager::GeofenceManager(const std::vector<Coordinates>& boundary) : geofenceBoundary(boundary) {}

bool GeofenceManager::IsInsideGeofence(double lat, double lon) const {
    double minLat = geofenceBoundary[0].latitude, maxLat = geofenceBoundary[0].latitude;
    double minLon = geofenceBoundary[0].longitude, maxLon = geofenceBoundary[0].longitude;

    for (const auto& coord : geofenceBoundary) {
        if (coord.latitude < minLat) minLat = coord.latitude;
        if (coord.latitude > maxLat) maxLat = coord.latitude;
        if (coord.longitude < minLon) minLon = coord.longitude;
        if (coord.longitude > maxLon) maxLon = coord.longitude;
    }

    return (lat >= minLat && lat <= maxLat && lon >= minLon && lon <= maxLon);
}

/*
int main() {
    std::vector<GeofenceManager::Coordinates> boundary = {
        {37.7749, -122.4194}, // San Francisco (example)
        {37.8044, -122.2711}, // Oakland
        {37.6879, -122.4702}, // Daly City
        {37.7749, -122.4194}  // Closing the loop
    };

    GeofenceManager geofence(boundary);

    double testLat = 37.78, testLon = -122.42;
    std::cout << "Test Location: (" << testLat << ", " << testLon << ")\n";
    std::cout << "Inside Geofence: " << (geofence.IsInsideGeofence(testLat, testLon) ? "Yes" : "No") << std::endl;

    return 0;
}*/

