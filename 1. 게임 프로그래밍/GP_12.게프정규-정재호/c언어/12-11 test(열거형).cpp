#include <stdio.h>
enum days{SUN, MON, TUE, WED, THU, FRI, SAT};
const char * days_name[] = {
	"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY" };

void DayPrint(void) {
	enum days d;
	d = days::WED;
	printf("%d��° ������ %s �Դϴ�.", d, days_name[d]);
}

int main(void) {
	DayPrint();
	return 0;
}