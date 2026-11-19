/* functional: high. Same control flow, reads, writes and call order; only register allocation and list-walk scheduling differ. */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;
extern s32 D_L01_001DE634;
extern s32 D_L01_001DE630;
extern s32 D_L01_001DE638;
extern s32 D_L01_001DE63C;
extern s32 D_L01_001DE640;
extern s32 D_L01_001DE644;
extern s32 D_L01_001DE648;
extern void func_L01_00456230(void *, s32);
extern void func_L01_003B4D58(u8 *, u8 *);
extern void func_L01_003B6108(u8 *);
extern void func_L01_004450F0(s32, s32, s32);

void func_L01_003B31B8(u8 *m, u8 *o) {
    u8 *s = *(u8 **)(m + 104);
    u16 *p;
    u8 *n;
    u8 *cur;
    u8 *prev;
    u8 *st;
    u8 *next;
    u8 *head;
    s32 cnt;

    func_L01_003B4D58(m, s);
    D_L01_001DE630 = 0;
    func_L01_00456230(m, 0);
    if (o == 0 || *(s16 *)(o + 170) == 6628) {
        head = (u8 *)D_L01_001DE634;
        D_L01_001DE638 = 0;
        D_L01_001DE63C = 0;
        D_L01_001DE640 = 0;
        D_L01_001DE644 = 0;
        D_L01_001DE648 = 0;
        if (head != 0) {
            do {
                st = *(u8 **)(head + 104);
                head = *(u8 **)(st + 88);
                *(s32 *)(st + 84) = 0;
                *(s32 *)(st + 88) = 0;
            } while (head != 0);
            D_L01_001DE634 = 0;
        }
    } else {
        head = (u8 *)D_L01_001DE634;
        if (head != 0) {
            cur = head;
            prev = 0;
            st = *(u8 **)(cur + 104);
            do {
                cnt = *(s32 *)(st + 84) - 1;
                *(s32 *)(st + 84) = cnt;
                next = *(u8 **)(st + 88);
                if (cnt != 0) {
                    prev = cur;
                } else if (prev == 0) {
                    *(s32 *)(st + 88) = 0;
                    head = next;
                } else {
                    *(u8 **)(*(u8 **)(prev + 104) + 88) = next;
                }
                cur = next;
                if (cur != 0) {
                    st = *(u8 **)(cur + 104);
                }
            } while (cur != 0);
            D_L01_001DE634 = (s32)head;
        }
    }
    if (*(s32 *)(s + 12) != -1) {
        p = D_L01_0021DE20[*(s32 *)(s + 12)];
        while ((*(s32 *)(s + 12) & 0xFF) != 255 && *(s32 *)(s + 12) <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(s + 12)])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            func_L01_003B6108(n);
            p++;
        }
    }
    func_L01_004450F0((s32)m, 1, -1);
}
