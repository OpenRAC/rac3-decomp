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

INCLUDE_ASM("asm/levels", func_L40_0053F570);

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
