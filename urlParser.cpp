#include <iostream>
#include <string>

std::string getScheme(std::string url);
std::string getAuthority(std::string url);
std::string getPath(std::string url);

int main() {
    std::cout << "Please enter a URL: ";
    std::string url;
    std::cin >> url;

    std::string scheme = getScheme(url);
    std::cout << "scheme = " << scheme << "\n";

    std::string authority = getAuthority(url);
    std::cout << "authority = " << authority << "\n";

    std::string path = getPath(url);
    std::cout << "path = " << path << "\n";
}

std::string getScheme(std::string url) {
    int end = url.find(':');
    return url.substr(0, end + 1);
}

std::string getAuthority(std::string url) {
    int start = url.find('/');
    int end = url.find('/', start + 2);
    return url.substr(start, end - start);
}

std::string getPath(std::string url) {
    int start = url.find('/', url.find('/') + 2);
    return url.substr(start);
}
