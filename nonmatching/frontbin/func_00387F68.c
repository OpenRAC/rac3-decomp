/* US draft of func_00387F68 (rac3-uya-decomp func_003838C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_00387F68 */
extern u32 *D_001DA050_00387F68;
__asm__(".extern D_001DA050_g, 4");
extern u32 *D_001DA050_g;
extern u8 D_001421B0[];
extern u8 D_00142120[];
extern long D_001D5330_00387F68[];
typedef struct { u8 p0[0x240]; s32 f240, f244, f248, f24C, f250, f254, f258; } S_225980_3838C0;
extern S_225980_3838C0 D_00225900_00387F68;
extern void func_0038CC88();
extern void func_003A9440(s32, unsigned long);
void func_00387F68(void) {
    D_001DA050_00387F68[0] = 0x30000013;
    D_001DA050_00387F68[1] = (u32)D_001421B0;
    D_001DA050_00387F68[2] = 0;
    D_001DA050_00387F68[3] = 0x50000013;
    D_001DA050_00387F68 += 4;
    D_001DA050_00387F68[0] = 0x30000009;
    D_001DA050_00387F68[1] = (u32)D_00142120;
    D_001DA050_00387F68[2] = 0;
    D_001DA050_00387F68[3] = 0x50000009;
    D_001DA050_00387F68 += 4;
    D_001DA050_00387F68[0] = 0x10000003;
    D_001DA050_00387F68[1] = 0;
    D_001DA050_00387F68[2] = 0;
    D_001DA050_00387F68[3] = 0x50000003;
    D_001D5330_00387F68[2] = (long)D_00225900_00387F68.f240 | ((long)D_00225900_00387F68.f244 << 16) | ((long)D_00225900_00387F68.f248 << 32) | ((long)D_00225900_00387F68.f24C << 48);
    D_001DA050_00387F68 += 4;
    D_001D5330_00387F68[4] = (long)D_00225900_00387F68.f240 | ((long)D_00225900_00387F68.f244 << 16) | ((long)D_00225900_00387F68.f248 << 32) | ((long)D_00225900_00387F68.f24C << 48);
    func_0038CC88(D_001DA050_00387F68, D_001D5330_00387F68, 0x30);
    D_001DA050_g = (u32 *)((u8 *)D_001DA050_00387F68 + 0x30);
    func_003A9440(0x3D, (long)D_00225900_00387F68.f250 | ((long)D_00225900_00387F68.f254 << 8) | ((long)D_00225900_00387F68.f258 << 16));
    func_003A9440(0x51, 0);
}
/* localdecomp:end func_00387F68 */
