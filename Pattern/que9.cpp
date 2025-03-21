// #include <iostream>

// using namespace std;

// int main() 
// {
//  int n;
//  cin>>n;
//  for(int i=0; i<n; i++){
//     for(int j=0; j<n-1-i; j++){
//       printf(" ");
//     }
//     for(int j=1;j<=i*2+1;j++){
//       printf("*");
//     }
//     for(int j=0; j<n-1-i; j++){
//       printf(" ");
//    }
//     printf("\n");
//  }
//   for (int i=0; i<n; i++){
//     for (int j=0; j<i; j++){
//         printf(" ");
//     }
//     for (int j=0; j<2*n-(2*i+1); j++){
//         printf("*");
//     }
//     for (int j=0; j<i;j++){
//         printf(" ");
//     }
//     cout<<endl;
//  }
// return 0;
// }


#include <iostream>

using namespace std;

int main() 
{
 int n;
 cin>>n;
 for (int i=0; i<n; i++){
    for(int j=0; j<n-1-i; j++){
        printf(" ");
    }
    for (int j=1; j<=i*2+1; j++){
        printf("*");
    }
    for(int j=0; j<n-1-i; j++){
        printf(" ");
    }
    cout<<endl;
 }
 for (int i=0; i<n; i++){
    for(int j=0; j<i; j++){
        printf(" ");
    }
    for (int j=1; j<=(n-i)*2-1; j++){
        printf("*");
    }
    for(int j=0; j<i; j++){
        printf(" ");
    }
    cout<<endl;
 }
return 0;
}