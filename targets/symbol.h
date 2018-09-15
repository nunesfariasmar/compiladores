#ifndef __GR8_SEMANTICS_SYMBOL_H__
#define __GR8_SEMANTICS_SYMBOL_H__

#include <string>
#include <vector>
#include <cdk/basic_type.h>

namespace gr8 {

  class symbol {
    basic_type *_type;
    std::string _name;
    long _value; // hack!
    bool _ispublic;
    std::vector<basic_type*> _args;
    int _entersize = 0;
    bool _infunction = false;
    int _offset = 0;
    
  public:
    symbol(basic_type *type, const std::string &name, long value) :
        _type(type), _name(name), _value(value) {
    }

    virtual ~symbol() {
      delete _type;
    }

    basic_type *type() const {
      return _type;
    }
    const std::string &name() const {
      return _name;
    }
    long value() const {
      return _value;
    }
    long value(long v) {
      return _value = v;
    }
    void set_is_public(bool ispublic){
      _ispublic = ispublic;
    }
    bool ispublic(){
      return _ispublic;
    }
    void setArgs(std::vector<basic_type*> args){
      _args = args;
    }
    std::vector<basic_type*> getArgs(){
      return _args;
    }
    int entersize(){
      return _entersize;
    }
    void set_entersize(int size){
      _entersize = size;
    }
    void set_function(bool function){
      _infunction = function;
    }
    bool infunction(){
      return _infunction;
    }
    int offset(){
      return _offset;
    }
    void set_offset(int size){
      _offset = size;
    }
  };

} // gr8

#endif
