#include <string>
#include <vector>
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated
#include "targets/function_checker.h"

#define ASSERT_UNSPEC \
    { if (node->type() != nullptr && \
          node->type()->name() != basic_type::TYPE_UNSPEC) return; }

basic_type *_typeReturn = new basic_type(0, basic_type::TYPE_UNSPEC);

void check_types(basic_type* type1, basic_type* type2){
  if ((type1->name() == basic_type::TYPE_UNSPEC) && (type2->name() == basic_type::TYPE_UNSPEC))
    throw std::string("Invalid types!");
  if (type1->name() == basic_type::TYPE_UNSPEC){
    type1->_name = type2->name();
    type1->_size = type2->size();
    if (type2->name() == basic_type::TYPE_POINTER){
      type1->_subtype = new basic_type(0, basic_type::TYPE_UNSPEC);
      check_types(type2->subtype(), type1->subtype());
    }
  }
  else if (type2->name() == basic_type::TYPE_UNSPEC){
      type2->_name = type1->name();
      type2->_size = type1->size();
      if (type1->name() == basic_type::TYPE_POINTER){
        type2->_subtype = new basic_type(0, basic_type::TYPE_UNSPEC);
        check_types(type2->subtype(), type1->subtype());
      }
    }
}

basic_type* find_subtype(basic_type* node){
  if (node->subtype() == nullptr){
    return node;
  }
  else return find_subtype(node->subtype());
}
//---------------------------------------------------------------------------

void gr8::type_checker::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  //EMPTY
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void gr8::type_checker::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void gr8::type_checker::do_double_node(cdk::double_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_DOUBLE));
}
void gr8::type_checker::do_not_node(cdk::not_node * const node, int lvl) {
  processUnaryExpression(node, lvl);
}
void gr8::type_checker::do_and_node(cdk::and_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void gr8::type_checker::do_or_node(cdk::or_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_integer_node(cdk::integer_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void gr8::type_checker::do_string_node(cdk::string_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_STRING));
}

//---------------------------------------------------------------------------

void gr8::type_checker::processUnaryExpression(cdk::unary_expression_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->type()->name() != basic_type::TYPE_INT)  throw std::string("wrong type in argument of unary expression");

  // in Simple, expressions were always int
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

void gr8::type_checker::do_neg_node(cdk::neg_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if ((node->argument()->type()->name() != basic_type::TYPE_INT) && (node->argument()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in argument of neg expression");
  if (node->argument()->type()->name() == basic_type::TYPE_INT)
    node->type(new basic_type(4, basic_type::TYPE_INT));
  else
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
}

//---------------------------------------------------------------------------

void gr8::type_checker::processBinaryExpression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  check_types(node->left()->type(), node->right()->type());
  if (node->left()->type()->name() != basic_type::TYPE_INT) throw std::string("wrong type in left argument of binary expression");
  if (node->right()->type()->name() != basic_type::TYPE_INT) throw std::string("wrong type in right argument of binary expression");

  // in Simple, expressions were always int
  node->type(new basic_type(4, basic_type::TYPE_INT));

}

void gr8::type_checker::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->right()->accept(this, lvl + 2);
  node->left()->accept(this, lvl + 2);
  check_types(node->left()->type(), node->right()->type());
  if ((node->right()->type()->name() != basic_type::TYPE_POINTER) && (node->right()->type()->name() != basic_type::TYPE_INT) && (node->right()->type()->name() != basic_type::TYPE_DOUBLE))
    throw std::string("wrong type in right argument of add expression");
  if ((node->left()->type()->name() != basic_type::TYPE_POINTER) && (node->left()->type()->name() != basic_type::TYPE_INT) && (node->left()->type()->name() != basic_type::TYPE_DOUBLE))
    throw std::string("wrong type in right argument of add expression");
  if (node->right()->type()->name() == basic_type::TYPE_POINTER){
    if ((node->left()->type()->name() == basic_type::TYPE_POINTER) || (node->left()->type()->name() == basic_type::TYPE_DOUBLE)) throw std::string("wrong type in arguments of add expression");
  }
  if (node->left()->type()->name() == basic_type::TYPE_POINTER){
    if (node->right()->type()->name() == basic_type::TYPE_DOUBLE) throw std::string("wrong type in arguments of add expression");
  }
  if (node->right()->type()->name() == basic_type::TYPE_POINTER) node->type(node->right()->type());
  else if (node->left()->type()->name() == basic_type::TYPE_POINTER){ node->type(node->left()->type());}
  else if ((node->right()->type()->name() == basic_type::TYPE_DOUBLE) || (node->left()->type()->name() == basic_type::TYPE_DOUBLE))
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else node->type(new basic_type(4, basic_type::TYPE_INT));
}

void gr8::type_checker::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->right()->accept(this, lvl + 2);
  node->left()->accept(this, lvl + 2);
  check_types(node->left()->type(), node->right()->type());
  if ((node->right()->type()->name() != basic_type::TYPE_POINTER) && (node->right()->type()->name() != basic_type::TYPE_INT) && (node->right()->type()->name() != basic_type::TYPE_DOUBLE))
    throw std::string("wrong type in right argument of sub expression");
  if ((node->left()->type()->name() != basic_type::TYPE_POINTER) && (node->left()->type()->name() != basic_type::TYPE_INT) && (node->left()->type()->name() != basic_type::TYPE_DOUBLE))
    throw std::string("wrong type in right argument of sub expression");
  if (node->right()->type()->name() == basic_type::TYPE_POINTER){
    if (node->type()->name() == basic_type::TYPE_DOUBLE) throw std::string("wrong type in arguments of sub expression");
  }
  if (node->left()->type()->name() == basic_type::TYPE_POINTER){
    if (node->right()->type()->name() == basic_type::TYPE_DOUBLE) throw std::string("wrong type in arguments of sub expression");
  }

  if ((node->right()->type()->name() == basic_type::TYPE_POINTER) && (node->left()->type()->name() == basic_type::TYPE_POINTER))
    node->type(new basic_type(4, basic_type::TYPE_INT));
  else if (node->right()->type()->name() == basic_type::TYPE_POINTER) node->type(node->right()->type());
  else if (node->left()->type()->name() == basic_type::TYPE_POINTER) node->type(node->left()->type());
  else if ((node->right()->type()->name() == basic_type::TYPE_DOUBLE) || (node->left()->type()->name() == basic_type::TYPE_DOUBLE))
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else node->type(new basic_type(4, basic_type::TYPE_INT));
}

