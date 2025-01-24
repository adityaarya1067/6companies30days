class ThroneInheritance {
    unordered_map<string, bool> deceased;  
    unordered_map<string, vector<string>> lineage;  
    string monarch;
public:
    ThroneInheritance(string kingName) {
        monarch = kingName;
    }
    
    void birth(string parentName, string childName) {
        lineage[parentName].push_back(childName); 
    
    void death(string name) {
        deceased[name] = true;
    }
    
    void traverse(vector<string> &order, string current) {
        if (!deceased[current]) {   
            order.push_back(current);
        }
        for (string heir : lineage[current]) {
            traverse(order, heir);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> order;
        traverse(order, monarch);
        return order;
    }
};
