#include "common.h"

/* localdecomp:start func_L39_0061E1B8 */
typedef struct S_0061E1B8 S_0061E1B8;
typedef struct V_0061E1B8 {
    u8 pad0[8];
    void (*f8)(S_0061E1B8 *);
    void (*fC)(S_0061E1B8 *);
} V_0061E1B8;
struct S_0061E1B8 {
    u32 uid;
    S_0061E1B8 *next;
    S_0061E1B8 *prev;
    V_0061E1B8 *vt;
};

extern S_0061E1B8 *D_L39_0024CEA0_0061E1B8[8] __attribute__((section(".sdata")));
extern S_0061E1B8 *D_L39_0024CEC0_0061E1B8[8] __attribute__((section(".sdata")));

S_0061E1B8 *func_L39_0061E1B8(S_0061E1B8 *src, s32 a1) {
    s32 type = (src->uid >> 24) & 0xF;
    S_0061E1B8 **free = &D_L39_0024CEC0_0061E1B8[type];
    S_0061E1B8 **used = &D_L39_0024CEA0_0061E1B8[type];
    S_0061E1B8 *p = *free;
    S_0061E1B8 *next;

    if (p != 0) {
        next = p->next;
        *free = next;
        next->prev = 0;
        p->prev = 0;
        p->next = *used;
        if (*used != 0) {
            (*used)->prev = p;
        }
        *used = p;
        p->uid = src->uid;
        p->vt->fC(p);
        if (a1 != 0) {
            p->vt->f8(p);
        }
        return p;
    }
    return 0;
}
/* localdecomp:end func_L39_0061E1B8 */

/* localdecomp:start func_L39_0061E278 */
typedef struct S_0061E278 S_0061E278;
struct S_0061E278 {
    u32 uid;
    S_0061E278 *next;
    S_0061E278 *prev;
};

extern S_0061E278 *D_L39_0024CEA0_0061E278[8] __attribute__((section(".sdata")));
extern S_0061E278 *D_L39_0024CEC0_0061E278[8] __attribute__((section(".sdata")));
extern S_0061E278 *func_L39_0061E118(u32);

S_0061E278 *func_L39_0061E278(u32 *a0) {
    u32 uid = *a0;
    s32 type = (uid >> 24) & 0xF;
    S_0061E278 *p = func_L39_0061E118(uid);
    S_0061E278 **free;
    S_0061E278 **used;
    S_0061E278 *next;

    if (p == 0) {
        return 0;
    }
    free = &D_L39_0024CEC0_0061E278[type];
    used = &D_L39_0024CEA0_0061E278[type];
    next = p->next;
    if (p->prev != 0) {
        p->prev->next = next;
    }
    if (p->next != 0) {
        p->next->prev = p->prev;
    }
    if (*used == p) {
        *used = p->next;
    }
    p->prev = 0;
    p->next = *free;
    p->uid = -1;
    if (*free != 0) {
        (*free)->prev = p;
    }
    *free = p;
    return next;
}
/* localdecomp:end func_L39_0061E278 */
