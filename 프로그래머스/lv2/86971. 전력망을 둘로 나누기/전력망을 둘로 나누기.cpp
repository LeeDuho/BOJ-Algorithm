#include <string>
#include <vector>

using namespace std;

int edge[101][101] = {0, };
vector<int> visited;
int result_min_diff = 987654321;
int find_node_num(int start) {
    int result = 0;
    visited[start] = 1;
    for(int i=1; i<=100; i++) {
        if(edge[start][i] == 1 && visited[i] == 0) {
            result += find_node_num(i);
        }
    }
    return result+1;
}

int solution(int n, vector<vector<int>> wires) {
    for(int i=0; i<wires.size(); i++) {
        edge[wires[i][0]][wires[i][1]] = 1;
        edge[wires[i][1]][wires[i][0]] = 1;
    }
    for(int i=0; i<wires.size(); i++) {
        visited.assign(101, 0);
        edge[wires[i][0]][wires[i][1]] = 0;
        edge[wires[i][1]][wires[i][0]] = 0;
        int diff = find_node_num(wires[i][0])-find_node_num(wires[i][1]);
        if(diff < 0) diff *= -1;
        if(diff < result_min_diff) result_min_diff = diff;
        edge[wires[i][0]][wires[i][1]] = 1;
        edge[wires[i][1]][wires[i][0]] = 1;
    }
    return result_min_diff;
}

