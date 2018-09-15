#include <string>
#include "targets/xml_writer.h"
#include "targets/type_checker.h"
#include "ast/all.h"  // automatically generated

//---------------------------------------------------------------------------

void gr8::xml_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  //EMPTY
}
void gr8::xml_writer::do_data_node(cdk::data_node * const node, int lvl) {
  //EMPTY
}
void gr8::xml_writer::do_double_node(cdk::double_node * const node, int lvl) {
  process_literal(node, lvl);
}
void gr8::xml_writer::do_not_node(cdk::not_node * const node, int lvl) {
  do_unary_expression(node, lvl);
}
void gr8::xml_writer::do_and_node(cdk::and_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_or_node(cdk::or_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  os() << std::string(lvl, ' ') << "<sequence_node size='" << node->size() << "'>" << std::endl;
  for (size_t i = 0; i < node->size(); i++)
    node->node(i)->accept(this, lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
  process_literal(node, lvl);
}

void gr8::xml_writer::do_string_node(cdk::string_node * const node, int lvl) {
  process_literal(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_unary_expression(cdk::unary_expression_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  do_unary_expression(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_binary_expression(cdk::binary_expression_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->left()->accept(this, lvl + 2);
  node->right()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_add_node(cdk::add_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_div_node(cdk::div_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_le_node(cdk::le_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}
void gr8::xml_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  do_binary_expression(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_identifier_node(cdk::identifier_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  os() << std::string(lvl, ' ') << "<" << node->label() << ">" << node->name() << "</" << node->label() << ">" << std::endl;
}

void gr8::xml_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->lvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  //ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);

  node->lvalue()->accept(this, lvl);

  node->rvalue()->accept(this, lvl + 4);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_evaluation_node(gr8::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  node->argument()->accept(this, lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_print_node(gr8::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("argument", lvl + 2);
  node->argument()->accept(this, lvl + 4);
  closeTag("argument", lvl + 2);
  openTag("newline", lvl + 2);
  os() << std::string(lvl, ' ') << node->newline();
  closeTag("newline", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_read_node(gr8::read_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------

void gr8::xml_writer::do_if_node(gr8::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_if_else_node(gr8::if_else_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("then", lvl + 2);
  node->thenblock()->accept(this, lvl + 4);
  closeTag("then", lvl + 2);
  openTag("else", lvl + 2);
  node->elseblock()->accept(this, lvl + 4);
  closeTag("else", lvl + 2);
  closeTag(node, lvl);
}

//---------------------------------------------------------------------------
void gr8::xml_writer::do_address_node(gr8::address_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("leftvalue", lvl + 2);
  node->leftvalue()->accept(this, lvl + 4);
  closeTag("leftvalue", lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_stop_node(gr8::stop_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("integerliteral", lvl + 2);
  os() << std::string(lvl, ' ') << node->integerLiteral();
  closeTag("integerliteral", lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_again_node(gr8::again_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("integerliteral", lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->integerLiteral();
  closeTag("integerliteral", lvl + 2);
  closeTag(node, lvl);

}

void gr8::xml_writer::do_sweep_node(gr8::sweep_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("leftvalue", lvl + 2);
  node->leftvalue()->accept(this, lvl + 4);
  closeTag("leftvalue", lvl + 2);
  openTag("condition", lvl + 2);
  node->condition()->accept(this, lvl + 4);
  closeTag("condition", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  openTag("initialization", lvl + 2);
  node->initialization()->accept(this, lvl + 4);
  closeTag("initialization", lvl + 2);
  openTag("increment", lvl + 2);
  node->increment()->accept(this, lvl + 4);
  closeTag("increment", lvl + 2);
  closeTag(node, lvl);

}

void gr8::xml_writer::do_function_call_node(gr8::function_call_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("name", lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->name();
  closeTag("name", lvl + 2);
  openTag("parameters", lvl + 2);
  node->parameters()->accept(this, lvl + 4);
  closeTag("parameters", lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_function_declaration_node(gr8::function_declaration_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("ispublic", lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->ispublic();
  closeTag("ispublic", lvl + 2);
  openTag("name", lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->name();
  closeTag("name", lvl + 2);
  openTag("parameters", lvl + 2);
  node->parameters()->accept(this, lvl + 4);
  closeTag("parameters", lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_function_node(gr8::function_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("ispublic", lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->ispublic();
  closeTag("ispublic", lvl + 2);
  openTag("identifier", lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->identifier();
  closeTag("identifier", lvl + 2);
  openTag("parameters", lvl + 2);
  node->parameters()->accept(this, lvl + 4);
  closeTag("parameters", lvl + 2);
  openTag("block", lvl + 2);
  node->block()->accept(this, lvl + 4);
  closeTag("block", lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_identity_node(gr8::identity_node * const node, int lvl){
 do_unary_expression(node, lvl);
}

void gr8::xml_writer::do_index_node(gr8::index_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("index", lvl + 2);
  node->index()->accept(this, lvl + 4);
  closeTag("index", lvl + 2);
  openTag("identifier", lvl + 2);
  node->identifier()->accept(this, lvl + 4);
  closeTag("identifier", lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_memory_reservation_node(gr8::memory_reservation_node * const node, int lvl){
  do_unary_expression(node, lvl);
}

void gr8::xml_writer::do_null_node(gr8::null_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  closeTag(node, lvl);

}

void gr8::xml_writer::do_return_node(gr8::return_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("value", lvl + 2);
  node->value()->accept(this, lvl + 4);
  closeTag("value", lvl + 2);
  closeTag(node, lvl);

}

void gr8::xml_writer::do_variable_declaration_node(gr8::variable_declaration_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("ispublic", lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->ispublic();
  closeTag("ispublic", lvl + 2);
  openTag("name", lvl + 2);
  os() << std::string(lvl + 4, ' ') << node->name();
  closeTag("name", lvl + 2);
  openTag("value", lvl + 2);
  node->value()->accept(this, lvl + 4);
  closeTag("value", lvl + 2);
  closeTag(node, lvl);
}

void gr8::xml_writer::do_block_node(gr8::block_node * const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  openTag(node, lvl);
  openTag("declarations", lvl + 2);
  node->declarations()->accept(this, lvl + 4);
  closeTag("declarations", lvl + 2);
  openTag("instructions", lvl + 2);
  node->instructions()->accept(this, lvl + 4);
  closeTag("instructions", lvl + 2);
  closeTag(node, lvl);
}
