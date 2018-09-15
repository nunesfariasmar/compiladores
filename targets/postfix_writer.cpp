#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include "ast/all.h"  // all.h is automatically generated
#include "targets/function_checker.h"

std::vector<int> _label4stop;
std::vector<int> _label4again;
std::set<std::string> _functions_to_import;
std::vector<gr8::variable_declaration_node*> _bss_nodes;
basic_type *_returnType = new basic_type(0, basic_type::TYPE_UNSPEC);

void gr8::postfix_writer::import_functions(){
  std::set<std::string>::iterator it;
  for(it = _functions_to_import.begin(); it != _functions_to_import.end(); ++it){
    _pf.EXTERN(*it);
  }
}

bool gr8::postfix_writer::convert_to_double(basic_type *type1, basic_type *type2){
  if ((type1->name() == basic_type::TYPE_DOUBLE) && (type2->name() == basic_type::TYPE_INT))
    return true;
  return false;
}

bool gr8::postfix_writer::in_vector(gr8::variable_declaration_node* node){
  for(size_t i = 0; i < _bss_nodes.size(); i++){
    variable_declaration_node* actual_node = _bss_nodes.at(i);
    if(node->name() == actual_node->name()) return true;
  }
  return false;
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void gr8::postfix_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void gr8::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  _pf.DOUBLE(node->value());
}
void gr8::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  int lblelse, lblend;
  _pf.INT(0);
  _pf.EQ();
  _pf.JZ(mklbl(lblelse = ++_lbl));
  _pf.TRASH(4);
  _pf.INT(1);
  _pf.JMP(mklbl(lblend = ++_lbl));
  _pf.LABEL(mklbl(lblelse));
  _pf.TRASH(4);
  _pf.INT(0);
  _pf.LABEL(mklbl(lblend));
}
void gr8::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lblfalse, lblend;
  node->left()->accept(this, lvl);
  _pf.INT(0);
  _pf.EQ();
  _pf.JNZ(mklbl(lblfalse = ++_lbl));
  node->right()->accept(this, lvl);
  _pf.INT(0);
  _pf.EQ();
  _pf.JNZ(mklbl(lblfalse));
  _pf.INT(1);
  _pf.JMP(mklbl(lblend = ++_lbl));
  _pf.LABEL(mklbl(lblfalse));
  _pf.INT(0);
  _pf.LABEL(mklbl(lblend));
}
void gr8::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbltrue, lblend;
  node->left()->accept(this, lvl);
  _pf.INT(0);
  _pf.EQ();
  _pf.JZ(mklbl(lbltrue = ++_lbl));
  node->right()->accept(this, lvl);
  _pf.INT(0);
  _pf.EQ();
  _pf.JZ(mklbl(lbltrue));
  _pf.INT(0);
  _pf.JMP(mklbl(lblend = ++_lbl));
  _pf.LABEL(mklbl(lbltrue));
  _pf.INT(1);
  _pf.LABEL(mklbl(lblend));
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  _pf.INT(node->value());
}

