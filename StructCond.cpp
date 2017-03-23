#include "StructCond.h"

using namespace std;

StructCond::StructCond()
{

}

StructCond::StructCond(Clause* & clause)
{
    AjouteClause(clause);
}

StructCond::~StructCond()
{

}

void StructCond::AjouteClause(Clause* & clause)
{
    clauses.push_back(clause);
}

std::string StructCond::toString() {
  return "[I] StructCond";
}
