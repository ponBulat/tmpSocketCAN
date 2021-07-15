# tmpSocketCAN

https://elinux.org/Bringing_CAN_interface_up

https://canable.io/getting-started.html


ls /sys/bus/usb/devices/  

sudo modprobe can  
sudo modprobe can-raw  
sudo modprobe slcan  

lsmod | grep can

udevadm monitor  
udevadm info /sys/bus/usb/devices/usb1/1-9


sudo slcand -o -s4 -t hw -S 500000 /sys/bus/usb/devices/usb1
