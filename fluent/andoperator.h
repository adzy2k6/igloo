#ifndef IGLOO_ANDOPERATOR_H
#define IGLOO_ANDOPERATOR_H

namespace igloo {
  
  struct AndOperator : public ConstraintOperator
  {
    template <typename ConstraintListType, typename ActualType>
    void Evaluate(ConstraintListType& list, ResultStack& result, OperatorStack& operators, const ActualType& actual)
    {
      EvaluateOperatorsOnStack(operators, result);
      
      EvaluateConstraintList(list.m_tail, result, operators, actual);
    }
    
    void PerformOperation(ResultStack& result)
    {
      if(result.size() < 2)
      {
        throw InvalidExpressionException("Too few arguments for and operator");
      }
      
      bool right = result.top();
      result.pop();
      bool left = result.top();
      result.pop();
      
      result.push(left && right);
    }
    
    int Precedence()
    {
      return 3;
    }
  };
  
  inline std::string Stringize(const AndOperator&)
  {
    return "and";
  }
  
}
#endif
