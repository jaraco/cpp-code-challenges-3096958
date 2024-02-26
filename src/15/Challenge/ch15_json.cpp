// C++ Code Challenges, LinkedIn Learning

// Challenge #15: JSON File Validation
// Write an application that reads a JSON file and checks if it's valid or not.
// Test the bracket balance (curly and square), and quote balance. 
// Assume simple content with no escape characters inside strings.
// Only count double quotes ("), not single quotes (').
// The application outputs a message indicating if the JSON file passed the tests or not.

#include <iostream>
#include <fstream>
#include <string>
#include <stack>


int check_valid_JSON(std::string rest) {
    std::stack<char> context;

    while(rest.length()) {
        int pos = rest.find_first_of("[]{}\"");
        if(pos == std::string::npos) {
            // no more characters; return true if the context is empty
            return context.empty();
        }
        if(rest[pos] == '"') {
            // jump to the close quote
            pos = rest.find_first_of("\"");
            if(pos == std::string::npos) {
                // unmatched quote
                return 0;
            }
        }
        else{
            switch(rest[pos]) {
            case '[':
                context.push('['); break;
            case '{':
                context.push('{'); break;
            case ']':
                if (context.top() != '[') return 0;
                context.pop();
                break;
            case '}':
                if(context.top() != '{') return 0;
                context.pop();
                break;
            }
        }
        rest = rest.substr(pos+1, std::string::npos);
    }
    return 1;
}

// is_valid_JSON()
// Summary: This function returns true if the file in the argument is a valid JSON file based on its balance of braces, brackets, and quotes.
// Arguments:
//           filename: A string with the name of the file to open.
// Returns: An integer enconding: 1 for valid JSON files, 0 for invalid, and -1 on failure to open file. 
int is_valid_JSON(std::string filename){
    std::string line;
    bool quotes = false; 

    std::fstream file (filename, std::ios::in);
    if(!file.is_open()){
        return -1;
    }

    std::string contents{std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};

    file.close();

    return check_valid_JSON(contents);
}

// JSON File Validation, main()
int main(){
    int x = is_valid_JSON("jason.json");

    if(x == 1)
        std::cout << "The JSON file is valid!\n\n";
    else if(x == 0)
        std::cout << "The JSON file is invalid!\n\n";
    else
        std::cout << "Could not open the file!\n\n";  
    std::cout << std::flush;
    return 0;
}
 
