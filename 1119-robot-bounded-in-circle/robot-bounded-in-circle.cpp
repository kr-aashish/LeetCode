class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dy[] = {1,0,-1,0};
        int dx[] = {0,1,0,-1};
        
        int dirn = 0; int x = 0, y = 0;
        for(auto ins:instructions) {
            if(ins=='G') {
                x += dx[dirn];
                y += dy[dirn];
            }
            else if(ins=='L') dirn--;
            else dirn++;
            dirn = ((dirn)+4)%4;
        }
        
        return (dirn or (x==0 and y==0));
        
    }
};