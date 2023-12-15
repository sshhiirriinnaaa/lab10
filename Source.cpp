#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <climits> 

using namespace std; 

struct Node {
	int data;
	Node* next;
};


void printAdjacencyList(Node** adjacencyList, int size) {
	for (int i = 0; i < size; i++) {
		cout << "������� " << i << " ������ �: ";
		Node* current = adjacencyList[i];
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
}


Node** adjacencyMatrixToAdjacencyList(int** matrix, int size) {
	Node** adjacencyList = new Node * [size];

	for (int i = 0; i < size; i++) {
		adjacencyList[i] = nullptr;

		for (int j = size - 1; j >= 0; j--) {
			if (matrix[i][j] != 0) {
				Node* newNode = new Node;
				newNode->data = j;
				newNode->next = adjacencyList[i];
				adjacencyList[i] = newNode;
			}
		}
	}




	return adjacencyList;
}


void freeAdjacencyList(Node** adjacencyList, int size) {
	for (int i = 0; i < size; i++) {
		Node* current = adjacencyList[i];
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
	}
	delete[] adjacencyList;
}

class Node1 {
public:
	int data;
	int priority;
	Node1* next;

	Node1(int d, int p) : data(d), priority(p), next(nullptr) {}
};


class PriorityQueue {
private:
	Node1* front;

public:
	PriorityQueue() : front(nullptr) {}

	// ������� �������� � ������ ����������
	void push(int data, int priority) {
		Node1* newNode1 = new Node1(data, priority);
		if (!front || priority < front->priority) {
			newNode1->next = front;
			front = newNode1;
		}
		else {
			Node1* current = front;
			while (current->next && current->next->priority <= priority) {
				current = current->next;
			}
			newNode1->next = current->next;
			current->next = newNode1;
		}
	}
	
	// ���������� �������� � ��������� �����������
	void pop() {
		if (front) {
			Node1* temp = front;
			front = front->next;
			delete temp;
		}
	}

	// ��������� �������� �������� � ��������� �����������
	int top() {
		if (front) {
			return front->data;
		}
		throw std::runtime_error("Queue is empty");
	}

	// ��������, ����� �� �������
	bool isEmpty() {
		return front == nullptr;
	}
};


int** createMatrix(int size) {
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}
	return matrix;
}

void deleteMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

int**  generateAdjacencyMatrix(int size) {

	int** matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {

			if (i == j) {
				matrix[i][j] = 0;
			}
			else {
				int randomValue = rand() % 5;
				if (randomValue == 0) {
					matrix[i][j] = 1;
					matrix[j][i] = 1;
				}
				else {
					matrix[i][j] = 0;
					matrix[j][i] = 0;
				}
			}

		}
	}
	return matrix;
}
//������������

int**  generateDirectedMatrix(int size) {
	int** matrix = new int*[size];

	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			if (i == j) {
				matrix[i][j] = 0;
			}
			else {
				int randomValue = rand() % 5;
				if (randomValue == 0) {
					matrix[i][j] = 1;

				}
				else {
					matrix[i][j] = 0;

				}
			}

		}
	}
	return matrix;
}
int summMatrix(int** matrix, int size) {
	int summ = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			summ += matrix[i][j];
		}
	}
	return summ;
}
void printMatrix(int** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//cout << matrix[i][j];
			printf("%2d", matrix[i][j]);
			cout << ", ";

		}
		cout << endl;
	}
}



// ������� ��� ��������� ������� ��������� ��� ������������������ ����������� �����
int** generateWeightedAdjacencyMatrix(int size) {

	int** matrix = new int*[size];

	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {

			if (i == j) {
				matrix[i][j] = 0;
			}
			else {
				int rnd = rand() % 10;
				// ���������� 0 � ������������ 50%
				if (rnd < 5) {
					matrix[i][j] = 0;
					matrix[j][i] = 0;
				}
				else {
					int weight = rand() % 20;
					matrix[i][j] = weight;
					matrix[j][i] = weight;
				}
			}

		}
	}

	return matrix;
}

// ������� ��� ��������� ������� ��������� ��� ���������������� ����������� �����
int** generateWeightedDirectedAdjacencyMatrix(int size) {
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	// ��������� ������� ���������� ������ (� ��������� �� 0 �� 9)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				matrix[i][j] = 0; // �� ������� ��������� ������ 0
			}
			else {

				int rnd = rand() % 10;

				// ���������� 0 � ������������ 70%
				if (rnd < 7) {
					matrix[i][j] = 0;
				}
				else {
					int weight = rand() % 20;
					matrix[i][j] = weight;
				}

			}
		}
	}

	return matrix;
}

