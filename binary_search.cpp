#include <iostream>
#include <vector>

int binary(std::vector<int> array, int key, int min, int max) {
	
	int mid = min + (max - min) / 2;

	if (min != max) {
		if (array[mid] == key) {
			return mid;
		}
		else if (array[mid] > key) {
			return binary(array, key, min, mid - 1);
		}
		else if (array[mid] < key) {
			return binary(array, key, mid + 1, max);
		}
		else {
			return -2;
		}
	}
	else {
		if (array[mid] == key) {
			return mid;
		}
		else {
			return -1;
		}
	}
}

int main() {
	int n;
	std::vector<int> input;
	int keep;
	int key;
	int answer;

	std::cout << "データ数 : ";
	std::cin >> n;

	std::cout << "入力配列 : " << std::endl;
	std::cout << "[ " << std::endl;

	for (int i = 0; i < n; i++) {
		std::cin >> keep;
		input.push_back(keep);
	}

	std::cout << " ]" << std::endl;

	std::cout << "input[0] : " << input[0] << std::endl;

	std::cout << "探索データ : " << std::endl;
	std::cin >> key;

	if (input[0] > key || input[n-1] < key) {
		std::cout << "探索先の範囲内には無し" << std::endl;
		return 0;
	}

	answer = binary(input, key, 0, n - 1);

	if (answer > 0) {
		std::cout << "input[" << answer << "] = " << key << std::endl;
	}
	else {
		std::cout << "not found" << std::endl;
	}

	return 0;
}