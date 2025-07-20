#ifndef TRUST_MANAGER_H
#define TRUST_MANAGER_H

#include <ns3/core-module.h>
#include <unordered_map>
#include <string>

class TrustManager {
public:
    TrustManager();
    ~TrustManager();
    
    void RecordAuthenticationAttempt(const std::string& nodeId, bool success);
    double GetTrustScore(const std::string& nodeId) const;
    
private:
    std::unordered_map<std::string, double> trustScores;
    static constexpr double successIncrement = 5.0;
    static constexpr double failureDecrement = 10.0;
    static constexpr double defaultTrustScore = 50.0;
};

#endif // TRUST_MANAGER_H

