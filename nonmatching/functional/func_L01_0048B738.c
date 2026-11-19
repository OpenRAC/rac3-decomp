/* functional: high. Not byte-identical (the retail float loads use lui $at+lwc1; compiler differs in scheduling), same reads, writes, calls and order; switch cases read from the jump table at 002BC9B0. */
typedef struct { s32 w0; s32 w4; } Ent_0048B738;
typedef struct { s32 id; u8 flag; u8 pad[0xA3]; Ent_0048B738 *ent; s32 padAC; } Slot_0048B738;
extern Slot_0048B738 D_L01_00233DD8[];
extern f32 D_L01_001D8A5C;
extern f32 D_L01_001D8A60;
extern f32 D_L01_001D8A58;
extern s32 D_L01_001D8A1C;
extern s32 D_L01_001D8A2C;
extern s32 D_L01_001D8A34;
extern s32 D_L01_001D8A38;
extern s32 D_L01_001D8A24;
extern s32 D_L01_001D8A20;
extern s32 D_L01_001D8A14;
extern s32 D_L01_001D8A6C;
extern f32 D_L01_001E0890[];
extern f32 D_L01_001E0894[];
extern f32 D_L01_001E08A0[];
extern f32 D_L01_001E08A4[];
extern u32 D_L01_001E08D0[];
extern void func_L01_00516D60(s32, s32);
extern void func_L01_00517190(s32, s32);
extern s32 func_003A5348(s32, s32, s32);
extern void func_003A4F28(void);
extern s32 *func_003B42F8(s32);
extern void func_L01_0048BA38(s32);

void func_L01_0048B738(void) {
    D_L01_001D8A5C = D_L01_001D8A5C + D_L01_001D8A60;
    D_L01_001E0890[0] = D_L01_001E0890[0] + D_L01_001E08A0[0];
    D_L01_001E0894[0] = D_L01_001E0894[0] + D_L01_001E08A4[0];
    switch (D_L01_001E08D0[0]) {
    case 0:
        if (D_L01_001D8A1C > 0) {
            D_L01_001D8A1C = D_L01_001D8A1C - 1;
        } else {
            D_L01_001D8A1C = 0;
            if (D_L01_00233DD8[D_L01_001D8A2C].ent->w4 != 0) {
                func_L01_00516D60(0x130027, 1);
                func_L01_00517190(0x130027, D_L01_00233DD8[D_L01_001D8A2C].ent->w4 + 1);
            } else {
                func_L01_00516D60(0x130027, 0);
            }
        }
        if (D_L01_001D8A2C != D_L01_001D8A34) {
            D_L01_001D8A6C = func_003A5348(0x16, 4, 0);
            func_L01_0048BA38(1);
        }
        break;
    case 1:
        if (D_L01_001D8A34 == D_L01_001D8A2C && D_L01_001D8A38 == D_L01_001D8A34) {
            func_L01_0048BA38(4);
            return;
        }
        if (D_L01_001D8A5C <= D_L01_001D8A58) {
            D_L01_001D8A5C = D_L01_001D8A58;
            func_L01_0048BA38(2);
        }
        break;
    case 2:
        if (D_L01_001D8A38 == D_L01_001D8A34) {
            D_L01_001D8A24 = D_L01_001D8A24 - 1;
            if (D_L01_001D8A24 <= 0) {
                func_L01_0048BA38(3);
            }
        } else {
            func_L01_0048BA38(2);
        }
        break;
    case 3:
        if (D_L01_001D8A38 != D_L01_001D8A34) {
            func_L01_0048BA38(2);
        } else {
            if (D_L01_001D8A14 == D_L01_001D8A20) {
                if (D_L01_00233DD8[D_L01_001D8A38].ent->w0 != 0) {
                    func_L01_00516D60(0x13000F, 1);
                    func_L01_00517190(0x13000F, D_L01_00233DD8[D_L01_001D8A34].ent->w0);
                } else {
                    func_L01_00516D60(0x13000F, 0);
                }
            } else if (D_L01_001D8A14 != 0) {
                D_L01_001D8A14 = D_L01_001D8A14 - 1;
                break;
            } else {
                if (*func_003B42F8(1) == 2) {
                    if (D_L01_001D8A6C != -1) {
                        func_003A4F28();
                        D_L01_001D8A6C = -1;
                    }
                    func_L01_0048BA38(4);
                }
            }
        }
        if (D_L01_001D8A14 != 0) {
            D_L01_001D8A14 = D_L01_001D8A14 - 1;
        }
        break;
    case 4:
        if (D_L01_001D8A38 != D_L01_001D8A34) {
            func_L01_0048BA38(1);
        } else if (D_L01_001D8A58 <= D_L01_001D8A5C) {
            D_L01_001D8A5C = D_L01_001D8A58;
            func_L01_0048BA38(0);
        }
        break;
    }
}
