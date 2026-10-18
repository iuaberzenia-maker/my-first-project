#include <iostream>


const int MAX = 20;

int graph[MAX][MAX];
int path[MAX];     
int n;              

bool isSafe(int v, int pos) {
       if (graph[path[pos - 1]][v] == 0) {
        return false;
    }
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }

    return true;
}

bool findHamiltonian(int pos) {
    
    if (pos == n) {
        
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true; 
        }
        return false;
    }

       for (int v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v; 

              if (findHamiltonian(pos + 1)) {
                return true;
            }

           
            path[pos] = -1;
        }
    }

    return false;
}

int main() {
         std::cin >> n;

   
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

   
    for (int i = 0; i < n; i++) {
        path[i] = -1;
    }

   
    path[0] = 0;

   
    if (findHamiltonian(1) == false) {
        std::cout << "\nGalmiltonov tsikl ne nayden.\n";
        return 0;
    }

   
    std::cout << "\nGalmiltonov tsikl uspeshno nayden:\n";
    for (int i = 0; i < n; i++) {
        std::cout << path[i] + 1 << " -> ";
    }
    std::cout << path[0] + 1 << "\n"; 

    return 0;
}