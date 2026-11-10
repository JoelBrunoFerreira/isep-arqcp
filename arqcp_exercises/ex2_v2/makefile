CC=riscv32-buildroot-linux-gnu-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-ilp32d--glibc--stable-2025.08-1/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o func1.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o func1.o func2.s -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

func1.o: func1.s
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c func1.s

func2.o: func2.s
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c func2.s	
	
clean:
	rm -f *.o *.elf .*~ *~

run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf

debug: program.elf
	@echo "On other terminal window do:"
	@echo "riscv32-buildroot-linux-gnu-gdb --tui ./program.elf"
	qemu-riscv32 -L $(LIBRV32) -g 1234 ./program.elf

.PHONY: clean run debug