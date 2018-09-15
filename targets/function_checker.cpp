#include "targets/function_checker.h"
#include "ast/all.h"

int _totalsize = 0;
int _functionOffset = 8;
int _varsOffset = 0;

void gr8::function_checker::do_nil_node(cdk::nil_node * const node, int lvl){ }
void gr8::function_checker::do_data_node(cdk::data_node * const node, int lvl){ }
void gr8::function_checker::do_double_node(cdk::double_node * const node, int lvl){ }
void gr8::function_checker::do_not_node(cdk::not_node * const node, int lvl){ }
void gr8::function_checker::do_and_node(cdk::and_node * const node, int lvl){ }
void gr8::function_checker::do_or_node(cdk::or_node * const node, int lvl){ }
void gr8::function_checker::do_sequence_node(cdk::sequence_node * const node, int lvl){
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}
void gr8::function_checker::do_integer_node(cdk::integer_node * const node, int lvl){ }
void gr8::function_checker::do_string_node(cdk::string_node * const node, int lvl){ }
void gr8::function_checker::do_neg_node(cdk::neg_node * const node, int lvl){ }
void gr8::function_checker::do_add_node(cdk::add_node * const node, int lvl){ }
void gr8::function_checker::do_sub_node(cdk::sub_node * const node, int lvl){ }
void gr8::function_checker::do_mul_node(cdk::mul_node * const node, int lvl){ }
void gr8::function_checker::do_div_node(cdk::div_node * const node, int lvl){ }
void gr8::function_checker::do_mod_node(cdk::mod_node * const node, int lvl){ }
void gr8::function_checker::do_lt_node(cdk::lt_node * const node, int lvl){ }
void gr8::function_checker::do_le_node(cdk::le_node * const node, int lvl){ }
void gr8::function_checker::do_ge_node(cdk::ge_node * const node, int lvl){ }
void gr8::function_checker::do_gt_node(cdk::gt_node * const node, int lvl){ }
void gr8::function_checker::do_ne_node(cdk::ne_node * const node, int lvl){ }
void gr8::function_checker::do_eq_node(cdk::eq_node * const node, int lvl){ }
void gr8::function_checker::do_identifier_node(cdk::identifier_node * const node, int lvl){ }
void gr8::function_checker::do_rvalue_node(cdk::rvalue_node * const node, int lvl){ }
void gr8::function_checker::do_assignment_node(cdk::assignment_node * const node, int lvl){ }
void gr8::function_checker::do_evaluation_node(gr8::evaluation_node * const node, int lvl){ }
void gr8::function_checker::do_print_node(gr8::print_node * const node, int lvl){ }
void gr8::function_checker::do_read_node(gr8::read_node * const node, int lvl){ }
void gr8::function_checker::do_if_node(gr8::if_node * const node, int lvl){
	node->block()->accept(this, lvl);
}
void gr8::function_checker::do_if_else_node(gr8::if_else_node * const node, int lvl){
	node->thenblock()->accept(this, lvl);
	node->elseblock()->accept(this, lvl);
}
void gr8::function_checker::do_address_node(gr8::address_node * const node, int lvl){ }
void gr8::function_checker::do_stop_node(gr8::stop_node * const node, int lvl){ }
void gr8::function_checker::do_again_node(gr8::again_node * const node, int lvl){ }
void gr8::function_checker::do_sweep_node(gr8::sweep_node * const node, int lvl){
	node->block()->accept(this, lvl);
}
void gr8::function_checker::do_function_call_node(gr8::function_call_node * const node, int lvl){ }
void gr8::function_checker::do_function_declaration_node(gr8::function_declaration_node * const node, int lvl){ }
void gr8::function_checker::do_function_node(gr8::function_node * const node, int lvl){
	const std::string &id = node->identifier();
	std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);
	if (symbol == nullptr) {
		throw std::string("function undeclared");
	}
	else{
		node->block()->accept(this, lvl);
		symbol->set_entersize(_totalsize);

		for (size_t i = 0; i < node->parameters()->size(); i++){
			gr8::variable_declaration_node* actual_node = (gr8::variable_declaration_node*) node->parameters()->node(i);
			const std::string &identifier = actual_node->name();
  			std::shared_ptr<gr8::symbol> symbolid = _symtab.find(identifier);
  			if (symbolid == nullptr) {
				      symbolid = std::make_shared<gr8::symbol>(actual_node->type(), actual_node->name(), 0);
              _symtab.insert(actual_node->name(), symbolid);
			  }
        if(symbolid->infunction()){
          symbolid->set_function(false);
        } else {
          symbolid->set_function(true);
        }
			symbolid->set_offset(_functionOffset);
			_functionOffset += actual_node->type()->size();
		}
		_totalsize = 0;
		_functionOffset = 8;
		_varsOffset = 0;
	}
}
void gr8::function_checker::do_identity_node(gr8::identity_node * const node, int lvl){ }
void gr8::function_checker::do_index_node(gr8::index_node * const node, int lvl){ }
void gr8::function_checker::do_memory_reservation_node(gr8::memory_reservation_node * const node, int lvl){ }
void gr8::function_checker::do_null_node(gr8::null_node * const node, int lvl){ }
void gr8::function_checker::do_return_node(gr8::return_node * const node, int lvl){ }
void gr8::function_checker::do_variable_declaration_node(gr8::variable_declaration_node * const node, int lvl){
	_totalsize += node->type()->size();
	const std::string &id = node->name();
	std::shared_ptr<gr8::symbol> symbol = _symtab.find(id);

  if (symbol == nullptr) {
    symbol = std::make_shared<gr8::symbol>(node->type(), node->name(), 0);
    symbol->set_is_public(node->ispublic());
    _symtab.insert(node->name(), symbol);
  }
  if(symbol->infunction()){
    symbol->set_function(false);
  } else {
    symbol->set_function(true);
  }
	_varsOffset -= node->type()->size();
	symbol->set_offset(_varsOffset);
}
void gr8::function_checker::do_block_node(gr8::block_node * const node, int lvl){
	node->declarations()->accept(this, lvl);
	node->instructions()->accept(this, lvl);
}
