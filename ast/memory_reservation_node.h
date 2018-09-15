#ifndef __GR8_MEMORYRESERVATIONNODE_H__
#define __GR8_MEMORYRESERVATIONNODE_H__



namespace gr8 {

  /**
   * Class for describing memory reservation nodes.
   */
  class memory_reservation_node: public cdk::unary_expression_node {

  public:
    inline memory_reservation_node(int lineno, expression_node *arg) :
        cdk::unary_expression_node(lineno, arg) {
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_memory_reservation_node(this, level);
    }

  };

} // gr8

#endif
