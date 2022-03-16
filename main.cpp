//
//  main.cpp
//  p1-stats
//  Project UID 5366c7e2b77742d5b2142097e51561a5
//  Created by Justin Brown on 1/8/22.
//  Copyright © 2022 Justin Brown. All rights reserved.
//

#include <stdio.h>
#include "stats.h"
#include "p1_library.h"
#include <iostream>
using namespace std;
int main() {
    string filename;
    string columnname;
    
    cout << "enter a filename" << endl;
    cin >> filename;
    
    cout << "enter a column name" << endl;
    cin >> columnname;
    
    cout << "reading column " << columnname << " from " << filename << endl;
    vector <double> data = extract_column(filename, columnname);
    
    cout << "Summary (value: frequency)" << endl;
    sort(data);
    vector<vector<double>> summary = summarize(data);
    
    for (size_t i = 0; i < data.size(); i++) {
        cout << summary[i][0] << ": " << summary[i][1] << endl;
        }
    
    cout << endl;
    cout << "count = " << count(data) << endl;
    cout << "sum = " << sum(data) << endl;
    cout << "mean = " << mean(data) << endl;
    cout << "stdev = " << stdev(data) << endl;
    cout << "median = " << median(data) << endl;
    cout << "mode = " << mode(data) << endl;
    cout << "min = " << min(data) << endl;
    cout << "max = " << max(data) << endl;
    
    cout << "  0th percentile = " << percentile(data, 0) << endl;
    cout << " 25th percentile = " << percentile(data, .25) << endl;
    cout << " 50th percentile = " << percentile(data, .50) << endl;
    cout << " 75th percentile = " << percentile(data, .75) << endl;
    cout << "100th percentile = " << percentile(data, 1) << endl;
}
