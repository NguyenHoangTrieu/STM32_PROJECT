#include "mbed.h"

// Gán LED tương ứng với chân của STM32F411 Discovery
DigitalOut led2(PD_12); // LED xanh lá
DigitalOut led3(PD_13); // LED cam
DigitalOut led4(PD_14); // LED đỏ
DigitalOut led5(PD_15); // LED xanh dương

// UART1 trên chân PA_15 (TX), PB_7 (RX
UnbufferedSerial uart1(PA_15, PB_7, 115200);  // TX, RX, Baudrate

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
    Thread t1(osPriorityNormal);
    Thread t2(osPriorityNormal);
    Thread t3(osPriorityNormal);
    Thread t4(osPriorityNormal);
    Thread t_hello(osPriorityHigh);  // Thread in có ưu tiên cao hơn

    // Khởi động các thread
    t1.start([&]() { blink_led(led2, 200); });
    t2.start([&]() { blink_led(led3, 400); });
    t3.start([&]() { blink_led(led4, 600); });
    t4.start([&]() { blink_led(led5, 1000); });

    t_hello.start(print_hello);  // Thread in UART

    while (true) {
        ThisThread::sleep_for(1s);
    }
}
