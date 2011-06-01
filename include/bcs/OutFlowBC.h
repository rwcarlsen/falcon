#ifndef OUTFLOWBC_H
#define OUTFLOWBC_H

#include "IntegratedBC.h"

//libMesh includes
#include "vector_value.h"


//Forward Declarations
class OutFlowBC;

template<>
InputParameters validParams<OutFlowBC>();

/**
 * Implements a simple constant VectorNeumann BC where grad(u)=value on the boundary.
 * Uses the term produced from integrating the diffusion operator by parts.
 */
class OutFlowBC : public IntegratedBC
{
public:

  /**
   * Factory constructor, takes parameters so that all derived classes can be built using the same
   * constructor.
   */
  OutFlowBC(const std::string & name, InputParameters parameters);
  
 virtual ~OutFlowBC(){}

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  
private:
  /**
   * Vector to dot with the normal.
   */
    VariableGradient & _grad_p;
    VariableGradient & _grad_T;
    
    
    VariableValue & _enthalpy_water;
    VariableValue & _enthalpy_steam;
    VariableValue & _dTdH;
    VariableValue & _denthalpy_waterdH;
    VariableValue & _denthalpy_steamdH;
    
 
    MaterialProperty<RealGradient> & _darcy_mass_flux_water;
    MaterialProperty<RealGradient> & _darcy_mass_flux_steam;
    MaterialProperty<Real> & _thermal_conductivity;   
//  std::vector<RealGradient> & _grad_p;
 
    
};

#endif //NEUMANNBC_H
