#ifndef IDENTITY_REVOKER_H
#define IDENTITY_REVOKER_H

#include <unordered_set>
#include <string>

class IdentityRevoker {
public:
    void RevokeIdentity(const std::string& nodeId);
    bool IsRevoked(const std::string& nodeId);
    
private:
    std::unordered_set<std::string> revokedIdentities;
};

#endif
