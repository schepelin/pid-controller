#define private public

#include <stdexcept>
#include <cxxtest/TestSuite.h>
#include "PID.h"


class PIDTestSuite : public CxxTest::TestSuite
{
public:
    void test_creates_PID_with_constructor(void)
    {
        PIDController pid (42, 1.0, 2.0, 3.0, 4.0);
        TS_ASSERT_EQUALS(pid.targetCondition, 42);
        TS_ASSERT_EQUALS(pid.proportionalGain, 1.0);
        TS_ASSERT_EQUALS(pid.integralGain, 2.0);
        TS_ASSERT_EQUALS(pid.derivativeGain, 3.0);
        TS_ASSERT_EQUALS(pid.accumulatedError, 0);
        TS_ASSERT_EQUALS(pid.previousError, 0);
        TS_ASSERT_EQUALS(pid.timeDelta, 4.0);
    }
    void test_constructor_validates_zero_time_elta(void)
    {
        TS_ASSERT_THROWS(PIDController pid (42, 1, 1, 1, 0), std::invalid_argument);

    }
    void test_it_calculates_proportional_error_correctly(void)
    {
        PIDController pid (42, 0.5, 1, 1, 1);
        double actual = pid._GetProportionalError(100);
        double expected = 50;
        TS_ASSERT_EQUALS(actual, expected);
    }
    void test_it_computes_accumulated_error(void)
    {
        PIDController pid (42, 1, 1, 1, 1);
        TS_ASSERT_EQUALS(pid.accumulatedError, 0);
        pid._ComputeAccumulatedError(42);
        TS_ASSERT_DELTA(pid.accumulatedError, 42 * pid.timeDelta, 0.0001);
    }
    void test_it_computes_derivative_error_correctly(void)
    {
        PIDController pid (42, 1, 1, 1, 1);
        double actual = pid._GetProportionalError(42);
        TS_ASSERT_DELTA(actual, 42 * pid.derivativeGain / pid.timeDelta, 0.0001)
    }
    void test_compute_is_ok(void)
    {
        PIDController pid (42, 1, 1, 1, 1);
        double currentCondition = 10;
        double actual = pid.Compute(currentCondition);
        TS_ASSERT_EQUALS(actual, 96);
    }
};
