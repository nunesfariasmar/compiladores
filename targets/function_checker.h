#ifndef __GR8_SEMANTICS_FUNCTION_CHECKER_H__
#define __GR8_SEMANTICS_FUNCTION_CHECKER_H__

#include <string>
#include <iostream>
#include <cdk/symbol_table.h>
#include <cdk/ast/basic_node.h>
#include <cdk/emitters/basic_postfix_emitter.h>
#include "targets/basic_ast_visitor.h"
#include "targets/symbol.h"

namespace gr8 {

	class function_checker : public basic_ast_visitor {
		cdk::symbol_table<gr8::symbol> &_symtab;

	public:
		function_checker(std::shared_ptr<cdk::compiler> comp, cdk::symbol_table<gr8::symbol> &symtab) :
			basic_ast_visitor(comp), _symtab(symtab) {}

	public:

		~function_checker() {
			os().flush();
		}

	public: 
		virtual void do_nil_node(cdk::nil_node * const node, int lvl); 
		virtual void do_data_node(cdk::data_node * const node, int lvl); 
		virtual void do_double_node(cdk::double_node * const node, int lvl); 
		virtual void do_not_node(cdk::not_node * const node, int lvl); 
		virtual void do_and_node(cdk::and_node * const node, int lvl); 
		virtual void do_or_node(cdk::or_node * const node, int lvl); 
		virtual void do_sequence_node(cdk::sequence_node * const node, int lvl);
		virtual void do_integer_node(cdk::integer_node * const node, int lvl);
		virtual void do_string_node(cdk::string_node * const node, int lvl);
		virtual void do_neg_node(cdk::neg_node * const node, int lvl);
		virtual void do_add_node(cdk::add_node * const node, int lvl); 
		virtual void do_sub_node(cdk::sub_node * const node, int lvl);
		virtual void do_mul_node(cdk::mul_node * const node, int lvl); 
		virtual void do_div_node(cdk::div_node * const node, int lvl); 
		virtual void do_mod_node(cdk::mod_node * const node, int lvl); 
		virtual void do_lt_node(cdk::lt_node * const node, int lvl);
		virtual void do_le_node(cdk::le_node * const node, int lvl); 
		virtual void do_ge_node(cdk::ge_node * const node, int lvl); 
		virtual void do_gt_node(cdk::gt_node * const node, int lvl);
		virtual void do_ne_node(cdk::ne_node * const node, int lvl);
		virtual void do_eq_node(cdk::eq_node * const node, int lvl);
		virtual void do_identifier_node(cdk::identifier_node * const node, int lvl); 
		virtual void do_rvalue_node(cdk::rvalue_node * const node, int lvl);
		virtual void do_assignment_node(cdk::assignment_node * const node, int lvl);
		virtual void do_evaluation_node(gr8::evaluation_node * const node, int lvl);
		virtual void do_print_node(gr8::print_node * const node, int lvl);
		virtual void do_read_node(gr8::read_node * const node, int lvl);
		virtual void do_if_node(gr8::if_node * const node, int lvl);
		virtual void do_if_else_node(gr8::if_else_node * const node, int lvl);
		virtual void do_address_node(gr8::address_node * const node, int lvl);
		virtual void do_stop_node(gr8::stop_node * const node, int lvl);
		virtual void do_again_node(gr8::again_node * const node, int lvl);
		virtual void do_sweep_node(gr8::sweep_node * const node, int lvl);
		virtual void do_function_call_node(gr8::function_call_node * const node, int lvl);
		virtual void do_function_declaration_node(gr8::function_declaration_node * const node, int lvl);
		virtual void do_function_node(gr8::function_node * const node, int lvl);
		virtual void do_identity_node(gr8::identity_node * const node, int lvl);
		virtual void do_index_node(gr8::index_node * const node, int lvl);
		virtual void do_memory_reservation_node(gr8::memory_reservation_node * const node, int lvl);
		virtual void do_null_node(gr8::null_node * const node, int lvl);
		virtual void do_return_node(gr8::return_node * const node, int lvl);
		virtual void do_variable_declaration_node(gr8::variable_declaration_node * const node, int lvl);
		virtual void do_block_node(gr8::block_node * const node, int lvl);
	};
}

#endif