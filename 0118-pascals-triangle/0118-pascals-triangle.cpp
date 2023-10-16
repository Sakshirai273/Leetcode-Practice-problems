class Solution {
public:
    vector<vector<int>> generate(int numRows) {
	vector<vector<int>> res;
	for (int i = 0; i < numRows; i++) {
		vector<int> row(i + 1, 1); // pehli row has 1 block , row 2 has 2 blocks and so on.
		for (int j = 1; j < i; j++) {
			row[j] = res[i - 1][j] + res[i - 1][j - 1]; // just upar wala block of upper row of array and usse piche wala block ka sum hi aata hai niche wale block me 
		}
		res.push_back(row);
	}
	return res;
    }
};

//NOTE:- To calculate the xCy(combination) of a number , pascal traingle is the most efficient solution!
