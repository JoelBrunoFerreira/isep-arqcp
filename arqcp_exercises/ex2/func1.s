.section .text
	.global low_pressure

low_pressure:
	lbu t0, 0(a0) # Load the first byte of the car's pressure data into t0
	sltiu t0, t0, 254 # Check if the pressure is less than 254
	bnez t0, .Llow_pressure # If the pressure is less than 254, branch to .Llow_pressure

	lbu t0, 1(a0) # Load the second byte of the car's pressure data into t0
	sltiu t0, t0, 254 # Check if the pressure is less than 254
	bnez t0, .Llow_pressure # If the pressure is less than 254, branch to .Llow_pressure

	lbu t0, 2(a0) # Load the third byte of the car's pressure data into t0
	sltiu t0, t0, 254 # Check if the pressure is less than 254
	bnez t0, .Llow_pressure # If the pressure is less than 254, branch to .Llow_pressure

	lbu t0, 3(a0) # Load the fourth byte of the car's pressure data into t0
	sltiu t0, t0, 254 # Check if the pressure is less than 254
	bnez t0, .Llow_pressure # If the pressure is less than 254, branch to .Llow_pressure

	li a0, 0 # If all pressures are 254 or higher, set return value to 0 (no low pressure)
	ret

.Llow_pressure:
	li a0, 1 # If any pressure is less than 254, set return value to 1 (low pressure detected)
    ret

