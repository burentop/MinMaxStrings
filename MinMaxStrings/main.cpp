//
//  main.cpp
//  MinMaxStrings
//
//  Created by Brent Perry on 7/10/16.
//  Copyright © 2016 Brent Perry. All rights reserved.
//

#include "../../../std_lib_facilities.h"

int main()
{
    vector<string> user_input;
    string current_mode, min, max;
    int running_count = 0;
    int count_of_mode = 0;
    bool to_continue = true;
    
    while (to_continue) {
        string to_input;
        cout << "Please enter a word (enter 'q' to quit): ";
        cin >> to_input;
        if (to_input == "q") {
            to_continue = false;
            break;
        }
        user_input.push_back(to_input);
        cout << "\n";
    }
    
    sort(user_input);
    min = user_input[0];
    max = user_input[int (user_input.size() - 1)];
    
    current_mode = user_input[0];
    running_count = 1;
    
    for (int i = 1; i < user_input.size(); ++i) {
        if (user_input[i] == user_input[i - 1]) {
            ++running_count;
        } else {
            running_count = 1;
        }
        
        if (running_count > count_of_mode) {
            current_mode = user_input[i];
            count_of_mode = running_count;
        }
    }
    
    cout << "\n";
    cout << "The 'min' word you entered was " << min << ".\n";
    cout << "The 'max' word you entered was " << max << ".\n";
    cout << "The mode of the words you entered is " << current_mode << ".\n";
    cout << "\n";
    
}