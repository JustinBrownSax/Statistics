//
//  stats.cpp
//  p1-stats
//  Project UID 5366c7e2b77742d5b2142097e51561a5
//  Created by Justin Brown on 1/8/22.
//  Copyright © 2022 Justin Brown. All rights reserved.
//

#include "stats.h"
#include <cassert>
#include <vector>
#include <cmath>
#include <iostream>
#include "p1_library.h"

using namespace std;
vector<vector<double> > summarize(vector<double> v) {
    assert(!v.empty());
    vector<vector<double>> data;
    vector<double> logic;
    sort(v);
    double a = v[0];
    double index = 0;
    double count = 1;
    
    /*
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] == a) {
            count++;
            reserve = v[i];
        }
        
    }
    */
    
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] == a) {
            count++;
        }
        else {
            logic = {};
            logic.push_back(a);
            logic.push_back(count);
            data.push_back(logic);
            a = v[i];
            index++;
            count = 1;
        }
    }
    logic = {};
    logic.push_back(a);
    logic.push_back(count);
    data.push_back(logic);
    return data;
    
    
    
}
int count(vector<double> v) {
    return v.size();
}
double sum(vector<double> v) {
  assert(!v.empty());
  double sum = 0;
  for (size_t i = 0; i < v.size(); ++i) {
      sum += v[i];
  }
  return sum;
}

double mean(vector<double> v) {
  double mean = 0;
  double total = sum(v);
  mean = total / v.size();
  return mean;
}

double median(vector<double> v) {
  sort(v);
  double median = 0;
  double index = 0;
  // if number of elements is even
  if (v.size() % 2 == 0){
      index = v.size() / 2;
      median =(v[index-1] + v[index]) / 2; }
  else {
      index = (v.size() / 2);
      median = v[index]; }
  return  median;
}

double mode(vector<double> v) {
  vector<vector<double>> mode = summarize(v);
  //loop over each vector pair, return one that has the highest mode
  double highest_count;
  double count_test;
  double reference;
  highest_count = mode[0][1];
  reference = mode[0][0];
  //for loop that wants to check mode[0][1], mode[1][1]...
  for (size_t i = 1; i < mode.size(); ++i){
      count_test = mode[i][1];
      if (count_test > highest_count){
          highest_count = mode[i][1];
          reference = mode[i][0];
      }
  }
  return reference;
}

double min(vector<double> v) {
  sort(v);
  return v[0];
}

double max(vector<double> v) {
  sort(v);
  return v[v.size() - 1];
}

double stdev(vector<double> v) {
  sort(v);
  vector<double> index(v.size());
  for (size_t i = 0; i < v.size(); ++i){
      index[i] = v[i] - mean(v);
      index[i] = pow(index[i], 2);
  }
  double sum = 0;
  for (size_t i = 0; i < v.size(); ++i) {
      sum += index[i];
  }
  double mean = 0;
  mean = sum / (v.size() - 1);
  mean = sqrt(mean);
  return mean;
}

double percentile(vector<double> v, double p) {
  sort(v);
    
   double s = v.size();
   double k;
   double q;
   
   if (p == 0) {
       q = v[0];
   }
   if (p == 1) {
       q = v[v.size() - 1];
   }
   else {
       double n = p * (s-1) + 1;
       double d = modf (n, &k);
       q = d * (v[k] - v[k-1]);
       q = v[k-1] + q;
   }
  
   return q;
}
