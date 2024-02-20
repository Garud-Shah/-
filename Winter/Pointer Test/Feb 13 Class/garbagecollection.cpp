#include <iostream>
using namespace std;
int main()
{    
    int a, *p;    
    p=&a;    
    p=new int[3];  
    cout << p;  
    cout << " " << a << endl;
    p[0]=10;p[1]=100;p[2]=200;    
    for (int i=0;i<3;i++){
        cout << p[i] << endl;
    }            
    delete [] p;
    int index = 0;
    while (true){
        int* indexptr = &p[index];
        int** dblptr = &indexptr;
        int*** triptr = &dblptr;
        cout << p[index] << " " << indexptr << " " << dblptr << " " << triptr << endl;
        index++;
        int n;
        for (int i=0; i<1000000000000; i++){
            n++;
        }
    }
    
    cout << p;  
    cout << " " << a;
    return 0;
}
