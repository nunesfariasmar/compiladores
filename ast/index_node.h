#ifndef __GR8_INDEXNODE_H__
#define __GR8_INDEXNODE_H__



namespace gr8 {

  /**
   * Class for describing index nodes.
   */
  class index_node: public cdk::lvalue_node {
    cdk::expression_node *_index;
    cdk::expression_node *_identifier;

  public:
    inline index_node(int lineno, cdk::expression_node *index, cdk::expression_node *identifier) :
        cdk::lvalue_node(lineno), _index(index), _identifier(identifier) {
    }

  public:
    inline cdk::expression_node *index() {
      return _index;
    }
    inline cdk::expression_node *identifier() {
      return _identifier;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_index_node(this, level);
    }

  };

} // gr8

#endif