void gr8::type_checker::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->right()->accept(this, lvl + 2);
  node->left()->accept(this, lvl + 2);
  check_types(node->left()->type(), node->right()->type());
  if ((node->right()->type()->name() != basic_type::TYPE_INT) && (node->right()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in right argument of mul expression");
  if ((node->left()->type()->name() != basic_type::TYPE_INT) && (node->left()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in left argument of mul expression");
  if ((node->left()->type()->name() == basic_type::TYPE_DOUBLE) || node->right()->type()->name() == basic_type::TYPE_DOUBLE)
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else
    node->type(new basic_type(4, basic_type::TYPE_INT));
}
void gr8::type_checker::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->right()->accept(this, lvl + 2);
  node->left()->accept(this, lvl + 2);
  check_types(node->left()->type(), node->right()->type());
  if ((node->right()->type()->name() != basic_type::TYPE_INT) && (node->right()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in right argument of div expression");
  if ((node->left()->type()->name() != basic_type::TYPE_INT) && (node->left()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in left argument of div expression");
  if ((node->left()->type()->name() == basic_type::TYPE_DOUBLE) || node->right()->type()->name() == basic_type::TYPE_DOUBLE)
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
  else
    node->type(new basic_type(4, basic_type::TYPE_INT));
}
void gr8::type_checker::do_mod_node(cdk::mod_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
}

void gr8::type_checker::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->right()->accept(this, lvl + 2);
  node->left()->accept(this, lvl + 2);
  check_types(node->left()->type(), node->right()->type());
  if ((node->right()->type()->name() != basic_type::TYPE_INT) && (node->right()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in right argument of lt expression");
  if ((node->left()->type()->name() != basic_type::TYPE_INT) && (node->left()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in left argument of lt expression");
  node->type(new basic_type(4, basic_type::TYPE_INT));

}

void gr8::type_checker::do_le_node(cdk::le_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
  check_types(node->left()->type(), node->right()->type());
}
void gr8::type_checker::do_ge_node(cdk::ge_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
  check_types(node->left()->type(), node->right()->type());
}
void gr8::type_checker::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_UNSPEC;
  node->right()->accept(this, lvl + 2);
  node->left()->accept(this, lvl + 2);
  check_types(node->left()->type(), node->right()->type());
  if ((node->right()->type()->name() != basic_type::TYPE_INT) && (node->right()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in right argument of lt expression");
  if ((node->left()->type()->name() != basic_type::TYPE_INT) && (node->left()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in left argument of lt expression");
  node->type(new basic_type(4, basic_type::TYPE_INT));
}
void gr8::type_checker::do_ne_node(cdk::ne_node * const node, int lvl) {
  processBinaryExpression(node, lvl);
  check_types(node->left()->type(), node->right()->type());
}
void gr8::type_checker::do_eq_node(cdk::eq_node * const node, int lvl) {
    ASSERT_UNSPEC;
    node->right()->accept(this, lvl + 2);
    node->left()->accept(this, lvl + 2);
    check_types(node->left()->type(), node->right()->type());
    if ((node->right()->type()->name() != basic_type::TYPE_INT) && (node->right()->type()->name() != basic_type::TYPE_DOUBLE) && (node->right()->type()->name() != basic_type::TYPE_POINTER)) throw std::string("wrong type in right argument of lt expression");
    if ((node->left()->type()->name() != basic_type::TYPE_INT) && (node->left()->type()->name() != basic_type::TYPE_DOUBLE)&& (node->left()->type()->name() != basic_type::TYPE_POINTER)) throw std::string("wrong type in left argument of lt expression");
    node->type(new basic_type(4, basic_type::TYPE_INT));
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  } else {
    throw id;
  }
}

void gr8::type_checker::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void gr8::type_checker::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_UNSPEC;

  try {
    node->lvalue()->accept(this, lvl);
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
  node->rvalue()->accept(this, lvl);
  check_types(node->lvalue()->type(), node->rvalue()->type());
  if ((node->lvalue()->type()->name() == basic_type::TYPE_DOUBLE) && (node->rvalue()->type()->name() == basic_type::TYPE_INT)) node->type(node->lvalue()->type());
  else if ((node->lvalue()->type()->name()) == (node->rvalue()->type()->name())) node->type(node->lvalue()->type());
  else throw std::string("wrong type in arguments of assignment expression");
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_evaluation_node(gr8::evaluation_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void gr8::type_checker::do_print_node(gr8::print_node * const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_read_node(gr8::read_node * const node, int lvl) {
  node->type(new basic_type(4, basic_type::TYPE_INT));
}

//---------------------------------------------------------------------------

void gr8::type_checker::do_if_node(gr8::if_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

void gr8::type_checker::do_if_else_node(gr8::if_else_node * const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
}

//--------------------------------------------------------------------------

void gr8::type_checker::do_address_node(gr8::address_node * const node, int lvl){
  ASSERT_UNSPEC;
  node->leftvalue()->accept(this, lvl + 4);
  node->type(new basic_type(4, basic_type::TYPE_POINTER));
}

void gr8::type_checker::do_stop_node(gr8::stop_node * const node, int lvl){
}

void gr8::type_checker::do_again_node(gr8::again_node * const node, int lvl){
}

void gr8::type_checker::do_sweep_node(gr8::sweep_node * const node, int lvl){
  node->leftvalue()->accept(this, lvl + 4);
  node->condition()->accept(this, lvl + 4);
  if(node->leftvalue()->type()->name() == basic_type::TYPE_STRING) throw std::string("wrong type in left value of sweep node");
  if (node->condition()->type()->name() != node->leftvalue()->type()->name()) throw std::string("wrong type in argument condition of sweep node");
  node->initialization()->accept(this, lvl + 4);
  if (node->initialization()->type()->name() != node->leftvalue()->type()->name()) throw std::string("wrong type in argument initialization of sweep node");
  node->increment()->accept(this, lvl + 4);
  if ((node->increment()->type()->name() != basic_type::TYPE_INT) && (node->increment()->type()->name() != basic_type::TYPE_INT)) throw std::string("wrong type in argument increment of sweep node");

}

void gr8::type_checker::do_function_call_node(gr8::function_call_node * const node, int lvl){
  const std::string &id = node->name();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);

  if (symbol == nullptr){
    throw id;
  }

  node->type(symbol->type());
  if(node->parameters()->size() != symbol->getArgs().size()) throw std::string("wrong arguments in function call node");
  for (size_t i = 0; i < node->parameters()->size(); i++){
    node->parameters()->node(i)->accept(this, lvl + 4);
    cdk::expression_node* actual_node = (cdk::expression_node*) node->parameters()->node(i);
    if (!((actual_node->type()->name() == basic_type::TYPE_INT) && (symbol->getArgs().at(i)->name() == basic_type::TYPE_DOUBLE)))
      if (actual_node->type()->name() != symbol->getArgs().at(i)->name()) throw std::string("wrong arguments in function call node");
  }
}

void gr8::type_checker::do_function_declaration_node(gr8::function_declaration_node * const node, int lvl){
  const std::string &id = node->name();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr){
    throw id + " already declared";
  }
  symbol = std::make_shared<gr8::symbol>(node->type(), node->name(), 0);
  symbol->set_is_public(node->ispublic());
  std::vector<basic_type*> args;
  for (size_t i = 0; i < node->parameters()->size(); i++){
    gr8::variable_declaration_node* actual_node = (gr8::variable_declaration_node*) node->parameters()->node(i);
    args.push_back(actual_node->type());
  }
  symbol->setArgs(args);
  _symtab.insert(node->name(), symbol);
  _parent->set_new_symbol(symbol);
}

void gr8::type_checker::do_function_node(gr8::function_node * const node, int lvl){
  const std::string &id = node->identifier();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);

  if (symbol == nullptr) {
    std::shared_ptr<gr8::symbol> symbol = std::make_shared<gr8::symbol>(node->type(), node->identifier(), 0);
    symbol->set_is_public(node->ispublic());
    std::vector<basic_type*> args;
    for (size_t i = 0; i < node->parameters()->size(); i++){
      gr8::variable_declaration_node* actual_node = (gr8::variable_declaration_node*) node->parameters()->node(i);
      args.push_back(actual_node->type());
    }
    symbol->setArgs(args);
    _symtab.insert(node->identifier(), symbol);
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted

  }
  else{
    for (size_t i = 0; i < node->parameters()->size(); i++){
      node->parameters()->node(i)->accept(this, lvl + 4);
      cdk::expression_node* actual_node = (cdk::expression_node*) node->parameters()->node(i);
      if (!((actual_node->type()->name() == basic_type::TYPE_INT) && (symbol->getArgs().at(i)->name() == basic_type::TYPE_DOUBLE)))
        if (actual_node->type()->name() != symbol->getArgs().at(i)->name()) throw std::string("wrong arguments in function call node");
    }
  }
  _typeReturn = node->type();
}

void gr8::type_checker::do_identity_node(gr8::identity_node * const node, int lvl){
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if ((node->argument()->type()->name() != basic_type::TYPE_INT) && (node->argument()->type()->name() != basic_type::TYPE_DOUBLE)) throw std::string("wrong type in argument of identity expression");
  if (node->argument()->type()->name() == basic_type::TYPE_INT)
    node->type(new basic_type(4, basic_type::TYPE_INT));
  else
    node->type(new basic_type(8, basic_type::TYPE_DOUBLE));
}

void gr8::type_checker::do_index_node(gr8::index_node * const node, int lvl){
  ASSERT_UNSPEC;
  node->identifier()->accept(this, lvl + 4);
  if(node->identifier()->type()->name() != basic_type::TYPE_POINTER) throw std::string("wrong type in identifier argument of index expression");
  node->index()->accept(this, lvl + 4);
  if(node->index()->type()->name() != basic_type::TYPE_INT) throw std::string("wrong type in index argument of index expression");
  node->type(find_subtype(node->identifier()->type()));
}

void gr8::type_checker::do_memory_reservation_node(gr8::memory_reservation_node * const node, int lvl){
    ASSERT_UNSPEC;
    node->argument()->accept(this, lvl + 2);
    if (node->argument()->type()->name() != basic_type::TYPE_INT)  throw std::string("wrong type in argument of unary expression");
    node->type(new basic_type(0, basic_type::TYPE_UNSPEC));
}

void gr8::type_checker::do_null_node(gr8::null_node * const node, int lvl){
  ASSERT_UNSPEC;
  node->type(new basic_type(4, basic_type::TYPE_POINTER));
}

void gr8::type_checker::do_return_node(gr8::return_node * const node, int lvl){
  node->value()->accept(this, lvl + 4);
  if (!((_typeReturn->name() == basic_type::TYPE_DOUBLE) && (node->value()->type()->name() == basic_type::TYPE_INT))){
    if (node->value()->type()->name() != _typeReturn->name()){
      throw std::string("wrong type of return in function");
    }
  }
}

void gr8::type_checker::do_variable_declaration_node(gr8::variable_declaration_node * const node, int lvl){
  node->value()->accept(this, lvl);
  check_types(node->type(), node->value()->type());
  if ((node->value()->type()->name() != node->type()->name()) && (!((node->type()->name() == basic_type::TYPE_DOUBLE) && (node->value()->type()->name() == basic_type::TYPE_INT)))){
    if (node->value()->type()->name() != basic_type::TYPE_POINTER) throw std::string("wrong type in value of variable declaration node");
  }
  const std::string &id = node->name();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);

  if (symbol == nullptr) {
    symbol = std::make_shared<gr8::symbol>(node->type(), node->name(), 0);
    symbol->set_is_public(node->ispublic());
    _symtab.insert(node->name(), symbol);
  }
  _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
}

void gr8::type_checker::do_block_node(gr8::block_node * const node, int lvl){
  //EMPTY
}
