# AlgorithmicDesign
This Repo contains the exercises for the algorithmic design course of DSSC, Academic year 2019/20.

In the Homework section you will find the pdf with the answers to the theoretical exercises or the ones
requiring us to perform an execution time analysis.

In the other directories you will find the source code of the required programs.

My suggestion regarding the compilation and execution of the code is the following:

Create a directory named Release in each subdirectory.

E.g. 
```
cd AD_sorting 
mkdir Release
```

Then type
```
cd Release
cmake -DCMAKE_BUILD_TYPE=Release ..
make
```

This will produce the executables. Repeat the process for every program you are interested in.