class Solution {
public:
    int maxArea(vector<int>& height) {
        int min_index=0, max_index=height.size()-1, min_height=height[0], max_height=height[height.size()-1];
        if(max_height < min_height){
            min_height = max_height;
            min_index = max_index;
            max_height = height[0];
            max_index = 0;
        }

        int width = height.size()-1;
        int area = min_height*width;

        while(width > 0){
            int index = min_index;
            while(height[index] <= min_height){
                (min_index < max_index) ? index++ : index--;
                width--;
                if(width<1) break;
            }

            if(height[index] > max_height){
                min_height = max_height;
                min_index = max_index;
                max_height = height[index];
                max_index = index;
            }else{
                min_height = height[index];
                min_index = index;
            }
            area = max(area, min_height*width);
        }

        return area;
    }
};
