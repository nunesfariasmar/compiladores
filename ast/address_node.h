#ifndef __GR8_ADDRESSNODE_H__
#define __GR8_ADRESSNODE_H__


namespace gr8 {

  /**
   * Class for describing adress nodes.
   */
  class address_node: public cdk::expression_node {
    cdk::lvalue_node *_leftvalue;

  public:
    inline address_node(int lineno, cdk::lvalue_node *leftvalue) :
        cdk::expression_node(lineno), _leftvalue(leftvalue) {
    }

    cdk::lvalue_node *leftvalue(){
      return _leftvalue;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_address_node(this, level);
    }

  };

} // gr8

#endif
