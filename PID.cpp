#include <stdio.h>
#include <stdexcept>
#include "PID.h"


PIDController::PIDController (double target, float kP, float kI, float kD, float dt)
{
    if (dt == 0) {
        throw std::invalid_argument("timeDelta interval is set to 0");
    }
    accumulatedError = 0;
    previousError = 0;
    targetCondition = target;
    proportionalGain = kP;
    integralGain = kI;
    derivativeGain = kD;
    timeDelta = dt;
}

double PIDController::_GetProportionalError(double e)
{
    return proportionalGain * e;
}

double PIDController::_GetDerivativeError(double e)
{
    return derivativeGain * (e - previousError) / timeDelta;
}

void PIDController::_ComputeAccumulatedError(double e)
{
    accumulatedError += e * timeDelta;
}

double PIDController::Compute(double currentCondition)
{
    double error = targetCondition - currentCondition;
    _ComputeAccumulatedError(error);
    double result = _GetProportionalError(error) + integralGain * accumulatedError + _GetDerivativeError(error);
    previousError = error;

    return result;
}
