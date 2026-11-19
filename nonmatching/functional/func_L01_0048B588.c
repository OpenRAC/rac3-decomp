/* functional: high. functional */
typedef struct {
    s32 w0;
    u8 u4;
    u8 pad5[0xA7];
    void (*fnAC)(s32, s32);
} E_lv100_B0;
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern E_lv100_B0 D_L01_00233DD8_0048B588[];
extern s32 D_L01_001D8A34;
extern s32 D_L01_001D8A28;
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C58(s32);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_0048EE70(void);
extern void func_L01_00517748(s32);
extern void func_L01_0048D930(s32, s32);
extern s32 func_L01_00495030(void);
extern s32 func_003BB0E8(s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00516090_0048B588(s32);

void func_L01_0048B588(s32 a0) {
    s32 idx;
    s32 b;
    s32 top;
    s32 st;
    s32 sfx;

    idx = func_003B9C58(func_003B9BD0(0));
    D_L01_001D8A34 = idx;
    b = *(s32 *)(D_001D52FC + 0x1C4);
    if (b & 0x40) {
        sfx = 1;
        if (D_L01_00233DD8_0048B588[idx].u4 != 0) {
            if (D_L01_00233DD8_0048B588[idx].fnAC != 0) {
                D_L01_00233DD8_0048B588[idx].fnAC(a0, D_L01_00233DD8_0048B588[idx].w0);
                sfx = 4;
            }
        }
        func_003A5348(sfx, 0, 0);
    } else if (b & 0x80) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0048EE70());
        func_L01_0048D930(1, -1);
        func_L01_00516090_0048B588(a0);
    }
    idx = D_L01_001D8A34;
    top = D_L01_001D8A28;
    if (idx < top) {
        D_L01_001D8A28 = idx;
    } else if (idx >= top + 7) {
        D_L01_001D8A28 = idx - 6;
    }
    if (D_L01_001D8A28 < 0) {
        D_L01_001D8A28 = 0;
    }
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x910) {
        st = D_001D545C;
        if (st == 0xC || st == 0x12) {
            func_003A5348(5, 0, 0);
            func_L01_00517748(func_L01_00495030());
            func_L01_00516090_0048B588(a0);
        } else {
            func_003BB0E8(st);
            func_L01_00517748(func_L01_0047EBE0());
            func_003A5348(0x14, 0, 0);
            func_L01_00516090_0048B588(a0);
        }
    }
}
