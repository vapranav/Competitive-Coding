class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, area = INT_MIN;
        while(i<j) {
            int minHeight = min(height[i], height[j]);
            area = max(area, minHeight*(j-i));
            cout<<area<<endl;
            if(height[i]<height[j])
                i++;
            else 
                j--;
        }
        return area;
    }
};