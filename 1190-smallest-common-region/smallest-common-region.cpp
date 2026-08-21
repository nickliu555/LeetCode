class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> regionToParent;
        for (vector<string> region: regions) {
            for (int i=1; i<region.size(); ++i) {
                regionToParent[region[i]] = region[0];
            }
        }

        unordered_set<string> ancestryRegion1;
        while (regionToParent.count(region1) > 0) {
            ancestryRegion1.insert(region1);
            region1 = regionToParent[region1];
        }
        ancestryRegion1.insert(region1);

        while (ancestryRegion1.count(region2) == 0) {
            region2 = regionToParent[region2];
        }
        return region2;
    }
};