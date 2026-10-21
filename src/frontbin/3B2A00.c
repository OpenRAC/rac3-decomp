#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003B2C68(void *);
extern void func_003B2BF8();
extern s32 func_003B2C50();
extern s32 func_003B2A00();
extern s32 func_003B2A30();
extern s32 func_003B2A58();
extern s32 func_003B2A80();
extern s32 func_003B2AC8();
extern void func_003B2C58();
extern s32 func_003B2CF0();
extern void func_003B2C80();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003B2A00 */
extern void func_003AFD88(void);
extern void func_003B19A0(u8 *);
extern u8 *D_001DA0B4[];
s32 func_003B2A00(void) {
    func_003AFD88();
    func_003B19A0(D_001DA0B4[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003B2A00 */

/* localdecomp:start func_003B2A30 */
extern void func_003B1B88(void *);
extern u8 *D_001DA0B4[];

s32 func_003B2A30(void) {
    func_003B1B88(D_001DA0B4[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003B2A30 */

/* localdecomp:start func_003B2A58 */
extern void func_003B1C98(void *);
extern u8 *D_001DA0B4[];

s32 func_003B2A58(void) {
    func_003B1C98(D_001DA0B4[0] + 0x48);
    return 1;
}
/* localdecomp:end func_003B2A58 */

/* localdecomp:start func_003B2A80 */
typedef struct { unsigned long a, b, c; } Q_3AD4D8;
extern u8 *D_001DA0B4[];
extern void func_003B22E0(u8 *, Q_3AD4D8 *);
s32 func_003B2A80(s32 unused, u8 *out) {
    Q_3AD4D8 t;
    func_003B22E0(D_001DA0B4[0] + 0x48, &t);
    *(unsigned long *)(out + 8) = t.a;
    *(unsigned long *)(out + 0x10) = t.b;
    return 1;
}
/* localdecomp:end func_003B2A80 */

/* localdecomp:start func_003B2AC8 */
extern void func_11A0B0();
s32 func_003B2AC8(u8 *a, s32 sz, u8 *b, s32 off, u8 *src1, s32 len1, u8 *src2, s32 len2) {
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
/* localdecomp:end func_003B2AC8 */

typedef struct {
    s32 stream;
    u8 *entries;
    s32 write_index;
    s32 count;
    s32 capacity;
} Queue_003AD650;
/* localdecomp:start func_003B2BF8 */
void func_003B2BF8(volatile Queue_003AD650 *queue, s32 stream, u8 *entries, s32 capacity) {
    s32 index = 0;
    queue->count = 0;
    queue->stream = stream;
    do { queue->entries = entries; queue->capacity = capacity; } while (0);
    queue->write_index = 0;
    if (capacity > 0) {
        do {
            *(s32 *)(index * 0x27E40 + (s32)queue->entries) = 0;
            *(s32 *)(index * 0x27E40 + (s32)queue->entries + 4) = index;
            index++;
        } while (index < capacity);
    }
}
/* localdecomp:end func_003B2BF8 */

/* localdecomp:start func_003B2C50 */
s32 func_003B2C50(void) {
}
/* localdecomp:end func_003B2C50 */

/* localdecomp:start func_003B2C58 */
void func_003B2C58(void *p) {
    *(volatile s32 *)((u8 *)p + 0xC) = 0;
    *(volatile s32 *)((u8 *)p + 0x8) = 0;
}
/* localdecomp:end func_003B2C58 */

/* localdecomp:start func_003B2C68 */
s32 func_003B2C68(void *a0) {
    return *(s32 *)((u8 *)a0 + 0xc) == *(s32 *)((u8 *)a0 + 0x10);
}
/* localdecomp:end func_003B2C68 */

/* localdecomp:start func_003B2C80 */
typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD6D8;
void func_124920(void);
void func_124970(void);
void func_003B2C80(S_3AD6D8 *p) {
    func_124920();
    *(s32 *)(p->x8 * 0x27E40 + p->x4) = 2;
    p->xC++;
    p->x8 = (p->x8 + 1) % p->x10;
    func_124970();
}
/* localdecomp:end func_003B2C80 */

/* localdecomp:start func_003B2CF0 */
s32 func_003B2CF0(s32 *p) {
    if (func_003B2C68(p)) return 0;
    return p[0] + p[2] * 0xD0000;
}
/* localdecomp:end func_003B2CF0 */

/* localdecomp:start func_003B2D30 */
s32 func_003B2D30(void *p) {
    return *(s32 *)((u8 *)p + 0xC) == 0;
}
/* localdecomp:end func_003B2D30 */

/* localdecomp:start func_003B2D40 */
typedef struct { s32 x0; s32 x4; volatile s32 x8; volatile s32 xC; s32 x10; } S_3AD798;
s32 func_003B2D40(S_3AD798 *p) {
 if (func_003B2D30(p)) return 0; return p->x4 + ((p->x8 - p->xC + p->x10) % p->x10) * 0x27E40;
}
/* localdecomp:end func_003B2D40 */

/* localdecomp:start func_003B2DA0 */
void func_003B2DA0(volatile s32 *p) {
    if (p[3] > 0) {
        p[3]--;
    }
}
/* localdecomp:end func_003B2DA0 */

LINKER_REMNANT("asm/remnants", func_003B2DC0);

/* localdecomp:start func_003B2DC8 */
extern s32 D_001DA0E8;
extern s32 D_001DA0FC;
extern s32 *func_003E5918(s32 *);
s32 *func_003B2DC8(s32 idx) {
    s32 i;
    s32 *p;
    if (D_001DA0FC == 0) {
        p = &D_001DA0E8;
        i = 4;
        do {
            func_003E5918(p);
            i--;
            __asm__ volatile("nop");
            p++;
        } while (i != -1);
        D_001DA0FC = 1;
    }
    return &D_001DA0E8 + idx;
}
/* localdecomp:end func_003B2DC8 */

LINKER_REMNANT("asm/remnants", func_003B2E48);

INCLUDE_ASM("asm/nonmatchings/text", func_003B2E50);
