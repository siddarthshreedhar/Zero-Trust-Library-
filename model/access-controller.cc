#include "access-controller.h"
#include <iostream>
AccessController::AccessController() {}

AccessController::~AccessController() {}

void AccessController::AddAuthorizedNode(const std::string& nodeId) {
    authorizedNodes.insert(nodeId);
}

void AccessController::RemoveAuthorizedNode(const std::string& nodeId) {
    authorizedNodes.erase(nodeId);
}

bool AccessController::IsAuthorized(const std::string& nodeId) const {
    return authorizedNodes.find(nodeId) != authorizedNodes.end();
}
/*
int main() {
    AccessController ac;
    
    std::string node1 = "Node1";
    std::string node2 = "Node2";
    
    ac.AddAuthorizedNode(node1);
    std::cout << "Is " << node1 << " authorized? " << (ac.IsAuthorized(node1) ? "Yes" : "No") << std::endl;
    std::cout << "Is " << node2 << " authorized? " << (ac.IsAuthorized(node2) ? "Yes" : "No") << std::endl;
    
    ac.RemoveAuthorizedNode(node1);
    std::cout << "Is " << node1 << " authorized after removal? " << (ac.IsAuthorized(node1) ? "Yes" : "No") << std::endl;
    
    return 0;
}*/

