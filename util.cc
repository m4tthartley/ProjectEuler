
bool isPrime (int64_t num) {
	bool result;

	if (num > 1) {
		result = true;
		for (int64_t i = 2; i < num; ++i) {
			if (num % i == 0) {
				result = false;
				break;
			}
		}
	} else {
		result = false;
	}

	return result;
}