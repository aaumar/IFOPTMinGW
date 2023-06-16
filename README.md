## Things to change in original ifopt to work on MinGW

Changes in `CMakeLists.txt` in ifopt_ipopt
1. remove `find_package(IPOPT 3.11.9 REQUIRED)`
2. add ipopt inside `target_link_libraries(${LIB_IPOPT} ... ... PRIVATE ipopt ...)`
    - actually you can remove `${IPOPT_LIBRARIES}` 

inside folder `ifopt_ipopt/include/ifopt`
1. File `ipopt_adapter.h`, change the following  
`#include <IpTNLP.hpp>`  
`#include <IpIpoptApplication.hpp>`  
`#include <IpSolveStatistics.hpp>`  
into  
`#include <coin-or/IpTNLP.hpp>`  
`#include <coin-or/IpIpoptApplication.hpp>`  
`#include <coin-or/IpSolveStatistics.hpp>`

## To-Do List

- [] Update documentation