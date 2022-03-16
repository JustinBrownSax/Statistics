/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include "p1_library.h"
using namespace std;

void test_sum_small_data_set();
void test_summarize();
void test_count();
void test_sum();
void test_mean();
void test_median();
void test_mode();
void test_min();
void test_max();
void test_stdev();
void test_percentile();

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  test_summarize();
  test_count();
  test_sum();
  test_mean();
  test_median();
  test_mode();
  test_min();
  test_max();
  test_stdev();
  test_percentile();

  return 0;
}

void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS 1 of 2!" << endl;
  
  vector<double> data2;
  data2.push_back(0);
  data2.push_back(0);
  data2.push_back(0);

  assert(sum(data2) == 0);

  cout << "PASS 2 of 2!" << endl;
    
}

void test_summarize(){
    cout << "test_summarize" << endl;

    vector<double> data;
    data.push_back(5);
    data.push_back(12);
    data.push_back(0);
    data.push_back(5);
    data.push_back(3);
    data.push_back(12);
    data.push_back(12);
    data.push_back(0);
    data.push_back(20);
    data.push_back(3);
    
    vector<vector<double>> result = summarize(data);
    
    assert((result[0][0]) == 0);
    cout << "PASS 1 of 2" << endl;
    assert((result[0][1]) == 2);
    cout << "PASS 2 of 2" << endl;
    
    
}

void test_count(){
    cout << "test_count" << endl;
    
    vector<double> data;
    
    data.push_back(1);
    data.push_back(4);
    data.push_back(27);
    data.push_back(3);
    
    assert(count(data) == 4 );
    
    cout << "PASS 1 of 2!" << endl;
    
    vector<double> data2;
    data2.push_back(9);
    data2.push_back(0);

    
    assert(count(data2) == 2 );
    
    cout << "PASS 2 of 2!" << endl;
}

void test_sum(){
    cout << "test_sum" << endl;
    vector<double> data3;
    
    data3.push_back(25);
    data3.push_back(50);
    data3.push_back(25);
    data3.push_back(0);
    
    assert(sum(data3) == 100);
    
    cout << "PASS!" << endl;
    
}

void test_mean(){
    cout << "test_mean" << endl;
    vector<double> data4;
    
    data4.push_back(3);
    data4.push_back(20);
    data4.push_back(12);
    data4.push_back(0);
    data4.push_back(5);
    
    assert(mean(data4) == 8);
    
    cout << "PASS!" << endl;
}

void test_median(){
    cout << "test_median" << endl;
    vector<double> data5;
    data5.push_back(3);
    data5.push_back(17);
    data5.push_back(5);
    data5.push_back(32);
    data5.push_back(41);
    
    sort(data5);
    
    assert(median(data5) == 17);
    
    cout << "PASS 1 of 2!" << endl;
    
    vector<double> data52;
    data52.push_back(3);
    data52.push_back(17);
    data52.push_back(5);
    data52.push_back(32);
    data52.push_back(41);
    data52.push_back(23);
    
    sort(data52);
    
    assert(median(data52) == 20);
    
    cout << "PASS 2 of 2!" << endl;
    
}


void test_mode(){
    cout << "test_mode" << endl;
    vector<double> data6;
    data6.push_back(4);
    data6.push_back(19);
    data6.push_back(4);
    data6.push_back(19);
    data6.push_back(19);
    data6.push_back(11);
    data6.push_back(11);
    
    
    assert(mode(data6) == 19);
    
    cout << "PASS!" << endl;
    
}



void test_min(){
    cout << "test_min" << endl;
    vector<double> data7;
    data7.push_back(3);
    data7.push_back(1);
    data7.push_back(12);
    data7.push_back(6);
    
    sort(data7);
    assert(min(data7) == 1);
    
    cout << "PASS!" << endl;
    
}

void test_max(){
    cout << "test_max" << endl;
       vector<double> data8;
       data8.push_back(3);
       data8.push_back(1);
       data8.push_back(12);
       data8.push_back(6);
       
        sort(data8);
       assert(max(data8) == 12);
       
       cout << "PASS!" << endl;
}

void test_stdev(){
    cout << "test_stdev" << endl;
    vector<double> data9;
    data9.push_back(5);
    data9.push_back(0);
    data9.push_back(19);
    data9.push_back(12);
    data9.push_back(7);
    
    cout << stdev(data9) << endl;
    assert(stdev(data9) - 0.00001 < 7.23187389);
    assert(stdev(data9) + 0.0001 > 7.23187389);
    cout << "PASS!" << endl;
}

void test_percentile(){
    cout << "test_percentile" << endl;
    vector<double> data10;
    data10.push_back(6);
    data10.push_back(13);
    data10.push_back(2);
    data10.push_back(15);
    data10.push_back(9);
    data10.push_back(5);
    
    cout << percentile(data10, 0) << endl;
    assert (percentile(data10, 0) == 2);
    cout << "PASS 1 of 5" << endl;
    
    cout << percentile(data10, .25) << endl;
    assert (percentile(data10, .25) == 5.25);
    cout << "PASS 2 of 5" << endl;
    
    cout << percentile(data10, .50) << endl;
    assert (percentile(data10, .50) == 7.5);
    cout << "PASS 3 of 5" << endl;
    
    cout << percentile(data10, .75) << endl;
    assert (percentile(data10, .75) == 12);
    cout << "PASS 4 of 5" << endl;
    
    cout << percentile(data10, 1) << endl;
    assert (percentile(data10, 1) == 15);
    cout << "PASS 5 of 5" << endl;
}
   

// Add the test function implementations here.
