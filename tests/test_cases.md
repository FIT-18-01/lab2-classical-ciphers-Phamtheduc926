# Test Cases – FIT4012 Lab 2

## Caesar Cipher
- [X] Encrypt `I LOVE YOU` với key `3` --> L ORYH BRX
- [X] Encrypt `hello world` với key `5` --> mjqqt btwqi
- [X] Decrypt `L ORYH BRX` với key `3` --> I LOVE YOU


## Rail Fence Cipher
- [X] Encrypt `I LOVE YOU` với `2` rails --> K NQXG AQW
- [X] Encrypt `I LOVE YOU` với `4` rails -->  M PSZI CSY
- [x] Decrypt một bản mã Rail Fence hợp lệ
Input: ILV O OEYU  
Rails: 2  
Output: I LOVE YOU
## Validation / File input
- [X] Kiểm tra đầu vào không hợp lệ
Input: HELLO123  
Output: Invalid input. Only letters and spaces are allowed.
- [X] Đọc thông điệp từ `data/input.txt`
