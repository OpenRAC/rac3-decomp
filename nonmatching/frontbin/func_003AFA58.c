/* Near miss of func_003AFA58 with its file's own flags: tools/check.py reports 181 diff
   (the version it replaces: 192).
   What differs: Only the buffer-end address differs: retail splits `b + 0x50000` (`lui $v0, 5`
   hoisted to the top of the prologue, then `addu $v0, $s2, $v0` (base first) and the sum
   spilled to 0xC($sp)), while this file's `-mno-split-addresses` always builds that address in
   one piece with the constant first (`lui $v0, 5; addu $v0, $v0, $s2`) and never hoists it out
   of the loop; pointer+literal, `(u32)`+literal, offset-in-a-variable and array-
   subscript/struct-member spellings all produce the same constant-first, non-hoisted code.
   That also moves `sent = left` (retail: `daddu $s5, $s4, $0` before the...
*/

/* PAL candidate for func_003AFA58 (frontbin), built from the US draft of
   rac3-uya-decomp func_003AA4B0 with PAL-specific changes:
   - the globals retail reaches with lui/%lo are declared as unsized arrays
     (never small data), the ones retail reaches through $gp stay sized;
   - the buffer end pointer b + 0x50000 is a local of its own, computed in
     the prologue and spilled to the stack. */

/* localdecomp:start func_003AFA58 */
typedef struct { u8 p0[0x1A0]; s32 f1A0; s32 f1A4; } P_3AA4B0;
extern P_3AA4B0 *D_001D52FC_003AFA58L[]; /* retail: lui %hi / lw %lo */
extern s32 D_001D4D40;
extern s32 D_001DA0CC_003AFA58L1[]; /* retail: lui %hi / lw %lo, one address per use */
extern s32 D_001DA0CC_003AFA58L2[];
extern s32 D_001DA0CC_003AFA58L3[];
extern s32 D_001DA0CC_003AFA58L4[];
extern s32 D_001DA0CC_003AFA58L5[];
extern s32 D_001DA088_003AF890;
extern s32 D_001DA0B4_003AFA58L[]; /* retail: lui %hi / lw %lo */
extern s32 D_001DA0B8_003AFA58L[]; /* retail: lui %hi / lw %lo */
extern void func_003A3B70(void);
extern void func_003B0130();
extern void func_003B2620(void *);
extern s32 func_003B1328(u8 *, void **);
extern s32 func_003B1440();
extern void func_003B1358(u8 *, s32);
extern void func_003AFD88(void);
extern s32 func_003B1398(u8 *, u8 **);
extern s32 func_139A70(void *, u8 *, s32, u8 *, s32);
extern s32 func_003B13D8();
extern void func_003B0048(void);
extern s32 func_003B2C68(void *);
extern s32 func_003AFDA8_003AFA58(void); /* defined void, but returns func_003B03A8's result */
extern void func_003B0F90(s32);
extern s32 func_003B2630(void *);
extern s32 func_003B26B0();
extern s32 func_003B2780(void *);
extern void func_003B0FE0(void);
extern void func_003B01D0(s32 *);
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
    D_001DA0CC_003AFA58L1[0] = 0;
    while (left >= 5 && func_003B2630(a) != 3) {
        func_003A3B70();
        flags = 0;
        if (D_001D52FC_003AFA58L[0]->f1A0 == 0 && done && go) armed = 1;
        if (armed && !(D_001D4D40 & 0x80)) {
            s32 st = D_001D4D40 & ~0xC0;
            if (st != 2) {
                if (st == 0 && D_001D52FC_003AFA58L[0]->f1A0 != 0 && D_001D52FC_003AFA58L[0]->f1A4 == 0) flags = 1;
                else if (D_001D52FC_003AFA58L[0]->f1A4 & 0x800) flags = 1;
            }
        }
        if (!done && D_001DA0CC_003AFA58L2[0] >= 10) {
            done = 1;
            func_003B0130(D_001DA0B8_003AF890);
        }
        if (flags && !started) {
            started = 1;
            func_003B2620((void *)D_001DA0B4_003AFA58L[0]);
        }
        if (!done && D_001DA0CC_003AFA58L3[0] >= 10) {
            done = 1;
            func_003B0130(D_001DA0B8_003AFA58L[0]);
        }
        n = func_003B1328(b, &rd);
        if (sent > 0 && n > 0xFFFF) {
            m = func_003B1440(c, rd, 0x10000);
            sent -= m;
            func_003B1358(b, m);
        }
        func_003AFD88();
        if (!done && D_001DA0CC_003AFA58L4[0] >= 10) {
            done = 1;
            func_003B0130(D_001DA0B8_003AFA58L[0]);
        }
        k = func_003B1398(b, &wr);
        if (k > 0) {
            m = func_139A70(a, wr, k, b, *(s32 *)(bp + 8));
            left -= m;
            func_003B13D8(b, m);
        }
        func_003B0048();
        if (!done && D_001DA0CC_003AFA58L5[0] >= 10) {
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
