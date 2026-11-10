#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_006AB098);

INCLUDE_ASM("asm/levels", func_L39_006AB300);

/* localdecomp:start func_L39_006AB6D0 */
typedef struct S3_006AB6D0 S3_006AB6D0;
typedef struct S2_006AB6D0 {
    char _p0[0x24];
    void (*f24)(S3_006AB6D0 *arg0);
} S2_006AB6D0;
struct S3_006AB6D0 {
    char _p0[0x60];
    S2_006AB6D0 *f60;
};
typedef struct S1_006AB6D0 {
    char _p0[0x110];
    S3_006AB6D0 *f110;
} S1_006AB6D0;

/* from rac4-decomp's func_L00_0071AB38 */
void func_L39_006AB6D0(S1_006AB6D0 *arg0) {
    S3_006AB6D0 *o = arg0->f110;
    o->f60->f24(o);
}
/* localdecomp:end func_L39_006AB6D0 */

/* localdecomp:start func_L39_006AB6F8 */
void func_L39_006AB6F8(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0x3BC) = arg1;
}
/* localdecomp:end func_L39_006AB6F8 */

/* localdecomp:start func_L39_006AB700 */
extern void *func_120D28(void *, const char *, s32);
extern void func_L39_006AB8F8(void *);
typedef struct S_006AB700 { char pad[0x2C4]; char *f2C4; u8 name[0xC8]; s32 f390; } S_006AB700;
void func_L39_006AB700(S_006AB700 *self, char *a1) {
    u8 *p;
    self->f2C4 = a1;
    func_120D28(self->name, a1, 0xC8);
    func_L39_006AB8F8(self);
    self->f390 = 0;
    p = self->name;
    while (*p != 0) {
        p++;
        self->f390++;
    }
}
/* localdecomp:end func_L39_006AB700 */

/* localdecomp:start func_L39_006AB778 */
void func_L39_006AB778(void *arg0, s8 arg1) {
    *(s8 *)((u8 *)arg0 + 0x2AB) = arg1;
}
/* localdecomp:end func_L39_006AB778 */

/* localdecomp:start func_L39_006AB780 */
extern void func_L39_006AB098(void *);
void func_L39_006AB780(u8 *p, s32 a1, s32 a2) {
    if (p[0x2A9] != a1) {
        *(s32 *)(p + 0x2AC) = (*(s32 *)(p + 0x2AC) + 1) % *(s32 *)(p + 0x2B4);
        p[0x2A9] = a1;
    }
    p[0x2A8] = a2;
    if (a2) {
        *(s32 *)(p + 0x2B0) = 1;
    } else {
        *(s32 *)(p + 0x2B0) = *(s32 *)(p + 0x2AC);
    }
    func_L39_006AB098(p);
}
/* localdecomp:end func_L39_006AB780 */

/* localdecomp:start func_L39_006AB7E0 */
extern void func_L39_006AB098(void *);

void func_L39_006AB7E0(void *arg0, s32 arg1) {
    u8 *buf;
    s32 n;
    u8 c;
    unsigned long sel;

    buf = (u8 *)arg0 + 0x2C8;
    sel = 0;
    c = arg1;
    n = *(s32 *)((u8 *)arg0 + 0x390);
    if (n < *(s32 *)((u8 *)arg0 + 0x394)) {
        if (n > 0) {
            unsigned long b = buf[n - 1];
            sel = b >> 7;
        }
        if (c == 0x20 && (n == 0 || buf[n - 1] == 0x20) && sel == 0) {
            return;
        }
        buf[*(s32 *)((u8 *)arg0 + 0x390)] = c;
        buf[*(s32 *)((u8 *)arg0 + 0x390) + 1] = 0;
        *(s32 *)((u8 *)arg0 + 0x390) = *(s32 *)((u8 *)arg0 + 0x390) + 1;
        if (*(u8 *)((u8 *)arg0 + 0x2A9) != 0) {
            s32 f = *(s32 *)((u8 *)arg0 + 0x2AC);
            *(u8 *)((u8 *)arg0 + 0x2A9) = 0;
            if (f == 1) {
                *(s32 *)((u8 *)arg0 + 0x2AC) = 0;
            }
            *(s32 *)((u8 *)arg0 + 0x2B0) = (*(u8 *)((u8 *)arg0 + 0x2A8) != 0) ? 1 : *(s32 *)((u8 *)arg0 + 0x2AC);
        }
        func_L39_006AB098(arg0);
    }
}
/* localdecomp:end func_L39_006AB7E0 */

/* localdecomp:start func_L39_006AB8A8 */
typedef struct S S;
struct S { char _p0[0x2c8]; u8 buf[0xC8]; s32 idx; };

/* from rac4-decomp's func_L00_007418C0 */
void func_L39_006AB8A8(S *p) {
    if (p->idx != 0) {
        u8 *b;
        b = p->buf;
        b[p->idx - 1] = 0;
        p->idx = p->idx - 1;
        if (b[p->idx - 1] & 0x80) {
            b[p->idx - 1] = 0;
            p->idx = p->idx - 1;
        }
    }
}
/* localdecomp:end func_L39_006AB8A8 */

INCLUDE_ASM("asm/levels", func_L39_006AB8F8);
