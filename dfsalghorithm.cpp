#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class vertex {

public:
    int data;
    vector <vertex*> neighbor;
    bool visited = false;
    vertex(int data) {
        this->data = data;
    }
    vertex(int data, vector<vertex*> neighbor) {
        this->data = data;
        this->neighbor = neighbor;
    }
};
void dephtfirsttraversel(vertex* current, stack<vertex*> &mystack) {
    if(current->visited == false){    
        current->visited = true;
    if(mystack.top()->neighbor.empty()){
        cout<<mystack.top()->data<<endl;
        cout<<mystack.top()->data<<"doesnt have any negihboor"<<endl;
    
        if(mystack.empty()){
            cout<<"stack is empty"<<endl;
            cout<<"traversel is done"<<endl;
            }
        else{
            mystack.pop();
            if(mystack.empty()){
                cout<<"stack is empty"<<endl;
                cout<<"traversel is done"<<endl;
                }
            else{
            dephtfirsttraversel(mystack.top(),mystack);
            /*in here there might be a problem with a singl vertexed graphs
            aka trivial graph*/
        }
        }
    }else{
        cout<<mystack.top()->data<<endl;
    for (vertex* neighbor : current->neighbor)
    {
        if(neighbor->visited == false){
            mystack.push(neighbor);
        }
    }
    dephtfirsttraversel(mystack.top(),mystack);
}
}else{
    cout<<"vertex is already visited:   **"<<current->data<<endl;
    mystack.pop();
    if(mystack.empty()){
        cout<<"stack is empty"<<endl;
        cout<<"traversel is done"<<endl;
        }
    else{
    dephtfirsttraversel(mystack.top(),mystack);
    };
};
};
int main() {
    vertex v1(1);
    vertex v2(2);
    vertex v3(3);
    vertex v4(4);
    vertex v5(5);

    // Connect vertices to form a graph (A->B->C, A->D, D->E)
    v1.neighbor.push_back(&v2);
    v2.neighbor.push_back(&v3);
    v1.neighbor.push_back(&v4);
    v4.neighbor.push_back(&v5);

    // Create a stack and push the starting vertex (A)
    stack<vertex*> mystack;
    mystack.push(&v1);

    // Perform depth-first traversal
    dephtfirsttraversel(mystack.top(), mystack);

    return 0;
};