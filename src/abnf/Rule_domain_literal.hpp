/* -----------------------------------------------------------------------------
 * Rule_domain_literal.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.5
 * Produced : Mon Jan 08 13:30:55 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_domain_literal_hpp
#define Rule_domain_literal_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_domain_literal : public Rule
{
public:
  Rule_domain_literal(const std::string& spelling, const std::vector<Rule*>& rules);
  Rule_domain_literal(const Rule_domain_literal& rule);

  Rule_domain_literal& operator=(const Rule_domain_literal& rule);

  virtual Rule* clone(void) const;

  static Rule_domain_literal* parse(ParserContext& context);

  virtual void* accept(Visitor& visitor);
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
