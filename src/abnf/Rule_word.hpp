/* -----------------------------------------------------------------------------
 * Rule_word.hpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.5
 * Produced : Mon Jan 08 13:30:55 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#ifndef Rule_word_hpp
#define Rule_word_hpp

#include <string>
#include <vector>

#include "Rule.hpp"

namespace abnf {

class Visitor;
class ParserContext;

class Rule_word : public Rule
{
public:
  Rule_word(const std::string& spelling, const std::vector<Rule*>& rules);
  Rule_word(const Rule_word& rule);

  Rule_word& operator=(const Rule_word& rule);

  virtual Rule* clone(void) const;

  static Rule_word* parse(ParserContext& context);

  virtual void* accept(Visitor& visitor);
};

}

#endif
/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
