/* -----------------------------------------------------------------------------
 * Rule_proto_version.cpp
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

#include "Rule_proto_version.hpp"
#include "Visitor.hpp"
#include "ParserAlternative.hpp"
#include "ParserContext.hpp"

#include "Rule_DIGIT.hpp"
#include "Rule_CRLF.hpp"
#include "Terminal_NumericValue.hpp"
#include "Terminal_StringValue.hpp"

using namespace abnf;

Rule_proto_version::Rule_proto_version(
  const string& spelling, 
  const vector<Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_proto_version::Rule_proto_version(const Rule_proto_version& rule) : Rule(rule)
{
}

Rule_proto_version& Rule_proto_version::operator=(const Rule_proto_version& rule)
{
  Rule::operator=(rule);
  return *this;
}

Rule* Rule_proto_version::clone() const
{
  return new Rule_proto_version(this->spelling, this->rules);
}

void* Rule_proto_version::accept(Visitor& visitor)
{
  return visitor.visit(this);
}

Rule_proto_version* Rule_proto_version::parse(ParserContext& context)
{
  context.push("proto-version");

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
      Rule* rule = Terminal_NumericValue::parse(context, "%x76", 0x76, 0x76);
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
      for (int i1 = 0; i1 < 1 && f1; i1++)
      {
        Rule* rule = Rule_DIGIT::parse(context);
        if ((f1 = rule != NULL))
        {
          a1.add(rule, context.index);
          c1++;
        }
      }
      while (f1)
      {
        Rule* rule = Rule_DIGIT::parse(context);
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
    rule = new Rule_proto_version(context.text.substr(a0.start, a0.end - a0.start), a0.rules);
  }
  else
  {
    context.index = s0;
  }

  context.pop("proto-version", parsed);

  return (Rule_proto_version*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
