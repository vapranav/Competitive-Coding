vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

//initialize sizes and rank vector
int scoreSize = scores.size();
int aliceSize = alice.size();
int prevElement = 0;
vector<int> rank;

//For all of Alice's scores
for(int i = 0; i<aliceSize; i++) {
    int counter = 1;

    //Loop through all distinct scores and increment rank if it's lesser than score[i]
    for(int j = 0; j<scoreSize; j++) {
        if(scores[j] != prevElement) {
            if(scores[j]>alice[i]) {
                counter++;
            }
        }
        prevElement = scores[j];
    }
    rank.push_back(counter);
}
return rank;
}
