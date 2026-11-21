#include "common.h"

/* localdecomp:start func_L40_0053F508 */
typedef struct {
    s32 w0;
    u8 pad4[24];
    s32 w28;
    u8 pad32[17];
    u8 b49;
    u8 pad50[18];
} E_0053CC58;
extern E_0053CC58 D_L40_0033F2E0[];
extern void func_L39_0066C470(s32);
s32 func_L40_0053F508(s32 a0) {
    E_0053CC58 *e;
    s32 i;
    for (i = 0; i < 50; i++) {
        e = &D_L40_0033F2E0[i];
        if (e->b49 == 1 && e->w28 == a0) {
            e->b49 = 0;
            func_L39_0066C470(e->w0);
            return e->w0;
        }
    }
    return -1;
}
/* localdecomp:end func_L40_0053F508 */

/* localdecomp:start func_L40_0053F570 */
extern s32 func_L40_0053F508(s32 a0);
typedef struct {
    s32 value;
    u8 pad04[0x10];
    u8 *callback;
    s32 unk18;
    u8 *moby;
    s32 time;
    s32 unk24;
    s32 a;
    s32 b;
    u8 kind;
    u8 state;
    u8 pad32[6];
    s32 zero;
    s32 value2;
    s32 time2;
} Entry_0053F570;

typedef struct {
    s32 id;
    s32 x4;
    s32 x8;
    s32 xC;
} Param_0053F570;

extern s32 func_L40_0053F498(void);
extern s32 func_L39_0066C428(s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_L39_0067FAA8_0053F570(void);
/* the moby array base, read through $gp (an alias with the size hint) and with lui/lw */
extern u8 *D_L40_0024845C_0053F570;
__asm__(".extern D_L40_0024845C_0053F570, 4");
extern u8 *D_L40_0024845C;
__asm__(".extern D_L40_0024845C, 16");
extern u8 D_L40_00246250[] __attribute__((section(".sdata")));
/* the file's D_L40_0033F2E0 (declared E_0053CC58[] above) seen as an array of whole entries:
   gcc builds the address of a field of a real array element as (base + field) + index, which
   combine and the post-reload cse turn into retail's three base sums and register copies; a
   cast pointer gives one shared base instead */
extern Entry_0053F570 D_L40_0033F2E0_0053F570[];
extern Param_0053F570 D_L40_00340030[];
extern s32 D_001A5DF8[];

static __inline__ void init_0053F570(Entry_0053F570 *e) {
    e->callback = D_L40_00246250;
}

u8 *func_L40_0053F570(s32 type, s32 value, s32 value2, s32 kind, u8 *obj) {
    s32 i;
    s32 j;

    i = func_L40_0053F498();
    if (i < 0) {
        return 0;
    }
    j = func_L39_0066C428(type);
    if (j < 0) {
        return 0;
    }
    if ((s32)obj == -1) {
        obj = func_003C24B0(type, 0x400);
        if (obj == 0) {
            return 0;
        }
    } else {
        obj = (u8 *)((s32)obj << 8);
        func_L40_0053F508((s32)(D_L40_0024845C_0053F570 + (s32)obj));
        obj = obj + (s32)D_L40_0024845C;
        obj[0x20] = 0;
    }
    init_0053F570(&D_L40_0033F2E0_0053F570[i]);
    D_L40_0033F2E0_0053F570[i].kind = kind;
    D_L40_0033F2E0_0053F570[i].moby = obj;
    D_L40_0033F2E0_0053F570[i].state = 1;
    D_L40_0033F2E0_0053F570[i].time = D_001A5DF8[0];
    D_L40_0033F2E0_0053F570[i].value = value;
    D_L40_0033F2E0_0053F570[i].a = D_L40_00340030[j].x4;
    D_L40_0033F2E0_0053F570[i].b = D_L40_00340030[j].x8;
    D_L40_0033F2E0_0053F570[i].value2 = value2;
    D_L40_0033F2E0_0053F570[i].time2 = D_001A5DF8[0];
    D_L40_0033F2E0_0053F570[i].zero = 0;
    *(Entry_0053F570 **)(obj + 0x90) = &D_L40_0033F2E0_0053F570[i];
    func_L39_0067FAA8_0053F570();
    return obj;
}
/* localdecomp:end func_L40_0053F570 */

/* localdecomp:start func_L40_0053F6E0 */
extern u32 func_L40_0053F018(u8 *p);
extern void *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, s32, s32, s32, void *);
extern void *func_L39_0066C3C8(void *, void **);
extern s32 func_L40_0053DC18(s32 id);
/* the empty stub at caller+0x250 (level 40 0x53F490): the catalogue names it differently per level
   (func_L39_0067FAA8, 0067FAB0, 0067FA98, 0067FA90, 0067F9E8), so an alias (docs/build/levels.md) */
extern void func_L39_0067FAA8_0053F6E0(void);
extern s32 D_001A5DF8[];

void func_L40_0053F6E0(u8 *m) {
    u8 *e = *(u8 **)(m + 0x90);
    s32 id = *(s32 *)e;
    void *n;
    void *p;

    if (func_L40_0053F018(m) != 0) {
        n = func_L39_0066C2B8();
        if (n == 0) {
            return;
        }
        *(s32 *)n = func_L39_0066C280(2, id, D_001A5DF8[0], id, n);
    }
    if (e != 0) {
        p = *(void **)(e + 0x38);
        while (p != 0) {
            p = func_L39_0066C3C8(p, (void **)(e + 0x38));
        }
        e[0x31] = 0;
    }
    func_L40_0053DC18(id);
    func_L39_0067FAA8_0053F6E0();
}
/* localdecomp:end func_L40_0053F6E0 */
