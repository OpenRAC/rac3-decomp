/* func_L01_004A2878: matches level 01 (check.py MATCH) but not every level: its 3rd call (func_L01_00516090 in level 01) goes to a different catalogue function in levels 04, 12, 18, 26 and 29. */
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 func_L01_004A1128(void);
extern s32 func_L01_00517748(s32 a);
extern void func_L01_00516090(void *p);

void func_L01_004A2878(void *a0) {
    if (*(s32 *)(D_001D52FC + 0x1C4) & 0x910) {
        func_L01_00517748(func_L01_004A1128());
        func_L01_00516090(a0);
    }
}
