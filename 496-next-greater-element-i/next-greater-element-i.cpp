class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> elementToNextGreaterElement;
        stack<int> monoDecr;
        for (int i=nums2.size()-1; i>=0; --i) {
            while (!monoDecr.empty() && monoDecr.top() < nums2[i]) {
                monoDecr.pop();
            }
            elementToNextGreaterElement[nums2[i]] = -1;
            if (!monoDecr.empty()) {
                elementToNextGreaterElement[nums2[i]] = monoDecr.top();
            }
            monoDecr.push(nums2[i]);
        }

        vector<int> ans;
        for (int num: nums1) {
            ans.push_back(elementToNextGreaterElement[num]);
        }
        return ans;
    }
};