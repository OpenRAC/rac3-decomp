/* Near miss of func_003B78D8 with its file's own flags: tools/check.py reports 85 diff
   (the version it replaces: 144).
*/

/* PAL candidate for func_003B78D8 (US draft: rac3-uya-decomp func_003B23F8).
   The US needed @ps2as and no -mno-split-addresses; with this file's flags the
   globals must be declared so that retail's addressing comes out: retail reads
   D_001D52FC, D_001D8A4C and D_001D5BDD through lui (unsized declarations),
   the small ones through $gp (sized declarations).  The file's own
   declarations cannot be changed here, so those three get per-function
   aliases at the same addresses. */

/* localdecomp:start func_003B78D8 */
typedef struct { u8 p[0x1C4]; u32 f1C4; } P_3B23F8;
typedef struct { u8 on; u8 pad[7]; } F_3B23F8;
typedef struct { void (*fn)(); s32 pad; } T_3B23F8;
__asm__(".extern D_001D8AB4, 4");
__asm__(".extern D_001D8A48_003B78D8, 8");
__asm__(".extern D_001D5BDC_003B78D8, 1");
__asm__(".extern D_001D8A68, 4");
__asm__(".extern D_001D8A6C, 4");
__asm__(".extern D_001D8A94, 4");
__asm__(".extern D_001D8A98, 4");
extern P_3B23F8 *D_001D52FC_003B78D8;
extern P_3B23F8 *D_001D52FC_l_003B78D8[];
extern F_3B23F8 D_001D8A48_003B78D8[1];
extern T_3B23F8 D_001D8A4C_003B78D8[1];
extern T_3B23F8 D_001D8A4C_l_003B78D8[];
extern s32 D_001D8AB4;
extern u8 D_001D5BDC_003B78D8;
extern u8 D_001D5BDD;
extern u8 D_001D5BDD_l_003B78D8[];
extern s32 func_003B4FD0_003B78D8(void);
extern s32 func_00381D08(s32);
extern s32 func_003B5028(void);
extern s32 func_00381CC0_003B78D8(void);
extern void func_003E83C8_003B78D8(s32);
extern void func_003E6FF8_003B78D8(s32);
extern s32 func_003E73B8(s32, f32, f32);
extern void func_003BB5D0();
extern void func_003BB590(s32);
void func_003B78D8(s32 a0) {
    u32 b = D_001D52FC_l_003B78D8[0]->f1C4;
    s32 i;
    s32 n = 0;
    if (b & 0x4000) {
        s32 found = 0;
        i = D_001D8AB4;
        do {
            i++;
            if (i >= 4) i = 0;
            if (D_001D8A48_003B78D8[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8AB4 = i;
        ((s32 (*)(s32, s32, s32))func_003A5348)(3, 0, 0);
    } else if (b & 0x1000) {
        s32 found = 0;
        i = D_001D8AB4;
        do {
            i--;
            { s32 lim = -1; if (i <= lim) i = 3; lim = 0; }
            if (D_001D8A48_003B78D8[i].on) found = 1;
            n++;
            if (found) break;
        } while (n < 4);
        D_001D8AB4 = i;
        ((s32 (*)(s32, s32, s32))func_003A5348)(3, 0, 0);
    } else if (b & 0x40) {
        F_3B23F8 *f = D_001D8A48_003B78D8;
        if (f[D_001D8AB4].on) {
            T_3B23F8 *t = D_001D8A4C_l_003B78D8;
            if (t[D_001D8AB4].fn) {
                t[D_001D8AB4].fn();
                ((s32 (*)(s32, s32, s32))func_003A5348)(4, 0, 0);
            }
        }
    } else if (b & 0x10) {
        ((s32 (*)(s32, s32, s32))func_003A5348)(4, 0, 0);
        if (D_001D5BDD_l_003B78D8[0]) {
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
        ((s32 (*)(s32, s32, s32))func_003A5348)(4, 0, 0);
        if (D_001D5BDD_l_003B78D8[0]) {
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
