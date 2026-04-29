# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Bài lab nhằm giúp sinh viên hiểu nguyên lý hoạt động của hai phương pháp mã hoá cổ điển là Caesar Cipher và Rail Fence Cipher, đồng thời thực hành cài đặt mã hoá và giải mã bằng C++, kiểm thử chương trình và quản lý bài bằng GitHub.
## 2. Cách làm
Hoàn thiện Caesar Cipher:
hỗ trợ chữ hoa và chữ thường;
giữ nguyên dấu cách;
cài đặt cả mã hoá và giải mã.
Hoàn thiện Rail Fence Cipher:
cài đặt mã hoá và giải mã theo zigzag;
giữ dấu cách như ký tự bình thường;
kiểm tra dữ liệu đầu vào hợp lệ;
đọc dữ liệu từ file data/input.txt.
Thực hiện kiểm thử với nhiều test case khác nhau và ghi lại kết quả.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX | Mã hóa thành công, giữ nguyên dấu cách|
| hello world | 5 | mjqqt btwqi | Mã hóa chữ thường, giữ nguyên khoảng trắng |
| LORYH BRX | 3 | I LOVE YOU | Giải mã thành công |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 |ILV O OEYU  | Mã hóa với 2 rails, giữ dấu cách |
| I LOVE YOU | 4 |I  EYLVOOU  | Mã hóa với 4 rails, giữ dấu cách |
| IOEOLVYU | 2 | ILOVEYOU | Giải mã thành công |

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ: Đầu vào 123abc bị từ chối với thông báo "Invalid input. Only letters and spaces are allowed."
Output: Invalid input. Only letters and spaces are allowed.
- Kết quả đọc từ data/input.txt: Đọc thành công "HELLO FROM FILE", mã hóa Rail Fence (3 rails) thành "HOOIEL RMFLLF E"
## 4. Kết luận
Qua bài lab này, em đã hiểu rõ hơn về nguyên lý hoạt động của hai thuật toán mã hóa cổ điển: Caesar Cipher và Rail Fence Cipher. Caesar Cipher sử dụng phép dịch chuyển các ký tự trong bảng chữ cái, còn Rail Fence Cipher sắp xếp thông điệp theo hình zigzag trên nhiều rail khác nhau.
Khó khăn lớn nhất là trong việc triển khai Rail Fence Cipher, đặc biệt là phần giải mã, vì cần phải mô phỏng lại chính xác đường zigzag để xác định vị trí của từng ký tự. Việc hiểu rõ cách hoạt động của con trỏ direction (đi lên/xuống) giúp em giải quyết vấn đề này.
Điều quan trọng giúp em hiểu rõ hơn là thực hành với nhiều test case khác nhau, đặc biệt là các trường hợp biên (edge case) như xử lý dấu cách, xác thực đầu vào, và đọc dữ liệu từ file.