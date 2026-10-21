/* US draft of func_0039A8B8 (rac3-uya-decomp func_00395AC8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0039A8B8 */
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; } E_00395AC8;
typedef struct { u8 pad[0x458C]; s32 g458C; E_00395AC8 el[0x30]; } S_00395AC8;
extern S_00395AC8 D_160C40_0039A8B8;
typedef struct { u8 pad[0x34]; s32 f34[3]; } T_00395AC8;
extern T_00395AC8 D_16C690_0039A8B8;
__asm__(".extern D_001D6000_0039A8B8, 4");
extern s32 D_001D6000_0039A8B8;
extern u8 D_001D6004_0039A8B8;
extern u8 D_001D6008_0039A8B8;
extern s32 func_003A2630();
extern void func_0039A748();
extern void func_0039A798();
s32 func_0039A8B8(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 t;
    if (D_160C40_0039A8B8.el[a0].f8 != 0) {
        t = D_001D6000_0039A8B8;
        if (t == -1) {
            *(volatile s32 *)&D_001D6000_0039A8B8 = a0;
            *(volatile s32 *)&D_001D6004_0039A8B8 = a1;
            *(volatile s32 *)&D_001D6008_0039A8B8 = a2;
            if (a1 >= 0) {
                D_16C690_0039A8B8.f34[a1] = t;
            }
            if (D_160C40_0039A8B8.el[a0].f10 != 0 && a3 == 0) {
                return func_003A2630(a2, D_160C40_0039A8B8.el[a0].fC + D_160C40_0039A8B8.g458C, D_160C40_0039A8B8.el[a0].f10, func_0039A798, &D_001D6000_0039A8B8);
            }
            return func_003A2630(a2, D_160C40_0039A8B8.el[a0].f4 + D_160C40_0039A8B8.g458C, D_160C40_0039A8B8.el[a0].f8, func_0039A748, &D_001D6000_0039A8B8);
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_0039A8B8 */
