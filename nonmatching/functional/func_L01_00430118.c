/* functional: high. Rewritten from the PAL asm (the old draft was ported from another project). Same checks, clamps, call order and bit logic; bytes differ (register allocation, 200 of 209 words) which does not change behaviour. */
typedef struct Map_430118 {
    u8 pad00[0xC];
    u8 *bitmap;        /* 512 rows x 64 bytes, 1 bit per cell */
    u8 pad10[0x18];
    s32 active;
    u8 pad2c[0xC];
    u8 *samples;       /* 32x32 block of 4-bit colours, 16 bytes per row */
    u8 pad3c[0x354];
    u8 mask[32][4];    /* 32x32 brush mask */
} Map_430118;
extern s32 D_001D545C;
__asm__(".extern D_L01_001D71E8, 1");
extern u8 D_L01_001D71E8 __attribute__((section(".sdata")));
extern s32 func_L01_00430778(void);
extern void func_L01_004308B0(s32);
extern void func_L01_004316B0(float, float, float *, float *, s32, s32);

void func_L01_00430118(float *position) {
    float px, py;
    s32 x, y, minX, minY, maxX, maxY, row, col, colour, dx, dy, bit;
    u8 *cell;
    Map_430118 *m = (Map_430118 *)&D_L01_001F3FA0;
    if (D_L01_001D71E8 != 0) return;
    if (m->active == 0) return;
    if (func_L01_00430778() != 0) return;
    func_L01_004316B0(position[0], position[1], &px, &py, D_001D545C, -1);
    x = (s32)(px * 512.0f) + 1;
    y = (s32)(py * 512.0f) + 1;
    if (x < 0 || y < 0 || x >= 512 || y >= 512) return;
    minX = x - 16; minY = y - 16; maxX = x + 16; maxY = y + 16;
    if (minX < 0) minX = 0;
    if (minY < 0) minY = 0;
    if (maxX >= 512) maxX = 511;
    if (maxY >= 512) maxY = 511;
    func_L01_004308B0((x >> 5) + (y >> 5) * 16);
    colour = m->samples[((x & 31) >> 1) + (y & 31) * 16];
    if (x & 1) colour >>= 4; else colour &= 15;
    for (row = minY; row < maxY; row++) {
        dy = row - y + 16;
        for (col = minX; col < maxX; col++) {
            cell = m->bitmap + row * 64 + col / 8;
            if (*cell == 0) continue;
            bit = 1 << (col & 7);
            if (!(*cell & bit)) continue;
            dx = col - x + 16;
            if ((m->mask[0][dx / 8 + dy * 4] >> (dx % 8)) & 1) continue;
            func_L01_004308B0((col >> 5) + (row >> 5) * 16);
            {
                s32 s = m->samples[((col & 31) >> 1) + (row & 31) * 16];
                if (col & 1) s >>= 4; else s &= 15;
                if (colour == s) *cell &= ~bit;
            }
        }
    }
}
