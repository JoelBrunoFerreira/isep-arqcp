.section .data

.section .bss

.section .text
	.global greater_date_asm
greater_date_asm:
	# Parameters: date1 in r0, date2 in r1
	# Return value: greater date in r0
	# Extract year, month, day from date1
	# 0x00FF = 255
	srl     t0, a0, 16        # t0 = year1
	andi    t2, a0, 0x00FF    # t2 = month1
	srl     t1, a0, 8         # t1 = day1
	andi    t1, t1, 0x00FF     # t1 = day1

	# Extract year, month, day from date2
	srl     t3, a1, 16        # t3 = year2
	andi    t5, a1, 0x00FF    # t5 = month2
	srl     t4, a1, 8         # t4 = day2
	andi    t4, t4, 0x00FF     # t4 = day2

	# Compare years
	bgt     t0, t3, date1_greater
	blt     t0, t3, date2_greater

	# Years are equal; compare months
	bgt     t2, t5, date1_greater
	blt     t2, t5, date2_greater

	# Months are equal; compare days
	bgt     t1, t4, date1_greater
	blt     t1, t4, date2_greater
date1_greater:
	mv      a0, a0            # return date1
	ret
date2_greater:
	mv      a0, a1            # return date2
	ret
