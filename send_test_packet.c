#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/l2cap.h>
#include <bluetooth/rfcomm.h>

int main() {
    int sock;
    struct sockaddr_rc addr; // 声明结构体变量
    memset(&addr, 0, sizeof(addr)); // 使用 memset 来确保所有字段都被初始化为 0
    uint8_t packet[] = {0x42, 0x6D, 0x8A, 0x5B, 0xAF, 0x82, 0x4B, 0xB9, 0xA5, 0xF4, 0x58, 0x6C, 0x0A, 0x11, 0x39, 0x19, 0x68, 0x3F, 0xA5, 0x57, 0xC2, 0xA1, 0xE9, 0x2E, 0xD1, 0x27, 0x37, 0x0A, 0x7B, 0xF6, 0xC5};

    sock = socket(AF_BLUETOOTH, SOCK_SEQPACKET, BTPROTO_L2CAP);
    if (sock < 0) {
        perror("Can't create socket");
        return 1;
    }

    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = 1; // 确认目标通道，通常是1
    str2ba("10:48:C6:00:22:23", &addr.rc_bdaddr); // 使用目标设备的MAC地址

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Can't bind socket");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Can't connect");
        close(sock);
        return 1;
    }

    if (send(sock, packet, sizeof(packet), 0) < 0) {
        perror("Can't send packet");
        close(sock);
        return 1;
    }

    printf("Packet sent successfully\n");
    close(sock);
    return 0;
}