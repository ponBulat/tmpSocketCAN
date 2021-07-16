# tmpSocketCAN

https://elinux.org/Bringing_CAN_interface_up

```bash
sudo modprobe can
sudo modprobe can_dev
sudo modprobe can-raw
```
```bash
lsmod | grep can
```

## slcand 
https://canable.io/getting-started.html

```bash
sudo modprobe slcan
```
```bash
sudo slcand -o -s4 bus/usb/001/004
sudo ip link set can0 type can bitrate 125000
```


## USB
```bash
ls /sys/bus/usb/devices/  
```
```bash
udevadm monitor  
udevadm info /sys/bus/usb/devices/usb1/1-9
```

## PCIe
```bash
sudo ip link set up can0 type can bitrate 125000
```
