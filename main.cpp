#include <bits/stdc++.h>

using namespace std;
int L[51][51], n_col, n_row, cur_n = 1, cur_n_next = 1, s_y, s_x;
bool notfound = true;

void Read(){
    ifstream input("lab.txt");
    input >> n_row >> n_col >> s_y >> s_x;
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            input >> L[i][j];
        }
    }
    L[s_y][s_x] = 1;
}

void Print(){
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            cout << setw(5) << L[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void Field_monitor(){
    while(notfound){
    	cur_n_next ++;
        for(int i = 0; i < n_row; i++){
            for(int j = 0; j < n_col; j++){
                if(L[i][j] == cur_n){
                	if (L[i][j + 1] == -2 || L[i][j - 1] == -2 || L[i + 1][j] == -2 || L[i - 1][j] == -2){
                		notfound = false;
					}
					else{
						
						if (L[i][j + 1] == 0)
                			L[i][j + 1] = cur_n_next;
                		if (L[i][j - 1] == 0)
                			L[i][j - 1] = cur_n_next;
                		if (L[i - 1][j] == 0)
                			L[i - 1][j] = cur_n_next;
                		if (L[i + 1][j] == 0)
                			L[i + 1][j] = cur_n_next;
							
					}
                }
            }
        }
        cur_n = cur_n_next;    
    }
    for(int i = 0; i < n_row; i++){
        for(int j = 0; j < n_col; j++){
            cout << setw(5) << L[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n   minimum number of moves: " << cur_n - 1 << endl;
}

int main(){
	
    Read(); Print(); Field_monitor();
    return 0;
}
