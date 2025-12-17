/**********************************************************************
 *                         Math_Tools v0.0.1                          
 *                Created by Ranyodh Mandur - ☔ 2025
 *
 *           Math_Tools is a free open source Math Tool Kit
 * 
 *  This program is free software: you can redistribute it and/or 
 *  modify it under the terms of the GNU General Public License 
 *  as published by the Free Software Foundation, either version 3 
 *      of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,  
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the 
 *         GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU GPL along with this 
 *      program. If not, see <https://www.gnu.org/licenses/>.
 * 
**********************************************************************/

#include <iostream>
#include <complex>
#include <cmath>

using namespace std;

complex<double> 
    fast_exp_neg_ix(double x) 
{
    return complex<double>(cos(x), -sin(x));
}

int 
    main(int fp_ArgCount, const char* fp_ArgVector[]) //This method kinda clean ngl lmfao
{
    std::cout << "Hello World!\n"; //Used this to test the projects first start up uwu

    try
    {
        double x = 1.0; // input angle in radians

        complex<double> z = exp(complex<double>(0, -x)); // e^(-ix)

        cout << "e^(-i * " << x << ") = " << z.real() << " + " << z.imag() << "i" << endl;


        return EXIT_SUCCESS;
    }

    catch (const std::exception& Exception) ///Try to ensure all destructors are called especially close() on LogManager
    {

        return EXIT_FAILURE;
    }
}
