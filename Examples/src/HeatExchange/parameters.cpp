#include <iostream>
#include "parameters.hpp"
std::ostream & operator << (std::ostream & out,const parameters & p)
{
  out<<"PARAMETER VALUES:"<<"\n";
  out<<"L= "<<p.L<<"\n";
  out<<"a1= "<<p.a1<<"\n";
  out<<"a2= "<<p.a2<<"\n";
  out<<"To= "<<p.To<<"\n";
  out<<"Te= "<<p.Te<<"\n";
  out<<"k= "<<p.k<<"\n";
  out<<"hc= "<<p.hc<<"\n";
  out<<"M= "<<p.M<<"\n\n";
  out<<"output= "<<p.output<<"\n\n";
  out<<"screen= "<<p.screen<<"\n\n";
  out<<"spreadsheet= "<<p.spreadsheet<<"\n\n";
  return out;
}
