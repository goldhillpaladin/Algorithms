// 使用牛顿迭代法
// f(x) = x^2 - a
// 导数 = 2*x
// 设当前 x 坐标为 x1，则下一个 x 坐标为 (x1 + a/x1)/2
double mySqrt(int a) {
	if (a == 0)
		return a;
	
	double cur = double(a);
	double prev = double(a);
	float eps = numeric_limits<float>::epsilon();
	
	do {
		prev = cur;
		cur = (prev + a / prev) / 2;
	} while (fabs(cur - prev) > eps);
	
	return cur;
}