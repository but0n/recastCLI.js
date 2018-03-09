# RecastCLI
![](https://user-images.githubusercontent.com/7625588/36931426-d560d6aa-1eef-11e8-96a2-14812f7994a3.png)

A command line tools to build navigation mesh for game, which means you can automatically generate navigation mesh on server or localhost.

> Based on [recastnavigation](https://github.com/recastnavigation/recastnavigation) under ZLib license

# Nodejs addon

## Building

```shell
$ node-gyp rebuild
```

## Build option

 - define OUTPUT_FILE
 - define OUTPUT_STRING


## Usage

```js
const c = require('./build/Release/RecastCLI');

c.setTarget("target.obj")

c.load('v -0.5 0 0.5@v -0.5 0 -0.5@v 0.5 0 0.5@v 0.5 0 -0.5@v -0.05 -0.05 -0.05@v -0.05 -0.05 0.05@v 0.05 -0.05 -0.05@v 0.05 -0.05 0.05@v -0.05 0.05 0.05@v -0.05 0.05 -0.05@v 0.05 0.05 0.05@v 0.05 0.05 -0.05@v -0.05 -0.05 0.05@v -0.05 0.05 0.05@v 0.05 -0.05 0.05@v 0.05 0.05 0.05@v -0.05 0.05 -0.05@v -0.05 -0.05 -0.05@v 0.05 0.05 -0.05@v 0.05 -0.05 -0.05@v 0.05 -0.05 -0.05@v 0.05 -0.05 0.05@v 0.05 0.05 -0.05@v 0.05 0.05 0.05@v -0.05 -0.05 0.05@v -0.05 -0.05 -0.05@v -0.05 0.05 0.05@v -0.05 0.05 -0.05@f 3 2 1@f 4 2 3@f 7 6 5@f 8 6 7@f 11 10 9@f 12 10 11@f 15 14 13@f 16 14 15@f 19 18 17@f 20 18 19@f 23 22 21@f 24 22 23@f 27 26 25@f 28 26 27@');

c.build(0.001, 0.001, 0.1, 0.1, 10.0); // return string

c.save("exp.obj");
```

![](https://user-images.githubusercontent.com/7625588/37197151-9621d722-23b4-11e8-95b2-f2f2a9b6dccf.png)

----
# Command line tools

> @ master branch

## Building

![](https://user-images.githubusercontent.com/7625588/36931376-1824eb9e-1eef-11e8-84f6-02b93cfce723.png)

## Usage

```shell
$ ./RecastCLI nav_test.obj 0 0 0 0 0 0 0 0 0 0 0 0 0 > navmesh.obj
```
 - Running at debug mode
Toggle with macro `#define DEBUG`
![](https://user-images.githubusercontent.com/7625588/37192900-ac44b93c-23a2-11e8-8487-92699f0ecb3c.png)

### Order

 - cellSize
 - cellHeight
 - agentHeight
 - agentRadius
 - agentMaxClimp
 - agentMaxSlope
 - regionMinSize
 - regionMergeSize
 - edgeMaxLen
 - edgeMaxError
 - vertsPerPoly
 - detailSampleDist
 - detailSampleMaxErro