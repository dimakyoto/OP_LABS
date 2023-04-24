#include "functions.h";

TPentagon findPentagonWithLargestPerimeter(TPentagon* pentagons, int numPentagons) {
    TPentagon maxPentagon = pentagons[0];
    for (int i = 1; i < numPentagons; i++) {
        if (pentagons[i].getPerimeter() > maxPentagon.getPerimeter()) {
            maxPentagon = pentagons[i];
        }
    }
    return maxPentagon;
}
THexagon findHexagonWithSmallestArea(THexagon* hexagons, int numHexagons) {
    THexagon minHexagon = hexagons[0];
    for (int i = 1; i < numHexagons; i++) {
        if (hexagons[i].getArea() < minHexagon.getArea()) {
            minHexagon = hexagons[i];
        }
    }
    return minHexagon;
}

void describeProgram() {
    cout << endl << endl << "This program creates a TFigure class that represents a geometric figure on a 2D plane with methods to calculate its area and perimeter. " << endl;
    cout << "Two descendant classes, THeharop and TRepiarop, are also created, which are defined by their coordinates. " << endl;
    cout << "The program generates p pentagons and t hexagons, and then finds the pentagon with the largest perimeter and the hexagon with the smallest area." << endl << endl;
}
void code() {

    int numPentagons, numHexagons;

    cout << "Enter the number of pentagons: ";
    cin >> numPentagons;
    cout << "Enter the number of hexagons: ";
    cin >> numHexagons;

    TPentagon* pentagons = new TPentagon[numPentagons];

    for (int i = 0; i < numPentagons; i++) {
        double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
        cout << "Enter the coordinates of the first point of pentagon #" << i + 1 << ": ";
        cin >> x1 >> y1;
        cout << "Enter the coordinates of the second point of pentagon #" << i + 1 << ": ";
        cin >> x2 >> y2;
        cout << "Enter the coordinates of the third point of pentagon #" << i + 1 << ": ";
        cin >> x3 >> y3;
        cout << "Enter the coordinates of the fourth point of pentagon #" << i + 1 << ": ";
        cin >> x4 >> y4;
        cout << "Enter the coordinates of the fifth point of pentagon #" << i + 1 << ": ";
        cin >> x5 >> y5;

        TPentagon pentagon(Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4), Point(x5, y5));
        pentagons[i] = pentagon;
        cout << "Pentagon #" << i + 1 << ": Perimeter = " << pentagon.getPerimeter() << ", Area = " << pentagon.getArea() << endl;
    }

    TPentagon maxPentagon = findPentagonWithLargestPerimeter(pentagons, numPentagons);
    cout << "Pentagon with largest perimeter: " << endl;
    cout << "Perimeter: " << maxPentagon.getPerimeter() << endl;
    cout << "Area: " << maxPentagon.getArea() << endl << endl;


    THexagon* hexagons = new THexagon[numHexagons];

    for (int i = 0; i < numHexagons; i++) {
        double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
        cout << "Enter the coordinates of the first point of hexagon #" << i + 1 << ": ";
        cin >> x1 >> y1;
        cout << "Enter the coordinates of the second point of hexagon #" << i + 1 << ": ";
        cin >> x2 >> y2;
        cout << "Enter the coordinates of the third point of hexagon #" << i + 1 << ": ";
        cin >> x3 >> y3;
        cout << "Enter the coordinates of the fourth point of hexagon #" << i + 1 << ": ";
        cin >> x4 >> y4;
        cout << "Enter the coordinates of the fifth point of hexagon #" << i + 1 << ": ";
        cin >> x5 >> y5;
        cout << "Enter the coordinates of the sixth point of hexagon #" << i + 1 << ": ";
        cin >> x6 >> y6;

        THexagon hexagon(Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4), Point(x5, y5), Point(x6, y6));
        hexagons[i] = hexagon;
        cout << "Hexagon #" << i + 1 << ": Perimeter = " << hexagon.getPerimeter() << ", Area = " << hexagon.getArea() << endl;
    }

    THexagon minHexagon = findHexagonWithSmallestArea(hexagons, numHexagons);
    cout << "Hexagon with smallest area: " << endl;
    cout << "Perimeter: " << minHexagon.getPerimeter() << endl;
    cout << "Area: " << minHexagon.getArea() << endl << endl;

    delete[] pentagons;
    delete[] hexagons;
}