/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2011 Ciengis

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Common Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */

#include <cppadcg/cg.hpp>
#include "gcc_load_dynamic.hpp"
#include "atan_2.hpp"

bool Atan2() {
    using namespace CppAD;

    // independent variable vector
    std::vector<double> u(1);
    u[0] = 1.;

    bool ok = test0nJac("Atan2",&Atan2Func<double >, &Atan2Func<CG<double> >, u);

    return ok;
}