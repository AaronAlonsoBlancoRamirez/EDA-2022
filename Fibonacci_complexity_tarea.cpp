#include <iostream>
using namespace std;
#include <chrono>

#define R1 2            
#define C1 2            
           

void multmatrices(int mat1[][C1], int mat2[][C1]) {
    int rslt[R1][C1];
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            rslt[i][j] = 0;
            for (int k = 0; k < R1; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }  
        }
    }
    mat1[0][0] = rslt[0][0];
    mat1[0][1] = rslt[0][1];
    mat1[1][0] = rslt[1][0];
    mat1[1][1] = rslt[1][1];
}

int fib_recursivo(int n){
 if((n==1 || n==2)){
  return 1;
 }
 
  return(fib_recursivo(n-1)+fib_recursivo(n-2));
 
}


int fib_iterativo(int n)
{
    if (n <= 1) {
        return n;
    }
 
    int prevfib = 0, actualfib = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int fib = prevfib + actualfib;
        prevfib = actualfib;
        actualfib = fib;
    }
 
    return actualfib;
}

int fib_logn(int n){
  int v1,v2;
  int m_res[2][1];
  
  int m_piv[2][2] ={1,1,1,0};
  int m[2][2] ={1,1,1,0};
  int m_ult[2][1] ={1,0};
  for(int i=0;i<n-2;i++){
    multmatrices(m,m_piv);
  }
  return m[0][1]+m[1][1];
  
  
}



int main(void)
{
    int n = 10;
  
    cout<<"F(n) = "<<fib_iterativo(n)<<"\n";
    cout<<"F(n) = "<<fib_recursivo(n)<<"\n";
    cout<<"F(n) = "<<fib_logn(n)<<"\n";
  
    return 0;
}