void gr8::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.SSTRING(node->value()); // output string characters

  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE){
    _pf.DNEG();
  } else
  _pf.NEG(); // 2-complement
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  else if((node->left()->type()->name() == basic_type::TYPE_INT) && (node->right()->type()->name() == basic_type::TYPE_POINTER)){
    if (node->right()->type()->subtype()->name() == basic_type::TYPE_DOUBLE){
      _pf.INT(8);
    } else
    _pf.INT(4);
    _pf.MUL();
  }
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  else if((node->right()->type()->name() == basic_type::TYPE_INT) && (node->left()->type()->name() == basic_type::TYPE_POINTER)){
    if (node->left()->type()->subtype()->name() == basic_type::TYPE_DOUBLE){
      _pf.INT(8);
    } else
    _pf.INT(4);
    _pf.MUL();
  }
  if ((node->right()->type()->name() == basic_type::TYPE_DOUBLE) || (node->left()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DADD();
  } else
  _pf.ADD();
}
void gr8::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  if ((node->right()->type()->name() == basic_type::TYPE_DOUBLE) || (node->left()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DSUB();
  } else
  _pf.SUB();
}
void gr8::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  if ((node->right()->type()->name() == basic_type::TYPE_DOUBLE) || (node->left()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DMUL();
  } else
  _pf.MUL();
}
void gr8::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  if ((node->right()->type()->name() == basic_type::TYPE_DOUBLE) || (node->left()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DDIV();
  } else
  _pf.DIV();
}
void gr8::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void gr8::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  if((node->left()->type()->name() == basic_type::TYPE_DOUBLE) || (node->right()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.LT();
}
void gr8::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  if((node->left()->type()->name() == basic_type::TYPE_DOUBLE) || (node->right()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.LE();
}
void gr8::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  if((node->left()->type()->name() == basic_type::TYPE_DOUBLE) || (node->right()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.GE();
}
void gr8::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  if((node->left()->type()->name() == basic_type::TYPE_DOUBLE) || (node->right()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.GT();
}
void gr8::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  if((node->left()->type()->name() == basic_type::TYPE_DOUBLE) || (node->right()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.NE();
}
void gr8::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  if(convert_to_double(node->right()->type(), node->left()->type())) _pf.I2D();
  node->right()->accept(this, lvl);
  if(convert_to_double(node->left()->type(), node->right()->type())) _pf.I2D();
  if((node->left()->type()->name() == basic_type::TYPE_DOUBLE) || (node->right()->type()->name() == basic_type::TYPE_DOUBLE)){
    _pf.DCMP();
    _pf.INT(0);
  }
  _pf.EQ();
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  const std::string &id = node->name();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);
  if (symbol == nullptr) {
    throw std::string("identifier undeclared");
  }

  if(!(symbol->infunction()))
    _pf.ADDR(node->name());
  else {
    _pf.LOCAL(symbol->offset());
  }
}

void gr8::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  if(node->type()->name() == basic_type::TYPE_INT || node->type()->name() == basic_type::TYPE_POINTER || node->type()->name() == basic_type::TYPE_STRING){
    _pf.LDINT();
  } else if(node->type()->name() == basic_type::TYPE_DOUBLE){
    _pf.LDDOUBLE();
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN1!" << std::endl;
    exit(1);
  }
}

void gr8::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->rvalue()->accept(this, lvl); // determine the new value
  if (convert_to_double(node->lvalue()->type(), node->rvalue()->type()))
    _pf.I2D();
  node->lvalue()->accept(this, lvl);

  // _pf.DUP32();

  if(node->type()->name() == basic_type::TYPE_INT || node->type()->name() == basic_type::TYPE_POINTER || node->type()->name() == basic_type::TYPE_STRING) {
    _pf.STINT();
  } else if(node->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.STDOUBLE();
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN2!" << std::endl;
    exit(1);
  }
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_evaluation_node(gr8::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  if (node->argument()->type()->name() == basic_type::TYPE_INT || node->argument()->type()->name() == basic_type::TYPE_STRING || node->argument()->type()->name() == basic_type::TYPE_POINTER) {
    _pf.TRASH(4); // delete the evaluated value
  } else if (node->argument()->type()->name() == basic_type::TYPE_DOUBLE){
    _pf.TRASH(8);
  } else if (node->argument()->type()->name() == basic_type::TYPE_VOID){
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN3!" << std::endl;
    exit(1);
  }
}

void gr8::postfix_writer::do_print_node(gr8::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value to print
  if (node->argument()->type()->name() == basic_type::TYPE_INT) {
    _functions_to_import.insert("printi");
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  } else if(node->argument()->type()->name() == basic_type::TYPE_DOUBLE){
    _functions_to_import.insert("printd");
    _pf.CALL("printd");
    _pf.TRASH(4);
  } else if (node->argument()->type()->name() == basic_type::TYPE_STRING) {
    _functions_to_import.insert("prints");
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN4!" << std::endl;
    exit(1);
  }
  if(node->newline()){
    _functions_to_import.insert("println");
    _pf.CALL("println"); // print a newline
  }
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_read_node(gr8::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if(node->type()->name() == basic_type::TYPE_INT){
    _functions_to_import.insert("readi");
    _pf.CALL("readi");
    _pf.LDFVAL32();
    _pf.STINT();
  }
  else if(node->type()->name() == basic_type::TYPE_DOUBLE){
    _functions_to_import.insert("readd");
    _pf.CALL("readd");
    _pf.LDFVAL64();
    _pf.STDOUBLE();
  }

}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_if_node(gr8::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}

//---------------------------------------------------------------------------

void gr8::postfix_writer::do_if_else_node(gr8::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  node->elseblock()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1 = lbl2));
}

//---------------------------------------------------------------------------


void gr8::postfix_writer::do_address_node(gr8::address_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  node->leftvalue()->accept(this, lvl);
}

void gr8::postfix_writer::do_stop_node(gr8::stop_node * const node, int lvl){
  int i = node->integerLiteral();
  int label, aux;
  int size = _label4stop.size() - 1;
  for (aux = 0; i > 0 ; i--, aux++){
    label = _label4stop.at(size - aux);
  }
  _pf.JMP(mklbl(label));
}

void gr8::postfix_writer::do_again_node(gr8::again_node * const node, int lvl){
  int i = node->integerLiteral();
  int size = _label4again.size() - 1;
  int label, aux = 0;
  for (aux = 0 ; i > 0 ; i--, aux++){
    label = _label4again.at(size - aux);
  }
  _pf.JMP(mklbl(label));
}

void gr8::postfix_writer::do_sweep_node(gr8::sweep_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  node->initialization()->accept(this, lvl);
  node->leftvalue()->accept(this, lvl);

  if(node->leftvalue()->type()->name() == basic_type::TYPE_INT || node->leftvalue()->type()->name() == basic_type::TYPE_POINTER) {
    _pf.STINT();
  } else if(node->leftvalue()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.STDOUBLE();
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN5!" << std::endl;
    exit(1);
  }

  int lblcond, lblsweepup, lblend, lblincr;
  lblincr = ++_lbl;
  lblend = ++_lbl;
  _label4again.push_back(lblincr);
  _label4stop.push_back(lblend);

  _pf.LABEL(mklbl(lblcond = ++_lbl));
  node->increment()->accept(this, lvl);

  _pf.INT(0);
  _pf.LT();
  _pf.JZ(mklbl(lblsweepup = ++_lbl));

  node->leftvalue()->accept(this, lvl);
  if(node->leftvalue()->type()->name() == basic_type::TYPE_INT || node->leftvalue()->type()->name() == basic_type::TYPE_POINTER) {
    _pf.LDINT();
  } else if(node->leftvalue()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.LDDOUBLE();
  }
  node->condition()->accept(this, lvl);
  _pf.GE();
  _pf.JZ(mklbl(lblend));

  node->block()->accept(this, lvl);
  _pf.JMP(mklbl(lblincr));

  _pf.LABEL(mklbl(lblsweepup));
  node->leftvalue()->accept(this, lvl);
  if(node->leftvalue()->type()->name() == basic_type::TYPE_INT || node->leftvalue()->type()->name() == basic_type::TYPE_POINTER) {
    _pf.LDINT();
  } else if(node->leftvalue()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.LDDOUBLE();
  }
  node->condition()->accept(this, lvl);
  _pf.LE();
  _pf.JZ(mklbl(lblend));
  node->block()->accept(this, lvl);

  _pf.LABEL(mklbl(lblincr));
  node->increment()->accept(this, lvl);
  node->leftvalue()->accept(this, lvl);
  if(node->leftvalue()->type()->name() == basic_type::TYPE_INT || node->leftvalue()->type()->name() == basic_type::TYPE_POINTER) {
    _pf.LDINT();
  } else if(node->leftvalue()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.LDDOUBLE();
  }
  _pf.ADD();
  node->leftvalue()->accept(this, lvl);

  if(node->leftvalue()->type()->name() == basic_type::TYPE_INT || node->leftvalue()->type()->name() == basic_type::TYPE_POINTER) {
    _pf.STINT();
  } else if(node->leftvalue()->type()->name() == basic_type::TYPE_DOUBLE) {
    _pf.STDOUBLE();
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN6!" << std::endl;
    exit(1);
  }

  _pf.JMP(mklbl(lblcond));

  _pf.LABEL(mklbl(lblend));

  _label4again.pop_back();
  _label4stop.pop_back();
}

void gr8::postfix_writer::do_function_call_node(gr8::function_call_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(node->name());
  if (symbol == nullptr){
    throw std::string("function undeclared");
  }
  std::vector<basic_type*> args = symbol->getArgs();

  for (int i = node->parameters()->size() - 1; i >=  0; i--) {
    node->parameters()->node(i)->accept(this, lvl);
    cdk::expression_node* actual_node = (cdk::expression_node*) node->parameters()->node(i);
    if (convert_to_double(args.at(i),actual_node->type())){
      _pf.I2D();
    }
  }
  _pf.CALL(node->name());
  /*for (int i = node->parameters()->size() - 1; i >=  0; i--){
    cdk::expression_node* actual_node = (cdk::expression_node*) node->parameters()->node(i);
     _pf.TRASH(actual_node->type()->size());
  }*/
  for (size_t i = 0; i < args.size(); i++){
    _pf.TRASH(args.at(i)->size());
  }
  if (node->type()->name() == basic_type::TYPE_DOUBLE){
    _pf.LDFVAL64();
  }else if(node->type()->name() == basic_type::TYPE_INT || node->type()->name() == basic_type::TYPE_STRING || node->type()->name() == basic_type::TYPE_POINTER) {
    _pf.LDFVAL32();
  }

}

void gr8::postfix_writer::do_function_declaration_node(gr8::function_declaration_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  _functions_to_import.insert(node->name());
}

void gr8::postfix_writer::do_function_node(gr8::function_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;

  _returnType = node->type();

  const std::string &id = node->identifier();
  std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);
  if (symbol == nullptr) {
    throw std::string("function undeclared");
  }
  std::set<std::string>::iterator it;
  it = _functions_to_import.find(node->identifier());
  if (it != _functions_to_import.end()){
    _functions_to_import.erase(it);
  }

  _pf.TEXT();
  _pf.ALIGN();
  if(node->identifier() == "covfefe"){
    if(node->ispublic()){
       _pf.GLOBAL("_main", _pf.FUNC());
    }
      _pf.LABEL("_main");
  } else {
    if(node->ispublic()){
       _pf.GLOBAL(node->identifier(), _pf.FUNC());
    }
      _pf.LABEL(node->identifier());
  }

  gr8::function_checker checker(_compiler, _symtab);
  node->accept(&checker, lvl);

  node->parameters()->accept(this, lvl);

  symbol = _symtab.find(id);
  _pf.ENTER(symbol->entersize());

  if (node->identifier() == "covfefe"){
    for(size_t i = 0; i < _bss_nodes.size(); i++){
      variable_declaration_node* actual_node = _bss_nodes.at(i);
      if(!((actual_node->value()->type()->subtype() == nullptr) && (actual_node->value()->type()->name() == basic_type::TYPE_POINTER))){
        actual_node->value()->accept(this, lvl);
        if(convert_to_double(actual_node->type(), actual_node->value()->type()))
          _pf.I2D();
        if(!(new_symbol()->infunction()))
          _pf.ADDR(actual_node->name());
        else {
          _pf.LOCAL(new_symbol()->offset());
        }
        if (actual_node->type()->name() == basic_type::TYPE_DOUBLE){
          _pf.STDOUBLE();
        }else if(actual_node->value()->type()->name() == basic_type::TYPE_INT || actual_node->value()->type()->name() == basic_type::TYPE_STRING || actual_node->value()->type()->name() == basic_type::TYPE_POINTER){
          _pf.STINT();
        }
      }
    }
  }

  node->block()->accept(this, lvl);

  node->accept(&checker, lvl);

  if(node->type()->name() == basic_type::TYPE_VOID){
    _pf.LEAVE();
    _pf.RET();
  }

}

