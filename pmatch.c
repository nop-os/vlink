/* $VER: vlink pmatch.c V0.9f (04.08.04)
 *
 * This file is part of vlink, a portable linker for multiple
 * object formats.
 * Copyright (c) 1997-2005  Frank Wille
 */


#define PMATCH_C
#include "vlink.h"

static bool portable_pattern_match(const char *mask, const char *name)
{
  int           wild  = 0,
                q     = 0;
  const char  * m     = mask,
              * n     = name,
              * ma    = mask,
              * na    = name;

  for(;;) {
    if (*m == '*') {
      while (*m == '*')
        ++m;
      wild = 1;
      ma = m;
      na = n;
    }
    if (!*m) {
      if (!*n)
        return(FALSE);
      for (--m; (m > mask) && (*m == '?'); --m);
      if ((*m == '*') && (m > mask) && (m[-1] != '\\'))
        return(FALSE);
      if (!wild)
        return(TRUE);
      m = ma;
    }
    else if (!*n) {
      while(*m == '*')
        ++m;
      return(*m != 0);
    }
    if ((*m == '\\') && ((m[1] == '*') || (m[1] == '?'))) {
      ++m;
      q = 1;
    }
    else {
      q = 0;
    }
    if ((tolower(*m) != tolower(*n)) && ((*m != '?') || q)) {
      if (!wild)
        return(TRUE);
      m = ma;
      n = ++na;
    }
    else {
      if (*m) ++m;
      if (*n) ++n;
    }
  }
}


bool pattern_match(const char *mask, const char *name)
{
  bool result = !portable_pattern_match(mask,name);
  return result;
}

bool patternlist_match(char **patlist,const char *str)
/* match string against a list of patterns */
{
  if (patlist) {
    while (*patlist) {
      if (pattern_match(*patlist,str))
        return (TRUE);
      patlist++;
    }
  }
  return (FALSE);
}
