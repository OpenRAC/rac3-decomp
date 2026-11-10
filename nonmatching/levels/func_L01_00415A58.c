/* Near miss, ported from rac2-decomp's func_00285548 (cross-game near pair). FLAGS: start_c unchanged (sync23/out3 file) matches under @ps2as (64-bit constants via ori/dsll32 and mixed lui/gp access are ps2as output); file flags need @ps2as. C could be tidied but is checker-verified as is */
extern int *D_L01_001E1068;
extern void func_003A9440(unsigned int, unsigned long);
extern void func_L01_004C5B48(int);

void func_L01_00415A58(int x0, int y0, int x1, int y1, int w, int h, unsigned int rgba) {
    long *q;
    int ax, ay, bx, by;
    int hw, hh;
    func_L01_004C5B48(0x13000000);
    func_003A9440(0x42, 0x64);
    *(int *)((char *)D_L01_001E1068 + 0) = 0x10000006;
    *(int *)((char *)D_L01_001E1068 + 4) = 0;
    *(int *)((char *)D_L01_001E1068 + 8) = 0;
    *(int *)((char *)D_L01_001E1068 + 12) = 0x50000006;
    ax = (x0 << 4) + 0x8000;
    ay = (y0 << 4) + 0x8000;
    bx = (x1 << 4) + 0x8000;
    by = (y1 << 4) + 0x8000;
    hw = w << 3;
    hh = h << 3;
    D_L01_001E1068 += 4;
    q = (long *)D_L01_001E1068;
    *(long *)((char *)q + 0) = 0x1000000000000001L;
    *(long *)((char *)q + 8) = 0xE;
    *(long *)((char *)q + 16) = 0x33003;
    *(long *)((char *)q + 24) = 0x47;
    *(long *)((char *)q + 32) = 0x2400000000000001L;
    *(long *)((char *)q + 40) = 0x10;
    *(long *)((char *)q + 48) = 0x106;
    *(long *)((char *)q + 56) = rgba;
    *(long *)((char *)q + 64) = 0x2400000000008001L;
    *(long *)((char *)q + 72) = 0x44;
    {
        long X1 = bx - hw;
        long X0 = ax - hw;
        long Y0 = ay - hh;
        long Y1 = by - hh;
        *(long *)((char *)q + 80) = X0 | (Y0 << 16);
        *(long *)((char *)q + 88) = X1 | (Y1 << 16);
    }
    D_L01_001E1068 += 0x18;
    func_003A9440(0x42, 0x8000000044L);
    func_L01_004C5B48(0x13000000);
}