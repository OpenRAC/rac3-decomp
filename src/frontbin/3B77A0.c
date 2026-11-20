#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 D_001D8A68;
extern f32 D_001D8A6C;
extern f32 D_001D8A94;
extern f32 D_001D8A98;
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);


typedef struct { u8 p0[0x4954]; s32 f4954; u8 p4958[0x7080 - 0x4958]; u8 f7080[4]; } S_B22C0;
extern s32 D_001D8A20[2];
extern s32 D_001D8A30[2];
extern s32 D_001D8B38[2];
extern u8 D_001D5BDC_003B77A0;
extern S_B22C0 D_00160C40_003B77A0[];
extern s32 D_001D8A40;
extern s32 func_003BB3A8(s32);
extern void *func_003B5048(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern void *func_003B42F8(s32);
extern void func_003B7288(void);
extern void func_003B6B90(void);
extern void func_003B6AC0();
/* localdecomp:start func_003B77A0 */
__asm__(".extern D_001D8A40, 4");
__asm__(".extern D_001D8A20, 8");
__asm__(".extern D_001D8A30, 8");
__asm__(".extern D_001D8B38, 8");
extern void func_003B69F8(void);
void func_003B77A0(void) {
    s32 i;
    s32 x;
    s32 y;
    for (i = 0; i < 4; i++) {
        if (D_001D5BDC_003B77A0 != 0) {
            D_001D8A20[i] = (s32)func_003B5048(i * 2);
            D_001D8A30[i] = (s32)func_003B5048(i * 2 + 1);
        } else {
            x = func_003BB3A8(0);
            D_001D8B38[i] = x;
            y = (x + 15) & 0xFFFFFFF0;
            D_001D8A20[i] = y;
            y = x + 0x8D00;
            y = (y + 15) & 0xFFFFFFF0;
            D_001D8A30[i] = y;
        }
        func_003B4528(func_003B42F8(i), D_001D8A20[i], D_001D8A30[i], D_00160C40_003B77A0->f4954, (s32)D_00160C40_003B77A0->f7080);
    }
    func_003B69F8();
    func_003B7288();
    func_003B6B90();
    func_003B6AC0();
    D_001D8A40 = 0;
}
/* localdecomp:end func_003B77A0 */

typedef struct { u8 p[0x1C4]; u32 f1C4; } P_3B23F8;
typedef struct { u8 on; u8 pad[7]; } F_3B23F8;
typedef struct { void (*fn)(); s32 pad; } T_3B23F8;
extern P_3B23F8 *D_001D52FC_003B78D8;
extern F_3B23F8 D_001D8A48_003B78D8[1];
extern T_3B23F8 D_001D8A4C_003B78D8[1];
extern s32 D_001D8AB4;
extern u8 D_001D5BDC_003B78D8;
extern u8 D_001D5BDD;
extern s32 func_003B4FD0_003B78D8(void);
extern s32 func_00381D08(s32);
extern s32 func_003B5028(void);
extern s32 func_00381CC0_003B78D8(void);
extern void func_003E83C8_003B78D8(s32);
extern void func_003E6FF8_003B78D8(s32);
extern s32 func_003E73B8(s32, f32, f32);
extern void func_003BB5D0();
extern void func_003BB590(s32);
/* localdecomp:start func_003B78D8 */
/* from boot_elf's func_003B7C90 (its twin), with the cursor stepped in place */
__asm__(".extern D_001D8AB4, 4");
__asm__(".extern D_001D8A48_003B78D8, 8");
__asm__(".extern D_001D5BDC_003B78D8, 1");
__asm__(".extern D_001D8A68, 4");
__asm__(".extern D_001D8A6C, 4");
__asm__(".extern D_001D8A94, 4");
__asm__(".extern D_001D8A98, 4");
extern s32 func_003A5348(s32, s32, s32);
void func_003B78D8(s32 a0) {
    u32 b = D_001D52FC_003B78D8->f1C4;
    s32 n = 0;
    if (b & 0x4000) {
        s32 found = 0;
        do {
            D_001D8AB4++;
            if (D_001D8AB4 >= 4) D_001D8AB4 = 0;
            if (D_001D8A48_003B78D8[D_001D8AB4].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        func_003A5348(3, 0, 0);
    } else if (b & 0x1000) {
        s32 found = 0;
        do {
            D_001D8AB4--;
            if (D_001D8AB4 < 0) D_001D8AB4 = 3;
            if (D_001D8A48_003B78D8[D_001D8AB4].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        func_003A5348(3, 0, 0);
    } else if (b & 0x40) {
        F_3B23F8 *f = D_001D8A48_003B78D8;
        if (f[D_001D8AB4].on) {
            T_3B23F8 *t = D_001D8A4C_003B78D8;
            if (t[D_001D8AB4].fn) {
                t[D_001D8AB4].fn();
                func_003A5348(4, 0, 0);
            }
        }
    } else if (b & 0x10) {
        func_003A5348(4, 0, 0);
        if (D_001D5BDD) {
            func_003E83C8_003B78D8(func_003B5028());
            func_003E6FF8_003B78D8(a0);
        } else if (D_001D5BDC_003B78D8) {
            func_003E83C8_003B78D8(func_003B4FD0_003B78D8());
            func_003E6FF8_003B78D8(a0);
        } else {
            func_003E83C8_003B78D8(func_00381D08(0));
            func_003E6FF8_003B78D8(a0);
        }
    } else if (b & 0x900) {
        func_003A5348(4, 0, 0);
        if (D_001D5BDD) {
            func_003E83C8_003B78D8(func_003B5028());
            func_003E6FF8_003B78D8(a0);
        } else if (!D_001D5BDC_003B78D8) {
            func_003E83C8_003B78D8(func_00381CC0_003B78D8());
            func_003E6FF8_003B78D8(a0);
        }
    }
    func_003E73B8(0x4C0038, D_001D8A94, D_001D8A6C + D_001D8A98 + (f32)D_001D8AB4 * D_001D8A68);
    func_003BB5D0();
    func_003BB590(0x4C0038);
}
/* localdecomp:end func_003B78D8 */
