#include "identity-revoker.h"
#include <iostream>

void IdentityRevoker::RevokeIdentity(const std::string& nodeId) {
    revokedIdentities.insert(nodeId);
}

bool IdentityRevoker::IsRevoked(const std::string& nodeId) {
    return revokedIdentities.find(nodeId) != revokedIdentities.end();
}

/*
int main() {
    IdentityRevoker revoker;
    std::string node1 = "Node1";
    std::string node2 = "Node2";
    
    std::cout << "Is " << node1 << " revoked? " << (revoker.IsRevoked(node1) ? "Yes" : "No") << std::endl;
    
    revoker.RevokeIdentity(node1);
    
    std::cout << "Is " << node1 << " revoked after revocation? " << (revoker.IsRevoked(node1) ? "Yes" : "No") << std::endl;
    std::cout << "Is " << node2 << " revoked? " << (revoker.IsRevoked(node2) ? "Yes" : "No") << std::endl;
    
    return 0;
}*/
