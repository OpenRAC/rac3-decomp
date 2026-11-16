/* PAL near miss (Codex wave 6): near miss: 64 words differ with the file's flags.
 * Worker's note: 64 diff: build/codex/w326/func_L07_003A2108.04.log; extra s4 for loop-hoisted -1 and queue/event register allocation; three forms reach same wrong bytes
 */
#include "common.h"
/* localdecomp:start func_L07_003A2108 */
extern Q_L07_003A2380 *D_L07_001DE330;
extern u8 D_001CCFD0[];
__asm__(".extern D_001CCFD0, 16");
typedef struct State_003A2108 {
    u8 pad0[0x24]; s32 f24;
    u8 pad28[0x44]; s32 f6C;
    u8 pad70[6]; s16 f76;
    u8 pad78[0x1C]; s32 f94;
    s16 f98; u8 pad9A[4]; s16 f9E;
} State_003A2108;
typedef struct Queue_003A2108 {
    s32 table[116]; s32 args[8]; u8 events[8]; u8 flags[8];
    s16 timers[8]; s16 head, tail, count, unused; u8 last[4];
} Queue_003A2108;
void func_L07_003A2108(u8 *arg0) {
    extern void func_L01_004450F0(void *, s32, s32);
    extern s32 func_0038CB00(void *);
    extern s32 func_L07_003A2408(u8);
    extern void func_003A2B68(s32, s32);
    extern void func_003A1798(void);
    Queue_003A2108 *p = *(Queue_003A2108 **)(arg0 + 0x68);
    State_003A2108 *state;
    s32 i;
    u8 index;
    s32 group;
    u8 *event;
    if (arg0[0x20] == 0) {
        p->count = 0;
        p->tail = 0;
        p->head = 0;
        D_L07_001DE330 = (Q_L07_003A2380 *)arg0;
        func_L01_004450F0(arg0, 1, -1);
    }
    for (i = 0; i < p->count; i++) {
        func_0038CB00(&p->timers[(p->head + i) & 7]);
    }
    switch (arg0[0x20]) {
    case 1:
        state = (State_003A2108 *)D_001CCFD0;
        if (state->f6C != 0 ||
            state->f24 != -1 ||
            state->f94 != 0) return;
        (*(u16 *)(arg0 + 0x96))++;
        while (p->count > 0) {
            index = p->head;
            p->count--;
            p->head = (p->head + 1) & 7;
            if (p->timers[index] > 0) {
                event = p->events;
                event += index;
                group = func_L07_003A2408(*event);
                if (group != -1) {
                    u8 *last = p->last;
                    last += group;
                    if (*last == *event) continue;
                    *last = *event;
                }
                if ((u32)(p->events[index] - 98) < 17) {
                    func_003A2B68((p->table[*event] & 0x3FFF) + 3000, 0);
                } else if (p->flags[index]) {
                    func_003A2B68(p->table[*event] + 2000, p->args[index]);
                } else {
                    func_003A2B68((p->table[*event] & 0x3FFF) + 2000, 0);
                }
                func_L01_004450F0(arg0, 2, -1);
                return;
            }
        }
        break;
    case 2:
        state = (State_003A2108 *)D_001CCFD0;
        if (state->f76 == 0 &&
            state->f9E == 3 &&
            state->f98 < 7000) {
            func_003A1798();
            func_L01_004450F0(arg0, 1, -1);
        }
        break;
    }
}
/* localdecomp:end func_L07_003A2108 */
