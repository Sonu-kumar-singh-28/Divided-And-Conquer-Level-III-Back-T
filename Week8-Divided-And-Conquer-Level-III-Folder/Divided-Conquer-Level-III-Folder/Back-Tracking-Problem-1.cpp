// Rat in a mage  interseting problems

#include<iostream>
#include<vector>
using namespace std;

bool issafe(int i, int j, int rows, int column, int mage[][3], vector<vector<bool>>& visited) 
{
    if ((i >= 0 && i < rows) && (j >= 0 && j < column) && (mage[i][j] == 1) && (visited[i][j]) == false) {
        return true;
    }
    return false;
}


void solvemage(int mage[3][3], int rows, int column, int i, int j,
vector<vector<bool>> &visited,vector<string> &path,string output)
{
    if(i == rows-1 && j== column-1)
    {
        path.push_back(output);
        return ;
    }

    // down 
    if(issafe(i+1,j, rows,column,mage,visited)){
        visited[i+1][j] = true;
        solvemage(mage,rows, column, i+1,j,visited,path,output + 'D');

        // backtrack
        visited[i+1][j] = false;
    }
    // left 

    if(issafe(i,j-1, rows,column,mage,visited)){
        visited[i][j-1] = true;
        solvemage(mage,rows, column, i,j-1,visited,path,output + 'L');

        // backtrack
        visited[i][j-1] = false;
    }
    // right

    if(issafe(i,j+1, rows,column,mage,visited)){
        visited[i][j+1] = true;
        solvemage(mage,rows, column, i,j+1,visited,path,output + 'R');

        // backtrack
        visited[i][j+1] = false;
    }
    // up

    if(issafe(i-1,j, rows,column,mage,visited)){
        visited[i-1][j] = true;
        solvemage(mage,rows, column, i-1,j,visited,path,output + 'U');

        // backtrack
        visited[i-1][j] = false;
    }

}

int main()
{
    int mage[3][3] = {{1,0,0}
                     ,{1,1,0},
                     {1,1,1}};
    int rows =3;
    int column= 3;

    if(mage[0][0] == 0)
    {
        cout<<"No path Exists " << endl;
        return 0;
    }
    
    cout<< endl;
    vector<vector<bool>>visited(rows,vector<bool>(column,false));

    visited[0][0] = true;

    vector<string>path;
    string output=" ";

    solvemage(mage,rows,column,0,0,visited, path,output);
    
    cout<< " printing the  results" << endl;
    for(auto i : path)
    {
        cout<< i << " ";
    }

    if(path.size()==0)
    {
        cout<<" no path exists " << endl;
    }

    return 0;
}