#include <iostream>
#include <vector>
#include <cmath>
typedef double real 
class derK{
	public
		derK(real k) : k(k){};
		real operator ()(real x){ return -k*x };
	private
		real k;
	}
class forward_euler{
	public	
		void apply(derK derk)
		{
			real t=start;
			real x=x0;
			real xold=0;
			real told=0;
			real xprime=0;
			while(t<stop)
			{
				xold=x;
				told=t;
				t+=dt;
				xprime=derk(x)
				x+=xprime*dt;
				real x2= .5*(x+xold+xprime*dt);
				real err= fabs(x2-x);
				if(err <= tol)
				{
					result.push_back(x);
					time.push_back(t);
				}
				else
				{
					std::cout << "reject"<< std::endl;
					x=xold;
					t=told;
				}
				std::cout << "%t="<<t<<";\ t_x_=" 
				<<x<<std::endl;
				dt *=.5*sqrt(tol/err);
				dt=t+dt>stop ? stop-t : dt;
			}
		}
