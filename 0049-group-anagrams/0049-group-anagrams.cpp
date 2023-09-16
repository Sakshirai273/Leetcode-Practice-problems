class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
      unordered_map<string,vector<string>>map1;  // declaring an map that will store all anagrams for a particular string ,
     //example:- mp[ate] = [ate,eat,tea]   here (string = ate & vector<string> = [ate,eat,tea]) which means key value is sorted string and vector store the anagrams
       
      for(auto i:s) {  // loop to start storing after sorting the string
        string str=i;
        sort(i.begin(),i.end()); // sort for checking that we have already this string or not in our map  
        map1[i].push_back(str); // after checking push current string value in corresponding sorted value
      }    
        
      vector<vector<string>>output; //to store the output 
        
     for(auto i:map1)  //iterate over the map, storing the angrams for every unique string that we got after sort
        output.push_back(i.second); 
    return output;
    }
};
        