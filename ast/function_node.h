#ifndef __GR8_FUNCTIONNODE_H__
#define __GR8_FUNCTIONNODE_H__

#include <string>

namespace gr8 {

  /**
   * Class for describing function nodes.
   */
  class function_node: public cdk::typed_node {
  	bool _ispublic;
    std::string *_identifier;
    cdk::sequence_node *_parameters;
    block_node *_block;

  public:
    inline function_node(int lineno, bool ispublic, std::string *identifier, cdk::sequence_node *parameters, block_node *block) :
        cdk::typed_node(lineno), _ispublic(ispublic), _identifier(identifier), _parameters(parameters), _block(block) {
    }

  public:
    const bool &ispublic() const {
      return _ispublic;
    }
    const std::string identifier() const {
      return *_identifier;
    }
    inline cdk::sequence_node *parameters() {
      return _parameters;
    }
    inline block_node *block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_node(this, level);
    }

  };

} // gr8

#endif
