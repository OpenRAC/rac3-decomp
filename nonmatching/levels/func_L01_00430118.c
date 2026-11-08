/* Near miss, ported from rac2-decomp's func_L00_003080D0 (cross-game near pair). NEAR: compiles; retail has extra gp byte early-return (.extern D_001D71E8,1 + sdata), 6th arg -1 to func_L01_004316B0, mask at +0x390; still 0x10 smaller frame (one fewer spilled local) and base ptr kept in s2/s7 differently; register-allocation level, stopped */
typedef struct Map_430118 {
    unsigned char pad00[0xc];
    unsigned char *bitmap;
    unsigned char pad10[0x18];
    int active;
    unsigned char pad2c[0xc];
    unsigned char *samples;
    unsigned char pad3c[0x354];
    unsigned char mask[32][4];
} Map_430118;
extern int func_L01_004308B0(int);
extern s32 D_001D545C;
__asm__(".extern D_001D71E8, 1");
extern u8 D_001D71E8 __attribute__((section(".sdata")));
extern int func_L01_00430778(void);
extern void func_L01_004316B0(float, float, float *, float *, int, int);

void func_L01_00430118(float *position)
{
    float px, py;
    int x, y, maxY, maxX, minY, minX;
    int row, col;
    int colour;
    int regionRow, sampleRow;
    unsigned int sample;
    unsigned char *cell;
    int bit;
    Map_430118 *m = (Map_430118 *)&D_L01_001F3FA0;
    if (D_001D71E8 != 0)
        return;
    if (m->active == 0)
        return;
    if (func_L01_00430778())
        return;
    func_L01_004316B0(position[0], position[1], &px, &py, D_001D545C, -1);
    x = (int)(px * 512.0f) + 1;
    y = (int)(py * 512.0f) + 1;
    if (x < 0 || y < 0 || x >= 512 || y >= 512)
        return;
    minY = y - 16;
    minX = x - 16;
    maxY = y + 16;
    maxX = x + 16;
    if (minY < 0) minY = 0;
    if (maxY >= 512) maxY = 511;
    if (minX < 0) minX = 0;
    if (maxX >= 512) maxX = 511;
    regionRow = (y >> 5) * 16;
    func_L01_004308B0((x >> 5) + regionRow);
    sampleRow = y & 31;
    sampleRow *= 16;
    {
        unsigned char value;
        int index;
        sample = x & 31;
        index = (int)sample >> 1;
        value = *(m->samples + index + sampleRow);
        if (x & 1) value >>= 4;
        else value &= 15;
        colour = value;
    }
    for (row = minY; row < maxY; row++) {
        int dy;
        dy = row - y + 16;
        regionRow = (row >> 5) * 16;
        sampleRow = row & 31;
        sampleRow *= 16;
        for (col = minX; col < maxX; col++) {
            cell = m->bitmap + row * 64 + col / 8;
            if (*cell != 0) {
                bit = 1 << (col & 7);
                if (*cell & bit) {
                    int dx = col - x + 16;
                    if ((*(m->mask[0] + (dx / 8 + (dy << 2))) >> (dx % 8)) & 1)
                        continue;
                    func_L01_004308B0((col >> 5) + regionRow);
                    sample = (col & 31) / 2;
                    sample = *(m->samples + sample + sampleRow);
                    if (col & 1) sample >>= 4;
                    else sample &= 15;
                    if (colour == sample)
                        *cell &= ~bit;
                }
            }
        }
    }
}