#include "common.h"

typedef struct { char pad[0x64]; int e[4]; int count; } S;

/* localdecomp:start func_L10_004F8E78 */
int func_L10_004F8E78(char *obj, int value) {
    S *s = *(S **)(obj + 4);
    if (s->count >= 4)
        return 0;
    s->e[s->count] = value;
    (*(S **)(obj + 4))->count++;
    return 1;
}
/* localdecomp:end func_L10_004F8E78 */