// ������� ��� ������ ���������� ���������� � �������������� ��������� ��������
void Dijkstra(int** G, int size, int v, int* DIST) {
	for (int i = 0; i < size; i++) {
		DIST[i] = -1; // �������������� ���������� ��� -1 (�� ��������)
	}

	// ������� ������������ ������� ��� ������ ������
	PriorityQueue pq;

	// �������� ��������� ������� � �������
	pq.push(v, 0);

	// ���������� �� ����� ���� ����� 0
	DIST[v] = 0;

	while (!pq.isEmpty()) {
		int currentVertex = pq.top(); // �������� ������� � ���������� �����������
		pq.pop(); // ������� ������� �� �������

		for (int i = 0; i < size; i++) {
			if (G[currentVertex][i] > 0 && (DIST[i] == -1 || DIST[i] > DIST[currentVertex] + G[currentVertex][i])) {
				// ���� ���� ����� ����� ������� �������� � i � i ��� �� ��������
				// ��� ����� ���� ������, ��� ������
				pq.push(i, DIST[currentVertex] + G[currentVertex][i]); // �������� ������� � ������� � ����������� �����������
				DIST[i] = DIST[currentVertex] + G[currentVertex][i]; // ��������� ����������
			}
		}
	}
}


int* findRadiusAndDiameter(int** G, int size, int& radius, int& diameter) {
	radius = INT_MAX;
	diameter = 0;

	int* eccentricities = new int[size];

	for (int i = 0; i < size; i++) {
		int* distances = new int[size];
		Dijkstra(G, size, i, distances);

		int maxEccentricity = 0;
		int minEccentricity = INT_MAX;
		for (int j = 0; j < size; j++) {
			if (distances[j] > maxEccentricity) {
				maxEccentricity = distances[j];
			}
		}
		for (int j = 0; j < size; j++) {
			if (distances[j] < minEccentricity && distances[j]>0) {
				minEccentricity = distances[j];
			}
		}
		eccentricities[i] = maxEccentricity;

		if (maxEccentricity < radius && maxEccentricity > 0 ) {
			radius = maxEccentricity;
		}
		if (maxEccentricity > diameter) {
			diameter = maxEccentricity;
		}

		delete[] distances;
	}
	return eccentricities;
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " <weighted (0 or 1)> <directed (0 or 1)>" << endl;
		return 1;
	}

	int weighted = atoi(argv[1]);
	int directed = atoi(argv[2]);

	int size;
	cout << "\n������� ������ ������� ���������: ";
	cin >> size;

	int** adjacencyMatrix;

	if (weighted) {
		if (directed) {
			adjacencyMatrix = generateWeightedDirectedAdjacencyMatrix(size);
		}
		else {
			adjacencyMatrix = generateWeightedAdjacencyMatrix(size);
		}
	}
	else {
		if (directed) {
			adjacencyMatrix = generateDirectedMatrix(size);
		}
		else {
			adjacencyMatrix = generateAdjacencyMatrix(size);
		}
	}

	printMatrix(adjacencyMatrix, size);
	cout << "\nAdjacency List:\n";
	Node** adjacencyList = adjacencyMatrixToAdjacencyList(adjacencyMatrix, size);
	printAdjacencyList(adjacencyList, size);


	int* DIST = new int[size];

	int radius, diameter;

	int sum = summMatrix(adjacencyMatrix, size);

	cout << "\n����� ����������:\n";
	for (int j = 0; j < size; j++) {
		Dijkstra(adjacencyMatrix, size, j, DIST);
		cout << "������� " << j << "\n";

		// ����� ���������� �� ���� ������
		for (int i = 0; i < size; i++) {
			cout << "���������� �� ������� " << i << " = " << DIST[i] << endl;
		}
		cout << "\n";
	}

	int* eccentricities = findRadiusAndDiameter(adjacencyMatrix, size, radius, diameter);
	if (size == 0 || size == 1 || sum == 0) {
		cout << "������ �����: " << " " << endl;
		cout << "������� �����: " << " " << endl;
	}
	else{
		cout << "������ �����: " << radius << endl;
		cout << "������� �����: " << diameter << endl;
	}
	if (size == 1 || sum == 0) cout << "����������� �������: " << endl; else {
		cout << "����������� �������: ";
		for (int i = 0; i < size; i++) {
			if (eccentricities[i] == radius) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	if (size == 1 || sum == 0) cout << "������������ �������: " << endl; else {
		cout << "������������ �������: ";
		for (int i = 0; i < size; i++) {
			if (eccentricities[i] == diameter) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	delete[] eccentricities;

	if (weighted) {
		deleteMatrix(adjacencyMatrix, size);
	}

	delete[] DIST;

	return 0;
}
