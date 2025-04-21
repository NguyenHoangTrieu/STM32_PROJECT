#include "mbed.h"

DigitalOut led3(PG_13);
DigitalOut led4(PG_14);

// ✅ Thay UART1 bằng USART2 - kết nối với VCP thông qua ST-Link
BufferedSerial uart2(PA_2, PA_3); // VCP TX (PA2), RX (PA3)

Thread t3(osPriority(1));
Thread t4(osPriority(1));
Thread t_hello(osPriority(2));
Thread t_hello2(osPriority(2));

Ticker hello2_timer; // Timer to notify t_hello2 every 5s

// Blink LED
void blink_led(DigitalOut& led, int interval_ms) {
    while (true) {
        led = !led;
        ThisThread::sleep_for(chrono::milliseconds(interval_ms));
    }
}

// Thread 1: print message every 3 seconds
void print_hello() {
    const char* msg = "hello_world\n";
    while (true) {
        uart2.write(msg, strlen(msg));
        ThisThread::sleep_for(3s);
    }
}

// Thread 2: print message every 5 seconds (when notified)
void print_hello2() {
    const char* msg = "Timer Called\n";
    while (true) {
        ThisThread::flags_wait_any(0x01);
        uart2.write(msg, strlen(msg));
    }
}

// Notify thread t_hello2
void hello2_notify() {
    t_hello2.flags_set(0x01);
}

int main() {
    uart2.set_baud(115200);
    uart2.set_format(8, BufferedSerial::None, 1);

    t3.start(callback(blink_led, std::ref(led3), 400));
    t4.start(callback(blink_led, std::ref(led4), 800));
    t_hello.start(print_hello);
    t_hello2.start(print_hello2);

    hello2_timer.attach(&hello2_notify, 5s);

    while (true) {
        ThisThread::sleep_for(1s);
    }
}