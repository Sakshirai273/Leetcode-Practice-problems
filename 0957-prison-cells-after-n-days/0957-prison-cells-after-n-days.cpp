class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(N == 0)
            return cells;
        prison(cells, 1);              //Prison cells for one day, The pattern repeats from day 1 - 14
        prison(cells, (N - 1) % 14);         //Simply day 14 = day 1, Day 0 never repeats because of corners  
        return cells;                               
    }
    void prison(vector<int>& cells, const int& N){
        for(int i = 0; i < N; i++){
            vector<int> v(8,0);
        for(int i = 1; i < 7; i++)
            if(cells[i - 1] == cells[i + 1])
                v[i] = 1;
            else v[i] = 0;
        cells = v;
        }
    }
};
/*
Logic:-when you write all the possible solutions then you will find that the pattern repeat itself after 14 iterations so ->
    1)if n is divisible by 14 then find pattern after exact 14 iterations
    2)else find pattern after n%14 iterations
*/