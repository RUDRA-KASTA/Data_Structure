

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Q. Find the sub array of 3 size with sum maximum.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

#include <iostream>
#define MAX_SIZE 10

int main()
{
    int arr[MAX_SIZE]={56,15,25,35,65,52,57,41,27,68};
    int ws = arr[0]+arr[1]+arr[2];
    int max=ws,index=0;
    for(int i=0;i<MAX_SIZE-3;i++)
    {
        ws = ws-arr[i]+arr[i+3];
        if(ws>max)
        {
            max=ws;
            index=i;
        }
    }

    std::cout << "the max value is : " << max << '\n';
    std::cout << "the Index is : " << index+1 << '\n';

    return 0;
}
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Q. Find the first -ve no in every window size N
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////    My First Approach (brute Force approch)   /////////////////////////////////////

/*
#include <iostream>
#define MAX_SIZE 10
#define WINDOW_SIZE 3

int main()
{
    int arr[MAX_SIZE]={25,-54,84,35,-75,65,78,91,51,11};
    int i=0,j=0;
    int ws = 0, max = ws, key = 0, flag=0;

    for(int i=0; i<(MAX_SIZE-WINDOW_SIZE) ; i++)
    {
        for(int j=i ; j<(i+WINDOW_SIZE) ; j++)
        {
            if(arr[j]<0)
            {
                key=arr[j];
                flag=1;
                break;
            }
        }
        if(flag)
        {
            std::cout << key << '\n';
            flag=0;
        }
        else
            std::cout << "0" << '\n';
    }
    return 0;
}
*/

///////////////////////////////////////////////////    Best Approach    ///////////////////////////////////////////////////////////
//
////////////   Approch   ////////////
//
//              __________
//   window->  |          |         (eg. window size = 4)
//   arr->     |  |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_ ......
//             |__________|
//                 ^     ^
//                 i     j
//
//////////////////////////////////////////////////////////
//  while(j<size)                                       //
//  {                                                   //
//     i) calculation....                               //
//                                                      //
//     ii) if(j-i+1<window_size)                        //
//            j++;                                      //
//                                                      //
//     iii) else if(j-i+1 == window size)               //
//            ->  answer to the calculation             //
//            ->  increment i , j                       //    
//  }                                                   //
//////////////////////////////////////////////////////////

/*

//#include <bits/stdc++.h>         //this header file include all the basic header files
#include <iostream>
#include <list>
#include <vector>

#define MAX_SIZE 10
#define WINDOW_SIZE 3

int i=0,j=0;
int main()
{
    int arr[MAX_SIZE]={25,-54,84,35,-75,-65,78,91,51,11};
    std::list <int> l;
    std::vector <int> v;

    while(j<MAX_SIZE)
    {
        if(arr[j]<0)
            l.push_back(arr[j]);
        if(j-i+1<WINDOW_SIZE)
            j++;
        else if(j-i+1 == WINDOW_SIZE)
        {
            if(l.size()==0)
                v.push_back(0);
            else
            {
                v.push_back(l.front());
                if(arr[i] == l.front())
                    l.pop_front();
            }
            i++;
            j++;
        }
    }
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    return 0;
}
*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Q. Count occurrences of Anagram.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::string str = "rkrsrkrsskrsks";
    std::string ptn = "rsk";

    int size = str.length();
    int wind_size = ptn.length();
    int i=0,j=0,cnt=0;
    std::list <int> l;
    std::vector <int> v;

    while(j<size)
    {
        if(str[j]==ptn[0] || str[j]==ptn[1] || str[j]==ptn[2])
            l.push_back(str[i]);
        if(i-j+1<wind_size)
            j++;
        else if(i-j+1==wind_size)
        {
            if(l.size()==wind_size)
            {
                cnt++;
                
            }
            else
            {

            }
            i++;
            j++;
        }
    }
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Q. Return the maximum of all sub array.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





