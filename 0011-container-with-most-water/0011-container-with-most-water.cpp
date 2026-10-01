class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int j=n-1;
        int width=0;
        int lambai=0;
        int area=0;
        int max_vol=0;
        for(int i=0; i<j; ){
            lambai=min(height[j],height[i]);
            width=j-i;
            area=(width*lambai);
            max_vol=max(max_vol,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }return max_vol;
    }
};