/* -----------------------------------------------------------------------------
 * Rule_m1.cpp
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

#include "Rule_m1.hpp"
#include "Visitor.hpp"
#include "ParserAlternative.hpp"
#include "ParserContext.hpp"

#include "Rule_DIGIT.hpp"
#include "Terminal_StringValue.hpp"

using namespace abnf;

Rule_m1::Rule_m1(
  const string& spelling, 
  const vector<Rule*>& rules) : Rule(spelling, rules)
{
}

Rule_m1::Rule_m1(const Rule_m1& rule) : Rule(rule)
{
}

Rule_m1& Rule_m1::operator=(const Rule_m1& rule)
{
  Rule::operator=(rule);
  return *this;
}

Rule* Rule_m1::clone() const
{
  return new Rule_m1(this->spelling, this->rules);
}

void* Rule_m1::accept(Visitor& visitor)
{
  return visitor.visit(this);
}

Rule_m1* Rule_m1::parse(ParserContext& context)
{
  context.push("m1");

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
      unsigned int g1 = context.index;
      vector<const ParserAlternative*> as2;
      parsed = false;
      {
        int s2 = context.index;
        ParserAlternative a2(s2);
        parsed = true;
        if (parsed)
        {
          bool f2 = true;
          int c2 = 0;
          Rule* rule = Terminal_StringValue::parse(context, "22");
          if ((f2 = rule != NULL))
          {
            a2.add(rule, context.index);
            c2++;
          }
          parsed = c2 == 1;
        }
        if (parsed)
        {
          bool f2 = true;
          int c2 = 0;
          unsigned int g2 = context.index;
          vector<const ParserAlternative*> as3;
          parsed = false;
          {
            int s3 = context.index;
            ParserAlternative a3(s3);
            parsed = true;
            if (parsed)
            {
              bool f3 = true;
              int c3 = 0;
              Rule* rule = Terminal_StringValue::parse(context, "4");
              if ((f3 = rule != NULL))
              {
                a3.add(rule, context.index);
                c3++;
              }
              parsed = c3 == 1;
            }
            if (parsed)
            {
              as3.push_back(new ParserAlternative(a3));
            }
            context.index = s3;
          }
          {
            int s3 = context.index;
            ParserAlternative a3(s3);
            parsed = true;
            if (parsed)
            {
              bool f3 = true;
              int c3 = 0;
              Rule* rule = Terminal_StringValue::parse(context, "5");
              if ((f3 = rule != NULL))
              {
                a3.add(rule, context.index);
                c3++;
              }
              parsed = c3 == 1;
            }
            if (parsed)
            {
              as3.push_back(new ParserAlternative(a3));
            }
            context.index = s3;
          }
          {
            int s3 = context.index;
            ParserAlternative a3(s3);
            parsed = true;
            if (parsed)
            {
              bool f3 = true;
              int c3 = 0;
              Rule* rule = Terminal_StringValue::parse(context, "6");
              if ((f3 = rule != NULL))
              {
                a3.add(rule, context.index);
                c3++;
              }
              parsed = c3 == 1;
            }
            if (parsed)
            {
              as3.push_back(new ParserAlternative(a3));
            }
            context.index = s3;
          }
          {
            int s3 = context.index;
            ParserAlternative a3(s3);
            parsed = true;
            if (parsed)
            {
              bool f3 = true;
              int c3 = 0;
              Rule* rule = Terminal_StringValue::parse(context, "7");
              if ((f3 = rule != NULL))
              {
                a3.add(rule, context.index);
                c3++;
              }
              parsed = c3 == 1;
            }
            if (parsed)
            {
              as3.push_back(new ParserAlternative(a3));
            }
            context.index = s3;
          }
          {
            int s3 = context.index;
            ParserAlternative a3(s3);
            parsed = true;
            if (parsed)
            {
              bool f3 = true;
              int c3 = 0;
              Rule* rule = Terminal_StringValue::parse(context, "8");
              if ((f3 = rule != NULL))
              {
                a3.add(rule, context.index);
                c3++;
              }
              parsed = c3 == 1;
            }
            if (parsed)
            {
              as3.push_back(new ParserAlternative(a3));
            }
            context.index = s3;
          }
          {
            int s3 = context.index;
            ParserAlternative a3(s3);
            parsed = true;
            if (parsed)
            {
              bool f3 = true;
              int c3 = 0;
              Rule* rule = Terminal_StringValue::parse(context, "9");
              if ((f3 = rule != NULL))
              {
                a3.add(rule, context.index);
                c3++;
              }
              parsed = c3 == 1;
            }
            if (parsed)
            {
              as3.push_back(new ParserAlternative(a3));
            }
            context.index = s3;
          }

          const ParserAlternative* b = ParserAlternative::getBest(as3);

          if ((parsed = b != NULL))
          {
            a2.add(b->rules, b->end);
            context.index = b->end;
          }

          for (vector<const ParserAlternative*>::const_iterator a = as3.begin(); a != as3.end(); a++)
          {
            delete *a;
          }

          f2 = context.index > g2;
          if (parsed) c2++;
          parsed = c2 == 1;
        }
        if (parsed)
        {
          as2.push_back(new ParserAlternative(a2));
        }
        context.index = s2;
      }

      const ParserAlternative* b = ParserAlternative::getBest(as2);

      if ((parsed = b != NULL))
      {
        a1.add(b->rules, b->end);
        context.index = b->end;
      }

      for (vector<const ParserAlternative*>::const_iterator a = as2.begin(); a != as2.end(); a++)
      {
        delete *a;
      }

      f1 = context.index > g1;
      if (parsed) c1++;
      parsed = c1 == 1;
    }
    if (parsed)
    {
      as1.push_back(new ParserAlternative(a1));
    }
    context.index = s1;
  }
  {
    int s1 = context.index;
    ParserAlternative a1(s1);
    parsed = true;
    if (parsed)
    {
      bool f1 = true;
      int c1 = 0;
      unsigned int g1 = context.index;
      vector<const ParserAlternative*> as2;
      parsed = false;
      {
        int s2 = context.index;
        ParserAlternative a2(s2);
        parsed = true;
        if (parsed)
        {
          bool f2 = true;
          int c2 = 0;
          Rule* rule = Terminal_StringValue::parse(context, "23");
          if ((f2 = rule != NULL))
          {
            a2.add(rule, context.index);
            c2++;
          }
          parsed = c2 == 1;
        }
        if (parsed)
        {
          bool f2 = true;
          int c2 = 0;
          Rule* rule = Rule_DIGIT::parse(context);
          if ((f2 = rule != NULL))
          {
            a2.add(rule, context.index);
            c2++;
          }
          parsed = c2 == 1;
        }
        if (parsed)
        {
          as2.push_back(new ParserAlternative(a2));
        }
        context.index = s2;
      }

      const ParserAlternative* b = ParserAlternative::getBest(as2);

      if ((parsed = b != NULL))
      {
        a1.add(b->rules, b->end);
        context.index = b->end;
      }

      for (vector<const ParserAlternative*>::const_iterator a = as2.begin(); a != as2.end(); a++)
      {
        delete *a;
      }

      f1 = context.index > g1;
      if (parsed) c1++;
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
    rule = new Rule_m1(context.text.substr(a0.start, a0.end - a0.start), a0.rules);
  }
  else
  {
    context.index = s0;
  }

  context.pop("m1", parsed);

  return (Rule_m1*)rule;
}

/* -----------------------------------------------------------------------------
 * eof
 * -----------------------------------------------------------------------------
 */
