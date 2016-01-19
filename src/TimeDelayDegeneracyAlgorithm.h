#ifndef _DJS_TDDEGENERACY_ALGORITHM_H_
#define _DJS_TDDEGENERACY_ALGORITHM_H_

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

// local includes
#include "Algorithm.h"
#include "Tools.h"
#include "MemoryManager.h"
#include "DegeneracyTools.h"

// system includes
#include <list>
#include <vector>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/*! \file TimeDelayDegeneracyAlgorithm.h

    \brief see TimeDelayDegeneracyAlgorithm.cpp

    \author Darren Strash (first name DOT last name AT gmail DOT com)

    \copyright Copyright (c) 2011 Darren Strash. This code is released under the GNU Public License (GPL) 3.0.

    \image html gplv3-127x51.png

    \htmlonly
    <center>
    <a href="gpl-3.0-standalone.html">See GPL 3.0 here</a>
    </center>
    \endhtmlonly
*/

class TimeDelayDegeneracyAlgorithm : public Algorithm
{
public:
    TimeDelayDegeneracyAlgorithm(std::vector<std::list<int>> const &adjacencyList);
    virtual ~TimeDelayDegeneracyAlgorithm();

    virtual long Run(std::list<std::list<int>> &cliques);

    TimeDelayDegeneracyAlgorithm           (TimeDelayDegeneracyAlgorithm const &) = delete;
    TimeDelayDegeneracyAlgorithm& operator=(TimeDelayDegeneracyAlgorithm const &) = delete;

    void listAllMaximalCliquesTimeDelayDegeneracyRecursive( long* cliqueCount,
                                               std::list<int> &partialClique, 
                                               int* vertexSets, int* vertexLookup,
                                               int** neighborsInP, int* numNeighbors,
                                               int beginX, int beginD, int beginP, int beginR);

    long listAllMaximalCliquesTimeDelayDegeneracy( std::vector<std::list<int>> const &adjList,
                                      int size );


private:
    std::vector<std::list<int>> const &m_AdjacencyList;
};
#endif
