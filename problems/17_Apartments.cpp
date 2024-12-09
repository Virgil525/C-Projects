#include <iostream>
#include <array>
#include <memory>
#include <algorithm>

/*
There n appliccants and m free apartments. Your task is to distribute the partments so that
as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, and they will accept any apartment whose size is
close enough to the desired size.

Input:
The first input line has three integers n,m and k: the number of applicants, the number of apartments,
and the maximum allowed difference.
The next line contains n integers a1,a2,a3,...,an: the desired apartment size of each applicant.
If the desired size of an applicant is x, he or she will accept and apartment whose size is between x-k and
x + k.
The last line contains m integers b1,b2,...,bm: The size of each apartment

Output:
Print one integer: the number of applicants who will get an apartment.

Sample input:
4 3 5
60 45 80 60
30 60 75
Sample output:
2
*/

using namespace std;
int main() {
    int applicants, apartments, differenceAllowed;
    cin >> applicants >> apartments >> differenceAllowed;
    std::unique_ptr<int[]> sizes = std::make_unique<int[]>(applicants);
    std::unique_ptr<int[]> apartmentSizes = std::make_unique<int[]>(apartments);
    for(int i = 0; i < applicants; i++){
        cin >> sizes[i];
    }
    for(int i = 0; i < apartments; i++){
        cin >> apartmentSizes[i];
    }
    int ans = 0;
    std::sort(sizes.get(),sizes.get() + applicants);
    std::sort(apartmentSizes.get(),apartmentSizes.get() + apartments);
    for(int i = 0, j = 0; i < applicants; ++i){
        while(j < apartments && apartmentSizes[j]<(sizes[i]-differenceAllowed))
            j++;
        if(j < apartments && apartmentSizes[j] <= (sizes[i] + differenceAllowed)){
            ans++;
            j++;
        }
    }
    cout << ans;

    return 0;
}

