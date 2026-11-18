/* func_L01_003B31B8, Sonnet b17-p1 (2026-11-18): 12 words differ with -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as (S mode, the flag line
 * src/levels/shared/L01_003B1F50.c already uses; check.py --mode S --as ps2as). The earlier 14 (S mode, default assembler) came from retail's
 * Ps2EeAs macro loads: D_L01_001E001C is a plain 4-byte scalar here (macro `lw $3, sym`, one register) and the seven $gp globals get early
 * `.extern X, 4` hints. What is left is only the swap of two registers: the list head ($v1 in retail, $a1 here) and the node's vars pointer q
 * ($a1 in retail, $v1 here); regalloc.py gives q priority 5.3 (16 refs) against head's 0.44, so q takes the lowest free register. Splitting
 * q (a separate variable for prev's vars), moving the declarations and a late `head` did not change it. Needs a cut with that flag line
 * (L01_003B2688.c is -mno-split-addresses): 0x3B31B8..0x3B3430 at most (func_L01_003B3430 does not match in S mode).
 */
extern void func_L01_003B4D58(void *a, u8 *b);
extern void func_L01_00456230(u8 *, s32);
extern void func_L01_003B6108(u8 *obj);
extern void func_L01_004450F0(s32, s32, s32);
extern s32 D_L01_001DE630;
extern s32 D_L01_001DE634;
extern s32 D_L01_001DE638;
extern s32 D_L01_001DE63C;
extern s32 D_L01_001DE640;
extern s32 D_L01_001DE644;
extern s32 D_L01_001DE648;
extern s32 D_L01_001E0058;
extern s16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C_003B31B8;
__asm__(".extern D_L01_001DE630, 4");
__asm__(".extern D_L01_001DE634, 4");
__asm__(".extern D_L01_001DE638, 4");
__asm__(".extern D_L01_001DE63C, 4");
__asm__(".extern D_L01_001DE640, 4");
__asm__(".extern D_L01_001DE644, 4");
__asm__(".extern D_L01_001DE648, 4");
__asm__(".extern D_L01_001E0058, 4");

void func_L01_003B31B8(u8 *a0, u8 *a1) {
    u8 *v = *(u8 **)(a0 + 0x68);
    u8 *p;
    s16 *s;
    func_L01_003B4D58(a0, v);
    D_L01_001DE630 = 0;
    func_L01_00456230(a0, 0);
    if (a1 == 0 || *(s16 *)(a1 + 0xAA) == 0x19E4) {
        p = (u8 *)D_L01_001DE634;
        D_L01_001DE638 = 0;
        D_L01_001DE63C = 0;
        D_L01_001DE640 = 0;
        D_L01_001DE644 = 0;
        D_L01_001DE648 = 0;
        if (p != 0) {
            do {
                u8 *q = *(u8 **)(p + 0x68);
                p = *(u8 **)(q + 0x58);
                *(s32 *)(q + 0x58) = 0;
                *(s32 *)(q + 0x54) = 0;
            } while (p != 0);
            D_L01_001DE634 = 0;
        }
    } else {
        p = (u8 *)D_L01_001DE634;
        if (p != 0) {
            u8 *head = p;
            u8 *prev = 0;
            u8 *q;
            do {
                q = *(u8 **)(p + 0x68);
                if (--*(s32 *)(q + 0x54) == 0) {
                    p = *(u8 **)(q + 0x58);
                    if (prev != 0) {
                        q = *(u8 **)(prev + 0x68);
                        *(u8 **)(q + 0x58) = p;
                    } else {
                        *(u8 **)(q + 0x58) = 0;
                        head = p;
                    }
                } else {
                    prev = p;
                    p = *(u8 **)(q + 0x58);
                }
            } while (p != 0);
            D_L01_001DE634 = (s32)head;
        }
    }
    if (*(s32 *)(v + 0xC) != -1) {
        s = D_L01_0021DE20[*(s32 *)(v + 0xC)];
        while (1) {
            s32 n = *(s32 *)(v + 0xC);
            u8 *m;
            if ((n & 0xFF) == 0xFF) break;
            if (D_L01_001E0058 < n) break;
            if (s == 0) break;
            if (s[-1] < 0 && s != D_L01_0021DE20[n]) break;
            m = D_L01_001E001C_003B31B8 + ((*(u16 *)s & 0x7FFF) << 8);
            if (m == 0) break;
            s++;
            func_L01_003B6108(m);
        }
    }
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(a0, 1, -1);
}
