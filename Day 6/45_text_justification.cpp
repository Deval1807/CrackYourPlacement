/*
Link: https://leetcode.com/problems/text-justification/
Method: 
Time Complexity: O(n)
Space Complexity: o(n)
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> v;
        vector<string> line;
        int l = 0;
        int w = 0;

        while(l<words.size()){
            string curWord = words[l];

            if(w + curWord.length() <= maxWidth){
                line.push_back(curWord);
                w += curWord.length() + 1;
                l++;
            }else{
                int space = maxWidth - w + line.size();

                int added = 0;
                int x = 0;

                while(added < space){
                    if(x>=line.size()-1){
                        x = 0;
                    }
                    line[x] += " ";
                    added++;
                    x++;
                }

                string linestr = "";
                for(auto word : line){
                    linestr += word;
                }
                v.push_back(linestr);

                line.clear();
                w = 0;
            }

        }

        for(int i = 0; i<line.size() - 1; i++){
            line[i]+=" ";
        }
        line[line.size() - 1] +=  string(maxWidth - w + 1, ' ');

        string lastLine = "";

        for(auto i : line){
            lastLine += i;
        }

        v.push_back(lastLine);

        return v;

    }
};