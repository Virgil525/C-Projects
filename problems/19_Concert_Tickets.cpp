#include <iostream>
#include <memory>
#include <algorithm>
/*
There are n concert tickets aviailable, each with a certain price. Then, m customers arrive, one after 
another.
Each customer announces the maximum price he or she is willing to pay for a ticket, and after this,
they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input:
The frist input line contains integers n and m: the number of tickets and the number of customers.
The next line contains n integers h1,h2,...,hn: the price of each ticket.
The last line contains m integers t1,t2,...,tm: the maximum price for each customer.

Output:
Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot
be purchased again.
If a customer cannot get any ticket, print -1.

Sample input:
5 3
5 3 7 8 5
4 8 3

Sample output:
3
8
-1
*/

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    std::unique_ptr<int[]> tickets = std::make_unique<int[]>(n);
    std::unique_ptr<int[]> customer = std::make_unique<int[]>(m);
    for(int i = 0 ; i < n; i++){
        cin >> tickets[i];
    }
    for(int i = 0 ; i < m; i++){
        cin >> customer[i];
    }
    cout << endl;
    sort(tickets.get(), tickets.get()+n); // 3 5 5 7 8
    int priceIndex;
    bool foundTicket = false;
    for (int j = 0; j < m; ++j) {
        int low = 0, high = n - 1, ans = -1;
        
        // Binary search to find the most expensive ticket <= customer's max price
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (tickets[mid] <= customer[j]) {
                ans = mid;
                low = mid + 1; // Try to find a better option
            } else {
                high = mid - 1;
            }
        }

        // Print the result and mark the ticket as sold
        if (ans != -1) {
            cout << tickets[ans] << endl;
            tickets[ans] = -1; // Mark the ticket as sold
            sort(tickets.get(), tickets.get() + n); // Re-sort the tickets to maintain order
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}

/*
#define ll long long
#define ar array
const int mxN=2e5;
int n,m;

int main(){
    cin >> n >> m;
    set<ar<int,2>> s;
    for(int i = 0 ; i < n; i++){
        int a;
        cin>> a;
        s.insert({a,i});
    }
    for(int i = 0; i < m; ++1){
        int t;
        cin>> t;
        auto it=s.lower_bound({t+1, 0});
        if(it == s.begin())
            cout << "-1\n";
        else{
            --it;
            cout << (*it)[0] << "\n";
            s.erase(it);
        }
    }
}
*/