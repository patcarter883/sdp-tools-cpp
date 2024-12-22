/* -----------------------------------------------------------------------------
 * Rule_phone_field.cpp
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

#include "Rule_phone_field.hpp"
#include "Visitor.hpp"
#include "ParserAlternative.hpp"
#include "ParserContext.hpp"

#include "Rule_CRLF.hpp"
#include "Rule_phone_number.hpp"
#include "Terminal_NumericValue.hpp"
#include "Terminal_StringValue.hpp"

using namespace abnf;

Rule_phone_field::Rule_phone_field(
  const string& spelling, 
  const vector<Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_phone_field::Rule_phone_field(const Rule_phone_field& rule) : Rule(rule)
{
}

Rule_phone_field& Rule_phone_field::operator=(const Rule_phone_field& rule)
{
  Rule::operator=(rule);
  return *this;
}

Rule* Rule_phone_field::clone() const
{
  return new Rule_phone_field(this->spelling, this->rules);
}

void* Rule_phone_field::accept(Visitor& visitor)
{
  return visitor.visit(this);
}

Rule_phone_field* Rule_phone_field::parse(ParserContext& context)
{
  context.push("phone-field");

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
      Rule* rule = Terminal_NumericValue::parse(context, "%x70", 0x70, 0x70);
      if ((f1 = rule != NULL))
      {
        a1.add(rule, context.index);
        c1++;
      }
      parsed = c1 == 1;
    }
    if (parsed)
    {
      bool f1 = true;
      int c1 = 0;
      Rule* rule = Terminal_StringValue::parse(context, "=");
      if ((f1 = rule != NULL))
      {
        a1.add(rule, context.index);
        c1++;
      }
      parsed = c1 == 1;
    }
    if (parsed)
    {
      bool f1 = true;
      int c1 = 0;
      Rule* rule = Rule_phone_number::parse(context);
      if ((f1 = rule != NULL))
      {
        a1.add(rule, context.index);
        c1++;
      }
      parsed = c1 == 1;
    }
    if (parsed)
    {
      bool f1 = true;
      int c1 = 0;
      Rule* rule = Rule_CRLF::parse(context);
      if ((f1 = rule != NULL))
      {
        a1.add(rule, context.index);
        c1++;
      }
      parsed = c1 == 1;
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
    rule = new Rule_phone_field(context.text.substr(a0.start, a0.end - a0.start), a0.rules);
  }
  else
  {
    context.index = s0;
  }

  context.pop("phone-field", parsed);

  return (Rule_phone_field*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
