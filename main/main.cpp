#include <stdio.h>
#include <stdlib.h>
#include "Recast.h"
#include "build.h"
#include <cstring>

const char *c_filename;
float 	c_cellSize;
float 	c_cellHeight;
float 	c_agentHeight;
float 	c_agentRadius;
float 	c_agentMaxClimp;
int 	c_agentMaxSlope;
int 	c_regionMinSize;
int 	c_regionMergeSize;
int 	c_edgeMaxLen;
float 	c_edgeMaxError;
int 	c_vertsPerPoly;
int 	c_detailSampleDist;
int 	c_detailSampleMaxErro;


int main(int argc, char const *argv[]) {
    //	handle arguments
    if (argc < 15) {
        printf("Please enter arg!\n");
        return -1;
    }

    c_filename = argv[1];

    c_cellSize = atof(argv[2]);
    c_cellHeight = atof(argv[3]);

    c_agentHeight = atof(argv[4]);
    c_agentRadius = atof(argv[5]);
    c_agentMaxClimp = atof(argv[6]);
    c_agentMaxSlope = atoi(argv[7]);

    c_regionMinSize = atoi(argv[8]);
    c_regionMergeSize = atoi(argv[9]);

    c_edgeMaxLen = atoi(argv[10]);
    c_edgeMaxError = atof(argv[11]);
    c_vertsPerPoly = atoi(argv[12]);

    c_detailSampleDist = atoi(argv[13]);
    c_detailSampleMaxErro = atoi(argv[14]);

    build(c_filename, c_cellSize, c_cellHeight, c_agentHeight, c_agentRadius, c_agentMaxClimp, c_agentMaxSlope, c_regionMinSize, c_regionMergeSize, c_edgeMaxLen, c_edgeMaxError, c_vertsPerPoly, c_detailSampleDist, c_detailSampleMaxErro);


    return 0;
}
