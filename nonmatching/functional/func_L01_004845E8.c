/* functional: high. 5-state fade/dialog sequencer for the popup (D_001E0754 = state, D_001E0758 = countdown handled by func_0038CAD0): 0 fills texts and starts the fade-in countdown, 1 fades all nine widgets in by writing the alpha byte of D_001D8508, 2 swaps the text and waits, 3 waits for countdown or X, 4 fades out and then closes via func_L01_00516090. Jump table (5 cases) read from the retail ELF. The float divides keep retail's divisor (the D_001D852C/8530 durations); a zero duration would give inf as in retail (PS2 clamps). Not byte-checked. */
typedef struct {
    u8 pad0[0x1C4];
    u32 buttons;
} S_Pad1C4;
extern S_Pad1C4 *D_001D52FC;
extern s32 D_001E0754;
extern s32 D_001E0758;
extern char D_001E0760[];
extern char D_001D8528[];
extern char D_001D8538[];
extern char D_001D8540[];
extern char D_001D8548[];
extern s32 D_001D8508;
extern s32 D_001D852C;
extern s32 D_001D8530;
extern s32 D_001D8534;

extern void func_L01_0047EC88(void);
extern s32 func_0011B2E8(char *, ...);
extern s32 func_L01_00516FD8(s32, void *);
extern s32 func_L01_005170B8(s32, s32);
extern s32 func_0038CAD0(void *);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);
extern void func_L01_00516090(s32);

void func_L01_004845E8(s32 a0) {
    s32 alpha;
    s32 r;

    func_L01_0047EC88();
    switch (D_001E0754) {
    case 0:
        func_0011B2E8(D_001E0760, D_001D8538, 0);
        func_L01_00516FD8(0x100006, D_001E0760);
        func_L01_00516FD8(0x10000A, D_001D8528);
        func_0011B2E8(D_001E0760, D_001D8540, 0, 0);
        func_L01_00516FD8(0x10000C, D_001E0760);
        D_001E0754 = 1;
        D_001E0758 = D_001D852C - 1;
        break;
    case 1: {
        f32 f1 = (f32)D_001D852C;
        f32 f0 = (f32)D_001E0758;
        f0 = f0 / f1;
        f0 = 1.0f - f0;
        f0 = f0 * 128.0f;
        alpha = (s32)f0 << 24;
        func_L01_005170B8(0x100005, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x100008, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x100009, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x100006, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x100007, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x10000A, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x10000B, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x10000C, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x10000D, (D_001D8508 & 0xFFFFFF) | alpha);
        if (func_0038CAD0(&D_001E0758) != 0) {
            D_001E0758 = 0;
            D_001E0754 = 2;
        }
        break;
    }
    case 2:
        func_0011B2E8(D_001E0760, D_001D8538, 0);
        func_L01_00516FD8(0x100006, D_001E0760);
        func_0011B2E8(D_001E0760, D_001D8548, 0);
        func_L01_00516FD8(0x10000A, D_001E0760);
        if (func_0038CAD0(&D_001E0758) != 0) {
            D_001E0754 = 3;
            D_001E0758 = D_001D8534 - 1;
        }
        break;
    case 3:
        func_L01_005170B8(0x100006, D_001D8508);
        r = func_0038CAD0(&D_001E0758);
        if (r != 0 || (D_001D52FC->buttons & 0x40)) {
            D_001E0754 = 4;
            D_001E0758 = D_001D8530 - 1;
        }
        break;
    case 4: {
        f32 f1 = (f32)D_001D8530;
        f32 f0 = (f32)D_001E0758;
        f0 = f0 / f1;
        f0 = f0 * 128.0f;
        alpha = (s32)f0 << 24;
        func_L01_005170B8(0x100005, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x100008, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x100009, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x100006, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x100007, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x10000A, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x10000B, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x10000C, (D_001D8508 & 0xFFFFFF) | alpha);
        func_L01_005170B8(0x10000D, (D_001D8508 & 0xFFFFFF) | alpha);
        if (func_0038CAD0(&D_001E0758) != 0) {
            func_L01_00517748(func_L01_0047EBE0());
            func_L01_00516090(a0);
        }
        break;
    }
    default:
        break;
    }
}
