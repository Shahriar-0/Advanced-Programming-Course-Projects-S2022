#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > farm;
//----------------
long int
Sum(
    vector<int> v
) {
     long int sum = 0;
    for (int i = 0; i < v.size(); i++)
    sum += v[i];
    return sum;
}
//--------------------------------
void solve(int m, int n, long int& harvest){
    long int sum = 0;
    int max_row = 0;
    int maxColumn = 0;
    int row = 0;
    int column = 0;

    for(int move = 0; move < 4; move++) {
        vector<long int> row_sums;

        for(int i = 0; i < m; i++){
            sum = Sum(farm[i]);
            row_sums.push_back(sum);
            sum = 0;
        }

        for(int i = 0; i < m; i++){
            if (row_sums[i] > max_row) {
                max_row = row_sums[i];
                row = i;
            }
        }

        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                sum += farm[i][j];
            }
            if(sum > maxColumn){
                maxColumn = sum;
                column = j;
            }
            sum = 0;
        }
        if(maxColumn > max_row){
            harvest += maxColumn;
            for(int i = 0; i < m; i++){
                farm[i][column] = 0;
            }
        }
        else{
            harvest += max_row;
            for(int j = 0; j < n; j++){
                farm[row][j] = 0;
            }
        }
        row = 0;
        column = 0;
        maxColumn = 0;
        max_row = 0;
    }
}
/*----------------*/
int main() {
    int m, n;
    int    product;
    
    long int harvest = 0;
    cin>>m>> n;
    farm = vector < vector < int > > (m, vector<int>(n));
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> product;farm[i][j] = product;
        }
    
    }

    
    
    // solve
    solve(m, n, harvest);
    cout<<harvest;
    return 0;
    cout << "Hello there! I'm unreachable!" << endl;
} // main

// no reason for this comment