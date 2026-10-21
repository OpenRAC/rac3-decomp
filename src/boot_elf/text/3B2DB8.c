#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B3020(void *);
extern void func_003B2FB0();
extern s32 func_003B3008();
extern s32 func_003B2DB8();
extern s32 func_003B2DE8();
extern s32 func_003B2E10();
extern s32 func_003B2E38();
extern s32 func_003B2E80();
extern void func_003B3010();
extern s32 func_003B30A8();
extern void func_003B3038();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B2DB8 */
extern void func_003B0140(void);
extern void func_003B1D58(u8 *);
extern u8 *D_001DA0B4[];
s32 func_003B2DB8(void) {
    func_003B0140();
    func_003B1D58(D_001DA0B4[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003B2DB8 */

/* localdecomp:start func_003B2DE8 */
extern void func_003B1F40(void *);
extern u8 *D_001DA0B4[];

s32 func_003B2DE8(void) {
    func_003B1F40(D_001DA0B4[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003B2DE8 */

/* localdecomp:start func_003B2E10 */
extern void func_003B2050(void *);
extern u8 *D_001DA0B4[];

s32 func_003B2E10(void) {
    func_003B2050(D_001DA0B4[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003B2E10 */

/* localdecomp:start func_003B2E38 */
typedef struct { unsigned long a, b, c; } Q_3AD4D8;
extern u8 *D_001DA0B4[];
extern void func_003B2698(u8 *, Q_3AD4D8 *);
s32 func_003B2E38(s32 unused, u8 *out) {
    Q_3AD4D8 t;
    func_003B2698(D_001DA0B4[0] + 0x48, &t);
    *(unsigned long *)(out + 8) = t.a;
    *(unsigned long *)(out + 0x10) = t.b;
    return 1;
}
/* localdecomp:end func_003B2E38 */

/* localdecomp:start func_003B2E80 */
extern void func_11A0B0();
s32 func_003B2E80(u8 *a, s32 sz, u8 *b, s32 off, u8 *src1, s32 len1, u8 *src2, s32 len2) {
    s32 d;
    if (sz + off < len1 + len2) return 0;
    if (len1 >= sz) {
        d = sz - len1;
        func_11A0B0(a, src1, sz);
        func_11A0B0(b, src1 + sz, len1 - sz);
        func_11A0B0(b + len1 - sz, src2, len2);
    } else {
        d = sz - len1;
        if (len2 >= d) {
            func_11A0B0(a, src1, len1);
            func_11A0B0(a + len1, src2, d);
            func_11A0B0(b, src2 + sz - len1, len2 - d);
        } else {
            func_11A0B0(a, src1, len1);
            func_11A0B0(a + len1, src2, len2);
        }
    }
    return len1 + len2;
}
/* localdecomp:end func_003B2E80 */

typedef struct {
    s32 stream;
    u8 *entries;
    s32 write_index;
    s32 count;
    s32 capacity;
} Queue_003AD650;
INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B2FB0);

/* localdecomp:start func_003B3008 */
s32 func_003B3008(void) {
}
/* localdecomp:end func_003B3008 */

/* localdecomp:start func_003B3010 */
void func_003B3010(void *p) {
    *(volatile s32 *)((u8 *)p + 0xC) = 0;
    *(volatile s32 *)((u8 *)p + 0x8) = 0;
}
/* localdecomp:end func_003B3010 */

/* localdecomp:start func_003B3020 */
s32 func_003B3020(void *a0) {
    return *(s32 *)((u8 *)a0 + 0xc) == *(s32 *)((u8 *)a0 + 0x10);
}
/* localdecomp:end func_003B3020 */

/* localdecomp:start func_003B3038 */
typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD6D8;
void func_124920(void);
void func_124970(void);
void func_003B3038(S_3AD6D8 *p) {
    func_124920();
    *(s32 *)(p->x8 * 0x27E40 + p->x4) = 2;
    p->xC++;
    p->x8 = (p->x8 + 1) % p->x10;
    func_124970();
}
/* localdecomp:end func_003B3038 */

/* localdecomp:start func_003B30A8 */
s32 func_003B30A8(s32 *p) {
    if (func_003B3020(p)) return 0;
    return p[0] + p[2] * 0xD0000;
}
/* localdecomp:end func_003B30A8 */

/* localdecomp:start func_003B30E8 */
s32 func_003B30E8(void *p) {
    return *(s32 *)((u8 *)p + 0xC) == 0;
}
/* localdecomp:end func_003B30E8 */

/* localdecomp:start func_003B30F8 */
typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD798;
s32 func_003B30F8(S_3AD798 *p) {
 if (func_003B30E8(p)) return 0; return p->x4 + ((p->x8 - p->xC + p->x10) % p->x10) * 0x27E40;
}
/* localdecomp:end func_003B30F8 */

/* localdecomp:start func_003B3158 */
void func_003B3158(volatile s32 *p) {
    if (p[3] > 0) {
        p[3]--;
    }
}
/* localdecomp:end func_003B3158 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B3178);

/* localdecomp:start func_003B3180 */
extern s32 D_001DA0E8;
extern s32 D_001DA0FC;
extern s32 *func_003E5CD0(s32 *);
s32 *func_003B3180(s32 idx) {
    s32 i;
    s32 *p;
    if (D_001DA0FC == 0) {
        p = &D_001DA0E8;
        i = 4;
        do {
            func_003E5CD0(p);
            i--;
            __asm__ volatile("nop");
            p++;
        } while (i != -1);
        D_001DA0FC = 1;
    }
    return &D_001DA0E8 + idx;
}
/* localdecomp:end func_003B3180 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003B3200);

INCLUDE_ASM("asm/boot_elf/nonmatchings/text", func_003B3208);