void gr8::postfix_writer::do_identity_node(gr8::identity_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value

}

void gr8::postfix_writer::do_index_node(gr8::index_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  node->identifier()->accept(this, lvl);
  node->index()->accept(this, lvl);
  if (node->type()->name() == basic_type::TYPE_DOUBLE){
    _pf.INT(8);
  } else if(node->type()->name() == basic_type::TYPE_INT || node->type()->name() == basic_type::TYPE_STRING) {
    _pf.INT(4);
  }
  _pf.MUL();
  _pf.ADD();
}

void gr8::postfix_writer::do_memory_reservation_node(gr8::memory_reservation_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);

  _pf.INT(node->type()->subtype()->size());
  _pf.MUL();
  _pf.ALLOC();
  _pf.SP();

}

void gr8::postfix_writer::do_null_node(gr8::null_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  _pf.INT(0);
}

void gr8::postfix_writer::do_return_node(gr8::return_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  node->value()->accept(this, lvl);

  if(convert_to_double(_returnType,node->value()->type())){
    _pf.I2D();
  }

  if (_returnType->name() == basic_type::TYPE_DOUBLE){
    _pf.STFVAL64();
  }else if(_returnType->name() == basic_type::TYPE_INT || _returnType->name() == basic_type::TYPE_STRING || _returnType->name() == basic_type::TYPE_POINTER){
    _pf.STFVAL32();
  }

  _pf.LEAVE();
  _pf.RET();

}

