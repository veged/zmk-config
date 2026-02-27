#define KEYPRESSES(word) _KEYPRESSES(word, 0)
#define _KEYPRESSES(word, i) (i < sizeof(#word) - 1 ? (&kp W##word[i]) _KEYPRESSES(word, i + 1) : NULL)

#define SNIPPETS(...) _SNIPPETS(__VA_ARGS__)
#define _SNIPPETS(first, ...) \
    ZMK_MACRO(s_##first, wait-ms = <0>; tap-ms = <3>; bindings = KEYPRESSES(first)) \
    __VA_ARGS__ ? (_SNIPPETS(__VA_ARGS__)) : (void)0

SNIPPETS(break
case
catch
class
const
continue
default
delete
else
export
extends
finally
for
function
import
let
new
return
super
switch
this
throw
try
typeof
var
while
yield)

#undef _KEYPRESSES
#undef _SNIPPETS

