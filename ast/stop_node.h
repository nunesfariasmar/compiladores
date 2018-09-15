#ifndef __GR8_STOPNODE_H__
#define __GR8_STOPNODE_H__


namespace gr8 {

  /**
   * Class for describing stop nodes.
   */
  class stop_node: public cdk::basic_node {
    int _integerLiteral;

  public:
    inline stop_node(int lineno, int integerLiteral) :
        cdk::basic_node(lineno), _integerLiteral(integerLiteral) {
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stop_node(this, level);
    }


  public:
    inline int integerLiteral() {
      return _integerLiteral;
    }

  };

} // gr8

#endif
