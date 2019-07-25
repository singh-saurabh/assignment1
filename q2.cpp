#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <netdb.h>
#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{  
    /*! \brief Get MAC address
    *
    *  The MAC address is stored in the file /sys/class/net/
    *  In wlp58s0 in my system
    *  We lookup the MAC address using the Socket libraries and print it here
    */
    struct ifreq ifr;
    int fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    string ans;
    char buff[3];
    strcpy(ifr.ifr_name, "wlp58s0");

    if (ioctl(fd, SIOCGIFHWADDR, &ifr) == 0) {
        for (int i = 0; i <= 5; i++){
            snprintf(buff, sizeof(buff), "%.2x", (unsigned char)ifr.ifr_addr.sa_data[i]);
            ans = ans + buff + ":";
        }
        cout << "MAC address is : " << ans << endl;
        return 0;
    }   

    return 1;
}