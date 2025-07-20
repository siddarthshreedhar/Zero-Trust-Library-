#ifndef ACCESS_CONTROLLER_H
#define ACCESS_CONTROLLER_H

#include <unordered_set>
#include <string>

class AccessController {
public:
    AccessController();
    ~AccessController();
    
    void AddAuthorizedNode(const std::string& nodeId);
    void RemoveAuthorizedNode(const std::string& nodeId);
    bool IsAuthorized(const std::string& nodeId) const;
    
private:
    std::unordered_set<std::string> authorizedNodes;
};

#endif
