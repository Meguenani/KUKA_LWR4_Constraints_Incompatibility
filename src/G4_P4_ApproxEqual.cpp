#include "G4ios.hh"
#include "globals.hh"
#include "G4AnalyticalPolSolver.hh"
#include "geomdefs.hh"

// #include "ApproxEqual.hh"

const G4double kApproxEqualTolerance = 1E-6;
// const G4double kApproxEqualTolerance = 1E-2;

// Return true if the double check is approximately equal to target
//
// Process:
//
// Return true is check if less than kApproxEqualTolerance from target

G4bool ApproxEqual(const G4double check,const G4double target)
{
  G4bool result;
  G4double mean, delta;
  mean  = 0.5*std::fabs(check + target);
  delta =     std::fabs(check - target);

  if(mean > 1.) delta /= mean;

  if(delta<kApproxEqualTolerance) result = true;
  else                            result = false;
  return result;
}


