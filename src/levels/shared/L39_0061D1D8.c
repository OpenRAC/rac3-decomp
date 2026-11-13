#include "common.h"

/* The guber pools (multiplayer network objects). Each of the 8 types has its used and free lists,
   its pool's base, entry count and entry size; the tables are small data in the multiplayer
   levels (inside their $gp window), which this file's code reaches with lui/addiu. */
struct S_61AEB0;

typedef struct {
    u8 pad[8];
    void (*init)(struct S_61AEB0 *);
    void (*fn)(struct S_61AEB0 *);
} V_61AEB0;

typedef struct S_61AEB0 {
    u32 uid;
    s32 owner;
    s32 state;
    struct S_61AEB0 *next;
    struct S_61AEB0 *prev;
    V_61AEB0 *vt;
} S_61AEB0;

extern S_61AEB0 *D_L39_0024CE40[8] __attribute__((section(".sdata")));
extern S_61AEB0 *D_L39_0024CE60[8] __attribute__((section(".sdata")));
extern u8 *D_L39_0024CE80[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245EE0[8] __attribute__((section(".sdata")));
extern s32 D_L39_00245F00[8] __attribute__((section(".sdata")));
extern s32 D_L39_0024D758[] __attribute__((section(".sdata")));
extern s32 D_L39_0024D75C[] __attribute__((section(".sdata")));

/* localdecomp:start func_L39_0061D1D8 */
extern void *func_L39_0061BFB0(u32 uid);
extern void *func_L39_006685D8(u32 uid);
extern void *func_L39_0066C1F0(u32 uid);

void *func_L39_0061D1D8(u32 uid) {
    s32 type;
    s32 index;
    S_61AEB0 *p;

    if (uid == -1) {
        return 0;
    }
    type = (uid >> 24) & 0xF;
    index = uid & 0xFFF;
    if (type == 0) {
        return func_L39_0061BFB0(uid);
    }
    if (type == 3) {
        return func_L39_006685D8(uid);
    }
    if (type == 2) {
        return func_L39_0066C1F0(uid);
    }
    p = (S_61AEB0 *)(D_L39_0024CE80[type] + index * D_L39_00245F00[type]);
    if (p->uid == uid && p->state != 2) {
        return p;
    }
    for (p = D_L39_0024CE40[type]; p != 0; p = p->next) {
        if (p->uid == uid && p->state != 2) {
            return p;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_0061D1D8 */

/* localdecomp:start func_L39_0061D2D8 */
extern u32 func_L39_0061D800(s32 type, s32 creator, s32 index);
extern void func_L39_0061E1B8(S_61AEB0 *p, s32 a1);

S_61AEB0 *func_L39_0061D2D8(s32 type, s32 creator, s32 owner) {
    S_61AEB0 **free;
    S_61AEB0 **used;
    S_61AEB0 *p;
    S_61AEB0 *next;

    if (creator == -1) {
        creator = D_L39_0024D75C[0];
    }
    free = &D_L39_0024CE60[type];
    used = &D_L39_0024CE40[type];
    p = *free;
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
        p->uid = func_L39_0061D800(type, creator, ((u8 *)p - D_L39_0024CE80[type]) / D_L39_00245F00[type]);
        p->state = 1;
        p->owner = owner;
        p->vt->init(p);
        if (D_L39_0024D75C[0] != -1 && owner == D_L39_0024D75C[0]) {
            func_L39_0061E1B8(p, 1);
        }
        return p;
    }
    return 0;
}
/* localdecomp:end func_L39_0061D2D8 */

/* localdecomp:start func_L39_0061D3F0 */
/* The UID the next guber of `type` would get (-1 when its pool is full). */
u32 func_L39_0061D3F0(s32 type, s32 creator) {
    S_61AEB0 *p;
    u32 r;

    p = D_L39_0024CE60[type];
    if (creator == -1) {
        creator = D_L39_0024D75C[0];
    }
    if (p == 0) {
        r = -1;
    } else {
        r = func_L39_0061D800(type, creator, ((u8 *)p - D_L39_0024CE80[type]) / D_L39_00245F00[type]);
    }
    return r;
}
/* localdecomp:end func_L39_0061D3F0 */

/* localdecomp:start func_L39_0061D470 */
S_61AEB0 *func_L39_0061D470(u32 uid, s32 owner) {
    s32 type = (uid >> 24) & 0xF;
    S_61AEB0 **free = &D_L39_0024CE60[type];
    S_61AEB0 **used = &D_L39_0024CE40[type];
    S_61AEB0 *p = *free;
    S_61AEB0 *next;

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
        p->state = 1;
        p->uid = uid;
        p->owner = owner;
        p->vt->init(p);
        if (D_L39_0024D75C[0] != -1 && owner == D_L39_0024D75C[0]) {
            func_L39_0061E1B8(p, 1);
        }
        return p;
    }
    return 0;
}
/* localdecomp:end func_L39_0061D470 */

/* localdecomp:start func_L39_0061D540 */
typedef struct {
    u32 index : 12;
    u32 gen : 12;
    u32 type : 4;
    u32 id : 4;
} Uid_61D540;

extern void func_L39_0061E278(S_61AEB0 *p);

S_61AEB0 *func_L39_0061D540(S_61AEB0 *p) {
    S_61AEB0 **free = &D_L39_0024CE60[((Uid_61D540 *)&p->uid)->type];
    S_61AEB0 **used = &D_L39_0024CE40[((Uid_61D540 *)&p->uid)->type];
    S_61AEB0 *next = p->next;
    s32 me = D_L39_0024D75C[0];

    p->state = 2;
    if (me != -1 && p->owner == me) {
        func_L39_0061E278(p);
    }
    if (p->prev != 0) {
        p->prev->next = p->next;
    }
    if (p->next != 0) {
        p->next->prev = p->prev;
    }
    if (*used == p) {
        *used = p->next;
    }
    p->prev = 0;
    p->next = *free;
    if (*free != 0) {
        (*free)->prev = p;
    }
    *free = p;
    return next;
}
/* localdecomp:end func_L39_0061D540 */

/* localdecomp:start func_L39_0061D628 */
void func_L39_0061D628(void) {
    s32 i;
    S_61AEB0 *p;
    S_61AEB0 *q;

    for (i = 0; i < 8; i++) {
        p = D_L39_0024CE40[i];
        while (p != 0) {
            q = p;
            p = p->next;
            q->vt->fn(q);
        }
    }
}
/* localdecomp:end func_L39_0061D628 */

/* localdecomp:start func_L39_0061D6A8 */
typedef struct {
    S_61AEB0 base;
    u8 pad18[0x14];
    u8 f2C;
} S_61D6A8;

void func_L39_0061D6A8(void) {
    s32 i;
    S_61AEB0 *p;
    s32 ok;

    if (D_L39_0024D758[0] == D_L39_0024D75C[0]) {
        for (i = 0; i < 8; i++) {
            p = D_L39_0024CE40[i];
            while (p != 0) {
                ok = p->owner == -1;
                if (ok) {
                    if (((p->uid & 0xF000000) >> 24) == 7 && ((S_61D6A8 *)p)->f2C) {
                        ok = 0;
                    }
                    if (ok) {
                        func_L39_0061E1B8(p, 1);
                    }
                }
                p = p->next;
            }
        }
    }
}
/* localdecomp:end func_L39_0061D6A8 */

/* localdecomp:start func_L39_0061D780 */
extern s32 func_L39_0061D7B0(void *a0);
u32 func_L39_0061D780(void) {
    s32 *p = ((s32 * (*)(void))func_L39_0061D7B0)();
    if (p) return *p;
    return 0xFFFFFFFF;
}
/* localdecomp:end func_L39_0061D780 */

/* localdecomp:start func_L39_0061D7B0 */
typedef s32 (*Fn_0061B038)(void *);
extern Fn_0061B038 *func_L39_005C1018(void);
s32 func_L39_0061D7B0(void *a0) {
    s32 r;
    if (a0) {
        r = func_L39_005C1018()[1](a0);
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_0061D7B0 */

/* localdecomp:start func_L39_0061D7F8 */
void func_L39_0061D7F8(s32 arg0, void *arg1) {
    *(s32 *)((u8 *)arg1 + 0x90) = arg0;
}
/* localdecomp:end func_L39_0061D7F8 */

/* localdecomp:start func_L39_0061D800 */
/* A guber UID: creator << 28 | type << 24 | generation << 12 | index. A free entry (state 0 or
   2) gets its next generation. */
u32 func_L39_0061D800(s32 type, s32 creator, s32 index) {
    S_61AEB0 *p;
    s32 gen;

    p = (S_61AEB0 *)(D_L39_0024CE80[type] + index * D_L39_00245F00[type]);
    gen = 0;
    if (p != 0 && (p->state == 2 || p->state == 0)) {
        gen = ((p->uid & 0xFFF000) >> 12) + 1;
        p->uid = (p->uid & 0xFF000FFF) | ((gen << 12) & 0xFFF000);
    }
    return (type << 24) | (creator << 28) | (index & 0xFFF) | ((gen << 12) & 0xFFF000);
}
/* localdecomp:end func_L39_0061D800 */

/* localdecomp:start func_L39_0061D8B8 */
s32 func_L39_0061D8B8(void *arg0) {
    return (*(s32 *)((u8 *)arg0 + 0x90));
}
/* localdecomp:end func_L39_0061D8B8 */

INCLUDE_ASM("asm/levels", func_L39_0061D8C0);

INCLUDE_ASM("asm/levels", func_L39_0061D9D8);

INCLUDE_ASM("asm/levels", func_L39_0061DAF0);

INCLUDE_ASM("asm/levels", func_L39_0061DC08);

INCLUDE_ASM("asm/levels", func_L39_0061DD20);

INCLUDE_ASM("asm/levels", func_L39_0061DE38);

INCLUDE_ASM("asm/levels", func_L39_0061DF50);
