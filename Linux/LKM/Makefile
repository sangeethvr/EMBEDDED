obj-m += LKM_driver.o
KDIR= /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(shell pwd) modules
clean:
	make -C $(KDIR) M=$(shell pwd) clean
load:
	sudo insmod LKM_driver.ko
unload:
	sudo rmmod LKM_driver.ko

