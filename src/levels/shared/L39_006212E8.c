#include "common.h"

/* localdecomp:start func_L39_006212E8 */
s32 func_L39_006212E8(void *arg0) {
    if ((*(s32 *)((u8 *)arg0 + 0x474)) == 2) {
        return (*(s32 *)((u8 *)arg0 + 0x478));
    }
    return -1;
}
/* localdecomp:end func_L39_006212E8 */

/* localdecomp:start func_L39_00621308 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xA0];
    u128_t q0A0;
    u8 padB0[0x2348 - 0xB0];
    s32 head;
    s32 count;
} S_00621308;

void func_L39_00621308(S_00621308 *s) {
    *(u128_t *)((s->head << 4) + (s32)s + 0x1DC0) = s->q0A0;
    s->head = (s->head + 1) % 32;
    s->count++;
    if (s->count > 32) {
        s->count = 32;
    }
}
/* localdecomp:end func_L39_00621308 */

/* localdecomp:start func_L39_00621370 */
typedef int u128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0xA0];
    u128 xA0;
    u8 padB0[0x1DC0 - 0xB0];
    u128 x1DC0;
    u8 pad1DD0[0x2348 - 0x1DD0];
    s32 x2348;
    s32 x234C;
} func_0061EBD0_t;

void func_L39_00621370(func_0061EBD0_t *a) {
    a->x2348 = 1;
    a->x1DC0 = a->xA0;
    a->x234C = 1;
}
/* localdecomp:end func_L39_00621370 */
