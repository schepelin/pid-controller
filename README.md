# TODO:
- add min and max values for control action

# PID Controller

It's simple implementation of [PID Controller](https://en.wikipedia.org/wiki/PID_controller). I hadn't found comprehensible library and implemented my own.

# Usage

I suppose to use it for arduino sensors

Simple example:

```c++
#include "PID.h"

int main() {
    double targetCondition = 1000;
    float proportionalGain, integralGain, derivativeGain = 0.1;
    PIDController pid (targetCondition, proportionalGain, integralGain, derivativeGain);

    double currentCondition = yourModel.getData();
    double controllAction = pid.compute(currentCondition);
    yourModel.apply(controllAction);
}
```

# Run test
To run test you have to install [CxxTest](http://cxxtest.com/)

```
CXX_PATH=/your/path/to/cxx make test
```

by default CXX_PATH is set `/usr/local/include`
