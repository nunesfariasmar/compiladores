// **** AUTOMATICALLY GENERATED BY mk-visitor-decls.pl -- DO NOT EDIT ****
#include <cdk/ast/visitor_decls.h>

#ifdef __IN_VISITOR_HEADER__

#ifdef __PURE_VIRTUAL_DECLARATIONS_ONLY__

  virtual void do_variable_declaration_node(gr8::variable_declaration_node *const node, int lvl) = 0;
  virtual void do_memory_reservation_node(gr8::memory_reservation_node *const node, int lvl) = 0;
  virtual void do_function_call_node(gr8::function_call_node *const node, int lvl) = 0;
  virtual void do_index_node(gr8::index_node *const node, int lvl) = 0;
  virtual void do_if_else_node(gr8::if_else_node *const node, int lvl) = 0;
  virtual void do_null_node(gr8::null_node *const node, int lvl) = 0;
  virtual void do_function_node(gr8::function_node *const node, int lvl) = 0;
  virtual void do_identity_node(gr8::identity_node *const node, int lvl) = 0;
  virtual void do_again_node(gr8::again_node *const node, int lvl) = 0;
  virtual void do_print_node(gr8::print_node *const node, int lvl) = 0;
  virtual void do_function_declaration_node(gr8::function_declaration_node *const node, int lvl) = 0;
  virtual void do_if_node(gr8::if_node *const node, int lvl) = 0;
  virtual void do_sweep_node(gr8::sweep_node *const node, int lvl) = 0;
  virtual void do_return_node(gr8::return_node *const node, int lvl) = 0;
  virtual void do_stop_node(gr8::stop_node *const node, int lvl) = 0;
  virtual void do_address_node(gr8::address_node *const node, int lvl) = 0;
  virtual void do_read_node(gr8::read_node *const node, int lvl) = 0;
  virtual void do_evaluation_node(gr8::evaluation_node *const node, int lvl) = 0;
  virtual void do_block_node(gr8::block_node *const node, int lvl) = 0;


#else

  void do_variable_declaration_node(gr8::variable_declaration_node *const node, int lvl);
  void do_memory_reservation_node(gr8::memory_reservation_node *const node, int lvl);
  void do_function_call_node(gr8::function_call_node *const node, int lvl);
  void do_index_node(gr8::index_node *const node, int lvl);
  void do_if_else_node(gr8::if_else_node *const node, int lvl);
  void do_null_node(gr8::null_node *const node, int lvl);
  void do_function_node(gr8::function_node *const node, int lvl);
  void do_identity_node(gr8::identity_node *const node, int lvl);
  void do_again_node(gr8::again_node *const node, int lvl);
  void do_print_node(gr8::print_node *const node, int lvl);
  void do_function_declaration_node(gr8::function_declaration_node *const node, int lvl);
  void do_if_node(gr8::if_node *const node, int lvl);
  void do_sweep_node(gr8::sweep_node *const node, int lvl);
  void do_return_node(gr8::return_node *const node, int lvl);
  void do_stop_node(gr8::stop_node *const node, int lvl);
  void do_address_node(gr8::address_node *const node, int lvl);
  void do_read_node(gr8::read_node *const node, int lvl);
  void do_evaluation_node(gr8::evaluation_node *const node, int lvl);
  void do_block_node(gr8::block_node *const node, int lvl);


#endif /* !defined(__PURE_VIRTUAL_DECLARATIONS_ONLY__) */

#endif /* __IN_VISITOR_HEADER__ */