set -e  # Dừng ngay khi có lỗi

# Xóa thư mục cmake_build nếu tồn tại
rm -rf cmake_build

# Cấu hình project với mbed-tools

# Gọi cmake để tạo file build với Ninja
cmake -G Ninja 

# Build project
ninja
