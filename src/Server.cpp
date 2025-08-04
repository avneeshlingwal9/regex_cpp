#include <iostream>
#include <string>

bool isDigit(char c){

    return  c >= '1' && c <= '9'; 

}
bool match_pattern(const std::string& input_line, const std::string& pattern , const std::string& flag) {


    if(pattern == "\\d"){

        for(int i = 0 ; i < input_line.size(); i++){

            if(isDigit(input_line[i])){

                return true; 

            }

        }

    }

    else if (pattern.length() == 1) {
        return input_line.find(pattern) != std::string::npos;
    }
    else {
        throw std::runtime_error("Unhandled pattern " + pattern);
    }
    return false; 
}

int main(int argc, char* argv[]) {
    // Flush after every std::cout / std::cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    // You can use print statements as follows for debugging, they'll be visible when running tests.
    std::cerr << "Logs from your program will appear here" << std::endl;

    if (argc != 3) {
        std::cerr << "Expected two arguments" << std::endl;
        return 1;
    }

    std::string flag = argv[1];
    std::string pattern = argv[2];

    if (flag != "-E") {
        std::cerr << "Expected first argument to be '-E'" << std::endl;
        return 1;
    }

    //Uncomment this block to pass the first stage
    
    std::string input_line;
    std::getline(std::cin, input_line);
    
    try {
        if (match_pattern(input_line, pattern , flag)) {

            return 0;

        } 
        else {

            return 1;

        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
