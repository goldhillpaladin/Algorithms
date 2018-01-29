// 当至少有多少人时，存在至少2人的生日是同一天的概率大于 probability
// 设人数为 n，则不存在任何人的生日是同一天的概率为 p1 = (365 * 364 * ... * (365-n+1)) / 365^n
int BirthdayParadox(const double probability) {
    int person_num = 0; // 人数
    int remain = 365;
    double quotient = 1.0;
    while (quotient >= (1 - probability)) {
        quotient *= (double)(remain--) / 365;
        person_num++;
    }
    return person_num;
}

int main() {
    int count = BirthdayParadox(0.5); // 23
    count = BirthdayParadox(0.8);     // 35
    count = BirthdayParadox(0.99);    // 57
	return 0;
}