/* Near miss, ported from rac2-decomp's func_L00_00310048 (cross-game near pair). NEAR: only diff: retail stores the increment via lui $at/sw -0xc0 (non-gp) while init store and loads use gp 0x3690; one extra instruction shifts the rest; .extern hints for E0020/E0024/FB40 fixed the rest */
__asm__(".extern D_L01_001E0020, 16");
__asm__(".extern D_L01_001E0024, 16");
__asm__(".extern D_L01_001DFB40, 16");
extern unsigned char *D_L01_001E0020;
extern unsigned char *D_L01_001E0024;
extern unsigned int D_L01_001DFB40;
extern unsigned int D_L01_001DFF40 __attribute__((section(".sdata")));

void func_L01_00438EA0(void)
{
    unsigned char *p;
    int seen = 0;
    D_L01_001DFF40 = 0;
    for (p = D_L01_001E0020; p < D_L01_001E0024; p += 256) {
        if ((p[32] >= 254 && *(unsigned int *)(p + 160) <= D_L01_001DFB40) || seen) {
            D_L01_001DFF40++;
            if (p[32] == 0xff)
                seen = 1;
        }
    }
}
