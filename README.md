用于蓝牙设备的模糊测试工具，基于马老师给的脚本加了日志功能


安装编译

sudo gcc -o bt-fuzzer bt-fuzzer.c -lbluetooth

报错头文件缺失执行

apt-get update

apt-get install libbluetooth-dev

dpkg -l | grep libbluetooth

ldconfig -p | grep libbluetooth

ls 

有bt-fuzzer就能使用了


./bt-fuzzer -h

./bt-fuzzer -p l2cap -b DE:74:4C:FF:3F:14

![image](https://github.com/user-attachments/assets/b9a09710-4075-450a-bace-d3d26112fa89)
Fuzzer initialized with seed: 0x33e62147：

  ○ 这表示 bt-fuzzer 工具使用了一个特定的种子值（0x33e62147）来初始化测试。种子值用于确定性地生成测试数据，这有助于重现测试结果。
Fuzzing l2cap remote device DE:74:4C:FF:3F:14 via local device 8C:88:2B:21:B5:27：


  ○ bt-fuzzer 正在对远程 BLE 设备（MAC 地址为 DE:74:4C:FF:3F:14）进行 L2CAP 层的模糊测试，测试通过本地蓝牙设备（MAC 地址为 8C:88:2B:21:B5:27）发送数据。

  
crash? error? on packet 14740：
  ○ 这表示在发送第 14740 个数据包时，远程设备可能发生了崩溃或错误。

  
send(): Connection reset by peer：
  ○ 这是一个错误消息，表示对端（peer）重置了连接。这通常意味着远程设备因为某些原因关闭了连接，可能是因为它遇到了一个无法处理的数据包。

  
对一个 BLE 设备进行模糊测试，并且在测试过程中发现了可能导致远程设备重置连接的数据包。这可能是一个潜在的漏洞或设备对某些异常数据包处理不当的证据。
