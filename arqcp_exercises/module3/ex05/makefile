CC=riscv32-buildroot-linux-gnu-gcc
CFLAGS=-Wall -Wextra -fanalyzer -g
ARCHFLAGS=-march=rv32imd -mabi=ilp32d
LIBRV32=${HOME}/bin/bootlin/riscv32-ilp32d--glibc--stable-2025.08-1/riscv32-buildroot-linux-gnu/sysroot

program.elf: main.o sum.o avg.o
	$(CC) $(CFLAGS) $(ARCHFLAGS) main.o sum.o avg.o -o program.elf

main.o: main.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c main.c

sum.o: sum.s
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c sum.s

avg.o: avg.s
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c avg.s

clean:
	rm -f *.o *.elf .*~ *~

run: program.elf
	qemu-riscv32 -L $(LIBRV32) ./program.elf

debug: program.elf
	@echo "On other terminal window do:"
	@echo "riscv32-buildroot-linux-gnu-gdb --tui ./program.elf"
	qemu-riscv32 -L $(LIBRV32) -g 1234 ./program.elf

.PHONY: clean run debug