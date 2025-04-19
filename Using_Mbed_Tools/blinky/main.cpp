#include "mbed.h"

DigitalOut led2(PD_12);
DigitalOut led3(PD_13);
DigitalOut led4(PD_14);
DigitalOut led5(PD_15);
BufferedSerial uart1(PA_15, PB_7);  // TX, RX

Thread t1(osPriority(1));
Thread t2(osPriority(1));
Thread t3(osPriority(1));
Thread t4(osPriority(1));
Thread t_hello(osPriority(2));
Thread t_hello2(osPriority(2));

Ticker hello2_timer; // Timer to notify t_hello2 (Period 5s) Ticker for period, Timeout for one-shot

// Thread function to blink LEDs
void blink_led(DigitalOut& led, int interval_ms) {
    while (true) {
        led = !led;
        ThisThread::sleep_for(chrono::milliseconds(interval_ms));
    }
}

// Thread function: print hello_world every second
void print_hello() {
    const char* msg = "hello_world\n";
    while (true) {
        uart1.write(msg, strlen(msg));
        ThisThread::sleep_for(3s);
    }
}

// Thread function: wait for flag to print hello_world2
void print_hello2_loop() {
    const char* msg = "Timer 2 Called\n";
    while (true) {
        ThisThread::flags_wait_any(0x01);  // Chờ "notify"
        uart1.write(msg, strlen(msg));
    }
}

// Timer callback: notify t_hello2
void hello2_notify() {
    t_hello2.flags_set(0x01);  // Notify thread
}

int main() {
    uart1.set_baud(115200);
    uart1.set_format(
        /* bits */ 8,
        /* parity */ BufferedSerial::None,
        /* stop bit */ 1
    );

    t1.start([&]() { blink_led(led2, 200); });
    t2.start([&]() { blink_led(led3, 400); });
    t3.start([&]() { blink_led(led4, 800); });
    t4.start([&]() { blink_led(led5, 1600); });
    t_hello.start(print_hello);
    t_hello2.start(print_hello2_loop);

    hello2_timer.attach(&hello2_notify, 5s);  // Notify mỗi 5 giây

    while (true) {
        ThisThread::sleep_for(1s);
    }
}
