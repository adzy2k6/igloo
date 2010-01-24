#ifndef IGLOO_CONSTRAINTADAPTER_H
#define IGLOO_CONSTRAINTADAPTER_H

namespace igloo {
 
  template <typename ConstraintType>
  struct ConstraintAdapter
  {
    ConstraintAdapter(const ConstraintType& constraint) : m_constraint(constraint)
    {
    }
    
    template <typename ConstraintListType, typename ActualType>
    void Evaluate(ConstraintListType& list, ResultStack& result, OperatorStack& operators, const ActualType& actual)
    {
      result.push(m_constraint(actual));
      EvaluateConstraintList(list.m_tail, result, operators, actual);
    }
    
    ConstraintType m_constraint;
  };
  
  template <typename ConstraintType>
  inline std::string Stringize(const ConstraintAdapter<ConstraintType>& constraintAdapter)
  {
    return Stringize(constraintAdapter.m_constraint);
  }
  
}

#endif
