#ifndef _DJS_TDADJLIST_ALGORITHM_H_
#define _DJS_TDADJLIST_ALGORITHM_H_
/* 
    This program is free software: you can redistribute it and/or modify 
    it under the terms of the GNU General Public License as published by 
    the Free Software Foundation, either version 3 of the License, or 
    (at your option) any later version. 
 
    This program is distributed in the hope that it will be useful, 
    but WITHOUT ANY WARRANTY; without even the implied warranty of 
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
    GNU General Public License for more details. 
 
    You should have received a copy of the GNU General Public License 
    along with this program.  If not, see <http://www.gnu.org/licenses/> 
*/

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "Tools.h"
#include <list>
#include <vector>
#include "Algorithm.h"

/*! \file TimeDelayAdjacencyListAlgorithm.h

    \brief see TimeDelayAdjacencyListAlgorithm.cpp

    \author Darren Strash (first name DOT last name AT gmail DOT com)

    \copyright Copyright (c) 2011 Darren Strash. This code is released under the GNU Public License (GPL) 3.0.

    \image html gplv3-127x51.png

    \htmlonly
    <center>
    <a href="gpl-3.0-standalone.html">See GPL 3.0 here</a>
    </center>
    \endhtmlonly
*/

class TimeDelayAdjacencyListAlgorithm : public Algorithm
{
public:
    TimeDelayAdjacencyListAlgorithm(std::vector<std::vector<int>> const &adjacencyList);
    virtual ~TimeDelayAdjacencyListAlgorithm();

    virtual long Run(std::list<std::list<int>> &cliques);

    TimeDelayAdjacencyListAlgorithm           (TimeDelayAdjacencyListAlgorithm const &) = delete;
    TimeDelayAdjacencyListAlgorithm& operator=(TimeDelayAdjacencyListAlgorithm const &) = delete;

    long listAllMaximalCliquesTimeDelayAdjacencyList( std::vector<std::vector<int>> const &adjacencyList, 
                                         int* degree, 
                                         int size);

    int findBestPivotNonNeighborsTimeDelayAdjacencyList( int** pivotNonNeighbors, int* numNonNeighbors,
                                            std::vector<std::vector<int>> const &adjacencyList, int* degree,
                                            int* vertexSets, int* vertexLookup, int size,
                                            int beginX, int beginD, int beginP, int beginR);

    void listAllMaximalCliquesTimeDelayAdjacencyListRecursive( long* cliqueCount,
                                                  std::list<int> &partialClique, 
                                                  std::vector<std::vector<int>> const &adjacencyList, int* degree,
                                                  int* vertexSets, int* vertexLookup, int size,
                                                  int beginX, int beginD, int beginR, int beginP);

void moveDominatedVerticesFromPtoD(std::vector<std::vector<int>> const &adjacencyList, int* vertexSets, int* vertexLookup, int size, int &beginX, int &beginD, int &beginP, int &beginR);

private:
    std::vector<std::vector<int>> const &m_AdjacencyList;
    int *m_pDegree;
};

#endif  //_DJS_TDADJLIST_ALGORITHM_H_
