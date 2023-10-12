#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

int getManhattanDistance(std::pair<int, int>& point1, std::pair<int, int>& point2) {
    return std::abs(point1.first - point2.first) 
        + std::abs(point1.second - point2.second);
}

int main(void) {
    int numOfCheckPoints;

    std::cin >> numOfCheckPoints;
    std::vector<std::pair<int, int> > checkPoints(numOfCheckPoints);

    for (int i = 0; i < numOfCheckPoints; i++) {
        std::cin >> checkPoints[i].first >> checkPoints[i].second;
        std::cin.ignore();
    }

    std::vector<int> distBetweenPoints(numOfCheckPoints - 1);
    for (int i = 0; i < numOfCheckPoints - 1; i++) {
        distBetweenPoints[i] = getManhattanDistance(checkPoints[i], checkPoints[i + 1]);
    }

    int maxDiff = 0, diffTemp, maxDiffIndex;
    int distSum, distSkipped, minDistSkipped;
    for (int i = 0; i < numOfCheckPoints - 2; i++) {
        distSum = distBetweenPoints[i] + distBetweenPoints[i + 1];
        distSkipped = getManhattanDistance(checkPoints[i], checkPoints[i + 2]);
        diffTemp = distSum - distSkipped;
        if (diffTemp > maxDiff) {
            maxDiff = diffTemp;
            maxDiffIndex = i + 1;
            minDistSkipped = distSkipped;
        }
    }

    int totalDist = 0;
    for (int i = 0; i < numOfCheckPoints - 1; i++) {
        if (i + 1 == maxDiffIndex) {
            totalDist += minDistSkipped;
            i++;
            continue ;
        }
        totalDist += distBetweenPoints[i];
    }

    std::cout << totalDist << '\n';

    return 0;
}