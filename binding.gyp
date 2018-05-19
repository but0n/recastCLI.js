{
    "targets": [
        {
            "include_dirs" : [
                "<!(node -e \"require('nan')\")"
            ],
            "target_name": "RecastCLI",
            "sources": [
                "main/port.cpp",
                # "main/main.cpp",
                "main/build.cpp",
                "recast/ChunkyTriMesh.cpp",
                "recast/MeshLoaderObj.cpp",
                "recast/InputGeom.cpp",
                "recast/Recast.cpp",
                "recast/RecastAlloc.cpp",
                "recast/RecastArea.cpp",
                "recast/RecastAssert.cpp",
                "recast/RecastContour.cpp",
                "recast/RecastFilter.cpp",
                "recast/RecastLayers.cpp",
                "recast/RecastMesh.cpp",
                "recast/RecastMeshDetail.cpp",
                "recast/RecastRasterization.cpp",
                "recast/RecastRegion.cpp",
                ]
        }
    ]
}