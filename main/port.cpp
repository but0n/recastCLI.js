#include <stdio.h>
#include <stdlib.h>
#include <node.h>
#include "../recast/Recast.h"
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

        const char *c_filename = ToCString(Local<v8::String>::Cast(args[0]));
        float c_cellSize = Local<v8::Number>::Cast(args[1])->NumberValue();
        float c_cellHeight = Local<v8::Number>::Cast(args[2])->NumberValue();
        float c_agentHeight = Local<v8::Number>::Cast(args[3])->NumberValue();
        float c_agentRadius = Local<v8::Number>::Cast(args[4])->NumberValue();
        float c_agentMaxClimp = Local<v8::Number>::Cast(args[5])->NumberValue();
        int c_agentMaxSlope = Local<v8::Number>::Cast(args[6])->NumberValue();
        int c_regionMinSize = Local<v8::Number>::Cast(args[7])->NumberValue();
        int c_regionMergeSize = Local<v8::Number>::Cast(args[8])->NumberValue();
        int c_edgeMaxLen = Local<v8::Number>::Cast(args[9])->NumberValue();
        float c_edgeMaxError = Local<v8::Number>::Cast(args[10])->NumberValue();
        int c_vertsPerPoly = Local<v8::Number>::Cast(args[11])->NumberValue();
        int c_detailSampleDist = Local<v8::Number>::Cast(args[12])->NumberValue();
        int c_detailSampleMaxErro = Local<v8::Number>::Cast(args[13])->NumberValue();

        build(c_filename, c_cellSize, c_cellHeight, c_agentHeight, c_agentRadius, c_agentMaxClimp, c_agentMaxSlope, c_regionMinSize, c_regionMergeSize, c_edgeMaxLen, c_edgeMaxError, c_vertsPerPoly, c_detailSampleDist, c_detailSampleMaxErro);



        // double value = value1->NumberValue() + value2->NumberValue();

    }

    void init(Local<Object> exports) {
        NODE_SET_METHOD(exports, "hello", Method);
        NODE_SET_METHOD(exports, "build", buildNavmesh);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, init)

}  // namespace demo