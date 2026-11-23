/* PAL near miss: 27 words differ with @ee29 -O2 -G0.
 * Uses approved CpuGp() at retail's direct sw $gp site and the owner's u64
 * timer prototypes. The argument store precedes relinking, as retail does.
 * Remaining: time/argument saved-register swap and a flags reload missing
 * after the GP store (one word short, shifting the suffix).
 * Typed, void-pointer and u32-pointer GP stores produced identical bytes.
 * Interrupt-written volatile flags were investigated from func_00125578,
 * but changed the other loads/delay slots (40 differences); bitfields gave 44.
 * An argument store after relinking gave 24 but does not preserve retail's
 * order and is not retained. No register pin or local EE asm.
 * Not linked; no full-build match is claimed.
 */
#include "common.h"
#include "cpu.h"

/* localdecomp:start func_00125A70 */
typedef struct {
    u8 pad0[8];
    u32 id;
    u32 flags;
    u64 start;
    u64 elapsed;
    u64 time;
    s32 handler;
    void *gp;
    s32 arg;
} Alarm_125A70;
extern void func_00125540(void *);
extern void *func_001254B8();

s32 func_00125A70(s32 id, u64 time, s32 handler, s32 arg) {
    Alarm_125A70 *t;
    Tm_125940 *st;

    t = (Alarm_125A70 *)(((u32)id >> 10) << 6);
    if (id < 0 || (id & 0x3FF) != t->id) {
        return 0x80008002;
    }
    st = (Tm_125940 *)&D_0013F288;
    if (st->active == id) {
        return 0x80000010;
    }
    if (t->flags & 2) {
        func_00125540(t);
    }
    t->handler = handler;
    if (handler == 0) {
        t->flags &= ~2;
    } else {
        t->time = time;
        t->flags |= 2;
        t->gp = CpuGp();
        t->arg = arg;
        if (t->flags & 1) {
            func_001254B8(t);
        }
    }
    func_00125328(func_00125820());
    return 0;
}
/* localdecomp:end func_00125A70 */
