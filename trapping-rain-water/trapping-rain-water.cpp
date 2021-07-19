class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j;
        int ctr = 0;
        while(i<height.size()) {
            j = i + 1;
            //bool found = false;
            //cout<<i;
            int nextBig = j;
            while(j<height.size()) {
                if(height[j]<height[i]) {
                    if(height[j] > height[nextBig]) 
                       nextBig = j;
                    j++;
                }
                else {
                    nextBig = j;//found = true;
                    break;
                }
            }
            
            for(int k = i+1; k<nextBig; k++) {
                int minimum = min(height[i], height[nextBig]);
                ctr+=minimum - height[k];
            }
            
            i = nextBig;
        }
         return ctr;
    }
   
};