#include "trust-manager.h"
#include <iostream>

// Constructor
TrustManager::TrustManager() {}

// Destructor
TrustManager::~TrustManager() {}

// Record authentication attempt and adjust trust score accordingly
void TrustManager::RecordAuthenticationAttempt(const std::string& nodeId, bool success) {
    if (trustScores.find(nodeId) == trustScores.end()) {
        trustScores[nodeId] = defaultTrustScore; // Initialize with default trust score
    }
    
    if (success) {
        trustScores[nodeId] += successIncrement;
    } else {
        trustScores[nodeId] -= failureDecrement;
    }
    
    // Clamp trust scores within [0, 100] range
    if (trustScores[nodeId] > 100.0) trustScores[nodeId] = 100.0;
    if (trustScores[nodeId] < 0.0) trustScores[nodeId] = 0.0;
}

// Retrieve the trust score of a given node
double TrustManager::GetTrustScore(const std::string& nodeId) const {
    auto it = trustScores.find(nodeId);
    return (it != trustScores.end()) ? it->second : defaultTrustScore;
}

/*
int main() {
    TrustManager trustManager;

    std::string node1 = "node1";
    std::string node2 = "node2";

    // Initial trust scores
    std::cout << "Initial Trust Scores:\n";
    std::cout << node1 << ": " << trustManager.GetTrustScore(node1) << "\n";
    std::cout << node2 << ": " << trustManager.GetTrustScore(node2) << "\n\n";

    // Simulate authentication attempts
    trustManager.RecordAuthenticationAttempt(node1, true);  // Success
    trustManager.RecordAuthenticationAttempt(node2, false); // Failure

    std::cout << "After Authentication Attempts:\n";
    std::cout << node1 << ": " << trustManager.GetTrustScore(node1) << "\n"; // Expected: 55
    std::cout << node2 << ": " << trustManager.GetTrustScore(node2) << "\n"; // Expected: 40

    return 0;
}
*/
