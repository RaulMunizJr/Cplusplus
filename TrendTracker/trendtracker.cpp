//
//  trendtracker.cpp
//  hwTT1
//
//  Created by Raul Muniz on 9/1/18.
//  Copyright © 2018 Raul Muniz. All rights reserved.
//

#include "trendtracker.h"
#include <iostream>
using namespace std;

/*************************************************************/


Trendtracker::Trendtracker()
{
    
}


/*************************************************************/


// Inserts a hashtag (tweeted 0 times) into the Trendtracker.
// If the hashtag already is in Trendtracker, does nothing.
void Trendtracker::insert(string ht)
{
    Entry trend;
    int i, n = E.size();
    trend.hashtag = ht;
    trend.pop = 0;
    for (i = 0; i < n; i++) {
        if (ht == E[i].hashtag) {
            break;
        }
    }
    if(i == n)
        E.push_back(trend);
    //Push the element only if i is equal to n, that is there was no instance of the hastag to be inserted
}

/*************************************************************/


// Return the number of hashtags in the Trendtracker.
int Trendtracker::size()
{
    return E.size();
}


/*************************************************************/


// Inserts a hashtag (tweeted 0 times) into the Trendtracker.
// If the hashtag already is in Trendtracker, does nothing.
void Trendtracker::tweeted(string ht) {
    int n = E.size();
    for (int i = 0; i < n; i++) {
        if (ht == E[i].hashtag) {
            E[i].pop++;
            break;
            // Breaks if required match found
        }
    }
}


/*************************************************************/


// Returns the number of times a hashtag has been tweeted.
// If the hashtag does not exist in Trendtracker, returns -1.
int Trendtracker::popularity(string name)
{
    int i = 0;
    int n = E.size();
    bool check = 0;
    
    for (i = 0; i < n; i++) {
        if (name == E[i].hashtag) {
            check = 1;
            break;
        }
    }
    
    if (check == 1) {
        return E[i].pop;
    }
    else {
        return -1;
    }
}


/*************************************************************/


// Returns a most-tweeted hashtag.
// If the Trendtracker has no hashtags, returns "".
string Trendtracker::top_trend()
{
    if(size() == 0)
        return "";
    //return an empty string if empty
    
    int i, n, popular;
    
    //loops through Trendtracker checking for the hashtag with most tweets
    for (i = 1, n = E.size(), popular = 0; i < n; i++) {
        if (E[i].pop > E[popular].pop)
            popular = i;
    }
    return E[popular].hashtag;
}


/*************************************************************/


// Fills the provided vector with the 3 most-tweeted hashtags,
// in order from most-tweeted to least-tweeted.
//
// If there are fewer than 3 hashtags, then the vector is filled
// with all hashtags (in most-tweeted to least-tweeted order).
void Trendtracker::top_three_trends(vector<string>& T)
{
    T.clear();
    //Clears the vector for further use
    if(size() == 0)
        return;
    //Returns if trends are empty
    int n = E.size();
    Entry dummy = {"", -1};
    E.push_back(dummy);
    //Create a dummy entry with a negative value and assume its the largest
    //first, second and third point to it
    
    int i, j, first, second, third;
    for (i = 0, first = second = third = n; i < n; i++) {
        if(E[i].pop > E[first].pop) {
            third = second;
            second = first;
            first = i;
        } else if(E[i].pop > E[second].pop) {
            third = second;
            second = i;
        } else if(E[i].pop > E[third].pop) {
            third = i;
        }
    }
    
    T.push_back(E[first].hashtag);
    if(second != n && second != first)
        T.push_back(E[second].hashtag);
    if(third != n && third != second)
        T.push_back(E[third].hashtag);
    //Check if the pointers still point to the dummy variable
    //insert only if it doesn't
    E.pop_back();
    //Remove the dummy element
}
