class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n_rows = matrix.size();
            int n_cols= matrix[0].size();

            //first, find the row that may contain our number
            int r_l=0, r_h = n_rows-1;
            while(r_l<=r_h)
            {
                int r_m = r_l + (r_h-r_l)/2;
                int left=0, right = n_cols-1;
                
                if(matrix[r_m][left] > target)  r_h = r_m -1;
                else if(matrix[r_m][right] < target) r_l = r_m + 1;
                else //the target must exist within this row
                {
                    while(left<=right)
                    {
                        int m = left + (right-left) / 2;
                        if(matrix[r_m][m] > target) right = m - 1;
                        else if(matrix[r_m][m] < target) left = m + 1;
                        else return true;
                    }
                    return false;
                }
            }
        return false;
    }
};
