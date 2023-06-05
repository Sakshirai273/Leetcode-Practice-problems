class Solution {
public:
        bool checkStraightLine( vector<vector<int>>& coordinates ) {        int n = coordinates.size();
	int dY = coordinates[1][1] - coordinates[0][1]; // y2 - y1 
	int dX = coordinates[1][0] - coordinates[0][0];     // x2- x1
                                                                    
	for( int i=2; i <n ; i++ ) {
        
        
        int dy_i = coordinates[i][1] - coordinates[0][1];
        int dx_i = coordinates[i][0] - coordinates[0][0];
	if( dX*dy_i != dY*dx_i )
			return false;
	}
	return true;
  }
};

