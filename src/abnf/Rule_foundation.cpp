/* -----------------------------------------------------------------------------
 * Rule_foundation.cpp
 * -----------------------------------------------------------------------------
 *
 * Producer : com.parse2.aparse.Parser 2.5
 * Produced : Mon Jan 08 13:30:55 CET 2018
 *
 * -----------------------------------------------------------------------------
 */

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Rule_foundation.hpp"
#include "Visitor.hpp"
#include "ParserAlternative.hpp"
#include "ParserContext.hpp"

#include "Rule_ice_char.hpp"

using namespace abnf;

Rule_foundation::Rule_foundation(
  const string& spelling, 
  const vector<Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_foundation::Rule_foundation(const Rule_foundation& rule) : Rule(rule)
{
}

Rule_foundation& Rule_foundation::operator=(const Rule_foundation& rule)
{
  Rule::operator=(rule);
  return *this;
}

Rule* Rule_foundation::clone() const
{
  return new Rule_foundation(this->spelling, this->rules);
}

void* Rule_foundation::accept(Visitor& visitor)
{
  return visitor.visit(this);
}

Rule_foundation* Rule_foundation::parse(ParserContext& context)
{
  context.push("foundation");

  bool parsed = true;
  int s0 = context.index;
  ParserAlternative a0(s0);

  vector<const ParserAlternative*> as1;
  parsed = false;
  {
    int s1 = context.index;
    ParserAlternative a1(s1);
    parsed = true;
    if (parsed)
    {
      bool f1 = true;
      int c1 = 0;
      for (int i1 = 0; i1 < 1 && f1; i1++)
      {
        Rule* rule = Rule_ice_char::parse(context);
        if ((f1 = rule != NULL))
        {
          a1.add(rule, context.index);
          c1++;
        }
      }
      for (int i1 = 1; i1 < 32 && f1; i1++)
      {
        Rule* rule = Rule_ice_char::parse(context);
        if ((f1 = rule != NULL))
        {
          a1.add(rule, context.index);
          c1++;
        }
      }
      parsed = c1 >= 1;
    }
    if (parsed)
    {
      as1.push_back(new ParserAlternative(a1));
    }
    context.index = s1;
  }

  const ParserAlternative* b = ParserAlternative::getBest(as1);

  if ((parsed = b != NULL))
  {
    a0.add(b->rules, b->end);
    context.index = b->end;
  }

  for (vector<const ParserAlternative*>::const_iterator a = as1.begin(); a != as1.end(); a++)
  {
    delete *a;
  }

  Rule* rule = NULL;
  if (parsed)
  {
    rule = new Rule_foundation(context.text.substr(a0.start, a0.end - a0.start), a0.rules);
  }
  else
  {
    context.index = s0;
  }

  context.pop("foundation", parsed);

  return (Rule_foundation*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
