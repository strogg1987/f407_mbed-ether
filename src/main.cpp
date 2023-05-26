#include "mbed.h"
#include "WIZnetInterface.h"

#define ECHO_SERVER_PORT   5005
WIZnetInterface net(PB_5, PB_4, PB_3, PB_7, PB_6);

int main() {
    int remaining;
    int rcount;
    char *p;
    char *buffer = new char[256];
    nsapi_size_or_error_t result;
    

    printf("Mbed OS Socket example\n");
    printf("Mbed OS version: %d.%d.%d\n\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

    net.init();
    result = net.connect();

    TCPSocket socket;
    result = socket.open(&net);
    if (result != 0) {
        printf("Error! socket.open() returned: %d\n", result);
    }
    socket.bind(ECHO_SERVER_PORT);

    socket.listen(1);

    printf("\nTCP echo server started\n");
    while (true) {
        TCPSocket* client = socket.accept();

        SocketAddress client_addr;
        client->getpeername(&client_addr);
        printf("Client connected: %s\n", client_addr.get_ip_address());

        char buffer1[1024];
        int con_count = 0;
        while (true) {
            nsapi_size_or_error_t size = client->recv(buffer1, sizeof(buffer));
            if (size > 0) {
                client->send(buffer1, size);
            }
            if(con_count > 10000)
                break;
            con_count++;
            
        }
        client->close();
        printf("Client disconnected\n");
    }
    delete[] buffer;
}