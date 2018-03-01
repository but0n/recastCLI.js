#ifndef _BUILD_H_
#define _BUILD_H_

// Default setting

// Rasterization
#define CFG_CELL_SIZE   0.30
#define CFG_CELL_HEIGHT 0.20

// Agent
#define CFG_AGENT_HEIGHT    2.0
#define CFG_AGENT_RADIUS    0.6
#define CFG_AGENT_MAX_CLIMP 0.9
#define CFG_AGENT_MAX_SLOPE 45

// Region
#define CFG_REGION_MIN_SIZE     8
#define CFG_REGION_MERGE_SIZE   20

// Polygonization
#define CFG_EDGE_MAX_LEN    12
#define CFG_EDGE_MAX_ERROR  1.3
#define CFG_VERTS_PER_POLY  6

// Detail Mesh
#define CFG_DETAIL_SAMPLE_DIST      6
#define CFG_DETAIL_SAMPLE_MAX_ERROR 1

enum SamplePartitionType
{
    SAMPLE_PARTITION_WATERSHED,
    SAMPLE_PARTITION_MONOTONE,
    SAMPLE_PARTITION_LAYERS,
};

extern bool m_keepInterResults;
extern bool m_filterLowHangingObstacles;
extern bool m_filterLedgeSpans;
extern bool m_filterWalkableLowHeightSpans;

extern int build(const char *filename, float cellSize, float cellHeight, float agentHeight, float agentRadius, float agentMaxClimp, int agentMaxSlope, int regionMinSize, int regionMergeSize, int edgeMaxLen, float edgeMaxError, int vertsPerPoly, int detailSampleDist, int detailSampleMaxError);

#endif