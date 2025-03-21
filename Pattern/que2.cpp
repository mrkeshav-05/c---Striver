// #include <iostream>

// using namespace std;

// int main() 
// {
//  int x;
//  cin >> x;
//  for(int i = 0; i <=x; i++){
//     for(int j=1; j<=i; j++){
//         cout <<"* ";
//  }
//  cout <<endl;
//  }
// return 0;
// }

#include <iostream>

using namespace std;
void pattn2(int x){
    for (int i=0; i<x; i++)
    {
        for (int j=0; j<i; j++){
            printf("* ");
    }
    printf("\n");
    }
}

int main() 
{
 int n;
 cin >> n;
 pattn2(n);
return 0;
}