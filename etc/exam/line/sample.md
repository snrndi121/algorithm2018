#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(string inputString) {
    //init
    int answer = -1;
    const string inBracket ="({[<", outBracket = ")}]>";
    vector < int > in_remainings, out_remainings;
    //marker-brackets
    for (int i = 0; i < inputString.size(); ++i) {
            //brackect checking
            if (inBracket.find(inputString[i]) != -1) {
                in_remainings.push_back(i);
            }
            else if (outBracket.find(inputString[i]) != -1) {
                out_remainings.push_back(i);
            }
    }
    //exception
    if (in_remainings.size() != out_remainings.size()) return answer;
    if (in_remainings.size() == 0 && out_remainings.size() == 0) return 0;
    //compare-brackets
    answer = 0;
    for(int i  = 0; i < in_remainings.size(); ++i) {
            int idx = inBracket.find(inputString[in_remainings[i]]);
            int j = inputString.find(outBracket[idx]);
            if (in_remainings[i] > j) return -1;
            if (j != -1) {answer++;}
    }
    return answer;
}

#5
bool cmp(const pair <int, int > &a, const pair <int, int> &b)
{
        return a.second > b.second && a.first > b.first;
}
vector < vector <string > > _dataSource = {
{"doc1", "t1", "t2", "t3"}, //3
{"doc2", "t0", "t2", "t3"}, //2
{"doc3", "t1", "t6", "t7"}, //1
{"doc4", "t1", "t2", "t4"}, //2
{"doc5", "t6", "t100", "t8"}//0
};
vector <string> _tags ={"t1", "t2", "t3"};
vector<string> solution(vector<vector<string>>& dataSource, vector<string> &tags) {
    vector<string> answer;
    //소스를 돌면서 주어진 태그가 몇개냐
    //String 타입이라서 그 수 자체 비교에도
    //태그수는 0 <= docs, tags <= 100,000
    map < int, int > find_counter;
    int idx_tags = 0;
    for (int idx_tags = 0; idx_tags < tags.size(); ++idx_tags) {
        for (int i = 0; i != dataSource.size(); ++i) {
            if (find(dataSource[i].begin(), dataSource[i].end(), tags[idx_tags]) != dataSource[i].end()) {
                //이미 존재
                if (find_counter.find(i) != find_counter.end()) {
                    find_counter[i] ++;
                } else {
                    find_counter.insert(make_pair(i, 1));
                }
            }
        }
    }
    // get-TOP10
    vector < pair < int, int > > temp(find_counter.begin(), find_counter.end());
    sort(temp.begin(), temp.end(), cmp);
    for (int i = 0; i < temp.size(); ++i) {
        cout << "res " << dataSource[temp[i].first][0] << endl;
        answer.push_back(dataSource[temp[i].first][0]);
    }
    return answer;
}
