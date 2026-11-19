/* functional: medium. functional: control flow read block by block; byte diff 300 words from layout */
typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 padC[0xF0 - 0xC];
} E_lv100_487930;
extern u8 *D_001D52FC;
extern u8 D_001D672C;
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern E_lv100_487930 D_L01_002C5600_00487930[];
extern s32 D_L01_001D86E8;
extern s32 D_L01_001D86EC;
extern s32 D_L01_001D86F0[];
extern void func_L01_0047EC88(void);
extern void func_L01_00487840(void);
extern void func_003BB5D0(void);
extern void func_003BB590(s32);
extern void func_L01_00487670(void);
extern s32 func_L01_0047EBE0(void);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_0047FE28(void);
extern s32 func_L01_00486980(void);
extern s32 func_L01_00489FD0(void);
extern s32 func_L01_005170B8(s32, u32);
extern s32 func_L01_00487508(s32, s32);
extern s32 func_L01_00487528(s32, s32);
extern s32 func_L01_0047DB70(s32);
extern void func_L01_0047EC38(s32);
extern void func_L01_00517748(s32);
extern void func_L01_00516090_00487930(s32);
extern void func_L01_00516D60(s32, s32);
extern void func_L01_0047EDB0(s32, s32);
extern void func_L01_004875F8(void);
extern void func_L01_004878D0(void);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);

void func_L01_00487930(s32 a0) {
    s32 b;
    s32 t;
    s32 r;
    s32 i;
    s32 k;
    s32 ok;
    s32 common;
    s32 moved;
    s32 c1;
    s32 c2;

    func_L01_0047EC88();
    func_L01_00487840();
    func_003BB5D0();
    func_003BB590(0xF0002);
    func_L01_00487670();
    b = *(s32 *)(D_001D52FC + 0x1C4);
    common = 0;
    moved = 0;
    if (b & 0x800) {
        t = func_L01_0047EBE0();
        common = 1;
    } else if (b & 0x10) {
        func_003A5348(4, 0, 0);
        t = func_L01_0047FE28();
        common = 1;
    } else if (b & 0x1000 || b & 0x4000) {
        func_003A5348(3, 0, 0);
        if (D_L01_001D86E8 == 4 && D_L01_001D86EC == 0) {
            D_L01_001D86EC = 1;
            D_L01_001D86E8 = 3;
        } else {
            D_L01_001D86EC = (D_L01_001D86EC + 1) % 2;
        }
        moved = 1;
    } else if (b & 0x8000) {
        func_003A5348(3, 0, 0);
        if (D_L01_001D86EC > 0) {
            D_L01_001D86E8 = (D_L01_001D86E8 + 3) % 4;
        } else {
            D_L01_001D86E8 = (D_L01_001D86E8 + 4) % 5;
        }
        moved = 1;
    } else if (b & 0x2000) {
        func_003A5348(3, 0, 0);
        if (D_L01_001D86EC > 0) {
            D_L01_001D86E8 = (D_L01_001D86E8 + 1) % 4;
        } else {
            D_L01_001D86E8 = (D_L01_001D86E8 + 1) % 5;
        }
        moved = 1;
    } else if (b & 0x40) {
        r = func_L01_00487508(D_L01_001D86E8, D_L01_001D86EC);
        c1 = 0;
        if (D_00142CA0[r] != 0) {
            c1 = ((u32)(r - 2) < 2) ^ 1;
        }
        c2 = 0;
        if ((u32)(r - 2) < 2) {
            c2 = D_001A7464[0] == 0;
        }
        if (c1 | c2) {
            func_003A5348(4, 0, 0);
            r = func_L01_00487508(D_L01_001D86E8, D_L01_001D86EC);
            if (D_L01_002C5600_00487930[D_001425C0[r]].x8 == 1 && func_L01_0047DB70(1) == r) {
                func_L01_0047EC38(0x1C);
            } else {
                func_L01_0047EC38(r);
            }
        } else {
            func_003A5348(5, 0, 0);
        }
    } else if (b & 1) {
        func_003A5348(4, 0, 0);
        t = func_L01_00486980();
        common = 1;
    } else if (b & 2) {
        func_003A5348(4, 0, 0);
        t = func_L01_00489FD0();
        common = 1;
    }
    if (moved) {
        func_L01_005170B8(0xF0002, 0x402299DE);
    }
    if (common) {
        func_L01_00517748(t);
        func_L01_00516090_00487930(a0);
    }
    r = func_L01_00487508(D_L01_001D86E8, D_L01_001D86EC);
    func_L01_0047EDB0(r, *(s32 *)(D_001D52FC + 0x1C4));
    func_L01_004875F8();
    for (i = 0; i < 9; i++) {
        ok = 1;
        k = 0;
        do {
            t = func_L01_0047DB70(k);
            if (t == D_L01_001D86F0[i]) {
                ok = 0;
            }
            k++;
            if (ok == 0) {
                break;
            }
        } while (k < 4);
        if (ok) {
            func_L01_005170B8(0xF001B + i, 0x8066CCFF);
            func_L01_00516D60(0xF0026 + i, 0);
        } else {
            func_L01_00516D60(0xF0026 + i, 1);
        }
    }
    func_L01_005170B8(func_L01_00487528(D_L01_001D86E8, D_L01_001D86EC) + 0xF001B, 0x80FFFFFF);
    func_L01_004878D0();
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090_00487930(a0);
        if (D_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
