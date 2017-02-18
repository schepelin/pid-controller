
class PIDController
{
private:
    double targetCondition;
    double accumulatedError;
    double previousError;
    float proportionalGain;
    float integralGain;
    float derivativeGain;
    float timeDelta;

    double _GetProportionalError(double);
    double _GetDerivativeError(double);
    void _ComputeAccumulatedError(double);
public:
    PIDController (double targetCondition, float kP, float kI, float kD, float dt);

    double Compute(double);

};
