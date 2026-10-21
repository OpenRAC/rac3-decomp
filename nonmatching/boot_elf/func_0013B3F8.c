/* US draft of func_0013B3F8 (rac3-uya-decomp func_0013B3F8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_0013B3F8 */
__asm__(".extern D_001D4E18, 4");
__asm__(".extern D_001D4DE8, 4");
__asm__(".extern D_001D4DF0, 4");
__asm__(".extern D_001D4DC0, 4");
__asm__(".extern D_001D4DC8, 4");
__asm__(".extern D_001D4DD0, 4");
__asm__(".extern D_001D4DD8, 4");
typedef struct { s32 a; s32 pad; long b; } E_13C578;
extern s32 D_001D4E18;
extern s32 *D_001D4DC0[2];
extern s32 D_001D4DC8[2];
extern E_13C578 *D_001D4DD0[2];
extern u8 *D_001D4DD8[2];
extern s32 D_001D4DE8;
extern s32 D_001D4DF0;
extern long D_001D4DF8;
typedef struct { s32 a, b; } S_1D4900;
extern S_1D4900 D_1D4900;
extern S_1D4900 D_1D49C0;
extern s32 D_1D4980;
extern s32 D_1D4990_0013B3F8;
extern s32 D_1D4A00;
extern u8 D_15C3C0[];
extern u8 D_15D3C0[];
extern u8 D_15E3C0[];
extern u8 D_15F3C0[];
extern u8 D_1603C0[];
extern u8 D_160800[];
extern char D_001D4E20[];
extern char D_001D4E48[];
extern void func_00121FE8(s32);
extern s32 func_00122630(void *, s32, s32);
extern void func_0011AF48();
extern s32 func_0013C348(s32, s32, void *);
void func_0013B3F8(s32 flags) {
    s32 i;
    s32 sv;
    s32 buf[2];

    D_001D4DC0[0] = (s32 *)D_15C3C0;
    D_001D4DC0[1] = (s32 *)D_15D3C0;
    D_001D4DD8[0] = D_1603C0;
    D_001D4DD8[1] = D_160800;
    D_001D4DD0[0] = (E_13C578 *)D_15E3C0;
    D_001D4DD0[1] = (E_13C578 *)D_15F3C0;
    if (flags & 2) D_001D4E18 = 1;
    else D_001D4E18 = 0;
    func_00121FE8(0);
    do {
        if (func_00122630(&D_1D4900, 0x123456, 0) < 0) {
            func_0011AF48(D_001D4E20, D_001D4E48, 0xB5);
            for (;;) ;
        }
        i = 9999;
        sv = *(s32 *)0x1D4924;
        do { for (; i != -1; i--) ; } while (0);
    } while (sv == 0);
    D_001D4DE8 = 0;
    D_001D4DF0 = 0;
    D_001D4DF8 = 0;
    D_1D4A00 = 0;
    do {
        if (func_00122630(&D_1D49C0, 0x123457, 0) < 0) {
            func_0011AF48(D_001D4E20, D_001D4E48, 0xCA);
            for (;;) ;
        }
        i = 9999;
        sv = *(s32 *)0x1D49E4;
        do { for (; i != -1; i--) ; } while (0);
    } while (sv == 0);
    D_001D4DC8[0] = 0xFFC;
    *(s32 *)0x1D4980 = 0;
    *(s32 *)D_15C3C0 = 0;
    *(s32 *)D_15D3C0 = 0;
    D_001D4DC8[1] = 0xFFC;
    buf[1] = flags;
    buf[0] = (s32)&D_1D4980;
    *(volatile s32 *)&D_1D4990_0013B3F8 = 0;
    func_0013C348(0, 8, buf);
}
/* localdecomp:end func_0013B3F8 */
