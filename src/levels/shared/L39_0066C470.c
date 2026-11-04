#include "common.h"

typedef struct Node_0066C470 {
    s32 f00;
    u8 pad[124];
} Node_0066C470;

/* localdecomp:start func_L39_0066C470 */
extern Node_0066C470 *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, void *, s32, void *, Node_0066C470 *);
extern s32 D_001A5DF8[];

void func_L39_0066C470(void *arg0) {
    Node_0066C470 *n;

    n = func_L39_0066C2B8();
    if (n != 0) {
        n->f00 = func_L39_0066C280(2, arg0, D_001A5DF8[0], arg0, n);
    }
}
/* localdecomp:end func_L39_0066C470 */
