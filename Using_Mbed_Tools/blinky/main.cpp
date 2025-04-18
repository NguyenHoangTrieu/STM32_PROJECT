#include "mbed.h"

// Gán LED tương ứng với chân của STM32F411 Discovery
DigitalOut led2(PD_12); // LED xanh lá
DigitalOut led3(PD_13); // LED cam
DigitalOut led4(PD_14); // LED đỏ
DigitalOut led5(PD_15); // LED xanh dương

// Hàm nhấp nháy LED
void blink_led(DigitalOut& led, int interval_ms) {
    while (true) {
        led = !led;
        ThisThread::sleep_for(chrono::milliseconds(interval_ms));
    }
}

int main() {
    Thread t1, t2, t3, t4;

    // Dùng lambda để gói tham số
    t1.start([&]() { blink_led(led2, 200); });
    t2.start([&]() { blink_led(led3, 400); });
    t3.start([&]() { blink_led(led4, 600); });
    t4.start([&]() { blink_led(led5, 1000); });

    while (true) {
        ThisThread::sleep_for(1s);
    }
}
