// #include <iostream>

// using namespace std;

// int main() 
// {
//  int n;
//  cin>>n;
//  if (n%2==0){
//  for(int i=0; i<n; i++){
//     for(int j=0; j<=i; j++){
//         cout<<"*";
//     }
//     for(int j=1; j<n-i; j++){
//     printf(" ");
//     }
//     cout<<endl;

//  }
//  }
 
//  else{
//     for(int i=0; i<n; i++){
//         for(int j=0; j<=i; j++){
//             cout<<"*";
//         }
//         for(int j=1; j<n-i; j++){
//             cout<<" ";
//         }
//         cout<<endl;
//     }
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n-i; j++){
//             printf("*");
//             }
//         for(int j=1; j<=i; j++){
//             printf(" ");
//         }
//         cout<<endl;
//     }
//  }
// return 0;
// }

// #include <iostream>

// using namespace std;

// int main() 
// {
//  int n;
//  cin>>n;
//  int m=n*2-1;
//  for(int i=0; i<m; i++){
//     for(int j=0; j<=i;j++){
//         printf("*");
//     }
//     for(int j=0; j)
//  }
// return 0;
// }


// #include <iostream>
// using namespace std;

// void pattern10(int N)
// {
//       for(int i=1;i<=2*N-1;i++){
//           int stars = i;
          
//           if(i>N) stars = 2*N-i;
          
//           for(int j=1;j<=stars;j++){
//              cout<<"*";
//           }
          
//           cout<<endl;
//       }
// }

// int main()
// {
//     int N = 4;
//     pattern10(N);
//     return 0;
// }