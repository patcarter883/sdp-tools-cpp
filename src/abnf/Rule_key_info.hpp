/* -----------------------------------------------------------------------------
 * Rule_key_info.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.5
 * Produced : Mon Jan 08 13:30:55 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_key_info_hpp
#define Rule_key_info_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_key_info : public Rule
{
public:
  Rule_key_info(const std::string& spelling, const std::vector<Rule*>& rules);
  Rule_key_info(const Rule_key_info& rule);

  Rule_key_info& operator=(const Rule_key_info& rule);

  virtual Rule* clone(void) const;

  static Rule_key_info* parse(ParserContext& context);

  virtual void* accept(Visitor& visitor);
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
