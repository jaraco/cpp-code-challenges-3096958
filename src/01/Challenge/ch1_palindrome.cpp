// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>
#include <cctype>


std::string to_lower(std::string str) {
    std::string out;
    for(int i=0; i < str.length(); i++) {
        out += std::tolower(str[i]);
    }
    return out;
}

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str){

    std::string clean = to_lower(str);

    for(int i=0; i < clean.length() / 2; i++) {
        if(clean[i] != clean[clean.length()-i-1]) return false;
    }

    return true;
}

// Main function
int main(){
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin,s);
    std::cout << "\n\"" << s << (is_palindrome(s) ? "\" is" : "\" is not" ) << " a palindrome.\n\n";
    return 0;
}
