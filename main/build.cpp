#include "Recast.h"

static rcConfig m_cfg;

void build() {

    m_cfg.cs = 0.3;
    m_cfg.ch = 0.3;
    m_cfg.walkableSlopeAngle = 3;
    // m_cfg.walkableHeight = (int)ceilf(m_agentHeight / m_cfg.ch);
    // m_cfg.walkableClimb = (int)floorf(m_agentMaxClimb / m_cfg.ch);
    // m_cfg.walkableRadius = (int)ceilf(m_agentRadius / m_cfg.cs);
    // m_cfg.maxEdgeLen = (int)(m_edgeMaxLen / m_cellSize);
    // m_cfg.maxSimplificationError = m_edgeMaxError;
    // m_cfg.minRegionArea = (int)rcSqr(m_regionMinSize);     // Note: area = size*size
    // m_cfg.mergeRegionArea = (int)rcSqr(m_regionMergeSize); // Note: area = size*size
    // m_cfg.maxVertsPerPoly = (int)m_vertsPerPoly;
    // m_cfg.detailSampleDist = m_detailSampleDist < 0.9f ? 0 : m_cellSize * m_detailSampleDist;
    // m_cfg.detailSampleMaxError = m_cellHeight * m_detailSampleMaxError;
}