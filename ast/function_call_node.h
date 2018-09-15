#ifndef __GR8_FUNCTIONCALLNODE_H__
#define __GR8_FUNCTIONCALLNODE_H__

#include <string>



namespace gr8 {

  /**
   * Class for describing function call nodes.
   */
  class function_call_node: public cdk::expression_node {
    std::string *_name;
    cdk::sequence_node *_parameters;


  public:
    inline function_call_node(int lineno, std::string *name, cdk::sequence_node *parameters) :
        cdk::expression_node(lineno),_name(name), _parameters(parameters) {
    }

  public:

    inline std::string name(){
      return *_name;
    }

    inline cdk::sequence_node *parameters(){
      return _parameters;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // gr8

#endif
