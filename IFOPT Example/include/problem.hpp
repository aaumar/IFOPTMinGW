#include <ifopt/variable_set.h>
#include <ifopt/constraint_set.h>
#include <ifopt/cost_term.h>

namespace ifopt {
using Eigen::Vector2d;


class ExVariables : public VariableSet {
public:
  ExVariables() : ExVariables("var_set1") {};
  ExVariables(const std::string& name) : VariableSet(2, name){
    // the initial values where the NLP starts iterating from
    x0_ = 3.5;
    x1_ = 1.5;
  };
  void SetVariables(const VectorXd& x) override;
  VectorXd GetValues() const override;
  VecBound GetBounds() const override;

private:
  double x0_, x1_;
};


class ExConstraint : public ConstraintSet {
public:
  ExConstraint() : ExConstraint("constraint1") {};
  ExConstraint(const std::string& name) : ConstraintSet(1, name) {}
  VectorXd GetValues() const override;
  VecBound GetBounds() const override;
  void FillJacobianBlock (std::string var_set, Jacobian& jac_block) const override;
};


class ExCost: public CostTerm {
public:
  ExCost() : ExCost("cost_term1") {}
  ExCost(const std::string& name) : CostTerm(name) {}

  double GetCost() const override;

  void FillJacobianBlock (std::string var_set, Jacobian& jac) const override;
};

} // namespace opt