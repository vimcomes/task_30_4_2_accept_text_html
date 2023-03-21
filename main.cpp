#include <iostream>
#include <cpr/cpr.h>


int main() {
    cpr::Response response = cpr::Get (cpr::Url("http://httpbin.org/html"),
                                cpr::Header({{"accept", "text/html"}}));
    if (response.status_code == 200) {
        for (int i = response.text.find("<h1>") + 4; i < response.text.find("</h1>"); i++) {
            std::cout << response.text[i];
        }
    } else {
        std::cerr << "Request failed: " << response.status_code << std::endl;
    }
    return 0;
}