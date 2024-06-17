#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<double>> ambilMatriksMinor(const vector<vector<double>> &matriks, int row, int col) {
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

double hitungDeterminan(const vector<vector<double>>& matriks) {
	int n = matriks.size();
	if (n == 1) return matriks[0][0];
	if (n == 2) return matriks[0][0] * matriks[1][1] - matriks[0][1] * matriks[1][0];
	
	double determinan = 0;
	for (int col = 0; col < n; col++) {
		vector<vector<double>> minor = ambilMatriksMinor(matriks, 0, col);
		determinan += (col % 2 == 0 ? 1 : -1) * matriks[0][col] * hitungDeterminan(minor);
	}
	return determinan;
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

		while (getline(ss, isiBaris, ',')) {
			input.push_back(stod(isiBaris));
		}
		matriks.push_back(input);
	}
	fileInput.close();


	double det = hitungDeterminan(matriks);
	system("clear");
	cout << "Matriks : " << endl;
	for (int i = 0; i < matriks.size(); i++) {
		cout << "| ";
		for (int j = 0; j < matriks[i].size(); j++) {
			cout << matriks[i][j] << " ";
		}

		cout << "|" << endl;
	}
	cout << "\nDeterminannya adalah : " << det << endl;
	
	return 0;
}
