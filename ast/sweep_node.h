#ifndef __GR8_SWEEPNODE_H__
#define __GR8_SWEEPNODE_H__



namespace gr8 {

  /**
   * Class for describing sweep-cycle nodes.
   */
  class sweep_node: public cdk::basic_node {
    cdk::lvalue_node *_leftvalue;
    cdk::expression_node *_condition;
    cdk::basic_node *_block;
    cdk::expression_node *_initialization;
    cdk::expression_node *_increment;

  public:
    inline sweep_node(int lineno, cdk::lvalue_node *leftvalue, cdk::expression_node *condition, cdk::basic_node *block, cdk::expression_node *initialization, cdk::expression_node *increment) :
        cdk::basic_node(lineno), _leftvalue(leftvalue), _condition(condition), _block(block), _initialization(initialization), _increment(increment) {
    }

  public:
    inline cdk::expression_node *condition() {
      return _condition;
    }
    inline cdk::basic_node *block() {
      return _block;
    }
    inline cdk::expression_node *initialization() {
      return _initialization;
    }
    inline cdk::expression_node *increment() {
      return _increment;
    }

    inline cdk::lvalue_node *leftvalue() {
      return _leftvalue;
    }
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_sweep_node(this, level);
    }

  };

} // gr8

#endif
