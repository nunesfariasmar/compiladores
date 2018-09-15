#ifndef __GR8_VARIABLE_DECLERATION_NODE_H__
#define __GR8_VARIABLE_DECLARATION_NODE_H__


namespace gr8 {

  /**
   * Class for describing variable declaration nodes.
   */
  class variable_declaration_node: public cdk::typed_node {
    bool _ispublic;
    std::string *_name;
    cdk::expression_node *_value;

  public:
    variable_declaration_node(int lineno, bool ispublic, std::string *name, cdk::expression_node *value) :
        cdk::typed_node(lineno), _ispublic(ispublic), _name(name), _value(value) {
    }

  public:
    inline cdk::expression_node *value() {
      return _value;
    }
    inline bool ispublic() {
      return _ispublic;
    }
    inline std::string name(){
      return *_name;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_variable_declaration_node(this, level);
    }

  };

} // gr8

#endif
