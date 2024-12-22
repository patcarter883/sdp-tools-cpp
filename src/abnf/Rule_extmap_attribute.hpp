/* -----------------------------------------------------------------------------
 * Rule_extmap_attribute.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.5
 * Produced : Mon Jan 08 13:30:55 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_extmap_attribute_hpp
#define Rule_extmap_attribute_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_extmap_attribute : public Rule
{
public:
  Rule_extmap_attribute(const std::string& spelling, const std::vector<Rule*>& rules);
  Rule_extmap_attribute(const Rule_extmap_attribute& rule);

  Rule_extmap_attribute& operator=(const Rule_extmap_attribute& rule);

  virtual Rule* clone(void) const;

  static Rule_extmap_attribute* parse(ParserContext& context);

  virtual void* accept(Visitor& visitor);
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
