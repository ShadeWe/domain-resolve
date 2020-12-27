#include <iostream>
#include <winsock2.h>
#include <wspiapi.h>

using namespace std;

/**
 * Returns the IP of domain provided as a string
 * @param domain
 */
string get_address(const char * domain)
{
    string ip;
    hostent * hp = gethostbyname(domain);
    char * addr = hp->h_addr_list[0];

    for (unsigned char i = 0; i < 4; i++)
    {
        ip.append(to_string((int)(unsigned char)addr[i]));

        if (i != 3) {
            ip.append(".");
        }
    }

    return ip;
}

int main(int argc, char * argv[]) {

    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2,1), &wsaData) != 0)
    {
        fprintf(stderr, "WSAStartup failed.\n");
        exit(1);
    }

    string domain;

    if (argc == 2) {

        domain = argv[1];

    } else {

        cout << "Hostname: ";
        cin >> domain;

    }

    cout << domain << ": " << get_address(domain.c_str()) << endl;
    system("pause");

    return 0;
}
