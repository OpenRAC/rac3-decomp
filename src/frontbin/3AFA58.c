#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3AF2A0.c's earlier functions */
extern s32 D_001DA088_003AF890;
extern s32 D_001DA0B4_003AF890;
extern s32 D_001DA0B8_003AF890;
extern s32 D_001D4D40;
extern s32 func_003AFA58();

typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } P_3AA4B0;
extern P_3AA4B0 *D_001D52FC_003AFA58;
extern s32 D_001D4D40;
extern volatile s32 D_001DA0CC;
extern s32 D_001DA088_003AF890;
extern s32 D_001DA0B4_003AF890;
extern s32 D_001DA0B8_003AF890;
extern void func_003A3B70(void);
extern void func_003B0130();
extern void func_003B2620(void *);
extern s32 func_003B1328(u8 *, void **);
extern s32 func_003B1440();
extern void func_003B1358(u8 *, s32);
extern s32 func_003B1398(u8 *, u8 **);
extern s32 func_139A70(void *, u8 *, s32, u8 *, s32);
extern s32 func_003B13D8();
extern void func_003B0048(void);
extern s32 func_003B2C68(void *);
extern s32 func_003AFDA8_003AFA58(void);
extern void func_003B0F90(s32);
extern s32 func_003B2630(void *);
extern s32 func_003B26B0();
extern s32 func_003B2780(void *);
extern void func_003B0FE0(void);
extern void func_003B01D0(s32 *);
/* localdecomp:start func_003AFA58 */
extern void func_003AFD88(void);
s32 func_003AFA58(void *a, u8 *b, s32 *c) {
    void *rd;
    u8 *wr;
    s32 started;
    u8 *bp;
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
    bp = b + 0x50000;
    sent = left;
    D_001DA0CC = 0;
    while (left >= 5 && func_003B2630(a) != 3) {
        func_003A3B70();
        flags = 0;
        if (D_001D52FC_003AFA58->f1A0 == 0 && done && go) armed = 1;
        if (armed && !(D_001D4D40 & 0x80)) {
            s32 st = D_001D4D40 & ~0xC0;
            if (st != 2) {
                if (st == 0 && D_001D52FC_003AFA58->f1A0 != 0 && D_001D52FC_003AFA58->f1A4 == 0) flags = 1;
                else if (D_001D52FC_003AFA58->f1A4 & 0x800) flags = 1;
            }
        }
        if (!done && D_001DA0CC >= 10) {
            done = 1;
            func_003B0130(D_001DA0B8_003AF890);
        }
        if (flags && !started) {
            started = 1;
            func_003B2620((void *)D_001DA0B4_003AF890);
        }
        if (!done && D_001DA0CC >= 10) {
            done = 1;
            func_003B0130(D_001DA0B8_003AF890);
        }
        n = func_003B1328(b, &rd);
        if (sent > 0 && n > 0xFFFF) {
            m = func_003B1440(c, rd, 0x10000);
            sent -= m;
            func_003B1358(b, m);
        }
        func_003AFD88();
        if (!done && D_001DA0CC >= 10) {
            done = 1;
            func_003B0130(D_001DA0B8_003AF890);
        }
        k = func_003B1398(b, &wr);
        if (k > 0) {
            m = func_139A70(a, wr, k, b, *(s32 *)(bp + 8));
            left -= m;
            func_003B13D8(b, m);
        }
        func_003B0048();
        if (!done && D_001DA0CC >= 10) {
            done = 1;
            func_003B0130(D_001DA0B8_003AF890);
        }
        if (!go && func_003B2C68((void *)D_001DA088_003AF890) && func_003AFDA8_003AFA58()) {
            func_003B0F90(1);
            go = 1;
        }
    }
    while (func_003B26B0(a) == 0) {
        func_003B0048();
        func_003AFD88();
    }
    while (func_003B2780(a) == 0 && func_003B2630(a) != 3) {
        func_003B0048();
        func_003AFD88();
    }
    func_003B0FE0();
    func_003B01D0((s32 *)D_001DA0B8_003AF890);
    return started;
}
/* localdecomp:end func_003AFA58 */
