/* -----------------------------------------------------------------------------
 * Rule_ssrc_id.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.5
 * Produced : Mon Jan 08 13:30:55 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_ssrc_id_hpp
#define Rule_ssrc_id_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_ssrc_id : public Rule
{
public:
  Rule_ssrc_id(const std::string& spelling, const std::vector<Rule*>& rules);
  Rule_ssrc_id(const Rule_ssrc_id& rule);

  Rule_ssrc_id& operator=(const Rule_ssrc_id& rule);

  virtual Rule* clone(void) const;

  static Rule_ssrc_id* parse(ParserContext& context);

  virtual void* accept(Visitor& visitor);
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
