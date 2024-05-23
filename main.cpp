#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<double>> getMinor(const vector<vector<double>> &matriks, int row, int col) {
	vector<vector<double>> minor;
	int n = matriks.size();
	for (int i = 0; i < n; i++) {
		if (i == row) continue;
		vector<double> minorRow;
		for (int j = 0; j < n; j++) {
			if (j == col) continue;
			minorRow.push_back(matriks[i][j]);
		}
		minor.push_back(minorRow);
	}
	return minor;
}

double determinan(const vector<vector<double>>& matriks) {
	int n = matriks.size();
	if (n == 1) return matriks[0][0];
	if (n == 2) return matriks[0][0] * matriks[1][1] - matriks[0][1] * matriks[1][0];
	
	double det = 0;
	for (int col = 0; col < n; col++) {
		vector<vector<double>> minor = getMinor(matriks, 0, col);
		det += (col % 2 == 0 ? 1 : -1) * matriks[0][col] * determinan(minor);
	}
	return det;
}

int main() {
	ifstream fileInput("input.csv");

	string str;
	vector<vector<double>> matriks;

	int noBaris = 0;
	while(getline(fileInput, str)) {
		noBaris++;
		string isiBaris;
		stringstream ss(str);
		vector<double> input;
		bool inputValid = true;

		while (getline(ss, isiBaris, ',')) {
			input.push_back(stod(isiBaris));
		}
		matriks.push_back(input);
	}
	fileInput.close();


	double det = determinan(matriks);
	system("clear"); // utk windows ganti jadi system("cls")
	cout << "Determinannya adalah : " << det << endl;
	
	return 0;
}
