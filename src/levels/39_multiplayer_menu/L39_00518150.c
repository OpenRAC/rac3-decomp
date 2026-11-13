#include "common.h"

/* localdecomp:start func_L39_00518150 */
typedef struct {
    u8 data[0x28];
} E_00518150;

typedef struct {
    u32 count;
    u32 cap;
    E_00518150 *items;
} S_00518150;

extern s32 func_L39_00518240(S_00518150 *, s32);
extern void func_0011D534(void *, s32, s32);

s32 func_L39_00518150(S_00518150 *p, s32 *out) {
    s32 r;
    if (p->count >= p->cap) {
        r = func_L39_00518240(p, (p->count + 2) * 2);
        if (r != 0) {
            return r;
        }
    }
    *out = p->count;
    func_0011D534(&p->items[p->count++], 0, 0x28);
    return 0;
}
/* localdecomp:end func_L39_00518150 */
