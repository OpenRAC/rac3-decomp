/* functional: high. Rewritten with plain declarations (the draft's aliased names do not compile in isolation). Verified vs asm: pad-button mask b=D_001D52FC[0]->f1C4: 0x4000 next / 0x1000 previous enabled entry among 4 (stride 8, byte 'on'), wrap 0..3, store D_001D8AB4 and func_003A5348(3,0,0); 0x40 call entry callback then func_003A5348(4,0,0); 0x10 and 0x900 select a value via D_001D5BDD / D_001D5BDC (gp-0x6CD4) and call func_003E83C8 then func_003E6FF8(a0) (0x900 case: no call when D_001D5BDC is set and D_001D5BDD clear); finally func_003E73B8(0x4C0038, D_001D8A94, D_001D8A6C+D_001D8A98+sel*D_001D8A68), func_003BB5D0, func_003BB590(0x4C0038). 150 words differ (gp vs lui addressing of the globals, scheduling). */
typedef struct { u8 p[0x1C4]; u32 f1C4; } P_3B23F8;
typedef struct { u8 on; u8 pad[7]; } F_3B23F8;
typedef struct { void (*fn)(); s32 pad; } T_3B23F8;
extern P_3B23F8 *D_001D52FC[];
extern F_3B23F8 D_001D8A48[];
extern T_3B23F8 D_001D8A4C[];
extern s32 D_001D8AB4;
extern u8 D_001D5BDC;
extern u8 D_001D5BDD[];
extern f32 D_001D8A68, D_001D8A6C, D_001D8A94, D_001D8A98;
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_003B4FD0(void);
extern s32 func_00381D08(s32);
extern s32 func_003B5028(void);
extern s32 func_00381CC0(void);
extern void func_003E83C8(s32);
extern void func_003E6FF8(s32);
extern s32 func_003E73B8(s32, f32, f32);
extern void func_003BB5D0(void);
extern void func_003BB590(s32);
void func_003B78D8(s32 a0) {
    u32 b = D_001D52FC[0]->f1C4;
    s32 i;
    s32 n = 0;
    if (b & 0x4000) {
        s32 found = 0;
        i = D_001D8AB4;
        do {
            i++;
            if (i >= 4) i = 0;
            if (D_001D8A48[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8AB4 = i;
        func_003A5348(3, 0, 0);
    } else if (b & 0x1000) {
        s32 found = 0;
        i = D_001D8AB4;
        do {
            i--;
            if (i <= -1) i = 3;
            if (D_001D8A48[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8AB4 = i;
        func_003A5348(3, 0, 0);
    } else if (b & 0x40) {
        if (D_001D8A48[D_001D8AB4].on) {
            if (D_001D8A4C[D_001D8AB4].fn) {
                D_001D8A4C[D_001D8AB4].fn();
                func_003A5348(4, 0, 0);
            }
        }
    } else if (b & 0x10) {
        func_003A5348(4, 0, 0);
        if (D_001D5BDD[0]) {
            func_003E83C8(func_003B5028());
        } else if (D_001D5BDC) {
            func_003E83C8(func_003B4FD0());
        } else {
            func_003E83C8(func_00381D08(0));
        }
        func_003E6FF8(a0);
    } else if (b & 0x900) {
        func_003A5348(4, 0, 0);
        if (D_001D5BDD[0]) {
            func_003E83C8(func_003B5028());
            func_003E6FF8(a0);
        } else if (!D_001D5BDC) {
            func_003E83C8(func_00381CC0());
            func_003E6FF8(a0);
        }
    }
    func_003E73B8(0x4C0038, D_001D8A94, D_001D8A6C + D_001D8A98 + (f32)D_001D8AB4 * D_001D8A68);
    func_003BB5D0();
    func_003BB590(0x4C0038);
}
