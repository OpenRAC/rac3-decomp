/* func_L01_003B31B8: 14 diff in split mode (check.py --mode S); about 60 in L01_003B1F50.c's N mode, which cannot
   give retail's code: retail keeps %hi(D_L01_0021DE20) in $s1 and rebuilds the %lo in the loop, a split-address
   form (N mode adds two saved registers and a 0x40 frame). So the function needs a cut with split addresses; of the
   neighbouring C blocks func_L01_003B3050 matches in S mode but func_L01_003B3430 does not (2 diff), so the S range
   would be 0x3B31B8..0x3B3430 at most. What differs in S mode: the list node's vars pointer (q) and the new list
   head are in $v1/$a1, retail has them the other way round ($a1 / $v1; global allocation gives q the higher
   priority), and D_L01_001E001C is loaded as lui $v1 / lw $a0 where retail reuses $v1. */
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
extern u8 *D_L01_001E001C_003B31B8[];

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
            m = D_L01_001E001C_003B31B8[0] + ((*(u16 *)s & 0x7FFF) << 8);
            if (m == 0) break;
            s++;
            func_L01_003B6108(m);
        }
    }
    ((void (*)(u8 *, s32, s32))func_L01_004450F0)(a0, 1, -1);
}
