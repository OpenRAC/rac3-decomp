#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AFC48.c's earlier functions */
extern s32 D_001DA088_003AFC48;
extern s32 D_001DA0B4_003AFC48;
extern s32 D_001DA0B8_003AFC48;
extern s32 D_001D4D40;
extern s32 func_003AFE10();

typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } P_3AA4B0;
extern P_3AA4B0 *D_001D52FC_003AFE10;
extern s32 D_001D4D40;
extern volatile s32 D_1DA0CC;
extern s32 D_001DA088_003AFC48;
extern s32 D_001DA0B4_003AFC48;
extern s32 D_001DA0B8_003AFC48;
extern void func_003A3F70(void);
extern void func_003B04E8();
extern void func_003B29D8(void *);
extern s32 func_003B16E0(u8 *, void **);
extern s32 func_003B17F8();
extern void func_003B1710(u8 *, s32);
extern s32 func_003B1750(u8 *, u8 **);
extern s32 func_00139A70(void *, u8 *, s32, u8 *, s32);
extern s32 func_003B1790();
extern void func_003B0400(void);
extern s32 func_003B3020(void *);
extern s32 func_003B0160_003AFE10(void);
extern void func_003B1348(s32);
extern s32 func_003B29E8(void *);
extern s32 func_003B2A68();
extern s32 func_003B2B38(void *);
extern void func_003B1398(void);
extern void func_003B0588(s32 *);
/* localdecomp:start func_003AFE10 */
/* from rac3-uya-decomp's func_003AFC70 (the NTSC-U twin) */
extern void func_003B0140(void);
s32 func_003AFE10(void *a, u8 *b, s32 *c) {
    void *rd;
    u8 *wr;
    s32 started;
    s32 done;
    s32 left;
    s32 sent;
    s32 armed;
    s32 go;
    s32 flags;
    s32 n;
    s32 k;
    s32 m;

    done = 0;
    armed = 0;
    go = 0;
    left = *c;
    started = 0;
    sent = left;
    D_1DA0CC = 0;
    while (left >= 5 && func_003B29E8(a) != 3) {
        func_003A3F70();
        flags = 0;
        if (D_001D52FC_003AFE10->f1A0 == 0 && done && go) armed = 1;
        if (armed && !(D_001D4D40 & 0x80)) {
            s32 st = D_001D4D40 & ~0xC0;
            if (st != 2) {
                if (st == 0 && D_001D52FC_003AFE10->f1A0 != 0 && D_001D52FC_003AFE10->f1A4 == 0) flags = 1;
                else if (D_001D52FC_003AFE10->f1A4 & 0x800) flags = 1;
            }
        }
        if (!done && D_1DA0CC >= 10) {
            done = 1;
            func_003B04E8(D_001DA0B8_003AFC48);
        }
        if (flags && !started) {
            started = 1;
            func_003B29D8((void *)D_001DA0B4_003AFC48);
        }
        if (!done && D_1DA0CC >= 10) {
            done = 1;
            func_003B04E8(D_001DA0B8_003AFC48);
        }
        n = func_003B16E0(b, &rd);
        if (sent > 0 && n > 0xFFFF) {
            m = func_003B17F8(c, rd, 0x10000);
            sent -= m;
            func_003B1710(b, m);
        }
        func_003B0140();
        if (!done && D_1DA0CC >= 10) {
            done = 1;
            func_003B04E8(D_001DA0B8_003AFC48);
        }
        k = func_003B1750(b, &wr);
        if (k > 0) {
            m = func_00139A70(a, wr, k, b, *(s32 *)(b + 0x50008));
            left -= m;
            func_003B1790(b, m);
        }
        func_003B0400();
        if (!done && D_1DA0CC >= 10) {
            done = 1;
            func_003B04E8(D_001DA0B8_003AFC48);
        }
        if (!go && func_003B3020((void *)D_001DA088_003AFC48) && func_003B0160_003AFE10()) {
            func_003B1348(1);
            go = 1;
        }
    }
    while (func_003B2A68(a) == 0) {
        func_003B0400();
        func_003B0140();
    }
    while (func_003B2B38(a) == 0 && func_003B29E8(a) != 3) {
        func_003B0400();
        func_003B0140();
    }
    func_003B1398();
    func_003B0588((s32 *)D_001DA0B8_003AFC48);
    return started;
}
/* localdecomp:end func_003AFE10 */