void gr8::postfix_writer::do_variable_declaration_node(gr8::variable_declaration_node * const node, int lvl){
    ASSERT_SAFE_EXPRESSIONS;
    if (!(new_symbol()->infunction()) && !(in_vector(node))){
      _pf.BSS();
      _pf.ALIGN();
      if(new_symbol()->ispublic()){
        _pf.GLOBAL(node->name(), _pf.OBJ());
      }
      _pf.LABEL(node->name());
      _pf.SALLOC(node->type()->size());
      if(!((node->value()->type()->subtype() == nullptr) && (node->value()->type()->name() == basic_type::TYPE_POINTER)))
        _bss_nodes.push_back(node);
    }

    if(!((node->value()->type()->subtype() == nullptr) && (node->value()->type()->name() == basic_type::TYPE_POINTER))){
      node->value()->accept(this, lvl);
      if(convert_to_double(node->type(), node->value()->type()))
        _pf.I2D();
      if(!(new_symbol()->infunction()))
        _pf.ADDR(node->name());
      else {
        _pf.LOCAL(new_symbol()->offset());
      }
      if (node->type()->name() == basic_type::TYPE_DOUBLE){
        _pf.STDOUBLE();
      }else if(node->value()->type()->name() == basic_type::TYPE_INT || node->value()->type()->name() == basic_type::TYPE_STRING || node->value()->type()->name() == basic_type::TYPE_POINTER){
        _pf.STINT();
      }
    }
}

void gr8::postfix_writer::do_block_node(gr8::block_node * const node, int lvl){
  node->declarations()->accept(this,lvl);
  node->instructions()->accept(this,lvl);
}
