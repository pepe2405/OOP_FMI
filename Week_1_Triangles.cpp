// Week_1_Triangles

#include <iostream>

namespace Points
{
	struct Point
	{
		int x = 0;
		int y = 0;
	};

	void readPoint(Point& point)
	{
		std::cin >> point.x;
		std::cin >> point.y;
	}

	double getDist(const Point& p1, const Point& p2)
	{
		const int dx = p1.x - p2.x;
		const int dy = p1.y - p2.y;

		return sqrt(dx * dx + dy * dy);
	}

	void printPoint(const Point& p)
	{
		std::cout << '(' << p.x << ' ' << p.y << ')';
	}
}

namespace Figures
{
	using namespace Points;

	struct Triangle
	{
		Point p1;
		Point p2;
		Point p3;
	};

	void readTriangle(Triangle& tr)
	{
		readPoint(tr.p1);
		readPoint(tr.p2);
		readPoint(tr.p3);
	}

	double getArea(const Triangle& tr)
	{
		const double sideA = getDist(tr.p1, tr.p2);
		const double sideB = getDist(tr.p2, tr.p3);
		const double sideC = getDist(tr.p3, tr.p1);

		const double halfP = (sideA + sideB + sideC) / 2;

		return sqrt(halfP * (halfP - sideA) * (halfP - sideB) * (halfP - sideC));
	}

	void sortTrianglesByArea(Triangle* triangles, const size_t N)
	{
		double* areas = new double[N];
		for (int i = 0; i < N; i++)
			areas[i] = getArea(triangles[i]);

		for (int i = 0; i < N; i++)
		{
			int minTrIndex = i;

			for (size_t j = 0; j < N; j++)
			{
				if (areas[j] < areas[minTrIndex])
					minTrIndex = j;
			}

			if (minTrIndex != i)
			{
				std::swap(triangles[i], triangles[minTrIndex]);
				std::swap(areas[i], areas[minTrIndex]);
			}
		}

		delete[] areas;
	}

	void printTraingle(const Triangle& tr)
	{
		printPoint(tr.p1);
		printPoint(tr.p2);
		printPoint(tr.p3);
		std::cout << std::endl;
	}

}

int main()
{
	size_t N;
	std::cin >> N;

	Figures::Triangle* triangles = new Figures::Triangle[N];

	for (size_t i = 0; i < N; i++)
		Figures::readTriangle(triangles[i]);

	Figures::sortTrianglesByArea(triangles, N);

	delete[] triangles;
}