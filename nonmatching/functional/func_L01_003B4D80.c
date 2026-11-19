/* functional: high. Same reads, calls and arguments; ternaries compile to movn instead of retail's branches and the two buffers use lui/addiu instead of gp-relative addresses, which does not change behaviour. */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;
extern s32 D_L01_001DFB40[];
extern s32 D_L01_001DE634;
extern char D_L01_001DE720[];
extern char D_L01_001DE728[];
extern char D_L01_001DE738[];
extern char D_L01_001DE740[];
extern char D_L01_001E2130[];
extern char D_L01_001E2170[];
extern void func_11B2E8(char *, char *, ...);
extern void func_L01_00516FD8(s32, char *);
extern s32 func_L01_003B4818(void *, u8 *);

void func_L01_003B4D80(u8 *a0, u8 *s) {
    s32 remain;
    s32 secs;
    s32 mins;
    s32 diff;
    u8 *st;
    u8 *cur;
    u8 *n;
    u16 *p;
    s32 idx;

    if (*(s32 *)(s + 36) == 0) {
        return;
    }
    remain = *(s32 *)(s + 36) * 50 - (D_L01_001DFB40[0] - *(s32 *)(*(u8 **)(*(u8 **)(s + 8) + 104) + 96));
    if (remain < 0) {
        remain = 0;
    }
    mins = remain / 3000;
    secs = (remain / 50) % 60;
    if (remain % 50 != 0) {
        secs += 1;
        if (secs >= 60) {
            mins += 1;
            secs = 0;
        }
    }
    func_11B2E8(D_L01_001E2130, D_L01_001DE728, mins < 10 ? D_L01_001DE738 : D_L01_001DE720, mins,
                secs < 10 ? D_L01_001DE738 : D_L01_001DE720, secs);
    func_L01_00516FD8(0x140004, D_L01_001E2130);
    if (func_L01_003B4818(a0, s) == 0) {
        return;
    }
    diff = 0;
    cur = (u8 *)D_L01_001DE634;
    if (cur != 0) {
        st = *(u8 **)(cur + 104);
        while (1) {
            if (*(s32 *)st == 0x1D75) {
                diff = *(s32 *)(st + 192) - *(s32 *)(st + 196);
                break;
            }
            cur = *(u8 **)(st + 88);
            if (cur == 0) {
                break;
            }
            st = *(u8 **)(cur + 104);
        }
    } else {
        idx = *(s32 *)(s + 12);
        if (idx == -1) {
            func_L01_00516FD8(0x140007, D_L01_001DE738);
            return;
        }
        p = D_L01_0021DE20[idx];
        while ((idx & 0xFF) != 255 && idx <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[idx])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            st = *(u8 **)(n + 104);
            if (*(s32 *)st == 0x1D75) {
                diff = *(s32 *)(st + 192) - *(s32 *)(st + 196);
                break;
            }
            p++;
        }
    }
    func_11B2E8(D_L01_001E2170, D_L01_001DE740, diff);
    func_L01_00516FD8(0x140007, D_L01_001E2170);
}
