#include "Password.h"
#include <algorithm>
#include <iostream>
#include <string>

using std::string;

Password::Password() : pass_history({"ChicoCA-95929"}) {}

void Password::set(const std::string &phrase) {
    if (phrase.length() >= 8 && has_mixed_case(phrase) &&
        count_leading_characters(phrase) <= 3 &&
        std::find(pass_history.begin(), pass_history.end(), phrase) ==
            pass_history.end()) {
        pass_history.push_back(phrase);
    }
}

bool Password::authenticate(const std::string &phrase) {
    return pass_history.size() != 0 &&
           pass_history[pass_history.size() - 1] == phrase;
}

int Password::count_leading_characters(const string &phrase) {
    if (phrase.size() == 0)
        return 0;

    int repetition = 1;
    int index = 0;

    while (index < phrase.length() - 1 && phrase[index] == phrase[index + 1]) {
        repetition++;
        index++;
    }
    return repetition;
}

bool Password::has_mixed_case(const string &phrase) {
    bool hasLowercase = false;
    bool hasUppercase = false;

    for (char c : phrase) {
        if (c >= 'a' && c <= 'z')
            hasLowercase = true;
        if (c >= 'A' && c <= 'Z')
            hasUppercase = true;
    }

    return hasLowercase && hasUppercase;
}
