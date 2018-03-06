#include <stdio.h>
#include <stdlib.h>
#include <node.h>
#include "../recast/Recast.h"
#include "../recast/InputGeom.h"
#include "../recast/MeshLoaderObj.h"
#include "build.h"

const char* ToCString(v8::Local<v8::String> str) {
    v8::String::Utf8Value value(str);
    return *value ? *value : "<string conversion failed>";
}

namespace demo {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

    void Method(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();
        args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
    }

    void buildNavmesh(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        float c_cellSize = Local<v8::Number>::Cast(args[1])->NumberValue();
        float c_cellHeight = Local<v8::Number>::Cast(args[2])->NumberValue();
        float c_agentHeight = Local<v8::Number>::Cast(args[3])->NumberValue();
        float c_agentRadius = Local<v8::Number>::Cast(args[4])->NumberValue();
        float c_agentMaxClimp = Local<v8::Number>::Cast(args[5])->NumberValue();
        float c_agentMaxSlope = Local<v8::Number>::Cast(args[6])->NumberValue();
        float c_regionMinSize = Local<v8::Number>::Cast(args[7])->NumberValue();
        float c_regionMergeSize = Local<v8::Number>::Cast(args[8])->NumberValue();
        float c_edgeMaxLen = Local<v8::Number>::Cast(args[9])->NumberValue();
        float c_edgeMaxError = Local<v8::Number>::Cast(args[10])->NumberValue();
        float c_vertsPerPoly = Local<v8::Number>::Cast(args[11])->NumberValue();
        float c_detailSampleDist = Local<v8::Number>::Cast(args[12])->NumberValue();
        float c_detailSampleMaxError = Local<v8::Number>::Cast(args[13])->NumberValue();

        // if missing arguments
        if(c_cellSize != c_cellSize)
            c_cellSize = 0;

        if(c_cellHeight != c_cellHeight)
            c_cellHeight = 0;

        if(c_agentHeight != c_agentHeight)
            c_agentHeight = 0;

        if(c_agentRadius != c_agentRadius)
            c_agentRadius = 0;

        if(c_agentMaxClimp != c_agentMaxClimp)
            c_agentMaxClimp = 0;

        if(c_agentMaxSlope != c_agentMaxSlope)
            c_agentMaxSlope = 0;

        if(c_regionMinSize != c_regionMinSize)
            c_regionMinSize = 0;

        if(c_regionMergeSize != c_regionMergeSize)
            c_regionMergeSize = 0;

        if(c_edgeMaxLen != c_edgeMaxLen)
            c_edgeMaxLen = 0;

        if(c_edgeMaxError != c_edgeMaxError)
            c_edgeMaxError = 0;

        if(c_vertsPerPoly != c_vertsPerPoly)
            c_vertsPerPoly = 0;

        if(c_detailSampleDist != c_detailSampleDist)
            c_detailSampleDist = 0;

        if(c_detailSampleMaxError != c_detailSampleMaxError)
            c_detailSampleMaxError = 0;
        char *result;
        result = build(
            c_cellSize,
            c_cellHeight,
            c_agentHeight,
            c_agentRadius,
            c_agentMaxClimp,
            c_agentMaxSlope,
            c_regionMinSize,
            c_regionMergeSize,
            c_edgeMaxLen,
            c_edgeMaxError,
            c_vertsPerPoly,
            c_detailSampleDist,
            c_detailSampleMaxError
        );
        Local<String> n_mesh = v8::String::NewFromUtf8(isolate, result);
        args.GetReturnValue().Set(n_mesh);
    }

    void loadBuff(const FunctionCallbackInfo<Value>& args) {
        const char *c_filename = ToCString(Local<v8::String>::Cast(args[0]));        
        load(c_filename);
    }

    void init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "hello", Method);
        NODE_SET_METHOD(exports, "build", buildNavmesh);
        NODE_SET_METHOD(exports, "load", loadBuff);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo