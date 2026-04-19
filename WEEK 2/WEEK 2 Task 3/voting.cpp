#include "Voter.h"

bool Voter::isEligible()
{
    if(age > 18)
        return true;
    else
        return false;
}
