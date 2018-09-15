#ifndef __GR8_FUNCTIONDECLARATIONNODE_H__
#define __GR8_FUNCTIONDECLARATIONNODE_H__

#include <string>


namespace gr8 {

  /**
   * Class for describing function call nodes.
   */
  class function_declaration_node: public cdk::typed_node {
    bool _ispublic;
    std::string *_name;
    cdk::sequence_node *_parameters;

  public:
    inline function_declaration_node(int lineno, bool ispublic, std::string *name, cdk::sequence_node *parameters) :
        cdk::typed_node(lineno), _ispublic(ispublic), _name(name),  _parameters(parameters){
    }

  public:

    inline bool ispublic(){
      return _ispublic;
    }

    inline std::string name(){
      return *_name;
    }

    inline cdk::sequence_node *parameters(){
      return _parameters;
    }


    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_declaration_node(this, level);
    }

  };

} // gr8

#endif
