#include <stdio.h>
#include "asm.h"

/*
Considering that the 32 bits on an unsigned integer represent a date like this:
• Bits 0 to 7 are the month
• Bits 8 to 15 are the day
• Bits 16 to 31 are the year
Implement the function unsigned int greater_date(unsigned int date1, unsigned int
date2) that returns the greater of the two dates passed as parameters.
	a) In C.
	b) In Assembly.
*/

int greater_date(unsigned int date1, unsigned int date2) {
	unsigned int year1 = (date1 >> 16) & 0xFFFF;
	unsigned int month1 = date1 & 0xFF;
	unsigned int day1 = (date1 >> 8) & 0xFF;

	unsigned int year2 = (date2 >> 16) & 0xFFFF;
	unsigned int month2 = date2 & 0xFF;
	unsigned int day2 = (date2 >> 8) & 0xFF;

	if (year1 != year2) {
		return (year1 > year2) ? date1 : date2;
	} 
	if (month1 != month2) {
		return (month1 > month2) ? date1 : date2;
	} 
	if (day1 != day2) {
		return (day1 > day2) ? date1 : date2;
	}
	return date1; // Dates are equal
}

int main(void) {

	int date1 = 0x0005150A; // 10/21/05
	int date2 = 0x00051E05; // 5/30/05
	unsigned int greater = greater_date(date1, date2);
	printf("Greater date: %08X\n", greater); // Expected output: 0005150A

	printf("==========================================\n");
	printf("Decode and print components for verification\n");
	/* Decode and print components for verification */
	unsigned int month1 = date1 & 0xFF;
	unsigned int day1   = (date1 >> 8) & 0xFF;
	unsigned int year1  = (date1 >> 16) & 0xFFFF;

	unsigned int month2 = date2 & 0xFF;
	unsigned int day2   = (date2 >> 8) & 0xFF;
	unsigned int year2  = (date2 >> 16) & 0xFFFF;

	printf("date1: %02u/%02u/%04u (hex: %08X)\n", month1, day1, year1, date1);
	printf("date2: %02u/%02u/%04u (hex: %08X)\n", month2, day2, year2, date2);
	printf("greater: %02u/%02u/%04u (hex: %08X)\n", greater & 0xFF, (greater >> 8) & 0xFF, (greater >> 16) & 0xFFFF, greater);

	printf("==========================================\n");
	/* Now test the assembly function */
	greater = greater_date_asm(date1, date2);
	printf("Greater date (ASM): %08X\n", greater); // Expected output: 0005150A
	return 0;
}