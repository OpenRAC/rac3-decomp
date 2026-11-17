#include "common.h"

/* localdecomp:start func_L39_004F1960 */
typedef struct S_004F1960 {
    s32 type;
    void *f4;
} S_004F1960;

extern s32 func_L39_004CC800(void *);
extern unsigned long func_L39_004F1800(void *);

unsigned long func_L39_004F1960(S_004F1960 *arg0) {
    if (arg0->type == 1) {
        return func_L39_004F1800((void *)func_L39_004CC800(arg0->f4));
    }
    return 0;
}
/* localdecomp:end func_L39_004F1960 */
