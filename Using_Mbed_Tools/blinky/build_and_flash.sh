set -e  # Dừng ngay khi có lỗi

# Xóa thư mục cmake_build nếu tồn tại
rm -rf cmake_build

# Cấu hình project với mbed-tools
mbed_tools configure -m STM32F411_DISCOVERY -t GCC_ARM

# Di chuyển vào thư mục cấu hình
cd cmake_build/STM32F411_DISCOVERY/develop/GCC_ARM

# Gọi cmake để tạo file build với Ninja
cmake -G Ninja ../../../../

# Build project
ninja
