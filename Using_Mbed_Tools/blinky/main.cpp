#include "mbed.h"

// Gán LED tương ứng với chân của STM32F411 Discovery
DigitalOut led2(PD_12); // LED xanh lá
DigitalOut led3(PD_13); // LED cam
// UART1 trên chân PA_15 (TX), PB_7 (RX) 
static BufferedSerial uart1(PA_15, PB_7);  // TX, RX, Baudrate

// Hàm nhấp nháy LED
void blink_led(DigitalOut& led, int interval_ms) {
    while (true) {
        led = !led;
        ThisThread::sleep_for(chrono::milliseconds(interval_ms));
    }
}

// Hàm in chuỗi "hello_world" mỗi 1 giây
void print_hello() {
    const char* msg = "hello_world\n";
    while (true) {
        uart1.write(msg, strlen(msg));
        ThisThread::sleep_for(1s);
    }
}

int main() {
    // Tạo thread với các mức ưu tiên
    uart1.set_baud(115200);
    uart1.set_format(
    /* bits */ 8,
    /* parity */ BufferedSerial::None,
    /* stop bit */ 1
    );
    Thread t1(osPriorityNormal);
    Thread t2(osPriorityNormal);
    Thread t_hello(osPriorityNormal);  // Thread in có ưu tiên cao hơn

    // Khởi động các thread
    t1.start([&]() { blink_led(led2, 200); });
    t2.start([&]() { blink_led(led3, 400); });
    t_hello.start(print_hello);  // Thread in UART

    while (true) {
        ThisThread::sleep_for(1s);
    }
}
