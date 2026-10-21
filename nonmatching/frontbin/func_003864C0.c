/* US draft of func_003864C0 (rac3-uya-decomp func_003821E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003864C0 */
typedef struct { u8 pad[0x450]; s32 f450; } E_3821E8;
extern u8 D_00222480_003864C0[];
typedef struct { u8 p0[0x228]; f32 f228; f32 f22C; u8 p230[8]; f32 f238; f32 f23C; u8 p240[0x10]; s32 f250; s32 f254; s32 f258; } S_3821E8;
extern S_3821E8 D_00225900;
extern u8 D_001D99AC, D_001D99AD, D_001D99AE, D_001D9C44, D_001D9C45, D_001D9C46;
extern f32 D_001D99C4, D_001D99C8, D_001D99CC, D_001D99D0, D_001D9C48, D_001D9C4C, D_001D9C50, D_001D9C54;
extern s32 D_001DA5D0, D_001D9C58;
extern void func_003873C0();
void func_003864C0(s32 a) {
    s32 c;
    if (((E_3821E8 *)(a * 0x460 + (s32)D_00222480_003864C0))->f450 != 0) {
        D_00225900.f250 = D_001D99AC;
        D_00225900.f254 = D_001D99AD;
        D_00225900.f258 = D_001D99AE;
        D_00225900.f228 = D_001D99C4;
        D_00225900.f22C = D_001D99C8;
        D_00225900.f238 = D_001D99CC;
        D_00225900.f23C = D_001D99D0;
        c = 0x40000;
    } else {
        D_00225900.f250 = D_001D9C44;
        D_00225900.f254 = D_001D9C45;
        D_00225900.f258 = D_001D9C46;
        D_00225900.f228 = D_001D9C48;
        D_00225900.f22C = D_001D9C4C;
        D_00225900.f238 = D_001D9C50;
        D_00225900.f23C = D_001D9C54;
        c = 0x7D0000;
    }
    D_001DA5D0 = c;
    func_003873C0();
    D_001D9C58 = 0;
}
/* localdecomp:end func_003864C0 */
