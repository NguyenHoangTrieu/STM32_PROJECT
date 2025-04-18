import pytest
import serial
import time
from datetime import datetime

@pytest.fixture(scope="module")
def uart_ch340():
    port = "/dev/ttyUSB0"
    try:
        ser = serial.Serial(port=port, baudrate=115200, timeout=1)
    except serial.SerialException:
        pytest.skip(f"{port} not available or permission denied.")

    print(f"Connected to {ser.name}")
    yield ser
    ser.close()

def test_uart_ch340_read(uart_ch340):
    """Read from CH340 UART for 10 seconds and print grouped bursts."""
    start_time = time.time()
    buffer = ""
    last_rx = time.time()
    burst_timeout = 0.01  # 10ms
    log = []

    while time.time() - start_time < 10:
        now = time.time()
        if uart_ch340.in_waiting:
            data = uart_ch340.read(uart_ch340.in_waiting).decode("utf-8", errors="ignore")
            buffer += data
            last_rx = now
        elif buffer and (now - last_rx) > burst_timeout:
            timestamp = datetime.now().strftime("%H:%M:%S.%f")[:-3]
            log.append(f"[{timestamp}] {buffer.strip()}")
            buffer = ""

    print("CH340 Output:")
    for entry in log:
        print(entry)

    assert True
