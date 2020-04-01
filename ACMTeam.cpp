vector<int> acmTeam(vector<string> topic) {

int numStrings = topic.size();
int sizeStrings = topic[1].size();
vector<int> ans;

int answer = 0;
int count = 0;

for(int i=0; i<numStrings; i++) {
    for(int j = i+1; j<numStrings; j++) {
        int value = 0;
        for(int k = 0; k<sizeStrings; k++) {
            if(topic[i][k] == '1' || topic[j][k] == '1') {
                value++;
            }
        }
        if(value>answer) {
            answer = value;
            count =1;
        }
        else if(value == answer) {
            count++;
        }
    }
}
ans.push_back(answer);
ans.push_back(count);
return ans;
}
