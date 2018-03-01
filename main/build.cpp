#include "stdio.h"
#include "Recast.h"
#include "math.h"
#include "build.h"
#include "InputGeom.h"
#include "MeshLoaderObj.h"

// Rasterization
#define CFG_CELL_SIZE 0.30
#define CFG_CELL_HEIGHT 0.20

// Agent
#define CFG_AGENT_HEIGHT 2.0
#define CFG_AGENT_RADIUS 0.6
#define CFG_AGENT_MAX_CLIMP 0.9
#define CFG_AGENT_MAX_SLOPE 45

// Region
#define CFG_REGION_MIN_SIZE 8
#define CFG_REGION_MERGE_SIZE 20

// Polygonization
#define CFG_EDGE_MAX_LEN 12
#define CFG_EDGE_MAX_ERROR 1.3
#define CFG_VERTS_PER_POLY 6

// Detail Mesh
#define CFG_DETAIL_SAMPLE_DIST 6
#define CFG_DETAIL_SAMPLE_MAX_ERROR 1

rcConfig m_cfg;
class rcContext *m_ctx = new rcContext;
class InputGeom *m_geom = new InputGeom;

int build()
{
	if (!m_geom->load(m_ctx, "nav_test.obj")) {
		return -1;
	}
	// 模型包围盒
	// const float *bmin = m_geom->getNavMeshBoundsMin();
	// const float *bmax = m_geom->getNavMeshBoundsMax();
	// 顶点数据
	const float *verts = m_geom->getMesh()->getVerts();
	const int nverts = m_geom->getMesh()->getVertCount();
	// 三角形索引数据
	const int *tris = m_geom->getMesh()->getTris();
	const int ntris = m_geom->getMesh()->getTriCount();

	printf("Verts\t: %d\n", nverts);
	printf("Tris\t: %d\n", ntris);

	if (!m_geom->getMesh()) {

		m_ctx->log(RC_LOG_ERROR, "buildTiledNavigation: Out of memory 'm_chunkyMesh'.");
		return false;
	}
	//
	// Step 1. Initialize build config.
	//

	// Init build configuration from GUI

	// 体素大小
	m_cfg.cs = CFG_CELL_SIZE;   // Cell Size
	m_cfg.ch = CFG_CELL_HEIGHT; // Cell Height

	// Agent
	m_cfg.walkableHeight = (int)ceilf(CFG_AGENT_HEIGHT / m_cfg.ch);
	m_cfg.walkableRadius = (int)ceilf(CFG_AGENT_RADIUS / m_cfg.cs);
	m_cfg.walkableClimb = (int)floorf(CFG_AGENT_MAX_CLIMP / m_cfg.ch);
	m_cfg.walkableSlopeAngle = CFG_AGENT_MAX_SLOPE;

	// Polygonization
	m_cfg.maxEdgeLen = (int)(CFG_EDGE_MAX_LEN / m_cfg.cs);
	m_cfg.maxSimplificationError = (float)CFG_EDGE_MAX_ERROR;
	m_cfg.maxVertsPerPoly = (int)CFG_VERTS_PER_POLY;

	// Region
	m_cfg.minRegionArea = (int)rcSqr(CFG_REGION_MIN_SIZE);	 // Note: area = size*size
	m_cfg.mergeRegionArea = (int)rcSqr(CFG_REGION_MERGE_SIZE); // Note: area = size*size

	// Detail mesh
	m_cfg.detailSampleDist = (float)CFG_DETAIL_SAMPLE_DIST < 0.9f ? 0 : m_cfg.cs * CFG_DETAIL_SAMPLE_DIST;
	m_cfg.detailSampleMaxError = (float)m_cfg.ch * CFG_DETAIL_SAMPLE_MAX_ERROR;

	// rcHeightfield *m_solid = rcAllocHeightfield();

	// rcCreateHeightfield(ctx, );

	return 0;
}